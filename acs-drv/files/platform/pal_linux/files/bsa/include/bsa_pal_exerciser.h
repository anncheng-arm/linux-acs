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
 * Copyright (C) 2016-2021, 2023-2024, Arm Limited
 *
 */

#ifndef __BSA_PAL_EXERCISER_H__
#define __BSA_PAL_EXERCISER_H__

#include <linux/kernel.h>

  
#define LEGACY_PCI_IRQ_CNT 4
#define MAX_IRQ_CNT        0xFFFF   // This value is arbitrary and may have to be adjusted

typedef struct {
  uint32_t  irq_list[MAX_IRQ_CNT];
  uint32_t  irq_count;
} PERIFERAL_IRQ_LIST;

typedef struct {
  PERIFERAL_IRQ_LIST  legacy_irq_map[LEGACY_PCI_IRQ_CNT];
} PERIPHERAL_IRQ_MAP;

uint32_t pal_exerciser_get_legacy_irq_map(uint32_t seg, uint32_t bus, uint32_t dev, uint32_t fn,
                                                                    PERIPHERAL_IRQ_MAP *irq_map);

#endif
