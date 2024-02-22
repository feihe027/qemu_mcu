#ifndef _SYS_MEMMAP_H_
#define _SYS_MEMMAP_H_

// ROM Memory
#define SYS_MEM_CPUM_IROM_BASE      
#define SYS_MEM_CPUM_IROM_SIZE

// CPU Local ITCM Memory
#define SYS_MEM_FEP_ITCM_BASE       (0x0000000000) 
#define SYS_MEM_FEP_ITCM_SIZE       (0)
#define SYS_MEM_MEAP_ITCM_BASE      (0x0000000000) 
#define SYS_MEM_MEAP_ITCM_SIZE      (128 * 1024)                    
#define SYS_MEM_BEP0_ITCM_BASE      (0x0000000000)
#define SYS_MEM_BEP0_ITCM_SIZE      (192 * 1024) 
#define SYS_MEM_BEP1_ITCM_BASE      (0x0000000000) 
#define SYS_MEM_BEP1_ITCM_SIZE      (192 * 1024) 
#define SYS_MEM_BEP2_ITCM_BASE      (0x0000000000) 
#define SYS_MEM_BEP2_ITCM_SIZE      (192 * 1024) 
#define SYS_MEM_BEP3_ITCM_BASE      (0x0000000000) 
#define SYS_MEM_BEP3_ITCM_SIZE      (192 * 1024) 
#define SYS_MEM_MEP0_ITCM_BASE      (0x0000000000) 
#define SYS_MEM_MEP0_ITCM_SIZE      (192 * 1024)                 
#define SYS_MEM_MEP1_ITCM_BASE      (0x0000000000) 
#define SYS_MEM_MEP1_ITCM_SIZE      (192 * 1024)                   
#define SYS_MEM_MEP2_ITCM_BASE      (0x0000000000) 
#define SYS_MEM_MEP2_ITCM_SIZE      (192 * 1024) 
#define SYS_MEM_MEP3_ITCM_BASE      (0x0000000000) 
#define SYS_MEM_MEP3_ITCM_SIZE      (192 * 1024) 

// CPU Local DTCM Memory 
#define SYS_MEM_FEP_DTCM_BASE       (0x0020000000) 
#define SYS_MEM_FEP_DTCM_SIZE       (96 * 1024) 
#define SYS_MEM_MEAP_DTCM_BASE      (0x0020000000) 
#define SYS_MEM_MEAP_DTCM_SIZE      (128 * 1024)                     
#define SYS_MEM_BEP0_DTCM_BASE      (0x0020000000)
#define SYS_MEM_BEP0_DTCM_SIZE      (128 * 1024) 
#define SYS_MEM_BEP1_DTCM_BASE      (0x0020000000) 
#define SYS_MEM_BEP1_DTCM_SIZE      (128 * 1024) 
#define SYS_MEM_BEP2_DTCM_BASE      (0x0020000000) 
#define SYS_MEM_BEP2_DTCM_SIZE      (128 * 1024) 
#define SYS_MEM_BEP3_DTCM_BASE      (0x0020000000) 
#define SYS_MEM_BEP3_DTCM_SIZE      (128 * 1024) 
#define SYS_MEM_MEP0_DTCM_BASE      (0x0020000000) 
#define SYS_MEM_MEP0_DTCM_SIZE      (128 * 1024)                  
#define SYS_MEM_MEP1_DTCM_BASE      (0x0020000000) 
#define SYS_MEM_MEP1_DTCM_SIZE      (128 * 1024) 
#define SYS_MEM_MEP2_DTCM_BASE      (0x0020000000) 
#define SYS_MEM_MEP2_DTCM_SIZE      (128 * 1024) 
#define SYS_MEM_MEP3_DTCM_BASE      (0x0020000000) 
#define SYS_MEM_MEP3_DTCM_SIZE      (128 * 1024) 

// CPU Share Memory
#define SYS_MEM_SHARE_SRAM_BASE     (0x003F000000)
#define SYS_MEM_SHARE_SRAM_SIZE     (6400 * 1024) // 6.25M

// CPU Local Memory Global View
#define SYS_MEM_FEP_ITCM_GLOBAL_BASE       (0x00A0000000)
#define SYS_MEM_MEAP_ITCM_GLOBAL_BASE      (0x00A0040000)
#define SYS_MEM_BEP0_ITCM_GLOBAL_BASE      (0x00A0080000)
#define SYS_MEM_BEP1_ITCM_GLOBAL_BASE      (0x00A00C0000)
#define SYS_MEM_BEP2_ITCM_GLOBAL_BASE      (0x00A0100000)
#define SYS_MEM_BEP3_ITCM_GLOBAL_BASE      (0x00A0140000)

#define SYS_MEM_FEP_DTCM_GLOBAL_BASE       (0x00A1000000)
#define SYS_MEM_MEAP_DTCM_GLOBAL_BASE      (0x00A1040000)
#define SYS_MEM_BEP0_DTCM_GLOBAL_BASE      (0x00A1080000)
#define SYS_MEM_BEP1_DTCM_GLOBAL_BASE      (0x00A10C0000)
#define SYS_MEM_BEP2_DTCM_GLOBAL_BASE      (0x00A1100000)
#define SYS_MEM_BEP3_DTCM_GLOBAL_BASE      (0x00A1140000)

