/*
 * This C file has been generated by smidump 0.2.17.
 * It is intended to be used with the NET-SNMP agent library.
 *
 * This C file is derived from the MAU-MIB module.
 *
 * $Id$
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "mau-mib.h"

#include <ucd-snmp/asn1.h>
#include <ucd-snmp/snmp.h>
#include <ucd-snmp/snmp_api.h>
#include <ucd-snmp/snmp_impl.h>
#include <ucd-snmp/snmp_vars.h>

/*
 * Forward declaration of read methods for groups of scalars and tables:
 */

static unsigned char *
read_rpMauEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_rpJackEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_ifMauEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_ifJackEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_broadMauBasicEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_ifMauAutoNegEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);

/*
 * Forward declaration of write methods for writable objects:
 */

static int
write_rpMauStatus_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_ifMauStatus_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_ifMauDefaultType_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_ifMauAutoNegAdminStatus_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_ifMauAutoNegCapAdvertised_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_ifMauAutoNegRestart_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_ifMauAutoNegCapAdvertisedBits_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_ifMauAutoNegRemoteFaultAdvertised_stub(int, u_char *, u_char, int, u_char *, oid *, int);

/*
 * Definitions of tags that are used internally to read/write
 * the selected object type. These tags should be unique.
 */

#define RPMAUGROUPINDEX                  1
#define RPMAUPORTINDEX                   2
#define RPMAUINDEX                       3
#define RPMAUTYPE                        4
#define RPMAUSTATUS                      5
#define RPMAUMEDIAAVAILABLE              6
#define RPMAUMEDIAAVAILABLESTATEEXITS    7
#define RPMAUJABBERSTATE                 8
#define RPMAUJABBERINGSTATEENTERS        9
#define RPMAUFALSECARRIERS               10

static oid rpMauEntry_base[] = {1, 3, 6, 1, 2, 1, 26, 1, 1, 1};

struct variable rpMauEntry_variables[] = {
    { RPMAUGROUPINDEX, ASN_INTEGER, RONLY, read_rpMauEntry_stub, 1, {1} },
    { RPMAUPORTINDEX, ASN_INTEGER, RONLY, read_rpMauEntry_stub, 1, {2} },
    { RPMAUINDEX, ASN_INTEGER, RONLY, read_rpMauEntry_stub, 1, {3} },
    { RPMAUTYPE, ASN_OBJECT_ID, RONLY, read_rpMauEntry_stub, 1, {4} },
    { RPMAUSTATUS, ASN_INTEGER, RWRITE, read_rpMauEntry_stub, 1, {5} },
    { RPMAUMEDIAAVAILABLE, ASN_INTEGER, RONLY, read_rpMauEntry_stub, 1, {6} },
    { RPMAUMEDIAAVAILABLESTATEEXITS, ASN_INTEGER, RONLY, read_rpMauEntry_stub, 1, {7} },
    { RPMAUJABBERSTATE, ASN_INTEGER, RONLY, read_rpMauEntry_stub, 1, {8} },
    { RPMAUJABBERINGSTATEENTERS, ASN_INTEGER, RONLY, read_rpMauEntry_stub, 1, {9} },
    { RPMAUFALSECARRIERS, ASN_INTEGER, RONLY, read_rpMauEntry_stub, 1, {10} },
};

#define RPJACKTYPE                       2

static oid rpJackEntry_base[] = {1, 3, 6, 1, 2, 1, 26, 1, 2, 1};

struct variable rpJackEntry_variables[] = {
    { RPJACKTYPE, ASN_INTEGER, RONLY, read_rpJackEntry_stub, 1, {2} },
};

#define IFMAUIFINDEX                     1
#define IFMAUINDEX                       2
#define IFMAUTYPE                        3
#define IFMAUSTATUS                      4
#define IFMAUMEDIAAVAILABLE              5
#define IFMAUMEDIAAVAILABLESTATEEXITS    6
#define IFMAUJABBERSTATE                 7
#define IFMAUJABBERINGSTATEENTERS        8
#define IFMAUFALSECARRIERS               9
#define IFMAUTYPELIST                    10
#define IFMAUDEFAULTTYPE                 11
#define IFMAUAUTONEGSUPPORTED            12
#define IFMAUTYPELISTBITS                13

static oid ifMauEntry_base[] = {1, 3, 6, 1, 2, 1, 26, 2, 1, 1};

