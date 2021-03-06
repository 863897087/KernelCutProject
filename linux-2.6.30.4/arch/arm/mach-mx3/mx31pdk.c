/*
 *  Copyright 2008 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <linux/types.h>
#include <linux/init.h>
#include <linux/clk.h>
#include <linux/irq.h>

#include <mach/hardware.h>
#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <asm/mach/time.h>
#include <asm/memory.h>
#include <asm/mach/map.h>
#include <mach/common.h>
#include <mach/board-mx31pdk.h>
#include <mach/imx-uart.h>
#include <mach/iomux-mx3.h>
#include "devices.h"

/*!
 * @file mx31pdk.c
 *
 * @brief This file contains the board-specific initialization routines.
 *
 * @ingroup System
 */

static struct imxuart_platform_data uart_pdata = {
	.flags = IMXUART_HAVE_RTSCTS,
};

static int uart_pins[] = {
	MX31_PIN_CTS1__CTS1,
	MX31_PIN_RTS1__RTS1,
	MX31_PIN_TXD1__TXD1,
	MX31_PIN_RXD1__RXD1
};

static inline void mxc_init_imx_uart(void)
{
	mxc_iomux_setup_multiple_pins(uart_pins, ARRAY_SIZE(uart_pins), "uart-0");
	mxc_register_device(&mxc_uart_device0, &uart_pdata);
}

/*!
 * Board specific initialization.
 */
static void __init mxc_board_init(void)
{
	mxc_init_imx_uart();
}

static void __init mx31pdk_timer_init(void)
{
	mx31_clocks_init(26000000);
}

static struct sys_timer mx31pdk_timer = {
	.init	= mx31pdk_timer_init,
};

/*
 * The following uses standard kernel macros defined in arch.h in order to
 * initialize __mach_desc_MX31PDK data structure.
 */
MACHINE_START(MX31_3DS, "Freescale MX31PDK (3DS)")
	/* Maintainer: Freescale Semiconductor, Inc. */
	.phys_io	= AIPS1_BASE_ADDR,
	.io_pg_offst	= ((AIPS1_BASE_ADDR_VIRT) >> 18) & 0xfffc,
	.boot_params    = PHYS_OFFSET + 0x100,
	.map_io         = mxc_map_io,
	.init_irq       = mxc_init_irq,
	.init_machine   = mxc_board_init,
	.timer          = &mx31pdk_timer,
MACHINE_END
