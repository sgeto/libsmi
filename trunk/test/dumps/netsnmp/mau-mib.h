/*
 * This C header file has been generated by smidump 0.4.2-pre1.
 * It is intended to be used with the NET-SNMP package.
 *
 * This header is derived from the MAU-MIB module.
 *
 * $Id$
 */

#ifndef _MAU_MIB_H_
#define _MAU_MIB_H_

#include <stdlib.h>

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

/*
 * C type definitions for MAU-MIB::rpMauEntry.
 */

typedef struct rpMauEntry {
    int32_t   *rpMauGroupIndex;
    int32_t   *rpMauPortIndex;
    int32_t   *rpMauIndex;
    uint32_t  *rpMauType;
    size_t    _rpMauTypeLength;
    int32_t   *rpMauStatus;
    int32_t   *rpMauMediaAvailable;
    uint32_t  *rpMauMediaAvailableStateExits;
    int32_t   *rpMauJabberState;
    uint32_t  *rpMauJabberingStateEnters;
    uint32_t  *rpMauFalseCarriers;
    void      *_clientData;		/* pointer to client data structure */
    struct rpMauEntry *_nextPtr;	/* pointer to next table entry */

    /* private space to hold actual values */

    int32_t   __rpMauGroupIndex;
    int32_t   __rpMauPortIndex;
    int32_t   __rpMauIndex;
    uint32_t  __rpMauType[128];
    int32_t   __rpMauStatus;
    int32_t   __rpMauMediaAvailable;
    uint32_t  __rpMauMediaAvailableStateExits;
    int32_t   __rpMauJabberState;
    uint32_t  __rpMauJabberingStateEnters;
    uint32_t  __rpMauFalseCarriers;
} rpMauEntry_t;

/*
 * C manager interface stubs for MAU-MIB::rpMauEntry.
 */

extern int
mau_mib_mgr_get_rpMauEntry(struct snmp_session *s, rpMauEntry_t **rpMauEntry);

/*
 * C agent interface stubs for MAU-MIB::rpMauEntry.
 */

extern int
mau_mib_agt_read_rpMauEntry(rpMauEntry_t *rpMauEntry);
extern int
mau_mib_agt_register_rpMauEntry();

/*
 * C type definitions for MAU-MIB::rpJackEntry.
 */

typedef struct rpJackEntry {
    int32_t   *rpJackIndex;
    int32_t   *rpJackType;
    void      *_clientData;		/* pointer to client data structure */
    struct rpJackEntry *_nextPtr;	/* pointer to next table entry */

    /* private space to hold actual values */

    int32_t   __rpJackIndex;
    int32_t   __rpJackType;
} rpJackEntry_t;

/*
 * C manager interface stubs for MAU-MIB::rpJackEntry.
 */

extern int
mau_mib_mgr_get_rpJackEntry(struct snmp_session *s, rpJackEntry_t **rpJackEntry);

/*
 * C agent interface stubs for MAU-MIB::rpJackEntry.
 */

extern int
mau_mib_agt_read_rpJackEntry(rpJackEntry_t *rpJackEntry);
extern int
mau_mib_agt_register_rpJackEntry();

/*
 * C type definitions for MAU-MIB::ifMauEntry.
 */

typedef struct ifMauEntry {
    int32_t   *ifMauIfIndex;
    int32_t   *ifMauIndex;
    uint32_t  *ifMauType;
    size_t    _ifMauTypeLength;
    int32_t   *ifMauStatus;
    int32_t   *ifMauMediaAvailable;
    uint32_t  *ifMauMediaAvailableStateExits;
    int32_t   *ifMauJabberState;
    uint32_t  *ifMauJabberingStateEnters;
    uint32_t  *ifMauFalseCarriers;
    int32_t   *ifMauTypeList;
    uint32_t  *ifMauDefaultType;
    size_t    _ifMauDefaultTypeLength;
    int32_t   *ifMauAutoNegSupported;
    u_char    *ifMauTypeListBits;
    size_t    _ifMauTypeListBitsLength;
    uint64_t  *ifMauHCFalseCarriers; 
    void      *_clientData;		/* pointer to client data structure */
    struct ifMauEntry *_nextPtr;	/* pointer to next table entry */

    /* private space to hold actual values */

    int32_t   __ifMauIfIndex;
    int32_t   __ifMauIndex;
    uint32_t  __ifMauType[128];
    int32_t   __ifMauStatus;
    int32_t   __ifMauMediaAvailable;
    uint32_t  __ifMauMediaAvailableStateExits;
    int32_t   __ifMauJabberState;
    uint32_t  __ifMauJabberingStateEnters;
    uint32_t  __ifMauFalseCarriers;
    int32_t   __ifMauTypeList;
    uint32_t  __ifMauDefaultType[128];
    int32_t   __ifMauAutoNegSupported;
    u_char    __ifMauTypeListBits[6];
    uint64_t  __ifMauHCFalseCarriers; 
} ifMauEntry_t;

/*
 * C manager interface stubs for MAU-MIB::ifMauEntry.
 */

extern int
mau_mib_mgr_get_ifMauEntry(struct snmp_session *s, ifMauEntry_t **ifMauEntry);

/*
 * C agent interface stubs for MAU-MIB::ifMauEntry.
 */

extern int
mau_mib_agt_read_ifMauEntry(ifMauEntry_t *ifMauEntry);
extern int
mau_mib_agt_register_ifMauEntry();