struct variable ifMauEntry_variables[] = {
    { IFMAUIFINDEX, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {1} },
    { IFMAUINDEX, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {2} },
    { IFMAUTYPE, ASN_OBJECT_ID, RONLY, read_ifMauEntry_stub, 1, {3} },
    { IFMAUSTATUS, ASN_INTEGER, RWRITE, read_ifMauEntry_stub, 1, {4} },
    { IFMAUMEDIAAVAILABLE, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {5} },
    { IFMAUMEDIAAVAILABLESTATEEXITS, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {6} },
    { IFMAUJABBERSTATE, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {7} },
    { IFMAUJABBERINGSTATEENTERS, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {8} },
    { IFMAUFALSECARRIERS, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {9} },
    { IFMAUTYPELIST, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {10} },
    { IFMAUDEFAULTTYPE, ASN_OBJECT_ID, RWRITE, read_ifMauEntry_stub, 1, {11} },
    { IFMAUAUTONEGSUPPORTED, ASN_INTEGER, RONLY, read_ifMauEntry_stub, 1, {12} },
    { IFMAUTYPELISTBITS, ASN_OCTET_STR, RONLY, read_ifMauEntry_stub, 1, {13} },
};

#define IFJACKTYPE                       2

static oid ifJackEntry_base[] = {1, 3, 6, 1, 2, 1, 26, 2, 2, 1};

struct variable ifJackEntry_variables[] = {
    { IFJACKTYPE, ASN_INTEGER, RONLY, read_ifJackEntry_stub, 1, {2} },
};

#define BROADMAUIFINDEX                  1
#define BROADMAUINDEX                    2
#define BROADMAUXMTRCVSPLITTYPE          3
#define BROADMAUXMTCARRIERFREQ           4
#define BROADMAUTRANSLATIONFREQ          5

static oid broadMauBasicEntry_base[] = {1, 3, 6, 1, 2, 1, 26, 3, 1, 1};

struct variable broadMauBasicEntry_variables[] = {
    { BROADMAUIFINDEX, ASN_INTEGER, RONLY, read_broadMauBasicEntry_stub, 1, {1} },
    { BROADMAUINDEX, ASN_INTEGER, RONLY, read_broadMauBasicEntry_stub, 1, {2} },
    { BROADMAUXMTRCVSPLITTYPE, ASN_INTEGER, RONLY, read_broadMauBasicEntry_stub, 1, {3} },
    { BROADMAUXMTCARRIERFREQ, ASN_INTEGER, RONLY, read_broadMauBasicEntry_stub, 1, {4} },
    { BROADMAUTRANSLATIONFREQ, ASN_INTEGER, RONLY, read_broadMauBasicEntry_stub, 1, {5} },
};

#define IFMAUAUTONEGADMINSTATUS          1
#define IFMAUAUTONEGREMOTESIGNALING      2
#define IFMAUAUTONEGCONFIG               4
#define IFMAUAUTONEGCAPABILITY           5
#define IFMAUAUTONEGCAPADVERTISED        6
#define IFMAUAUTONEGCAPRECEIVED          7
#define IFMAUAUTONEGRESTART              8
#define IFMAUAUTONEGCAPABILITYBITS       9
#define IFMAUAUTONEGCAPADVERTISEDBITS    10
#define IFMAUAUTONEGCAPRECEIVEDBITS      11
#define IFMAUAUTONEGREMOTEFAULTADVERTISED 12
#define IFMAUAUTONEGREMOTEFAULTRECEIVED  13

static oid ifMauAutoNegEntry_base[] = {1, 3, 6, 1, 2, 1, 26, 5, 1, 1};

struct variable ifMauAutoNegEntry_variables[] = {
    { IFMAUAUTONEGADMINSTATUS, ASN_INTEGER, RWRITE, read_ifMauAutoNegEntry_stub, 1, {1} },
    { IFMAUAUTONEGREMOTESIGNALING, ASN_INTEGER, RONLY, read_ifMauAutoNegEntry_stub, 1, {2} },
    { IFMAUAUTONEGCONFIG, ASN_INTEGER, RONLY, read_ifMauAutoNegEntry_stub, 1, {4} },
    { IFMAUAUTONEGCAPABILITY, ASN_INTEGER, RONLY, read_ifMauAutoNegEntry_stub, 1, {5} },
    { IFMAUAUTONEGCAPADVERTISED, ASN_INTEGER, RWRITE, read_ifMauAutoNegEntry_stub, 1, {6} },
    { IFMAUAUTONEGCAPRECEIVED, ASN_INTEGER, RONLY, read_ifMauAutoNegEntry_stub, 1, {7} },
    { IFMAUAUTONEGRESTART, ASN_INTEGER, RWRITE, read_ifMauAutoNegEntry_stub, 1, {8} },
    { IFMAUAUTONEGCAPABILITYBITS, ASN_OCTET_STR, RONLY, read_ifMauAutoNegEntry_stub, 1, {9} },
    { IFMAUAUTONEGCAPADVERTISEDBITS, ASN_OCTET_STR, RWRITE, read_ifMauAutoNegEntry_stub, 1, {10} },
    { IFMAUAUTONEGCAPRECEIVEDBITS, ASN_OCTET_STR, RONLY, read_ifMauAutoNegEntry_stub, 1, {11} },
    { IFMAUAUTONEGREMOTEFAULTADVERTISED, ASN_INTEGER, RWRITE, read_ifMauAutoNegEntry_stub, 1, {12} },
    { IFMAUAUTONEGREMOTEFAULTRECEIVED, ASN_INTEGER, RONLY, read_ifMauAutoNegEntry_stub, 1, {13} },
};



