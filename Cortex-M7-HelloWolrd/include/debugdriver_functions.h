/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2011-2014  ARM Limited.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *      SVN Information
 *
 *      Checked In          : $Date: 2014-02-05 14:12:57 +0000 (Wed, 05 Feb 2014) $
 *
 *      Revision            : $Revision: 269405 $
 *
 *      Release Information : CORTEX-M7-r1p2-00rel0
 *-----------------------------------------------------------------------------
 */

////////////////////////////////////////////////////////////////////////////////
//
// Cortex M7 Integration Kit Debug Driver Functions header file
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Function enumeration to allow access to debugdriver functions
//

enum Function { FnCheckOK,
		FnDelay,
		FnSetModeJTAG,
		FnSetModeSW,
		FnCheckTAPID,
		FnCheckDPIDR,
		FnDAPPowerUp,
		FnDAPPowerDown,
		FnCheckAPIDR,
		FnCheckBASE,
		FnCheckCPUID,
		FnCheckROMTable,
		FnCheckNumBKPT,
		FnCheckNumWPT,
		FnCheckPID3,
		FnGetMemValue,
		FnConnectWakeUnhalt,
		FnQueryFirstCall,
		FnConnectCheckUnlockup,
		FnEnableHaltingDebug,
		FnConnectCheckHaltDbgrestart,
		FnDAPAccess,
		FnGetBASE,
		FnGetCID,
		FnGetPID,
                FnGetCSWProt,
                FnCheckDormantState,
                FnTrace,
		FnExtDebugCheck,
                FnCheckHALTEV,
                FnDAPtarget
              };
