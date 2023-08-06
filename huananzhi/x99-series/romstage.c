/* SPDX-License-Identifier: GPL-2.0-only */

#include <stdint.h>
#include <northbridge/intel/haswell/haswell.h>
#include <northbridge/intel/haswell/raminit.h>
#include <southbridge/intel/lynxpoint/pch.h>

void mainboard_config_rcba(void)
{
}

/* FIXME: called after romstage_common, remove it if not used */
void mb_late_romstage_setup(void)
{
}

void mb_get_spd_map(struct spd_info *spdi)
{
	/* FIXME: check this */
	spdi->addresses[0] = 0x50;
	spdi->addresses[1] = 0x51;
	spdi->addresses[2] = 0x52;
	spdi->addresses[3] = 0x53;
}
