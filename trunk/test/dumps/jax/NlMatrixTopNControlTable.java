/*
 * This Java file has been generated by smidump 0.2.17. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table nlMatrixTopNControlTable defined in RMON2-MIB.

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

public class NlMatrixTopNControlTable extends AgentXTable
{

    // entry OID
    private final static long[] OID = {1, 3, 6, 1, 2, 1, 16, 15, 4, 1};

    // constructors
    public NlMatrixTopNControlTable()
    {
        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(2));
        columns.addElement(new Long(3));
        columns.addElement(new Long(4));
        columns.addElement(new Long(5));
        columns.addElement(new Long(6));
        columns.addElement(new Long(7));
        columns.addElement(new Long(8));
        columns.addElement(new Long(9));
        columns.addElement(new Long(10));
        columns.addElement(new Long(11));
    }

    public NlMatrixTopNControlTable(boolean shared)
    {
        super(shared);

        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(2));
        columns.addElement(new Long(3));
        columns.addElement(new Long(4));
        columns.addElement(new Long(5));
        columns.addElement(new Long(6));
        columns.addElement(new Long(7));
        columns.addElement(new Long(8));
        columns.addElement(new Long(9));
        columns.addElement(new Long(10));
        columns.addElement(new Long(11));
    }

    public AgentXVarBind getVarBind(AgentXEntry entry, long column)
    {
        AgentXOID oid = new AgentXOID(getOID(), column, entry.getInstance());

        switch ((int)column) {
        case 2: // nlMatrixTopNControlMatrixIndex
        {
            int value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlMatrixIndex();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
        }
        case 3: // nlMatrixTopNControlRateBase
        {
            int value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlRateBase();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
        }
        case 4: // nlMatrixTopNControlTimeRemaining
        {
            int value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlTimeRemaining();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
        }
        case 5: // nlMatrixTopNControlGeneratedReports
        {
            long value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlGeneratedReports();
            return new AgentXVarBind(oid, AgentXVarBind.COUNTER32, value);
        }
        case 6: // nlMatrixTopNControlDuration
        {
            int value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlDuration();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
        }
        case 7: // nlMatrixTopNControlRequestedSize
        {
            int value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlRequestedSize();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
        }
        case 8: // nlMatrixTopNControlGrantedSize
        {
            int value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlGrantedSize();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
        }
        case 9: // nlMatrixTopNControlStartTime
        {
            long value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlStartTime();
            return new AgentXVarBind(oid, AgentXVarBind.TIMETICKS, value);
        }
        case 10: // nlMatrixTopNControlOwner
        {
            byte[] value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlOwner();
            return new AgentXVarBind(oid, AgentXVarBind.OCTETSTRING, value);
        }
        case 11: // nlMatrixTopNControlStatus
        {
            int value = ((NlMatrixTopNControlEntry)entry).get_nlMatrixTopNControlStatus();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
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
        case 2: // nlMatrixTopNControlMatrixIndex
        {
            if (vb.getType() != AgentXVarBind.INTEGER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((NlMatrixTopNControlEntry)entry).set_nlMatrixTopNControlMatrixIndex(phase, vb.intValue());
        }
        case 3: // nlMatrixTopNControlRateBase
        {
            if (vb.getType() != AgentXVarBind.INTEGER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((NlMatrixTopNControlEntry)entry).set_nlMatrixTopNControlRateBase(phase, vb.intValue());
        }
        case 4: // nlMatrixTopNControlTimeRemaining
        {
            if (vb.getType() != AgentXVarBind.INTEGER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((NlMatrixTopNControlEntry)entry).set_nlMatrixTopNControlTimeRemaining(phase, vb.intValue());
        }
        case 7: // nlMatrixTopNControlRequestedSize
        {
            if (vb.getType() != AgentXVarBind.INTEGER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((NlMatrixTopNControlEntry)entry).set_nlMatrixTopNControlRequestedSize(phase, vb.intValue());
        }
        case 10: // nlMatrixTopNControlOwner
        {
            if (vb.getType() != AgentXVarBind.OCTETSTRING)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((NlMatrixTopNControlEntry)entry).set_nlMatrixTopNControlOwner(phase, vb.bytesValue());
        }
        case 11: // nlMatrixTopNControlStatus
        {
            if (vb.getType() != AgentXVarBind.INTEGER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((NlMatrixTopNControlEntry)entry).set_nlMatrixTopNControlStatus(phase, vb.intValue());
        }
        }

        return AgentXResponsePDU.NOT_WRITABLE;
    }

}

