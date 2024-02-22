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
 *      Checked In          : $Date: 2018-11-19 11:25:44 +0000 (Mon, 19 Nov 2018) $
 *
 *      Revision            : $Revision: 375803 $
 *
 *      Release Information : CORTEX-M7-r1p2-00rel0
 *-----------------------------------------------------------------------------
 */

////////////////////////////////////////////////////////////////////////////////
//
// Cortex M7 Integration Kit Configuration File
//
////////////////////////////////////////////////////////////////////////////////
//
//  Processor configuration options.
//  These must match the expected hardware configuration of the processor.
//
//  - EXPECTED_BE            : Expected Endianness (0-1)
//  - EXPECTED_DBGLVL        : Expected debug level (0-1)
//  - EXPECTED_MPU           : Expected MPU config (0,8,16)
//  - EXPECTED_IRQNUM        : Expected number of IRQ lines (0-240)
//  - EXPECTED_IRQLVL        : Expected number of IRQ levels (3-8)
//  - EXPECTED_SYST          : Expected SysTick extension (0-1)
//  - EXPECTED_WIC           : Expected Wake-up interrupt controller support <0-1>
//  - EXPECTED_WICLINES      : Expected number of supported WIC lines <2-243>
//  - EXPECTED_ICACHE        : Expected Icache config (0-1)
//  - EXPECTED_DCACHE        : Expected Dcache config (0-1)
//  - EXPECTED_CACHEECC      : Expected Cache ECC config (0-1)
//  - EXPECTED_ICACHE_SIZE   : Expected DCache size (4, 8, 16, 32, 64)
//  - EXPECTED_DCACHE_SIZE   : Expected DCache size (4, 8, 16, 32, 64)
//  - EXPECTED_FPU           : Expected Floating Point Unit (0-2)
//
//  Processor Tie-offs
//
//  - EXPECTED_ITCMSZ        : Expected Instruction Tightly Coupled Memory (0-15)
//  - EXPECTED_DTCMSZ        : Expected Data Tightly Coupled Memory (0-15)
//  - EXPECTED_STCALIB       : Expected value of STCALIB (0-0x3FFFFFF)
//  - EXPECTED_INITVTOR      : Expected initialisation vector
//  - EXPECTED_AHBPSZ        : Expected AHBP Address range (0, 1, 2, 3, 4)
//
////////////////////////////////////////////////////////////////////////////////
//
//  DAP configuration options.
//  These must match the expected hardware configuration of the DAP.
//
//  - EXPECTED_BASEADDR      : Expected BASEADDR at Cortex M7 DAP (0-0xFFFFFFFF)
//  - EXPECTED_HALTEV        : Expected Halt Event support (0-1)
//  - EXPECTED_JTAGnSW       : Expected Cortex M7 DAP Protocol (0,1)
//  - EXPECTED_SWMD          : Expected SW Multi-Drop config (0-1)
//
//  DAP Tie-offs
//
//  - EXPECTED_INSTANCEID    : Expected DAP instance number (0-0xF)
//  - EXPECTED_TREVISION     : Expected Revision number (0-0xF)
//  - EXPECTED_TPARTNO       : Expected Part number (0-0xFFFF)
//  - EXPECTED_TDESIGNER     : Expected Designer code (0-0x7FF)
//
////////////////////////////////////////////////////////////////////////////////
//
//  CoreSight Debug configuration options.
//
//  - EXPECTED_ETM           : Expected CoreSight ETM-M7 config (0,1)
//  - EXPECTED_TRC           : Expected CoreTrace Support (0,1)
//  - EXPECTED_CTI           : Expected Cross Trigger Interface Support (0,1)
//  - EXPECTED_CSI           : Expected CoreSight Integration Level (0-1)
//
////////////////////////////////////////////////////////////////////////////////
//
//  System ROM Table options.
//  These must match the values in the System ROM Table.
//
//  - EXPECTED_CUST_JEP_ID   : Expected JEDEC JEP-106 identity code (0-0x7F)
//  - EXPECTED_CUST_JEP_CONT : Expected JEDEC JEP-106 continuation code (0-0xF)
//  - EXPECTED_CUST_PART     : Expected Part number (0-0xFFF)
//  - EXPECTED_CUST_REV      : Expected Revision number (0-0xF)
//  - EXPECTED_CUST_REVAND   : Expected Manufacturer Revision number (0-0xF)
//
////////////////////////////////////////////////////////////////////////////////
//
//  Engineering Change Order and Revision Number Tie-off.
//
//  - EXPECTED_ECOREVNUM     : Expected Engineering Change Order and Revision number (0-0xFFFFF_FFFFFFFF)
//
////////////////////////////////////////////////////////////////////////////////

