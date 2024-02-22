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
 *      Checked In          : $Date: 2014-10-01 15:00:37 +0100 (Wed, 01 Oct 2014) $
 *
 *      Revision            : $Revision: 291095 $
 *
 *      Release Information : CORTEX-M7-r1p2-00rel0
 *-----------------------------------------------------------------------------
 */

////////////////////////////////////////////////////////////////////////////////
//
// Cortex M7 Integration Kit generic header file
//
////////////////////////////////////////////////////////////////////////////////

#include "IKConfig.h"

#include "debugdriver_functions.h"

#define TEST_PASS 0
#define TEST_FAIL 1


////////////////////////////////////////////////////////////////////////////////
//
// CM7IKMCU External GPIO Pin Assignments
//
////////////////////////////////////////////////////////////////////////////////

//
// Debug Driver Hardware Interface to the IK
//
// Debug Driver --------------------------------------- CM7IKMCU
//
// GPIO[31] 7 >----------------------------------------> Running
// GPIO[30] 6 >----------------------------------------> Error
// GPIO[29] 5 <----------------------------------------< Function Strobe
// GPIO[28] 4 <----------------------------------------< }
// GPIO[27] 3 <----------------------------------------< }
// GPIO[26] 2 <----------------------------------------< > Function Select
// GPIO[25] 1 <----------------------------------------< }
// GPIO[24] 0 <----------------------------------------< }
//
//

#define IO_BYTE 3

#define IO_RUNNING (1 << 7)
#define IO_ERROR (1 << 6)
#define IO_STROBE (1 << 5)
#define IO_FUNCSEL (0x1f)


//
// Character device for printf and miscellaneous signals
//
//
// GPIO[15] 7 >----------------------------------------> Character Strobe
// GPIO[14] 6 >----------------------------------------> }
// GPIO[13] 5 >----------------------------------------> }
// GPIO[12] 4 >----------------------------------------> } Character
// GPIO[11] 3 >----------------------------------------> > Value
// GPIO[10] 2 >----------------------------------------> }
// GPIO[ 9] 1 >----------------------------------------> }
// GPIO[ 8] 0 >----------------------------------------> }
//
//


#define PRINT_BYTE 1

#define PRINT_STROBE (1 << 7)
#define PRINT_CHAR 0x7F



//
// Test Completion and Status
//
//
// GPIO[ 7] 7 >---------------------------------------->
// GPIO[ 6] 6 >---------------------------------------->
// GPIO[ 5] 5 >---------------------------------------->
// GPIO[ 4] 4 >---------------------------------------->
// GPIO[ 3] 3 >---------------------------------------->
// GPIO[ 2] 2 >---------------------------------------->
// GPIO[ 1] 1 >----------------------------------------> Test PASS
// GPIO[ 0] 0 >----------------------------------------> Test Complete


#define MISC_BYTE 0

#define MISC_PASS (1 << 1)
#define MISC_COMPLETE (1 << 0)


////////////////////////////////////////////////////////////////////////////////
//
// CM7IKMCU Internal GPIO Pin Assignments
//
////////////////////////////////////////////////////////////////////////////////

//
// GPIO1
//
// GPIO[31] 7 >----------> NMI
// GPIO[30] 6 >----------> gpio_loopout --> Delay -+
// GPIO[29] 5 <----------< gpio_loopin  <----------+
// GPIO[28] 4
// GPIO[27] 3
// GPIO[26] 2 >----------> DBGRESTART
// GPIO[25] 1 <----------< DBGRESTARTED
// GPIO[24] 0 >----------> EDBGRQ

#define INTDBG_BYTE 3

#define GPIO_NMI (1 << 7)
#define GPIO_LOOPOUT (1 << 6)
#define GPIO_LOOPIN  (1 << 5)
#define GPIO_DBGRESTART (1 << 2)
#define GPIO_DBGRESTARTED (1 << 1)
#define GPIO_EDBGRQ (1 << 0)


