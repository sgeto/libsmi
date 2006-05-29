/*
 * This Java file has been generated by smidump 0.4.5. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the scalar group probeConfig defined in RMON2-MIB.

    @version 1
    @author  smidump 0.4.5
    @see     AgentXGroup, AgentXScalars
 */

import java.util.Vector;
import java.util.Enumeration;
import jax.AgentXOID;
import jax.AgentXVarBind;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXScalars;

public class ProbeConfig extends AgentXScalars
{

    private final static long[] ProbeConfigOID = {1, 3, 6, 1, 2, 1, 16, 19};

    protected AgentXOID ProbeCapabilitiesOID;
    protected final static long[] ProbeCapabilitiesName = {1, 3, 6, 1, 2, 1, 16, 19, 1, 0};
    protected byte[] probeCapabilities = new byte[0];
    protected AgentXOID ProbeSoftwareRevOID;
    protected final static long[] ProbeSoftwareRevName = {1, 3, 6, 1, 2, 1, 16, 19, 2, 0};
    protected byte[] probeSoftwareRev = new byte[0];
    protected AgentXOID ProbeHardwareRevOID;
    protected final static long[] ProbeHardwareRevName = {1, 3, 6, 1, 2, 1, 16, 19, 3, 0};
    protected byte[] probeHardwareRev = new byte[0];
    protected AgentXOID ProbeDateTimeOID;
    protected final static long[] ProbeDateTimeName = {1, 3, 6, 1, 2, 1, 16, 19, 4, 0};
    protected byte[] probeDateTime = new byte[0];
    protected byte[] undo_probeDateTime = new byte[0];
    protected AgentXOID ProbeResetControlOID;
    protected final static long[] ProbeResetControlName = {1, 3, 6, 1, 2, 1, 16, 19, 5, 0};
    protected int probeResetControl = 0;
    protected int undo_probeResetControl = 0;
    protected AgentXOID ProbeDownloadFileOID;
    protected final static long[] ProbeDownloadFileName = {1, 3, 6, 1, 2, 1, 16, 19, 6, 0};
    protected byte[] probeDownloadFile = new byte[0];
    protected byte[] undo_probeDownloadFile = new byte[0];
    protected AgentXOID ProbeDownloadTFTPServerOID;
    protected final static long[] ProbeDownloadTFTPServerName = {1, 3, 6, 1, 2, 1, 16, 19, 7, 0};
    protected byte[] probeDownloadTFTPServer = new byte[4];
    protected byte[] undo_probeDownloadTFTPServer = new byte[4];
    protected AgentXOID ProbeDownloadActionOID;
    protected final static long[] ProbeDownloadActionName = {1, 3, 6, 1, 2, 1, 16, 19, 8, 0};
    protected int probeDownloadAction = 0;
    protected int undo_probeDownloadAction = 0;
    protected AgentXOID ProbeDownloadStatusOID;
    protected final static long[] ProbeDownloadStatusName = {1, 3, 6, 1, 2, 1, 16, 19, 9, 0};
    protected int probeDownloadStatus = 0;
    public ProbeConfig()
    {
        oid = new AgentXOID(ProbeConfigOID);
        data = new Vector();
        ProbeCapabilitiesOID = new AgentXOID(ProbeCapabilitiesName);
        data.addElement(ProbeCapabilitiesOID);
        ProbeSoftwareRevOID = new AgentXOID(ProbeSoftwareRevName);
        data.addElement(ProbeSoftwareRevOID);
        ProbeHardwareRevOID = new AgentXOID(ProbeHardwareRevName);
        data.addElement(ProbeHardwareRevOID);
        ProbeDateTimeOID = new AgentXOID(ProbeDateTimeName);
        data.addElement(ProbeDateTimeOID);
        ProbeResetControlOID = new AgentXOID(ProbeResetControlName);
        data.addElement(ProbeResetControlOID);
        ProbeDownloadFileOID = new AgentXOID(ProbeDownloadFileName);
        data.addElement(ProbeDownloadFileOID);
        ProbeDownloadTFTPServerOID = new AgentXOID(ProbeDownloadTFTPServerName);
        data.addElement(ProbeDownloadTFTPServerOID);
        ProbeDownloadActionOID = new AgentXOID(ProbeDownloadActionName);
        data.addElement(ProbeDownloadActionOID);
        ProbeDownloadStatusOID = new AgentXOID(ProbeDownloadStatusName);
        data.addElement(ProbeDownloadStatusOID);
    }