// RealView MDK GUI Support
// <<< Use Configuration Wizard in Context Menu >>>
// <h> Processor configuration options
// <o> EXPECTED_BIGEND: Expected Endianness <0=> Little Endian <1=> Big Endian
#define EXPECTED_BIGEND         0


// <o> EXPECTED_DBGLVL: Expected debug level <0=> 2 WPT and 4 BKPT <1=> 4 WPT and 8 BKPT
#define EXPECTED_DBGLVL         0

// <o> EXPECTED_MPU: Expected MPU config <0=> Absent <8=> Present (8 Regions)
#define EXPECTED_MPU         8

// <o> EXPECTED_IRQNUM: Expected number of IRQ lines <0-240>
#define EXPECTED_IRQNUM         32

// <o> EXPECTED_IRQLVL: Expected number of exception levels <3-8>
#define EXPECTED_IRQLVL         3

// <o> EXPECTED_SYST: Expected SysTick extension <0=> Absent <1=> Present
#define EXPECTED_SYST           1

// <o> EXPECTED_WIC: Expected Wake-up interrupt controller support <0-1>
#define EXPECTED_WIC         0

// <o> EXPECTED_WICLINES : Expected number of supported WIC lines <2-243>
#define EXPECTED_WICLINES       35

// <o> EXPECTED_ICACHE: Expected icache configuration  <0-1>
#define EXPECTED_ICACHE         1

// <o> EXPECTED_DCACHE: Expected dcache configuration  <0-1>
#define EXPECTED_DCACHE         1

// <o> EXPECTED_CACHEECC: Expected cache ECC configuration  <0-1>
#define EXPECTED_CACHEECC       1

// <o> EXPECTED_ICACHE_SIZE: Expected ICache size (4, 8, 16, 32, 64)
#define EXPECTED_ICACHE_SIZE    16

// <o> EXPECTED_DCACHE_SIZE: Expected DCache size (4, 8, 16, 32, 64)
#define EXPECTED_DCACHE_SIZE    16

// <o> EXPECTED_FPU: Expected Floating Point Unit (0, 1, 2)
#define EXPECTED_FPU         1

// </h>

// <h> Processor port Tie-offs
// <o> EXPECTED_ITCMSZ: Expected value of ITCMSZ <0-15>
#define EXPECTED_ITCMSZ         11

// <o> EXPECTED_DTCMSZ: Expected value of DTCMSZ <0-15>
#define EXPECTED_DTCMSZ         11

// <o> EXPECTED_INITRETRYEN:  Expected initial value for (D,I) TCM retry enable (0, 1, 2, 3)
#define EXPECTED_INITRETRYEN    0

// <o> EXPECTED_INITRMWEN:  Expected initial value for (D,I) TCM Read Modify Write enable (0, 1, 2, 3)
#define EXPECTED_INITRMWEN      0

// <o> EXPECTED_STCALIB: Expected value of STCALIB[25:0] at CM7MTBINTEGRATION <0x0-0x3FFFFFF>
#define EXPECTED_STCALIB        0x1051615

// <o> EXPECTED_INITVTOR:  Expected default initialisation vector
#define EXPECTED_INITVTOR       0

// <o> EXPECTED_AHBPSZ: Address range of the APBP bus (0, 1, 2, 3, 4)
#define EXPECTED_AHBPSZ         4

// </h>

// <h> DAP configuration options
// <o> EXPECTED_BASEADDR: Expected value of BASEADDR[31:0] at CM7 DAP <0x0-0xFFFFFFFF>
#define EXPECTED_BASEADDR       0xE00FD003


// <o> EXPECTED_HALTEV: Expected Halt Event support <0=> Absent <1=> Present
#define EXPECTED_HALTEV         0


// <o> EXPECTED_JTAGnSW: Expected Cortex M7 DAP Protocol <0=> Serial Wire <1=> JTAG
#define EXPECTED_JTAGnSW        0


