/*
 * This Java file has been generated by smidump 0.4.2-pre1. It
 * is intended to be edited by the application programmer and
 * to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class extends the Java AgentX (JAX) implementation of
    the table row historyControl2Entry defined in RMON2-MIB.
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class HistoryControl2EntryImpl extends HistoryControl2Entry
{

    // constructor
    public HistoryControl2EntryImpl()
    {
        super();
    }

    public long get_historyControlDroppedFrames()
    {
        return historyControlDroppedFrames;
    }

}

