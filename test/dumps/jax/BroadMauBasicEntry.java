/*
 * This Java file has been generated by smidump 0.4.2-pre1. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table row broadMauBasicEntry defined in MAU-MIB.

    @version 1
    @author  smidump 0.4.2-pre1
    @see     AgentXTable, AgentXEntry
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class BroadMauBasicEntry extends AgentXEntry
{

    protected int broadMauIfIndex = 0;
    protected int broadMauIndex = 0;
    protected int broadMauXmtRcvSplitType = 0;
    protected int broadMauXmtCarrierFreq = 0;
    protected int broadMauTranslationFreq = 0;

    public BroadMauBasicEntry(int broadMauIfIndex,
                              int broadMauIndex)
    {
        this.broadMauIfIndex = broadMauIfIndex;
        this.broadMauIndex = broadMauIndex;

        instance.append(broadMauIfIndex);
        instance.append(broadMauIndex);
    }

    public int get_broadMauIfIndex()
    {
        return broadMauIfIndex;
    }

    public int get_broadMauIndex()
    {
        return broadMauIndex;
    }

    public int get_broadMauXmtRcvSplitType()
    {
        return broadMauXmtRcvSplitType;
    }

    public int get_broadMauXmtCarrierFreq()
    {
        return broadMauXmtCarrierFreq;
    }

    public int get_broadMauTranslationFreq()
    {
        return broadMauTranslationFreq;
    }

}