// <o> EXPECTED_SWMD: Expected SW Multi-Drop config <0=> Absent <1=> Present (Serial Wire Protocol 2)
#define EXPECTED_SWMD           0

// </h>

// <h> DAP Tie-offs
// <o> EXPECTED_INSTANCEID: Expected DAP instance number (0-0xF)
#define EXPECTED_INSTANCEID     0x0


// <o> EXPECTED_TREVISION: Expected Revision number (0-0xF)
#define EXPECTED_TREVISION      0x0


// <o> EXPECTED_TPARTNO: Expected Part number (0-0xFFFF)
#define EXPECTED_TPARTNO        0x0000


// <o> EXPECTED_TDESIGNER: Expected Designer code (0-0x7FF)
#define EXPECTED_TDESIGNER      0x000

// </h>

// <h> CoreSight ETM-M7 configuration options
// <o> EXPECTED_ETM: Expected CoreSight ETM-M7 config <0=> No ETM <1=> Instruction-only ETM
#define EXPECTED_ETM         1
// </h>

// <h> TRC configuration options
// <o> EXPECTED_TRC: Expected Internal Trace support <0=> No ITM or DWT trace  <1=> ITM and DWT trace implemented
#define EXPECTED_TRC         1
// </h>

// <o> EXPECTED_CSI: Expected CoreSight Integration Level <0=> Absent <1=> Present
#define EXPECTED_CSI            1

// <o> EXPECTED_CTI: Expected Cross Trigger Interface <0=> Absent <1=> Present
#define EXPECTED_CTI            0

// <h> System ROM Table ID values
// <o> EXPECTED_CUST_JEPID: Expected JEDEC JEP-106 identity code (0-0x7F)
#define EXPECTED_CUST_JEPID     0x00


// <o> EXPECTED_CUST_JEPCONT: Expected JEDEC JEP-106 continuation code (0-0xF)
#define EXPECTED_CUST_JEPCONT   0x0


// <o> EXPECTED_CUST_PART: Expected Part number (0-0xFFF)
#define EXPECTED_CUST_PART      0x000


// <o> EXPECTED_CUST_REV: Expected Revision number (0-0xF)
#define EXPECTED_CUST_REV       0x0


// <o> EXPECTED_CUST_REVAND: Expected Manufacturer Revision number (0-0xF)
#define EXPECTED_CUST_REVAND    0x0

// </h>

// <h> EXPECTED_ECOREVNUM
// <o> EXPECTED_ECOREVNUM: Expected Engineering Change Order and Revision number (0-0xFFFFF_FFFFFFFF)
#define EXPECTED_ECOREVNUM      0x0000000000000LL

// </h>

// <<< end of configuration section >>>

////////////////////////////////////////////////////////////////////////////////
//
// Define whether the IK tests and the DebugDriver code should display messages
// using the chracter output device in the testbench.
//
#define CM7IKMCU_PRINTF
//#define DEBUGDRIVER_PRINTF
//#define DEBUGTRACE_PRINTF

// These values are used for TRACE ID when testing trace.
// Allows the formatter output to be associated with the generating source

#define CM7IKMCU_ETM_ID 0x22
#define CM7IKMCU_ITM_ID 0x59


////////////////////////////////////////////////////////////////////////////////
//
// ID values - DO NOT MODIFY
//
#define CORTEXM7_CPUID          (0x411fc272 ^ (EXPECTED_ECOREVNUM & 0x0000000FLL))

// CoreSight Component Identifier for Peripheral classes
#define CORESIGHT_CID0          0x0D
#define CORESIGHT_CID1_tbl      0x10
#define CORESIGHT_CID1_dbg      0x90
#define CORESIGHT_CID1_mem      0xE0
#define CORESIGHT_CID1_prm      0xF0
#define CORESIGHT_CID2          0x05
#define CORESIGHT_CID3          0xB1

// Component Part Numbers
#define ARM_JEP_ID              0x3B
#define ARM_JEP_CONT            0x4

#define CM7_CPU_PART            0x4C7
#define CM7_SCS_PART            0x00C
#define CM7_DWT_PART            0x002
#define CM7_FPB_PART            0x00E
#define CM7_ITM_PART            0x001
#define CM7_ETM_PART            0x975
#define CM7_CSI_PART            0x4C8
#define CM7_CTI_PART            0x906
#define CM7_TPIU_PART           0x9A9
#define CM7_ETB_PART            0x907
#define CM7_TR_PART             0x909
#define CM7_DAP_DP_PART         0xBD

