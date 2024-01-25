/*
 * SBSA ACS Kernel module header file.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2016-2020, 2023-2024 Arm Limited
 *
 * Author: Prasanth Pulla <prasanth.pulla@arm.com>
 *
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

#include <linux/slab.h>

#define SBSA_CREATE_INFO_TABLES 0x1000
#define SBSA_PCIE_EXECUTE_TEST  0x2000
#define SBSA_UPDATE_SKIP_LIST   0x3000
#define SBSA_EXERCISER_EXECUTE_TEST  0x4000
#define SBSA_SMMU_EXECUTE_TEST  0x5000
#define SBSA_FREE_INFO_TABLES   0x9000

/* STATUS MESSAGES */
#define DRV_STATUS_AVAILABLE     0x10000000
#define DRV_STATUS_PENDING       0x40000000

/* Please MAKE SURE all table sizes are 16 bytes aligned */
#define PE_INFO_TBL_SZ             16384    /* Supports maximum 400 PEs [40 B each + 4 B header] */
#define IOVIRT_INFO_TBL_SZ         1048576  /* Supports maximum 2400 iort nodes [268+32*5 B each + 24 B header] */
#define PERIPHERAL_INFO_TBL_SZ     8192     /* Supports maximum 145 PCIe peripheral device (anykind) [56 B each + 16 B header] */
#define PCIE_INFO_TBL_SZ           512      /* Supports maximum 20 PCIe ECAM block [24 B each + 4 B header] */
#define DMA_INFO_TBL_SZ            1024     /* Supports maximum 30 DMA ctrl [32 B each + 4 B header] */

typedef
struct __TEST_PARAMS__
{
    unsigned int  api_num;
    unsigned int  num_pe;
    unsigned int  level;
    unsigned long arg0;
    unsigned long arg1;
    unsigned long arg2;
}test_params_t;

typedef struct __TEST_SBSA_MSG__ {
    char string[92];
    unsigned long data;
}test_msg_parms_t;
