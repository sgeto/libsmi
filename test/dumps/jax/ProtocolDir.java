/*
 * This Java file has been generated by smidump 0.2.8. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the scalar group protocolDir defined in RMON2-MIB.

    @version 1
    @author  smidump 0.2.8
    @see     AgentXGroup, AgentXScalars
 */

import java.util.Vector;
import java.util.Enumeration;
import jax.AgentXOID;
import jax.AgentXVarBind;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXScalars;

public class ProtocolDir extends AgentXScalars
{

    private final static long[] ProtocolDirOID = {1, 3, 6, 1, 2, 1, 16, 11};

    protected AgentXOID ProtocolDirLastChangeOID;
    protected final static long[] ProtocolDirLastChangeName = {1, 3, 6, 1, 2, 1, 16, 11, 1, 0};
    protected long protocolDirLastChange = 0;
    public ProtocolDir()
    {
        oid = new AgentXOID(ProtocolDirOID);
        data = new Vector();
        ProtocolDirLastChangeOID = new AgentXOID(ProtocolDirLastChangeName);
        data.addElement(ProtocolDirLastChangeOID);
    }

    public long get_protocolDirLastChange()
    {
        return protocolDirLastChange;
    }

    public AgentXVarBind getScalar(AgentXOID pos, AgentXOID oid)
    {
        if ((pos == null) || (pos.compareTo(oid) != 0))
            return new AgentXVarBind(oid, AgentXVarBind.NOSUCHOBJECT);
        else {
            if (pos == ProtocolDirLastChangeOID)
                return new AgentXVarBind(oid, AgentXVarBind.TIMETICKS, 
                                         get_protocolDirLastChange());
        }
        return new AgentXVarBind(oid, AgentXVarBind.NOSUCHOBJECT);
    }

    public int setScalar(AgentXSetPhase phase, AgentXOID pos,
                         AgentXVarBind inVb)
    {
        if ((pos == null) || (pos.compareTo(inVb.getOID()) != 0))
            return AgentXResponsePDU.INCONSISTENT_NAME;
        else {
        }
        return AgentXResponsePDU.NOT_WRITABLE;
    }

    public AgentXVarBind getNextScalar(AgentXOID pos, AgentXOID oid)
    {
        if ((pos == null) || (pos.compareTo(oid) <= 0))
            return new AgentXVarBind(oid, AgentXVarBind.ENDOFMIBVIEW);
        else {
            if (pos == ProtocolDirLastChangeOID)
                return new AgentXVarBind(pos, AgentXVarBind.TIMETICKS, 
                                         get_protocolDirLastChange());
        }
        return new AgentXVarBind(pos, AgentXVarBind.ENDOFMIBVIEW);
    }

}
