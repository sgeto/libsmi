/*
 * This Java file has been generated by smidump 0.4.5. It
 * is intended to be edited by the application programmer and
 * to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class extends the Java AgentX (JAX) implementation of
    the table row alMatrixDSEntry defined in RMON2-MIB.
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class AlMatrixDSEntryImpl extends AlMatrixDSEntry
{

    // constructor
    public AlMatrixDSEntryImpl(int hlMatrixControlIndex,
                           long alMatrixDSTimeMark,
                           int protocolDirLocalIndex,
                           byte[] nlMatrixDSDestAddress,
                           byte[] nlMatrixDSSourceAddress,
                           int protocolDirLocalIndex)
    {
        super(hlMatrixControlIndex,
                 alMatrixDSTimeMark,
                 protocolDirLocalIndex,
                 nlMatrixDSDestAddress,
                 nlMatrixDSSourceAddress,
                 protocolDirLocalIndex);
    }

    public long get_alMatrixDSPkts()
    {
        return alMatrixDSPkts;
    }

    public long get_alMatrixDSOctets()
    {
        return alMatrixDSOctets;
    }

    public long get_alMatrixDSCreateTime()
    {
        return alMatrixDSCreateTime;
    }

}

