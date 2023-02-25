/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Register definitions taken from drivers/power/smb1360-charger-fg.c
 * Copyright (c) 2013-2015 The Linux Foundation. All rights reserved.
 */

#ifndef __LK2ND_SMB1360_I2C_H
#define __LK2ND_SMB1360_I2C_H
#include <bits.h>
#include "../regmap/regmap.h"

#define _SMB1360_MASK(BITS, POS) \
	((unsigned char)(((1 << (BITS)) - 1) << (POS)))
#define SMB1360_MASK(LEFT_BIT_POS, RIGHT_BIT_POS) \
		_SMB1360_MASK((LEFT_BIT_POS) - (RIGHT_BIT_POS) + 1, \
				(RIGHT_BIT_POS))

/* Charger Registers */
#define PRE_TO_FAST_REG			0x12
#define PRE_TO_FAST_MASK		SMB1360_MASK(7, 5)
#define PRE_TO_FAST_SHIFT		5

/* Command Registers */
#define CMD_I2C_REG			0x40
#define RELOAD_BIT			BIT(7)
#define ALLOW_VOLATILE_BIT		BIT(6)
#define FG_ACCESS_ENABLED_BIT		BIT(5)
#define FG_RESET_BIT			BIT(4)
#define CYCLE_STRETCH_CLEAR_BIT		BIT(3)

/* Status Registers */
#define STATUS_4_REG			0x4C
#define CYCLE_STRETCH_ACTIVE_BIT	BIT(5)

/* IRQ Status Registers */
#define IRQ_I_REG			0x58
#define IRQ_I_FG_ACCESS_ALLOWED_BIT	BIT(0)

struct smb1360 {
	const struct regmap *regmap;
	const struct regmap *fg_regmap;
};

status_t smb1360_enable_fg_access(const struct smb1360 *smb);
void smb1360_disable_fg_access(const struct smb1360 *smb);
status_t smb1360_check_cycle_stretch(const struct smb1360 *smb);
status_t smb1360_reload(const struct smb1360 *smb);
status_t smb1360_fg_reset(const struct smb1360 *smb);

#endif
