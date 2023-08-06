## SPDX-License-Identifier: GPL-2.0-only

bootblock-y += variants/$(VARIANT_DIR)/bootblock.c
bootblock-y += variants/$(VARIANT_DIR)/gpio.c
romstage-y += variants/$(VARIANT_DIR)/gpio.c
romstage-y += variants/$(VARIANT_DIR)/romstage.c