/*
 * C type definitions for MAU-MIB::ifJackEntry.
 */

typedef struct ifJackEntry {
    int32_t   *ifJackIndex;
    int32_t   *ifJackType;
    void      *_clientData;		/* pointer to client data structure */
    struct ifJackEntry *_nextPtr;	/* pointer to next table entry */

    /* private space to hold actual values */

    int32_t   __ifJackIndex;
    int32_t   __ifJackType;
} ifJackEntry_t;

/*
 * C manager interface stubs for MAU-MIB::ifJackEntry.
 */

extern int
mau_mib_mgr_get_ifJackEntry(struct snmp_session *s, ifJackEntry_t **ifJackEntry);

/*
 * C agent interface stubs for MAU-MIB::ifJackEntry.
 */

extern int
mau_mib_agt_read_ifJackEntry(ifJackEntry_t *ifJackEntry);
extern int
mau_mib_agt_register_ifJackEntry();

/*
 * C type definitions for MAU-MIB::broadMauBasicEntry.
 */

typedef struct broadMauBasicEntry {
    int32_t   *broadMauIfIndex;
    int32_t   *broadMauIndex;
    int32_t   *broadMauXmtRcvSplitType;
    int32_t   *broadMauXmtCarrierFreq;
    int32_t   *broadMauTranslationFreq;
    void      *_clientData;		/* pointer to client data structure */
    struct broadMauBasicEntry *_nextPtr;	/* pointer to next table entry */

    /* private space to hold actual values */

    int32_t   __broadMauIfIndex;
    int32_t   __broadMauIndex;
    int32_t   __broadMauXmtRcvSplitType;
    int32_t   __broadMauXmtCarrierFreq;
    int32_t   __broadMauTranslationFreq;
} broadMauBasicEntry_t;

/*
 * C manager interface stubs for MAU-MIB::broadMauBasicEntry.
 */

extern int
mau_mib_mgr_get_broadMauBasicEntry(struct snmp_session *s, broadMauBasicEntry_t **broadMauBasicEntry);

/*
 * C agent interface stubs for MAU-MIB::broadMauBasicEntry.
 */

extern int
mau_mib_agt_read_broadMauBasicEntry(broadMauBasicEntry_t *broadMauBasicEntry);
extern int
mau_mib_agt_register_broadMauBasicEntry();

/*
 * C type definitions for MAU-MIB::ifMauAutoNegEntry.
 */

typedef struct ifMauAutoNegEntry {
    int32_t   *ifMauAutoNegAdminStatus;
    int32_t   *ifMauAutoNegRemoteSignaling;
    int32_t   *ifMauAutoNegConfig;
    int32_t   *ifMauAutoNegCapability;
    int32_t   *ifMauAutoNegCapAdvertised;
    int32_t   *ifMauAutoNegCapReceived;
    int32_t   *ifMauAutoNegRestart;
    u_char    *ifMauAutoNegCapabilityBits;
    size_t    _ifMauAutoNegCapabilityBitsLength;
    u_char    *ifMauAutoNegCapAdvertisedBits;
    size_t    _ifMauAutoNegCapAdvertisedBitsLength;
    u_char    *ifMauAutoNegCapReceivedBits;
    size_t    _ifMauAutoNegCapReceivedBitsLength;
    int32_t   *ifMauAutoNegRemoteFaultAdvertised;
    int32_t   *ifMauAutoNegRemoteFaultReceived;
    void      *_clientData;		/* pointer to client data structure */
    struct ifMauAutoNegEntry *_nextPtr;	/* pointer to next table entry */

    /* private space to hold actual values */

    int32_t   __ifMauAutoNegAdminStatus;
    int32_t   __ifMauAutoNegRemoteSignaling;
    int32_t   __ifMauAutoNegConfig;
    int32_t   __ifMauAutoNegCapability;
    int32_t   __ifMauAutoNegCapAdvertised;
    int32_t   __ifMauAutoNegCapReceived;
    int32_t   __ifMauAutoNegRestart;
    u_char    __ifMauAutoNegCapabilityBits[2];
    u_char    __ifMauAutoNegCapAdvertisedBits[2];
    u_char    __ifMauAutoNegCapReceivedBits[2];
    int32_t   __ifMauAutoNegRemoteFaultAdvertised;
    int32_t   __ifMauAutoNegRemoteFaultReceived;
} ifMauAutoNegEntry_t;

/*
 * C manager interface stubs for MAU-MIB::ifMauAutoNegEntry.
 */

extern int
mau_mib_mgr_get_ifMauAutoNegEntry(struct snmp_session *s, ifMauAutoNegEntry_t **ifMauAutoNegEntry);

/*
 * C agent interface stubs for MAU-MIB::ifMauAutoNegEntry.
 */

extern int
mau_mib_agt_read_ifMauAutoNegEntry(ifMauAutoNegEntry_t *ifMauAutoNegEntry);
extern int
mau_mib_agt_register_ifMauAutoNegEntry();


typedef struct mau_mib {
    rpMauEntry_t	*rpMauEntry;
    rpJackEntry_t	*rpJackEntry;
    ifMauEntry_t	*ifMauEntry;
    ifJackEntry_t	*ifJackEntry;
    broadMauBasicEntry_t	*broadMauBasicEntry;
    ifMauAutoNegEntry_t	*ifMauAutoNegEntry;
} mau_mib_t;

/*
 * Initialization function:
 */

void mau_mib_agt_init(void);

#endif /* _MAU_MIB_H_ */
