/*
 * dump-sming.c --
 *
 *      Operations to dump SMIng module information.
 *
 * Copyright (c) 1998 Technical University of Braunschweig.
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * @(#) $Id$
 */

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "error.h"
#include "util.h"
#include "data.h"
#include "smi.h"



static char *
getOidString(nodePtr)
    Node *nodePtr;
{
    static char s[SMI_MAX_OID+1];

    s[0] = 0;

    /* TODO: ptrs might be NULL, firstObjectPtr might be the wrong one */
    strcpy(s, nodePtr->parentPtr->firstObjectPtr->name);
    strcat(s, ".");
    sprintf(&s[strlen(s)], "%d", nodePtr->subid);
    return s;
}



static void
printMultilineString(s)
    const char *s;
{
    int i;
    
    printf("       \"");
    if (s) {
	for (i=0; i < strlen(s); i++) {
	    if (s[i] != '\n') {
		printf("%c", s[i]);
	    } else {
		printf("\n");
		printf("        ");
	    }
	}
    }
    printf("\"");
}



static void
printImports()
{

}



void
dumpSming(modulename)
    const char *modulename;
{
    Module *modulePtr;

    modulePtr = findModuleByName(modulename);

    if (!modulePtr) {
	printError(NULL, ERR_MODULE_NOT_FOUND, modulename);
    } else {
	printf("//\n");
	printf("// This module has been generated by smidump. Do not edit.\n");
	printf("//\n");
	printf("module %s ", modulePtr->name);
	if (modulePtr->objectPtr) {
	    printf("%s ", modulePtr->objectPtr->name);
	}
	printf("{\n");
	printf("\n");

	printImports();

	if (modulePtr->objectPtr) {
	    printf("    oid                 %s;\n",
		   getOidString(modulePtr->objectPtr->nodePtr));
	    printf("\n");
	    printf("    organization        \n");
	    printMultilineString(modulePtr->organization);
	    printf(";\n");
	    printf("\n");
	    printf("    contact             \n");
	    printMultilineString(modulePtr->contactInfo);
	    printf(";\n");
	    printf("\n");
	    printf("    description         \n");
	    printMultilineString(modulePtr->objectPtr->description);
	    printf(";\n");
	    printf("\n");
	    
	    
	}
	
	/* printTypedefs(); */
	/* printObjects(); */
	/* printNotifications(); */
	/* printGroups(); */
	/* printCompliances(); */	
	printf("};\n");
    }
#if 0
    if (root) {
	if (root != rootNode) {
	    if ((root->flags & FLAG_MODULE) &&
		(root->firstObject->descriptor &&
		 root->parent->firstObject->descriptor)) {
		sprintf(s, "%s.%d",
			root->parent->firstObject->descriptor->name,
			root->subid);
		if (root->firstObject->decl == SMI_DECL_OBJECTTYPE) {
		    printf("%-19s %-19s %-15s %-15s %s\n",
			   root->firstObject->descriptor->name,
			   s,
			   "<type>",
			   smiStringAccess(root->firstObject->access),
			   smiStringStatus(root->firstObject->status));
		} else {
		    printf("%-19s %s\n",
			   root->firstObject->descriptor->name,
			   s);
		}
	    }
	}
	for (c = root->firstChild; c; c = c->next) {
	    dumpMosy(c);
	}
    }
#endif
}
