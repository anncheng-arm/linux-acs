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
 * Copyright (C) 2016-2019, 2021, 2023, 2024, Arm Limited
 *
 * Author: Sakar Arora<sakar.arora@arm.com>
 *
 */

#include <linux/acpi_iort.h>
#include <linux/kernel.h>
#include <linux/pci.h>
#include <linux/version.h>

#include "common/include/pal_linux.h"
#include "sbsa/include/sbsa_pal_linux.h"

#define NOT_IMPLEMENTED    0x4B1D

/**
  @brief  This function is called by the val function pal_get_device_path
          when the hid type is found

  @param  handle       device handle
  @param  level        nesting level
  @param  context      data to be passed from caller function
  @param  return_value return value passed to caller function pal_get_device_path

  @return 1 if test fails, 0 if test passes
**/
acpi_status user_function(acpi_handle handle, uint32_t level,
                   void *context, void **return_value)
{
  acpi_status status;
  static uint32_t count;
  struct acpi_buffer buffer;
  char (*path_buffer)[MAX_NAMED_COMP_LENGTH] = context;

  buffer.length = ACPI_ALLOCATE_BUFFER;
  status = acpi_get_name(handle, ACPI_FULL_PATHNAME, &buffer);
  strncpy((char *)path_buffer[count++], (char *)(buffer.pointer), 16);
  return status;
}

/**
  @brief  Check the hid in ACPI and copy te full path of hid

  @param  hid      hardware ID to get the path for
  @param  hid_path 2D array in which the path is copied

  @return 1 if test fails, 0 if test passes
**/
uint32_t
pal_get_device_path(const char *hid, char hid_path[][MAX_NAMED_COMP_LENGTH])
{
    acpi_status status;
    status = acpi_get_devices(hid, user_function, (void *)hid_path, NULL);
    return status;
}

/**
  @brief  Platform defined method to check if CATU is behind an ETR device

  @param  etr_path  full path of ETR device

  @return 0 - Success, NOT_IMPLEMENTED - API not implemented, Other values - Failure
**/
uint32_t
pal_smmu_is_etr_behind_catu(char *etr_path)
{
    return NOT_IMPLEMENTED;
}