#define SYS_MEM_MEP0_ITCM_GLOBAL_BASE      (0x00B0000000)
#define SYS_MEM_MEP0_DTCM_GLOBAL_BASE      (0x00B0100000)
#define SYS_MEM_MEP1_ITCM_GLOBAL_BASE      (0x00B0200000)
#define SYS_MEM_MEP1_DTCM_GLOBAL_BASE      (0x00B0300000)
#define SYS_MEM_MEP2_ITCM_GLOBAL_BASE      (0x00B0400000)
#define SYS_MEM_MEP2_DTCM_GLOBAL_BASE      (0x00B0500000)
#define SYS_MEM_MEP3_ITCM_GLOBAL_BASE      (0x00B0600000)
#define SYS_MEM_MEP3_DTCM_GLOBAL_BASE      (0x00B0700000)

#define SYS_MEM_CPU_LOCAL_ITCM_BASE        (0x0000000000) 
#define SYS_MEM_CPU_LOCAL_DTCM_BASE        (0x0020000000) 
//#define SYS_MEM_CPU_GLOBAL_ITCM_BASE(id)   (0x00A0000000 + (id) * 0x40000) 
//#define SYS_MEM_CPU_GLOBAL_DTCM_BASE(id)   (0x00A1000000 + (id) * 0x40000) 

// Front-end Subsystem Address 
#define PCIE_CTRL_PHY_BASE       (0x0050000000)
#define PCIE_CTRL_PHY_SIZE       (1024 * 1024)

#define NVME_CTRL_BASE           (0x0050100000)
#define NVME_CTRL_SIZE           (256 * 1024)

#define MEC_IF_BASE              (0x0050140000)
#define MEC_IF_SIZE              (4 * 1024)

#define VDM_MI_BASE              (0x0050180000)
#define VDM_MI_SIZE              (4 * 1024)

#define PNSRAM_BASE              (0x00501C0000)
#define PNSRAM_SIZE              (32 * 1024)

// Middle-end Subsystem Address 
#define MEC_CDB_BASE             (0x00B1000000)
#define MEC_CDB_SIZE             (1024 * 1024)

#define MEC_CSR_REG_BASE         (0x0052000000)
#define MEC_CSR_REG_SIZE         (64 * 1024)

#define MEC_CMP_REG_BASE         (0x0052010000)
#define MEC_CMP_REG_SIZE         (64 * 1024)

#define MEC_DMP_REG_BASE         (0x0052020000)
#define MEC_DMP_REG_SIZE         (64 * 1024)

// Back-end Subsystem Address 
#define FEH_AXI_BASE             (0x0054000000)
#define FEH_AXI_SIZE             (256 * 1024)

#define FDUM_CMD_BUFF_BASE       (0x0054040000)
#define FDUM_CMD_BUFF_SIZE       (16 * 1024)

#define FDUM_SGL_MEM_BASE        (0x0054044000)
#define FDUM_SGL_MEM_SIZE        (16 * 1024)

#define NFC0_NFC_REG_BASE        (0x0054048000)
#define NFC0_NFC_REG_SIZE        (4 * 1024)

#define NFC0_NFC_SQ_BASE         (0x0054049000)
#define NFC0_NFC_SQ_SIZE         (32 * 1024)

#define NFC0_FPH_REG_BASE        (0x0054051000)
#define NFC0_FPH_REG_SIZE        (8 * 1024)

#define NFC0_FPHY_REG_BASE       (0x0054053000)
#define NFC0_FPHY_REG_SIZE       (4 * 1024)

#define NFC0_FPH_MEM_BASE        (0x0054054000)
#define NFC0_FPH_MEM_SIZE        (128 * 1024)

#define NFC1_NFC_REG_BASE        (0x0054074000)
#define NFC1_NFC_REG_SIZE        (4 * 1024)

#define NFC1_NFC_SQ_BASE         (0x0054075000)
#define NFC1_NFC_SQ_SIZE         (32 * 1024)

#define NFC1_FPH_REG_BASE        (0x005407D000)
#define NFC1_FPH_REG_SIZE        (8 * 1024)

#define NFC1_FPHY_REG_BASE       (0x005407F000)
#define NFC1_FPHY_REG_SIZE       (4 * 1024)

#define NFC1_FPH_MEM_BASE        (0x0054080000)
#define NFC1_FPH_MEM_SIZE        (128 * 1024)

// Peripheral Interface Address 
#define SYS_TIMER_REG_BASE       (0x00A8000000)
#define SYS_TIMER_REG_SIZE       (32 * 1024)

#define SYS_SMBUS0_REG_BASE      (0x00A8008000)
#define SYS_SMBUS0_REG_SIZE      (32 * 1024)

#define SYS_SMBUS1_REG_BASE      (0x00A8010000)
#define SYS_SMBUS1_REG_SIZE      (32 * 1024)

