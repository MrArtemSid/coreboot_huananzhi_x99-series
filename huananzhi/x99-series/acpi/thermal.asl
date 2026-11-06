/* SPDX-License-Identifier: GPL-2.0-only */

Scope (\_TZ)
{
	ThermalZone (THRM)
	{
		Name (_TC1, 2)
		Name (_TC2, 3)

		/* Polling frequency: 2 seconds (in tenths of a second) */
		Name (_TZP, 20)

		/* Sampling period for passive cooling: 2 seconds */
		Name (_TSP, 20)

		/* Hardware Monitor ports on Nuvoton Super I/O (LPC Generic Decode 1: 0x0a00..0x0a3f) */
		OperationRegion (NCTH, SystemIO, 0x0a25, 2)
		Field (NCTH, ByteAcc, NoLock, Preserve)
		{
			HIDX, 8, /* 0x0a25: Index Register */
			HDAT, 8  /* 0x0a26: Data Register  */
		}

		/* Convert Celsius to tenths of Kelvin */
		Method (CTOK, 1, NotSerialized)
		{
			Local0 = Arg0 * 10
			Local0 += 2732
			Return (Local0)
		}

		/* Current CPU temperature in tenths of Kelvin */
		Method (_TMP, 0, Serialized)
		{
			/* Select Bank 0 (Bank Select Register at offset 0x4e) */
			HIDX = 0x4e
			HDAT = 0x00

			/* Read CPUTIN temperature sensor at register offset 0x27 */
			HIDX = 0x27
			Local0 = HDAT

			/* Validate sensor range: 5 C to 120 C */
			If ((Local0 >= 5) && (Local0 <= 120)) {
				Return (CTOK (Local0))
			}

			/* Fallback: 45 C (318.2 K) */
			Return (CTOK (45))
		}

		/* Critical trip point: 98 C (371.2 K) */
		Method (_CRT, 0, Serialized)
		{
			Return (CTOK (98))
		}

		/* Hot trip point: 92 C (365.2 K) */
		Method (_HOT, 0, Serialized)
		{
			Return (CTOK (92))
		}

		/* Passive cooling trip point: 85 C (358.2 K) */
		Method (_PSV, 0, Serialized)
		{
			Return (CTOK (85))
		}
	}
}
