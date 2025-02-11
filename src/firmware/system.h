/*
 * bbs-fw
 *
 * Copyright (C) Daniel Nilsson, 2022.
 *
 * Released under the GPL License, Version 3
 */

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "stc15.h"
#include "interrupt.h"
#include <stdint.h>

#define CPU_FREQ	20000000L

void system_init();

uint32_t system_ms();
void system_delay_ms(uint16_t ms);

#endif

