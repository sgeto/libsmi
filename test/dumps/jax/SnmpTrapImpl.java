/*
 * This Java file has been generated by smidump 0.4.5. It
 * is intended to be edited by the application programmer and
 * to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class extends the Java AgentX (JAX) implementation of
    the scalar group snmpTrap defined in SNMPv2-MIB.
 */

import java.util.Vector;
import java.util.Enumeration;
import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;

public class SnmpTrapImpl extends SnmpTrap
{

    public AgentXOID get_snmpTrapOID()
    {
        return snmpTrapOID;
    }

    public AgentXOID get_snmpTrapEnterprise()
    {
        return snmpTrapEnterprise;
    }

}

