/*
 * BSA SBSA ACS Platform module.
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
 * Copyright (C) 2016-2018, 2021, 2024, Arm Limited
 *
 * Author: Prasanth Pulla <prasanth.pulla@arm.com>
 *
 */

#ifndef __PAL_LINUX_H__
#define __PAL_LINUX_H__

#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/device.h>
#include<linux/kthread.h>
#include<linux/sched.h>
#include<linux/delay.h>

#include "val/include/pal_interface.h"



acpi_status user_function (acpi_handle handle, uint32_t level, void *context, void **return_value);

uint32_t pal_get_device_path(const char *hid, char hid_path[][MAX_NAMED_COMP_LENGTH]);

uint32_t pal_smmu_is_etr_behind_catu(char *etr_path);


#endif
