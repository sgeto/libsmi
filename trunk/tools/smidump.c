/*
 * smidump.c --
 *
 *      Dump a MIB module conforming to a given format.
 *
 * Copyright (c) 1999 Frank Strauss, Technical University of Braunschweig.
 * Copyright (c) 1999 J. Schoenwaelder, Technical University of Braunschweig.
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * @(#) $Id: smidump.c,v 1.30 2000/02/24 10:35:43 strauss Exp $
 */

#include <config.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

#include "smi.h"
#include "smidump.h"



typedef struct {
    char *name;				/* Name of the output driver. */
    int (*func) (char *, int);		/* Output generating function. */
    int smiflags;			/* Flags for the SMI parser. */
    char *descr;			/* Short description. */
} Driver;
 


static Driver driverTable[] = {
    { "SMIng",	   dumpSming,	0,
      "SMIng" },
    { "SMIv2",	   dumpSmiV2,	0,
      "SMIv2 (RFC 2578, RFC 2579, RFC 2580)"},
    { "SMIv1",	   dumpSmiV1,	0,
      "SMIv1 (RFC 1155, RFC 1212, RFC 1215)"},
    { "imports",   dumpImports,	SMI_FLAG_NODESCR,
      "recursive list of all imports" },
    { "types",	   dumpTypes,	SMI_FLAG_NODESCR,
      "recursive list of all derived types" },
    { "tree",	   dumpTree,	SMI_FLAG_NODESCR,
      "structure of the OID tree" },
    { "mosy",	   dumpMosy,	SMI_FLAG_NODESCR,
      "output format generated by the mosy compiler" },
    { "corba-idl", dumpCorbaIdl, 0,
      "corba IDL interface definitions (JIDM)" },
    { "corba-oid", dumpCorbaOid, SMI_FLAG_NODESCR,
      "corba OID definitions (JIDM)" },
#if 0
    { "sql",       dumpSql,	SMI_FLAG_NODESCR,
      "SQL data definition statements" },
#endif
    { "ucd-h",     dumpUcdH,	SMI_FLAG_NODESCR,
      "UCD SNMP mib module C header" },
    { "ucd-c",	   dumpUcdC,	SMI_FLAG_NODESCR,
      "UCD SNMP mib module C code" },
    { "dia",       dumpDia,	SMI_FLAG_NODESCR,
      "UML graphics in DIA XML format" },
    { "jax",       dumpJax,	SMI_FLAG_NODESCR,
      "Java AgentX sub-agent classes format in separate files" },
#if 0
    { "fig-tree",  dumpFigTree,	SMI_FLAG_NODESCR,
      "tree graphics in xfig fig format" },
    { "fig-uml",   dumpFigUml,	SMI_FLAG_NODESCR,
      "UML graphics in xfig fig format" },
#endif
#if 0
    { "java",      dumpJava,	SMI_FLAG_NODESCR,
      "java manager stub code (JMGMT)" },
    { "jdmk",      dumpJdmk,	SMI_FLAG_NODESCR,
      "java manager stub code (JDMK)" },
#endif
    { NULL, NULL, 0, NULL }
};



void *xmalloc(size_t size)
{
    char *m = malloc(size);
    if (! m) {
	fprintf(stderr, "smidump: malloc failed - running out of memory\n");
	exit(1);
    }
    return m;
}



void *xrealloc(void *ptr, size_t size)
{
    char *m = realloc(ptr, size);
    if (! m) {
	fprintf(stderr, "smidump: realloc failed - running out of memory\n");
	exit(1);
    }
    return m;
}



char *xstrdup(const char *s)
{
    char *m = strdup(s);
    if (! m) {
	fprintf(stderr, "smidump: strdup failed - running out of memory\n");
	exit(1);
    }
    return m;
}



void xfree(void *ptr)
{
    free(ptr);
}



static void formats()
{
    Driver *driver = driverTable;
    
    for (driver = driverTable; driver->name; driver++) {
	fprintf(stderr, "  %-12s: %s\n", driver->name,
 		driver->descr ? driver->descr : "...");
    }
}



static void usage()
{
    fprintf(stderr,
	    "Usage: smidump [-Vhsu] [-l <level>] [-c <configfile>] [-f <format>]\n"
	    "               [-p <module>] <module_or_path>\n"
	    "-V                  show version and license information\n"
	    "-h                  show usage information\n"
	    "-s                  do not generate any comments\n"
	    "-c <configfile>     load a specific configuration file\n"
	    "-p <module>         preload <module>\n"
	    "-l <level>          set maximum level of errors and warnings\n"
	    "-f <format>         use <format> when dumping (default %s)\n"
	    "-u                  print a single united output of all modules\n"
	    "<module_or_path>    name of a MIB module or file path\n\n",
	    driverTable->name);
    fprintf(stderr, "Supported formats are:\n");
    formats();
}



static void version()
{
    printf("smidump " VERSION "\n");
}



int
main(argc, argv)
    int argc;
    char *argv[];
{
    char c;
    char *modulename;
    int flags, smiflags, i;
    int errors = 0;
    int unite = 0;
    Driver *driver = driverTable;

    for (i = 1; i < argc; i++) if (strstr(argv[i], "-c") == argv[i]) break;
    if (i == argc) 
	smiInit("smidump");
    else
	smiInit(NULL);

    flags = 0;
    while ((c = getopt(argc, argv, "Vhsul:f:p:c:")) != -1) {
	switch (c) {
	case 'c':
	    smiReadConfig(optarg, "smiquery");
	    break;
	case 'V':
	    version();
	    exit(0);
	case 'h':
	    usage();
	    exit(0);
	case 'l':
	    smiSetErrorLevel(atoi(optarg));
	    break;
	case 's':
	    flags |= SMIDUMP_FLAG_SILENT;
	    break;
	case 'p':
	    smiLoadModule(optarg);
	    break;
	case 'u':
	    unite++;
	    break;
	case 'f':
	    for (driver = driverTable; driver->name; driver++) {
		if (strcasecmp(driver->name, optarg) == 0) {
		    break;
		}
	    }
	    if (!driver->name) {
		fprintf(stderr, "smidump: invalid dump format `%s'"
			" - supported formats are:\n", optarg);
		formats();
		exit(1);
	    }
	    break;
	default:
	    usage();
	    exit(1);
	}
    }

    smiflags = smiGetFlags();
    smiflags |= SMI_FLAG_ERRORS;
    smiflags |= driver->smiflags;
    smiSetFlags(smiflags);

    while (optind < argc) {
	modulename = smiLoadModule(argv[optind]);
	if (modulename) {
	    if (!unite)
		errors += (driver->func)(modulename, flags);
	} else {
	    fprintf(stderr, "smidump: cannot locate module `%s'\n",
		    argv[optind]);
	}
	optind++;
    }

    if (unite)
	errors += (driver->func)(NULL, flags);
    
    smiExit();
    
    exit(errors);
}
