/*
 * This Java file has been generated by smidump 0.2.17. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table addressMapTable defined in RMON2-MIB.

    @version 1
    @author  smidump 0.2.17
    @see     AgentXTable
 */

import java.util.Vector;

import jax.AgentXOID;
import jax.AgentXVarBind;
import jax.AgentXResponsePDU;
import jax.AgentXSetPhase;
import jax.AgentXTable;
import jax.AgentXEntry;

public class AddressMapTable extends AgentXTable
{

    // entry OID
    private final static long[] OID = {1, 3, 6, 1, 2, 1, 16, 13, 5, 1};

    // constructors
    public AddressMapTable()
    {
        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(4));
        columns.addElement(new Long(5));
    }

    public AddressMapTable(boolean shared)
    {
        super(shared);

        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(4));
        columns.addElement(new Long(5));
    }

    public AgentXVarBind getVarBind(AgentXEntry entry, long column)
    {
        AgentXOID oid = new AgentXOID(getOID(), column, entry.getInstance());

        switch ((int)column) {
        case 4: // addressMapPhysicalAddress
        {
            byte[] value = ((AddressMapEntry)entry).get_addressMapPhysicalAddress();
            return new AgentXVarBind(oid, AgentXVarBind.OCTETSTRING, value);
        }
        case 5: // addressMapLastChange
        {
            long value = ((AddressMapEntry)entry).get_addressMapLastChange();
            return new AgentXVarBind(oid, AgentXVarBind.TIMETICKS, value);
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

