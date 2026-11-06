/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/azalia_device.h>

/*
 * HD-audio pin configuration for the Huananzhi X99-BD4, from a real board.
 *
 * Source: Huananzhi X99-BD4 V1.33, vendor AMI 5.11 dated 2022-09-06, captured
 * with the vendor firmware running -- upstream
 * MrArtemSid/coreboot_huananzhi_x99-series, branch staging1, commit
 * a27935715644b6d2ff8827438208065756d2895b (local copy under
 * evidence/bd4-hardware-logs/raw/logs/):
 *
 *   BD4/logs/lspci.log:2813  00:1b.0 [8086:8c20] Audio device, enabled
 *   BD4/logs/codec#2         Codec: Realtek ALC897, address 2,
 *                            Vendor Id 0x10ec0897, Subsystem Id 0x10ec0897,
 *                            Revision Id 0x100402
 *   BD4/logs/pin_hwC0D2      pin configuration for NID 0x11..0x1f
 *
 * The 14 pin values below are that dump verbatim.  BD4 is a stereo board: one
 * rear line-out (0x14), front headphone (0x1b), rear mic (0x18), front mic
 * (0x19), line-in (0x1a), and seven unconnected pins at 0x411111f0.  The
 * X99-QD4 table is a different board's data and differs on 12 of these 14 pins
 * (only 0x12 and 0x1c agree); it must not be copied here.
 *
 * Scope: the dump is the codec state after the vendor firmware programmed it,
 * so it proves the end state this table reproduces, not the ALC897 hardware
 * defaults and not which verbs the vendor issued.  Only pin configuration and
 * the codec's own subsystem id are encoded -- no amplifier, coefficient or
 * processing verb is added, because nothing in the capture justifies one.  A
 * pre/post-reset hda-verb dump on the same board is what would extend this.
 *
 * Paired with `device pci 1b.0 on` in variants/bd4/overridetree.cb, which the
 * lspci line above supports.
 */

const u32 cim_verb_data[] = {
	0x10ec0897,	/* Codec Vendor / Device ID: Realtek ALC897 */
	0x10ec0897,	/* Subsystem ID */
	15,		/* Number of 4 dword sets */
	AZALIA_SUBVENDOR(0, 0x10ec0897),
	AZALIA_PIN_CFG(0, 0x11, 0x40000000),
	AZALIA_PIN_CFG(0, 0x12, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x14, 0x01014410),
	AZALIA_PIN_CFG(0, 0x15, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x16, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x17, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x18, 0x01a19c40),
	AZALIA_PIN_CFG(0, 0x19, 0x02a19c50),
	AZALIA_PIN_CFG(0, 0x1a, 0x0181344f),
	AZALIA_PIN_CFG(0, 0x1b, 0x02214420),
	AZALIA_PIN_CFG(0, 0x1c, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1d, 0x4024c601),
	AZALIA_PIN_CFG(0, 0x1e, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1f, 0x411111f0),
};

const u32 pc_beep_verbs[0] = {};

AZALIA_ARRAY_SIZES;