/*
 * Registration functions for the various MIB groups.
 */

int register_rpMauEntry()
{
    return register_mib("rpMauEntry",
         rpMauEntry_variables,
         sizeof(struct variable),
         sizeof(rpMauEntry_variables)/sizeof(struct variable),
         rpMauEntry_base,
         sizeof(rpMauEntry_base)/sizeof(oid));
};


int register_rpJackEntry()
{
    return register_mib("rpJackEntry",
         rpJackEntry_variables,
         sizeof(struct variable),
         sizeof(rpJackEntry_variables)/sizeof(struct variable),
         rpJackEntry_base,
         sizeof(rpJackEntry_base)/sizeof(oid));
};


int register_ifMauEntry()
{
    return register_mib("ifMauEntry",
         ifMauEntry_variables,
         sizeof(struct variable),
         sizeof(ifMauEntry_variables)/sizeof(struct variable),
         ifMauEntry_base,
         sizeof(ifMauEntry_base)/sizeof(oid));
};


int register_ifJackEntry()
{
    return register_mib("ifJackEntry",
         ifJackEntry_variables,
         sizeof(struct variable),
         sizeof(ifJackEntry_variables)/sizeof(struct variable),
         ifJackEntry_base,
         sizeof(ifJackEntry_base)/sizeof(oid));
};


int register_broadMauBasicEntry()
{
    return register_mib("broadMauBasicEntry",
         broadMauBasicEntry_variables,
         sizeof(struct variable),
         sizeof(broadMauBasicEntry_variables)/sizeof(struct variable),
         broadMauBasicEntry_base,
         sizeof(broadMauBasicEntry_base)/sizeof(oid));
};


int register_ifMauAutoNegEntry()
{
    return register_mib("ifMauAutoNegEntry",
         ifMauAutoNegEntry_variables,
         sizeof(struct variable),
         sizeof(ifMauAutoNegEntry_variables)/sizeof(struct variable),
         ifMauAutoNegEntry_base,
         sizeof(ifMauAutoNegEntry_base)/sizeof(oid));
};


/*
 * Read methods for groups of scalars and tables:
 */

