/*
 * This Java file has been generated by smidump 0.4.2-pre1. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table ringStationControl2Table defined in RMON2-MIB.

    @version 1
    @author  smidump 0.4.2-pre1
    @see     AgentXTable
 */

import java.util.Vector;

import jax.AgentXOID;
import jax.AgentXVarBind;
import jax.AgentXResponsePDU;
import jax.AgentXSetPhase;
import jax.AgentXTable;
import jax.AgentXEntry;

public class RingStationControl2Table extends AgentXTable
{

    // entry OID
    private final static long[] OID = {1, 3, 6, 1, 2, 1, 16, 10, 7, 1};

    // constructors
    public RingStationControl2Table()
    {
        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(1));
        columns.addElement(new Long(2));
    }

    public RingStationControl2Table(boolean shared)
    {
        super(shared);

        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(1));
        columns.addElement(new Long(2));
    }

    public AgentXVarBind getVarBind(AgentXEntry entry, long column)
    {
        AgentXOID oid = new AgentXOID(getOID(), column, entry.getInstance());

        switch ((int)column) {
        case 1: // ringStationControlDroppedFrames
        {
            long value = ((RingStationControl2Entry)entry).get_ringStationControlDroppedFrames();
            return new AgentXVarBind(oid, AgentXVarBind.COUNTER32, value);
        }
        case 2: // ringStationControlCreateTime
        {
            long value = ((RingStationControl2Entry)entry).get_ringStationControlCreateTime();
            return new AgentXVarBind(oid, AgentXVarBind.GAUGE32, value);
        }
        }

        return null;
    }

    public int setEntry(AgentXSetPhase phase,
                        AgentXEntry entry,
                        long column,
                        AgentXVarBind vb)
    {

        switch ((int)column) {
        }

        return AgentXResponsePDU.NOT_WRITABLE;
    }

}

