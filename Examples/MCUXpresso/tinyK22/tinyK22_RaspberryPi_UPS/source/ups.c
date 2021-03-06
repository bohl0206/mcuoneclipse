/*
 * Copyright (c) 2019, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "platform.h"
#if PL_CONFIG_USE_UPS
#include <stdbool.h>
#include "McuGenericI2C.h"
#include "ups.h"

/* Maxim 17048 */
#define MAX17048_VREG     2  /* VCELL Register: voltage between Vdd und GND */
#define MAX17048_CREG     4 /* SOC Register: State of Charge */
#define MAX17048_I2C_ADDR 0x36

static bool isCharging = true;

void UPS_SetIsCharging(bool charging) {
  isCharging = charging;
}

bool UPS_IsCharging(void) {
  return isCharging;
}

int UPS_GetVoltage(float *voltage) {
  uint8_t res;
  uint16_t val;

  res = McuGenericI2C_ReadWordAddress8(MAX17048_I2C_ADDR, MAX17048_VREG, &val);
  if (res!=ERR_OK) {
    return -1; /* failed */
  }
  /* swap bytes */
  val = (val>>8)|(val<<8);
  *voltage = (((float)val)*78.125f)/1000000.0f;  /* 78.125uV/cell */
  return 0; /* ok */
}

int UPS_GetCharge(float *charge) {
  uint8_t res;
  uint16_t val;

  res = McuGenericI2C_ReadWordAddress8(MAX17048_I2C_ADDR, MAX17048_CREG, &val);
  if (res!=ERR_OK) {
    return -1; /* failed */
  }
  /* swap bytes */
  val = (val>>8)|(val<<8);
  *charge = ((float)val)/256.0f;  /* 1%/256 */
  return 0; /* ok */
}

void UPS_Deinit(void) {
  /* nothing to do */
}

void UPS_Init(void) {
  isCharging = true;
}

#endif /* PL_CONFIG_USE_UPS */