// GPIO[23] 7
// GPIO[22] 6
// GPIO[21] 5 <----------< HALTED
// GPIO[20] 4 <----------< LOCKUP
// GPIO[19] 3 <----------< SLEEPDEEP
// GPIO[18] 2 <----------< SLEEPING
// GPIO[17] 1
// GPIO[16] 0

#define POWER_BYTE 2

#define GPIO_HALTED (1 << 5)
#define GPIO_LOCKUP (1 << 4)
#define GPIO_SLEEPDEEP (1 << 3)
#define GPIO_SLEEPING (1 << 2)


// GPIO[15] 7 <----------< TXEV
// GPIO[14] 6 >----------> RXEV
// GPIO[13] 5 <----------< delayed_RXEV
// GPIO[12] 4
// GPIO[11] 3
// GPIO[10] 2
// GPIO[ 9] 1
// GPIO[ 8] 0

#define EVENT_BYTE 1

#define GPIO_TXEV (1 << 7)
#define GPIO_RXEV (1 << 6)
#define GPIO_delayed_RXEV (1 << 5)


// GPIO[7] 7 >----------> TSTART
// GPIO[6] 6 >----------> TSTOP
// GPIO[5] 5
// GPIO[4] 4
// GPIO[3] 3
// GPIO[2] 2 >----------> sys_iop_clr
// GPIO[1] 1 <----------< sys_iop_present
// GPIO[0] 0

#define MISC2_BYTE 0

#define GPIO_TSTART  (1 << 7)
#define GPIO_TSTOP   (1 << 6)
#define GPIO_iop_clr (1 << 2)
#define GPIO_IOP     (1 << 1)

//
// GPIO2
//
// GPIO[31:1] >----------> IRQ[31:1]


////////////////////////////////////////////////////////////////////////////////
//
// Print macro to allow conditional printing of messages
//
// Invoke like printf, but use double braces: MSG(("format %x", var));
//

#ifdef CM7IKMCU_PRINTF
#define MSG(arg) { printf arg ; }
#else
#define MSG(arg) { (void) 0; }
#endif


////////////////////////////////////////////////////////////////////////////////
//
// Common Global Variables
//
extern volatile uint32_t Errors;


////////////////////////////////////////////////////////////////////////////////
//
// Function Prototype for Initialisation for ALL Integration Kit tests
//

extern void IKInit(void);
extern void IKInit_dhry(void);


////////////////////////////////////////////////////////////////////////////////
//
// CM7IKMCU's view of the memory shared with the debugdriver
// (4 words above stack top)
// This macro uses the SP value from the vector table as stacktop
#define DEBUGDRIVERDATA ((volatile uint32_t *) *((uint32_t *) 0x0))


////////////////////////////////////////////////////////////////////////////////
//
// A convenient way to access the AHB Default Slave
#define AHBDEFAULTSLAVE ((volatile uint32_t *) ((uint32_t) 0x30100000))



////////////////////////////////////////////////////////////////////////////////
//
// Function Prototypes and enumeration to allow access to debugdriver functions
//

extern void     StartDebugDriver(uint32_t);
extern uint32_t CheckDebugDriver(void);
extern uint32_t CallDebugDriver(uint32_t);


////////////////////////////////////////////////////////////////////////////////
//
// Common Function Prototypes
//
extern uint32_t SwapEndian(uint32_t);
extern void     Check(char *, uint32_t, uint32_t);
extern void     CheckHex(char *, uint32_t, uint32_t);
extern void     CheckHexNoMsg(char *, uint32_t, uint32_t);
extern uint32_t ReadMemCore(uint32_t);
extern void     WriteMemCore(uint32_t, uint32_t);
extern void     SetSleepMode(uint32_t);

////////////////////////////////////////////////////////////////////////////////
//
// Trace Capture config
//

#define TRACE_CONFIG_NRZ (1<<5)
#define TRACE_CONFIG_MAN (1<<4)
#define TRACE_CONFIG_PORT4 8
#define TRACE_CONFIG_PORT2 2
#define TRACE_CONFIG_PORT1 1
