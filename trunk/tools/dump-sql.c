/*
 * dump-sql.c --
 *
 *      Operations to generate SQL data definitions statements.
 *
 * Copyright (c) 2000 Frank Strauss, Technical University of Braunschweig.
 * Copyright (c) 2000 J. Schoenwaelder, Technical University of Braunschweig.
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * @(#) $Id: dump-sql.c,v 1.12 2000/02/12 10:56:21 strauss Exp $
 */

#include <config.h>

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>

#include "smi.h"
#include "smidump.h"


static char* translate(char *m)
{
    char *s;
    int i;

    s = xstrdup(m);
    for (i = 0; s[i]; i++) {
	if (s[i] == '-') s[i] = '_';
    }
  
    return s;
}



static int isGroup(SmiNode *smiNode)
{
    SmiNode *childNode;

    if (smiNode->nodekind == SMI_NODEKIND_ROW) {
	return 1;
    }
    
    for(childNode = smiGetFirstChildNode(smiNode);
	childNode;
	childNode = smiGetNextChildNode(childNode)) {
	if (childNode->nodekind == SMI_NODEKIND_SCALAR) {
	    return 1;
	}
    }

    return 0;
}



static int isAccessible(SmiNode *groupNode)
{
    SmiNode *smiNode;
    int num = 0;
    
    for (smiNode = smiGetFirstChildNode(groupNode);
	 smiNode;
	 smiNode = smiGetNextChildNode(smiNode)) {
	if ((smiNode->nodekind == SMI_NODEKIND_SCALAR
	     || smiNode->nodekind == SMI_NODEKIND_COLUMN)
	    && (smiNode->access == SMI_ACCESS_READ_ONLY
		|| smiNode->access == SMI_ACCESS_READ_WRITE)) {
	    num++;
	}
    }

    return num;
}



static void printCreateTable(SmiNode *groupNode)
{
    SmiNode *smiNode;
    SmiType *smiType;
    char    *sqlTableName;
    int     i;

    if (groupNode->nodekind == SMI_NODEKIND_ROW) {
	sqlTableName = translate(smiGetParentNode(groupNode)->name);
    } else {
	sqlTableName = translate(groupNode->name);
    }
    printf("create table %s (\n", sqlTableName);
    xfree(sqlTableName);

    for (smiNode = smiGetFirstChildNode(groupNode), i = 0;
	 smiNode;
	 smiNode = smiGetNextChildNode(smiNode), i++) {
	if (smiNode->nodekind & (SMI_NODEKIND_COLUMN | SMI_NODEKIND_SCALAR)
#if 0
	    && (smiNode->access == SMI_ACCESS_READ_ONLY
		|| smiNode->access == SMI_ACCESS_READ_WRITE)
#endif
	    ) {
	    smiType = smiGetNodeType(smiNode);
	    if (smiType && ! smiType->name) {
		smiType = smiGetParentType(smiType);
	    }
	    if (i) {
		printf(",\n");
	    }
	    if (smiType) {
		printf("    %s %s", smiNode->name, smiType->name);
	    }
	}
    }
    printf("\n);\n\n");
}



static void printCreateTables(SmiModule *smiModule)
{
    SmiNode   *smiNode;
    int       cnt = 0;
    
    for(smiNode = smiGetFirstNode(smiModule, SMI_NODEKIND_ANY);
	smiNode;
	smiNode = smiGetNextNode(smiNode, SMI_NODEKIND_ANY)) {
	if (isGroup(smiNode) && isAccessible(smiNode)) {
	    cnt++;
	    printCreateTable(smiNode);
	}
    }
    
    if (cnt) {
	printf("\n");
    }
}



int dumpSql(char *modulename, int flags)
{
    SmiModule    *smiModule;

    if (!modulename) {
	fprintf(stderr,
		"smidump: united output not supported for UCD-C format\n");
	exit(1);
    }
    
    smiModule = smiGetModule(modulename);
    if (!smiModule) {
	fprintf(stderr, "smidump: cannot locate module `%s'\n", modulename);
	exit(1);
    }

    printf("/*\n"
	   " * This SQL file has been generated by smidump " VERSION ".\n"
	   " *\n"
	   " * This SQL file is derived from the %s module.\n"
	   " *\n * $I" "d$\n"
	   " */\n\n", smiModule->name );
	
    printCreateTables(smiModule);

    return 0;
}
