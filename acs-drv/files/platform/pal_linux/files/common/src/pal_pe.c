/*
 * BSA ACS Platform module.
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
 * Copyright (C) 2016-2018, 2021, 2023 Arm Limited
 *
 * Author: Prasanth Pulla <prasanth.pulla@arm.com>
 *
 */

#include "common/include/pal_linux.h"
#include <linux/acpi.h>
#include <acpi/platform/aclinux.h>
#include <acpi/actypes.h>
#include <acpi/actbl.h>
#include <acpi/actbl1.h>
#include "bsa/include/bsa_pal_dt.h"

/**
  @brief  This API fills in the PE_INFO Table with information about the PEs in the
          system. This is achieved by parsing the ACPI - MADT table.

  @param  PeTable  - Address where the PE information needs to be filled.

  @return  None
**/
void
pal_pe_create_info_table(PE_INFO_TABLE *PeTable)
{
  unsigned int                       length=0, table_length=0;
  PE_INFO_ENTRY                      *ptr;
  struct acpi_table_madt             *madt;
  struct acpi_madt_generic_interrupt *entry;

  /* initialise number of PEs to zero */
  PeTable->header.num_of_pe = 0;

  madt = (struct acpi_table_madt *)pal_get_madt_ptr();

  if (madt) {
  
  table_length = madt->header.length;
  length = sizeof(struct acpi_table_madt);
  entry = (struct acpi_madt_generic_interrupt *) &madt[1];
  ptr = PeTable->pe_info;

  do {
      if (entry->header.type == ACPI_MADT_TYPE_GENERIC_INTERRUPT) {
          ptr->mpidr    = entry->arm_mpidr;
          ptr->pe_num   = PeTable->header.num_of_pe;
          ptr->pmu_gsiv = entry->performance_interrupt;
          pr_info("MPIDR %llx PE num %x \n", ptr->mpidr, ptr->pe_num);
          ptr++;
          PeTable->header.num_of_pe++;
      }
      length += entry->header.length;
      entry = (struct acpi_madt_generic_interrupt *) ((u8 *)entry + (entry->header.length));

  } while(length < table_length);
#ifndef BUILD_SBSA
  } else {
      // Get from DT
      //
      pal_pe_create_info_table_dt(PeTable);
      return;
#endif
 }
}


/**
  @brief  Install Exception Handler using UEFI CPU Architecture protocol's
          Register Interrupt Handler API

  @param  ExceptionType  - AARCH64 Exception type
  @param  esr            - Function pointer of the exception handler

  @return status of the API
**/
unsigned int
pal_pe_install_esr(unsigned int ExceptionType,  void (*esr)(unsigned long long, void *))
{

  return 0; /* IN SBSA it is 1 TODO */
}


void
pal_pe_data_cache_ops_by_va(unsigned long long addr, unsigned type)
{
}

/**
  @brief  Make the SMC call using AARCH64 Assembly code

  @param  Argumets to pass to the EL3 firmware

  @return  None
**/
void
pal_pe_call_smc(ARM_SMC_ARGS *ArmSmcArgs, int32_t conduit)
{
}


/**
  @brief  Make a PSCI CPU_ON call using SMC instruction.
          Pass PAL Assembly code entry as the start vector for the PSCI ON call

  @param  Argumets to pass to the EL3 firmware

  @return  None
**/
void
pal_pe_execute_payload(ARM_SMC_ARGS *ArmSmcArgs)
{

  int pe_id = ArmSmcArgs->Arg1;
  int (*vector)(void *data);
  uint64_t test_arg = 0;
  struct task_struct *task;

  vector = (void *)ArmSmcArgs->Arg2;
  test_arg = ArmSmcArgs->Arg3;

  printk(" thread cpu = %d %x \n", pe_id, *(uint32_t *)vector);

  task = kthread_create(vector,(void *)&test_arg,"one");
  kthread_bind(task, pe_id);
  wake_up_process(task);

  ArmSmcArgs->Arg0 = 0;
}

/**
  @brief  Place holder for Updating the Exception Link Register Value
**/
void
pal_pe_update_elr(void *context, unsigned long long offset)
{
}

/**
  @brief  Place holder to get the Fault Address Register Value
**/
unsigned long long
pal_pe_get_far(void *context)
{
  return 0;
}

/**
  @brief  Place holder to get the Exception Syndrome Register
**/
unsigned long long
pal_pe_get_esr(void *context)
{
  return 0;
}

int32_t
pal_psci_get_conduit (void)
{
  return 0;
}