#define SYS_I2C_REG_BASE         (0x00A8018000)
#define SYS_I2C_REG_SIZE         (32 * 1024)

#define SYS_QSPI_REG_BASE        (0x00A8020000)
#define SYS_QSPI_REG_SIZE        (32 * 1024)

#define SYS_GPIO_REG_BASE        (0x00A8028000)
#define SYS_GPIO_REG_SIZE        (32 * 1024)

#define SYS_UART0_REG_BASE       (0x00A8030000)
#define SYS_UART0_REG_SIZE       (32 * 1024)

#define SYS_UART1_REG_BASE       (0x00A8038000)
#define SYS_UART1_REG_SIZE       (32 * 1024)

#define SYS_SENSOR_REG_BASE      (0x00A8040000)
#define SYS_SENSRO_REG_SIZE      (32 * 1024)

#define SYS_SMBUS0_SRAM_BASE     (0x00A8048000)
#define SYS_SMBUS0_SRAM_SIZE     (1 * 1024)

#define SYS_SMBUS1_SRAM_BASE     (0x00A8048400)
#define SYS_SMBUS1_SRAM_SIZE     (1 * 1024)

#define SYS_I2C_SRAM_BASE        (0x00A8048800)
#define SYS_I2C_SRAM_SIZE        (1 * 1024)

#define SYS_QSPI_SRAM_BASE       (0x00A8048C00)
#define SYS_QSPI_SRAM_SIZE       (1 * 1024)

#define SYS_UART0_SRAM_BASE      (0x00A8049000)
#define SYS_UART0_SRAM_SIZE      (1 * 1024)

#define SYS_UART1_SRAM_BASE      (0x00A8049400)
#define SYS_UART1_SRAM_SIZE      (1 * 1024)

// FFA Address 
#define FFA_CSR_BASE             (0x0058000000)
#define FFA_CSR_SIZE             (16 * 1024)

// DDR CTRL Address 
#define DDRSS_CRTL_BASE          (0x005A000000)
#define DDRSS_CRTL_SIZE          (16 * 1024 * 1024)

#define DDRSS_PHY_BASE           (0x005C000000)
#define DDRSS_PHY_SIZE           (32 * 1024 * 1024)

// TOP Level Address 
#define TOP_PMU_BASE             (0x0056000000)
#define TOP_PMU_SIZE             (512 * 1024)

#define TOP_MISC_BASE            (0x0056080000)
#define TOP_MISC_SIZE            (512 * 1024)

#define TOP_CRM_BASE             (0x0056100000)
#define TOP_CRM_SIZE             (512 * 1024)

// CPU System Ctrl Address 
#define CPU_SYS_CTRL_BASE        (0x00A2000000)
#define CPU_SYS_CTRL_SIZE        (32 * 1024 * 1024)

// MFR Ctrl Address 
#define MFR_CTRL_BASE            (0x005E000000)
#define MFR_CTRL_SIZE            (32 * 1024 * 1024)

// DDR 1G for M7 Address 
#define DDR_MEM_BANK_BASE        (0x60000000)
#define DDR_MEM_BANK_SIZE        (1024 * 1024 * 1024)

// Security Address 
#define SECURITY_BASE            (0x00D0000000)
#define SECURITY_SIZE            (256 * 1024 * 1024)

// DDR Memory for R82 Address 
#define DDR_MEMORY_BASE          (0x0160000000)
#define DDR_MEMORY_SIZE          (16 * 1024 * 1024 * 1024)

/// ------- DDR  ---------------------------------------
#define SYS_MEM_DDR_TOTAL_SIZE                  (0x180000000)           //6G
#define M7_DDR_TOTAL_SIZE                       (0x40000000)            //1G
#define SYS_MEM_DDR_BASE                        (DDR_MEMORY_BASE)

// FEP only DDR
#define SYS_MEM_DDR_FEP_ONLY_BASE               (SYS_MEM_DDR_BASE)
#define SYS_MEM_DDR_FEP_ONLY_SIZE               (0x1000000)             //16M

// BEPx only DDR
#define SYS_MEM_DDR_SDISK_BEP_SIZE              (0x1000000)             //16M PER SUBDISK
#define SYS_MEM_DDR_SDISK_BEP_BASE(Cpu_id)      (SYS_MEM_DDR_FEP_ONLY_BASE + SYS_MEM_DDR_FEP_ONLY_SIZE + SYS_MEM_DDR_SDISK_BEP_SIZE * (Cpu_id))

// M7 1G Remain DDR
#define SYS_MEM_DDR_M7_REMAIN_BASE              (SYS_MEM_DDR_SDISK_BEP_BASE(0) + SYS_MEM_DDR_SDISK_BEP_SIZE * 4)
#define SYS_MEM_DDR_M7_REMAIN_SIZE              (0x3B000000)            //944M

// MEPx(include hw use region) only DDR
#define SYS_MEM_DDR_SDISK_MEP_BASE              (SYS_MEM_DDR_BASE + M7_DDR_TOTAL_SIZE)


#endif //ndef _SYS_MEMMAP_H_