// Revision Codes
#define CM7_ROM_REV             0x0
#define CM7_SCS_REV             0x0
#define CM7_DWT_REV             0x0
#define CM7_FPB_REV             0x0
#define CM7_ITM_REV             0x0
#define CM7_ETM_REV             0x1
#define CM7_DAP_DP_REV          (0x0 ^ ((EXPECTED_ECOREVNUM & 0x00F0000000000LL) >> 40))
#define CM7_DAP_AP_REV          (0x0 ^ ((EXPECTED_ECOREVNUM & 0x000F000000000LL) >> 36))

// Revand
#define CM7_SYSROM_ECO          ((EXPECTED_ECOREVNUM & 0xF000000000000LL) >> 48)
#define CM7_TPIU_ECO            ((EXPECTED_ECOREVNUM & 0x0F00000000000LL) >> 44)
#define CM7_ETM_ECO             ((EXPECTED_ECOREVNUM & 0x0000F00000000LL) >> 32)
#define CM7_CTI_ECO             ((EXPECTED_ECOREVNUM & 0x00000F0000000LL) >> 28)
#define CM7_CSI_ECO             ((EXPECTED_ECOREVNUM & 0x000000F000000LL) >> 24)
#define CM7_ITM_ECO             ((EXPECTED_ECOREVNUM & 0x0000000F00000LL) >> 20)
#define CM7_ROM_ECO             ((EXPECTED_ECOREVNUM & 0x00000000F0000LL) >> 16)
#define CM7_SCS_ECO             ((EXPECTED_ECOREVNUM & 0x000000000F000LL) >> 12)
#define CM7_DWT_ECO             ((EXPECTED_ECOREVNUM & 0x0000000000F00LL) >>  8)
#define CM7_FPB_ECO             ((EXPECTED_ECOREVNUM & 0x00000000000F0LL) >>  4)

// DAP Registers
#define CM7_DAP_JTAG_TAPID      (0x0BA02477 | (CM7_DAP_DP_REV << 28))
#define CM7_DAP_JTAG_DPIDR      (0x0BD11477 | (CM7_DAP_DP_REV << 28))
#define CM7_DAP_SW_DPIDR        (0x0BD11477 | (CM7_DAP_DP_REV << 28))
#define CM7_DAP_SWMD_DPIDR      (0x0BD12477 | (CM7_DAP_DP_REV << 28))
#define CM7_DAP_APIDR           (0x04770041 | (CM7_DAP_AP_REV << 28))

// CTI Registers
#define DEV_TYPE_VALUE          0x00000014

// ARM_START_INTERNAL
// Non Cortex-M7 values - used in romtable test
#define CS_CTI_PART             0x906
#define CM0_CPU_PART            0x471
#define CM0_CSI_PART            0x4C2
// ARM_END_INTERNAL
////////////////////////////////////////////////////////////////////////////////
//
// Defines used in IK - Do not modify
//

#define SYSROMTABLE_BASE        0xE00FD000
#define PILROMTABLE_BASE        0xE00FE000
#define CM7ROMTABLE_BASE        0xE00FF000

#define MEMTYPE_Offset          0xFCC
#define PID4_Offset             0xFD0
#define PID5_Offset             0xFD4
#define PID6_Offset             0xFD8
#define PID7_Offset             0xFDC
#define PID0_Offset             0xFE0
#define PID1_Offset             0xFE4
#define PID2_Offset             0xFE8
#define PID3_Offset             0xFEC
#define CID0_Offset             0xFF0
#define CID1_Offset             0xFF4
#define CID2_Offset             0xFF8
#define CID3_Offset             0xFFC

#define CORTEXM7_SCB_MVFR0_SP   0x10110021
#define CORTEXM7_SCB_MVFR1_SP   0x11000011
#define CORTEXM7_SCB_MVFR2      0x00000040
#define CORTEXM7_SCB_MVFR0_DP   0x10110221
#define CORTEXM7_SCB_MVFR1_DP   0x12000011

/*SCB */
#define SCB_CPACR_FPU           (0xF << 20)   /*!< cp10 and cp11 set in CPACR  */
////////////////////////////////////////////////////////////////////////////////
