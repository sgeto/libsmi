/*
 * This Java file has been generated by smidump 0.2.7. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table row tokenRingPStats2Entry defined in RMON2-MIB.

    @version 1
    @author  smidump 0.2.7
    @see     AgentXTable, AgentXEntry
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class TokenRingPStats2Entry extends AgentXEntry
{

    protected long tokenRingPStatsDroppedFrames = 0;
    protected long tokenRingPStatsCreateTime = 0;

    public TokenRingPStats2Entry()
    {

    }

    public long get_tokenRingPStatsDroppedFrames()
    {
        return tokenRingPStatsDroppedFrames;
    }

    public long get_tokenRingPStatsCreateTime()
    {
        return tokenRingPStatsCreateTime;
    }

}

