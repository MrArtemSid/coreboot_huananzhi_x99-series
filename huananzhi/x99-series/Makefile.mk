## SPDX-License-Identifier: GPL-2.0-only

bootblock-y += bootblock.c
# The QD4 GPIO capture is that board's own data; no BD4 capture exists yet,
# so the BD4 variant must not inherit it.
ifeq ($(CONFIG_BOARD_HUANANZHI_X99_QD4),y)
bootblock-y += variants/qd4/gpio.c
romstage-y += variants/qd4/gpio.c
endif

ifeq ($(CONFIG_BOARD_HUANANZHI_X99_BD4),y)
bootblock-y += variants/bd4/gpio.c
romstage-y += variants/bd4/gpio.c
endif