    public byte[] get_probeCapabilities()
    {
        return probeCapabilities;
    }

    public byte[] get_probeSoftwareRev()
    {
        return probeSoftwareRev;
    }

    public byte[] get_probeHardwareRev()
    {
        return probeHardwareRev;
    }

    public byte[] get_probeDateTime()
    {
        return probeDateTime;
    }

    public int set_probeDateTime(AgentXSetPhase phase, byte[] value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_probeDateTime = probeDateTime;
            probeDateTime = new byte[value.length];
            for(int i = 0; i < value.length; i++)
                probeDateTime[i] = value[i];
            break;
        case AgentXSetPhase.UNDO:
            probeDateTime = undo_probeDateTime;
            break;
        case AgentXSetPhase.CLEANUP:
            undo_probeDateTime = null;
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public int get_probeResetControl()
    {
        return probeResetControl;
    }

    public int set_probeResetControl(AgentXSetPhase phase, int value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_probeResetControl = probeResetControl;
            probeResetControl = value;
            break;
        case AgentXSetPhase.UNDO:
            probeResetControl = undo_probeResetControl;
            break;
        case AgentXSetPhase.CLEANUP:
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public byte[] get_probeDownloadFile()
    {
        return probeDownloadFile;
    }

    public int set_probeDownloadFile(AgentXSetPhase phase, byte[] value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_probeDownloadFile = probeDownloadFile;
            probeDownloadFile = new byte[value.length];
            for(int i = 0; i < value.length; i++)
                probeDownloadFile[i] = value[i];
            break;
        case AgentXSetPhase.UNDO:
            probeDownloadFile = undo_probeDownloadFile;
            break;
        case AgentXSetPhase.CLEANUP:
            undo_probeDownloadFile = null;
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public byte[] get_probeDownloadTFTPServer()
    {
        return probeDownloadTFTPServer;
    }

    public int set_probeDownloadTFTPServer(AgentXSetPhase phase, byte[] value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_probeDownloadTFTPServer = probeDownloadTFTPServer;
            probeDownloadTFTPServer = new byte[value.length];
            for(int i = 0; i < value.length; i++)
                probeDownloadTFTPServer[i] = value[i];
            break;
        case AgentXSetPhase.UNDO:
            probeDownloadTFTPServer = undo_probeDownloadTFTPServer;
            break;
        case AgentXSetPhase.CLEANUP:
            undo_probeDownloadTFTPServer = null;
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public int get_probeDownloadAction()
    {
        return probeDownloadAction;
    }

    public int set_probeDownloadAction(AgentXSetPhase phase, int value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_probeDownloadAction = probeDownloadAction;
            probeDownloadAction = value;
            break;
        case AgentXSetPhase.UNDO:
            probeDownloadAction = undo_probeDownloadAction;
            break;
        case AgentXSetPhase.CLEANUP:
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public int get_probeDownloadStatus()
    {
        return probeDownloadStatus;
    }

    public AgentXVarBind getScalar(AgentXOID pos, AgentXOID oid)
    {
        if ((pos == null) || (pos.compareTo(oid) != 0))
            return new AgentXVarBind(oid, AgentXVarBind.NOSUCHOBJECT);
        else {
            if (pos == ProbeCapabilitiesOID)
                return new AgentXVarBind(oid, AgentXVarBind.OCTETSTRING, 
                                         get_probeCapabilities());
            if (pos == ProbeSoftwareRevOID)
                return new AgentXVarBind(oid, AgentXVarBind.OCTETSTRING, 
                                         get_probeSoftwareRev());
            if (pos == ProbeHardwareRevOID)
                return new AgentXVarBind(oid, AgentXVarBind.OCTETSTRING, 
                                         get_probeHardwareRev());
            if (pos == ProbeDateTimeOID)
                return new AgentXVarBind(oid, AgentXVarBind.OCTETSTRING, 
                                         get_probeDateTime());
            if (pos == ProbeResetControlOID)
                return new AgentXVarBind(oid, AgentXVarBind.INTEGER, 
                                         get_probeResetControl());
            if (pos == ProbeDownloadFileOID)
                return new AgentXVarBind(oid, AgentXVarBind.OCTETSTRING, 
                                         get_probeDownloadFile());
            if (pos == ProbeDownloadTFTPServerOID)
                return new AgentXVarBind(oid, AgentXVarBind.IPADDRESS, 
                                         get_probeDownloadTFTPServer());
            if (pos == ProbeDownloadActionOID)
                return new AgentXVarBind(oid, AgentXVarBind.INTEGER, 
                                         get_probeDownloadAction());
            if (pos == ProbeDownloadStatusOID)
                return new AgentXVarBind(oid, AgentXVarBind.INTEGER, 
                                         get_probeDownloadStatus());
        }
        return new AgentXVarBind(oid, AgentXVarBind.NOSUCHOBJECT);
    }

    public int setScalar(AgentXSetPhase phase, AgentXOID pos,
                         AgentXVarBind inVb)
    {
        if ((pos == null) || (pos.compareTo(inVb.getOID()) != 0))
            return AgentXResponsePDU.INCONSISTENT_NAME;
        else {
            if (pos == ProbeDateTimeOID)
                return set_probeDateTime(phase, inVb.bytesValue());
            if (pos == ProbeResetControlOID)
                return set_probeResetControl(phase, inVb.intValue());
            if (pos == ProbeDownloadFileOID)
                return set_probeDownloadFile(phase, inVb.bytesValue());
            if (pos == ProbeDownloadTFTPServerOID)
                return set_probeDownloadTFTPServer(phase, inVb.bytesValue());
            if (pos == ProbeDownloadActionOID)
                return set_probeDownloadAction(phase, inVb.intValue());
        }
        return AgentXResponsePDU.NOT_WRITABLE;
    }

    public AgentXVarBind getNextScalar(AgentXOID pos, AgentXOID oid)
    {
        if ((pos == null) || (pos.compareTo(oid) <= 0))
            return new AgentXVarBind(oid, AgentXVarBind.ENDOFMIBVIEW);
        else {
            if (pos == ProbeCapabilitiesOID)
                return new AgentXVarBind(pos, AgentXVarBind.OCTETSTRING, 
                                         get_probeCapabilities());
            if (pos == ProbeSoftwareRevOID)
                return new AgentXVarBind(pos, AgentXVarBind.OCTETSTRING, 
                                         get_probeSoftwareRev());
            if (pos == ProbeHardwareRevOID)
                return new AgentXVarBind(pos, AgentXVarBind.OCTETSTRING, 
                                         get_probeHardwareRev());
            if (pos == ProbeDateTimeOID)
                return new AgentXVarBind(pos, AgentXVarBind.OCTETSTRING, 
                                         get_probeDateTime());
            if (pos == ProbeResetControlOID)
                return new AgentXVarBind(pos, AgentXVarBind.INTEGER, 
                                         get_probeResetControl());
            if (pos == ProbeDownloadFileOID)
                return new AgentXVarBind(pos, AgentXVarBind.OCTETSTRING, 
                                         get_probeDownloadFile());
            if (pos == ProbeDownloadTFTPServerOID)
                return new AgentXVarBind(pos, AgentXVarBind.IPADDRESS, 
                                         get_probeDownloadTFTPServer());
            if (pos == ProbeDownloadActionOID)
                return new AgentXVarBind(pos, AgentXVarBind.INTEGER, 
                                         get_probeDownloadAction());
            if (pos == ProbeDownloadStatusOID)
                return new AgentXVarBind(pos, AgentXVarBind.INTEGER, 
                                         get_probeDownloadStatus());
        }
        return new AgentXVarBind(pos, AgentXVarBind.ENDOFMIBVIEW);
    }

}

