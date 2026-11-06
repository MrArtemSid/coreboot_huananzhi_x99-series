/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/pnp_ops.h>
#include <southbridge/intel/lynxpoint/pch.h>
#include <superio/nuvoton/common/nuvoton.h>

void mainboard_config_superio(void)
{
	const pnp_devfn_t serial_dev = PNP_DEV(0x2e, 2);

	/*
	 * One generic call, exactly as QD4 does it: LDN 2 (UART A) at 0x3f8.
	 * Nothing is replayed from the stock image before this, so the vendor
	 * 55-record stream's other muxes (global CR2A/CR1A/CR1B/CR1C/CR1D/CR2C/
	 * CR2F, the KBC) are not written at this point; the KBC is configured in
	 * ramstage instead.  CONFIG_SUPERIO_NUVOTON_COMMON_COM_A is not selected
	 * for this board, so the helper does not touch CR2A either: CR2A keeps
	 * the chip default 0xc0, where bit 7 still routes COM A to the GPIO8 pin
	 * group.  The stock firmware leaves CR2A at 0x08 (bit 7 clear), so the
	 * console pins are NOT proven to match the vendor configuration and this
	 * path has never been observed on a BD4.  Do not describe the console as
	 * working until a hardware capture shows UART A output.
	 */
	nuvoton_enable_serial(serial_dev, CONFIG_TTYS0_BASE);
}