static unsigned char *
read_rpMauEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static rpMauEntry_t rpMauEntry;

    /* call the user supplied function to retrieve values */

    read_rpMauEntry(&rpMauEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case RPMAUGROUPINDEX:
        return (unsigned char *) &rpMauEntry.rpMauGroupIndex;

    case RPMAUPORTINDEX:
        return (unsigned char *) &rpMauEntry.rpMauPortIndex;

    case RPMAUINDEX:
        return (unsigned char *) &rpMauEntry.rpMauIndex;

    case RPMAUTYPE:
        *var_len = rpMauEntry._rpMauTypeLength;
        return (unsigned char *) rpMauEntry.rpMauType;

    case RPMAUSTATUS:
        return (unsigned char *) &rpMauEntry.rpMauStatus;

    case RPMAUMEDIAAVAILABLE:
        return (unsigned char *) &rpMauEntry.rpMauMediaAvailable;

    case RPMAUMEDIAAVAILABLESTATEEXITS:
        return (unsigned char *) &rpMauEntry.rpMauMediaAvailableStateExits;

    case RPMAUJABBERSTATE:
        return (unsigned char *) &rpMauEntry.rpMauJabberState;

    case RPMAUJABBERINGSTATEENTERS:
        return (unsigned char *) &rpMauEntry.rpMauJabberingStateEnters;

    case RPMAUFALSECARRIERS:
        return (unsigned char *) &rpMauEntry.rpMauFalseCarriers;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_rpJackEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static rpJackEntry_t rpJackEntry;

    /* call the user supplied function to retrieve values */

    read_rpJackEntry(&rpJackEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case RPJACKTYPE:
        return (unsigned char *) &rpJackEntry.rpJackType;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_ifMauEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static ifMauEntry_t ifMauEntry;

    /* call the user supplied function to retrieve values */

    read_ifMauEntry(&ifMauEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case IFMAUIFINDEX:
        return (unsigned char *) &ifMauEntry.ifMauIfIndex;

    case IFMAUINDEX:
        return (unsigned char *) &ifMauEntry.ifMauIndex;

    case IFMAUTYPE:
        *var_len = ifMauEntry._ifMauTypeLength;
        return (unsigned char *) ifMauEntry.ifMauType;

    case IFMAUSTATUS:
        return (unsigned char *) &ifMauEntry.ifMauStatus;

    case IFMAUMEDIAAVAILABLE:
        return (unsigned char *) &ifMauEntry.ifMauMediaAvailable;

    case IFMAUMEDIAAVAILABLESTATEEXITS:
        return (unsigned char *) &ifMauEntry.ifMauMediaAvailableStateExits;

    case IFMAUJABBERSTATE:
        return (unsigned char *) &ifMauEntry.ifMauJabberState;

    case IFMAUJABBERINGSTATEENTERS:
        return (unsigned char *) &ifMauEntry.ifMauJabberingStateEnters;

    case IFMAUFALSECARRIERS:
        return (unsigned char *) &ifMauEntry.ifMauFalseCarriers;

    case IFMAUTYPELIST:
        return (unsigned char *) &ifMauEntry.ifMauTypeList;

    case IFMAUDEFAULTTYPE:
        *var_len = ifMauEntry._ifMauDefaultTypeLength;
        return (unsigned char *) ifMauEntry.ifMauDefaultType;

    case IFMAUAUTONEGSUPPORTED:
        return (unsigned char *) &ifMauEntry.ifMauAutoNegSupported;

    case IFMAUTYPELISTBITS:
        *var_len = ifMauEntry._ifMauTypeListBitsLength;
        return (unsigned char *) ifMauEntry.ifMauTypeListBits;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_ifJackEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static ifJackEntry_t ifJackEntry;

    /* call the user supplied function to retrieve values */

    read_ifJackEntry(&ifJackEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case IFJACKTYPE:
        return (unsigned char *) &ifJackEntry.ifJackType;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_broadMauBasicEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static broadMauBasicEntry_t broadMauBasicEntry;

    /* call the user supplied function to retrieve values */

    read_broadMauBasicEntry(&broadMauBasicEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case BROADMAUIFINDEX:
        return (unsigned char *) &broadMauBasicEntry.broadMauIfIndex;

    case BROADMAUINDEX:
        return (unsigned char *) &broadMauBasicEntry.broadMauIndex;

    case BROADMAUXMTRCVSPLITTYPE:
        return (unsigned char *) &broadMauBasicEntry.broadMauXmtRcvSplitType;

    case BROADMAUXMTCARRIERFREQ:
        return (unsigned char *) &broadMauBasicEntry.broadMauXmtCarrierFreq;

    case BROADMAUTRANSLATIONFREQ:
        return (unsigned char *) &broadMauBasicEntry.broadMauTranslationFreq;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_ifMauAutoNegEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static ifMauAutoNegEntry_t ifMauAutoNegEntry;

    /* call the user supplied function to retrieve values */

    read_ifMauAutoNegEntry(&ifMauAutoNegEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case IFMAUAUTONEGADMINSTATUS:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegAdminStatus;

    case IFMAUAUTONEGREMOTESIGNALING:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegRemoteSignaling;

    case IFMAUAUTONEGCONFIG:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegConfig;

    case IFMAUAUTONEGCAPABILITY:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegCapability;

    case IFMAUAUTONEGCAPADVERTISED:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegCapAdvertised;

    case IFMAUAUTONEGCAPRECEIVED:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegCapReceived;

    case IFMAUAUTONEGRESTART:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegRestart;

    case IFMAUAUTONEGCAPABILITYBITS:
        *var_len = ifMauAutoNegEntry._ifMauAutoNegCapabilityBitsLength;
        return (unsigned char *) ifMauAutoNegEntry.ifMauAutoNegCapabilityBits;

    case IFMAUAUTONEGCAPADVERTISEDBITS:
        *var_len = ifMauAutoNegEntry._ifMauAutoNegCapAdvertisedBitsLength;
        return (unsigned char *) ifMauAutoNegEntry.ifMauAutoNegCapAdvertisedBits;

    case IFMAUAUTONEGCAPRECEIVEDBITS:
        *var_len = ifMauAutoNegEntry._ifMauAutoNegCapReceivedBitsLength;
        return (unsigned char *) ifMauAutoNegEntry.ifMauAutoNegCapReceivedBits;

    case IFMAUAUTONEGREMOTEFAULTADVERTISED:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegRemoteFaultAdvertised;

    case IFMAUAUTONEGREMOTEFAULTRECEIVED:
        return (unsigned char *) &ifMauAutoNegEntry.ifMauAutoNegRemoteFaultReceived;

    default:
         ERROR_MSG("");
    }

    return NULL;
}


/*
 * Forward declaration of write methods for writable objects:
 */

static int
write_rpMauStatus_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_ifMauStatus_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_ifMauDefaultType_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_ifMauAutoNegAdminStatus_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_ifMauAutoNegCapAdvertised_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_ifMauAutoNegRestart_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_ifMauAutoNegCapAdvertisedBits_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_ifMauAutoNegRemoteFaultAdvertised_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

