/*
 * This Java file has been generated by smidump 0.4.5. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table row ringStationControl2Entry defined in RMON2-MIB.

    @version 1
    @author  smidump 0.4.5
    @see     AgentXTable, AgentXEntry
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class RingStationControl2Entry extends AgentXEntry
{

    protected long ringStationControlDroppedFrames = 0;
    protected long ringStationControlCreateTime = 0;

    public RingStationControl2Entry()
    {

    }

    public long get_ringStationControlDroppedFrames()
    {
        return ringStationControlDroppedFrames;
    }

    public long get_ringStationControlCreateTime()
    {
        return ringStationControlCreateTime;
    }

}

