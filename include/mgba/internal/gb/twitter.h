/* Copyright (c) 2013-2016 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef GB_TWITTER_H
#define GB_TWITTER_H

#include <mgba-util/common.h>

void fake_ram_init();
uint8_t read_fake_ram(uint16_t address);
void write_fake_ram(uint16_t address, uint8_t value);

#endif