/*
 * This Java file has been generated by smidump 0.4.2-pre1. It
 * is intended to be edited by the application programmer and
 * to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class extends the Java AgentX (JAX) implementation of
    the table row usrHistoryControlEntry defined in RMON2-MIB.
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class UsrHistoryControlEntryImpl extends UsrHistoryControlEntry
{

    // constructor
    public UsrHistoryControlEntryImpl(int usrHistoryControlIndex)
    {
        super(usrHistoryControlIndex);
    }

    public int get_usrHistoryControlObjects()
    {
        return usrHistoryControlObjects;
    }

    public int set_usrHistoryControlObjects(AgentXSetPhase phase, int value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_usrHistoryControlObjects = usrHistoryControlObjects;
            usrHistoryControlObjects = value;
            break;
        case AgentXSetPhase.UNDO:
            usrHistoryControlObjects = undo_usrHistoryControlObjects;
            break;
        case AgentXSetPhase.CLEANUP:
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public int get_usrHistoryControlBucketsRequested()
    {
        return usrHistoryControlBucketsRequested;
    }

    public int set_usrHistoryControlBucketsRequested(AgentXSetPhase phase, int value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_usrHistoryControlBucketsRequested = usrHistoryControlBucketsRequested;
            usrHistoryControlBucketsRequested = value;
            break;
        case AgentXSetPhase.UNDO:
            usrHistoryControlBucketsRequested = undo_usrHistoryControlBucketsRequested;
            break;
        case AgentXSetPhase.CLEANUP:
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public int get_usrHistoryControlBucketsGranted()
    {
        return usrHistoryControlBucketsGranted;
    }

    public int get_usrHistoryControlInterval()
    {
        return usrHistoryControlInterval;
    }

    public int set_usrHistoryControlInterval(AgentXSetPhase phase, int value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_usrHistoryControlInterval = usrHistoryControlInterval;
            usrHistoryControlInterval = value;
            break;
        case AgentXSetPhase.UNDO:
            usrHistoryControlInterval = undo_usrHistoryControlInterval;
            break;
        case AgentXSetPhase.CLEANUP:
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public byte[] get_usrHistoryControlOwner()
    {
        return usrHistoryControlOwner;
    }

    public int set_usrHistoryControlOwner(AgentXSetPhase phase, byte[] value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_usrHistoryControlOwner = usrHistoryControlOwner;
            usrHistoryControlOwner = new byte[value.length];
            for(int i = 0; i < value.length; i++)
                usrHistoryControlOwner[i] = value[i];
            break;
        case AgentXSetPhase.UNDO:
            usrHistoryControlOwner = undo_usrHistoryControlOwner;
            break;
        case AgentXSetPhase.CLEANUP:
            undo_usrHistoryControlOwner = null;
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public int get_usrHistoryControlStatus()
    {
        return usrHistoryControlStatus;
    }

    public int set_usrHistoryControlStatus(AgentXSetPhase phase, int value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_usrHistoryControlStatus = usrHistoryControlStatus;
            usrHistoryControlStatus = value;
            break;
        case AgentXSetPhase.UNDO:
            usrHistoryControlStatus = undo_usrHistoryControlStatus;
            break;
        case AgentXSetPhase.CLEANUP:
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
}

