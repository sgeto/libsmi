/*
 * dump-fig.c --
 *
 *      Operations to dump graphic representation of MIBs in fig format.
 *
 * Copyright (c) 1999 J. Schoenwaelder, Technical University of Braunschweig.
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * @(#) $Id$
 */

#include <config.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "smi.h"
#include "smidump.h"


#define	 X_OFFSET	225
#define	 Y_OFFSET	225
#define	 X_INDENT	225
#define	 Y_INDENT	225



static char *getSmiTypeName(SmiNode *smiNode)
{
    char *type;
    SmiType *smiType, *parentType;

    smiType = smiGetNodeType(smiNode);

    if (!smiType || smiNode->nodekind == SMI_NODEKIND_TABLE)
	return NULL;

    if (smiType->decl == SMI_DECL_IMPLICIT_TYPE) {
	parentType = smiGetParentType(smiType);
	if (!parentType)
	    return NULL;
	smiType = parentType;
    }

    type = smiStrdup(smiType->name);
    return type;
}



static void setupPage(FILE *f)
{
    fprintf(f,
	    "#FIG 3.2\n"
	    "#\n"
	    "# This FIG file has been generated by smidump " SMI_VERSION_STRING
	    ". Do not edit.\n#\n"
	    "Landscape\n"
	    "Center\n"
	    "Metric\n"
	    "A4\n"
	    "50.00\n"
	    "Single\n"
	    "-1\n"
	    "1200 2\n");
}



static void printString(FILE *f, int x, int y, int angle, char *string)
{
    int height = 180, length = 22;

    fprintf(f, "4 0 0 0 0 18 12 0.0 4 %d %d %d %d %s\\001\n",
	    height, length, x, y, string);
}



static int isGroup(SmiNode *smiNode)
{
    SmiNode *childNode;
    
    for (childNode = smiGetFirstChildNode(smiNode);
	 childNode;
	 childNode = smiGetNextChildNode(childNode)) {
	if ((childNode->nodekind == SMI_NODEKIND_SCALAR
	     || childNode->nodekind == SMI_NODEKIND_TABLE)
	    && childNode->status == SMI_STATUS_CURRENT) {
	    return 1;
	}
    }
    
    return 0;
}



static void printGroup(FILE *f, int *x, int *y, SmiNode *smiNode)
{
    SmiNode *childNode;
    char string[4096];

    *y += Y_OFFSET;
    printString(f, *x, *y, 0, smiNode->name);

    for (childNode = smiGetFirstChildNode(smiNode);
	 childNode;
	 childNode = smiGetNextChildNode(childNode)) {
	if (childNode->nodekind == SMI_NODEKIND_SCALAR
	    || childNode->nodekind == SMI_NODEKIND_COLUMN) {
	    if (childNode->status != SMI_STATUS_OBSOLETE) {
		*y += Y_OFFSET;
		snprintf(string, sizeof(string), "%s(%d)", childNode->name,
			 childNode->oid[childNode->oidlen-1]);
		printString(f, *x + X_INDENT, *y, 0, string);
	    }
	}
    }
    *y += Y_OFFSET;
}



static void printGroups(FILE *f, int *x, int *y, SmiModule *smiModule)
{
    SmiNode *smiNode;

    for (smiNode = smiGetFirstNode(smiModule, SMI_NODEKIND_ANY);
	 smiNode;
	 smiNode = smiGetNextNode(smiNode, SMI_NODEKIND_ANY)) {
	if (isGroup(smiNode)) {
	    printGroup(f, x, y, smiNode);
	}
	if (smiNode->nodekind == SMI_NODEKIND_ROW) {
	    printGroup(f, x, y, smiNode);
	}
    }
}



static void dumpFigTree(int modc, SmiModule **modv, int flags, char *output)
{
    int       x, y, i;
    FILE      *f = stdout;

    if (output) {
	f = fopen(output, "w");
	if (!f) {
	    fprintf(stderr, "smidump: cannot open %s for writing: ", output);
	    perror(NULL);
	    exit(1);
	}
    }

    setupPage(f);
    x = X_OFFSET, y = Y_OFFSET;
    for (i = 0; i < modc; i++) {
	printGroups(f, &x, &y, modv[i]);
    }

    if (fflush(f) || ferror(f)) {
	perror("smidump: write error");
	exit(1);
    }

    if (output) {
	fclose(f);
    }
}



static void printClass(FILE *f, int *x, int *y, SmiNode *smiNode)
{
    SmiNode *childNode;
    char *type;
    char string[4096];

    *y += Y_OFFSET;
    printString(f, *x, *y, 0, smiNode->name);

    for(childNode = smiGetFirstChildNode(smiNode);
	childNode;
	childNode = smiGetNextChildNode(childNode)) {
	if (childNode->nodekind == SMI_NODEKIND_SCALAR
	    || childNode->nodekind == SMI_NODEKIND_COLUMN) {
	    if (childNode->status != SMI_STATUS_OBSOLETE) {
		type = getSmiTypeName(childNode);
		*y += Y_OFFSET;
		snprintf(string, sizeof(string), "%s : %s",
			 childNode->name, type ? type : "?");
		printString(f, *x + X_INDENT, *y, 0, string);
		if (type) smiFree(type);
	    }
	}
    }
    *y += Y_OFFSET;
}



static void printClasses(FILE *f, int *x, int *y, SmiModule *smiModule)
{
    SmiNode *smiNode;

    for (smiNode = smiGetFirstNode(smiModule, SMI_NODEKIND_ANY);
	 smiNode;
	 smiNode = smiGetNextNode(smiNode, SMI_NODEKIND_ANY)) {
	if (isGroup(smiNode)) {
	    printClass(f, x, y, smiNode);
	}
	if (smiNode->nodekind == SMI_NODEKIND_ROW) {
	    printClass(f, x, y, smiNode);
	}
    }
}



static void dumpFigUml(int modc, SmiModule **modv, int flags, char *output)
{
    int       x, y, i;
    FILE      *f = stdout;

    if (output) {
	f = fopen(output, "w");
	if (!f) {
	    fprintf(stderr, "smidump: cannot open %s for writing: ", output);
	    perror(NULL);
	    exit(1);
	}
    }

    setupPage(f);
    x = X_OFFSET, y = Y_OFFSET;
    for (i = 0; i < modc; i++) {
	printClasses(f, &x, &y, modv[i]);
    }

    if (fflush(f) || ferror(f)) {
	perror("smidump: write error");
	exit(1);
    }

    if (output) {
	fclose(f);
    }
}



void initFig()
{
    static SmidumpDriver driverTree = {
	"fig-tree",
	dumpFigTree,
	SMI_FLAG_NODESCR,
	SMIDUMP_DRIVER_CANT_UNITE | SMIDUMP_DRIVER_CANT_OUTPUT,
	"tree graphics in xfig fig format",
	NULL,
	NULL
    };
    static SmidumpDriver driverUml = {
	"fig-uml",
	dumpFigUml,
	SMI_FLAG_NODESCR,
	SMIDUMP_DRIVER_CANT_UNITE | SMIDUMP_DRIVER_CANT_OUTPUT,
	"UML graphics in xfig fig format",
	NULL,
	NULL
    };
    
    smidumpRegisterDriver(&driverTree);
    smidumpRegisterDriver(&driverUml);
}
