/*
 *  format.ino - eMMC format sample application
 *  Copyright 2019 Sony Semiconductor Solutions Corporation
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
 * @file format.ino
 * @author Sony Semiconductor Solutions Corporation
 * @brief eMMC format sample application.
 */

#include <Arduino.h>
#include <eMMC.h>

// eMMCの電源をコントロールする端子
#define POWER_1V8_ENABLE  26     /* JP1 1: CTS(D27)  3: I2S_BCK(D26) */

/**
 * @brief Write to the file and read from the file.
 * 
 * @details The file is located on the eMMC.
 */
void setup() {

  /* Open serial communications and wait for port to open */
  Serial.begin(115200);
  while (!Serial) {
    ; /* wait for serial port to connect. Needed for native USB port only */
  }
  
  /* 1.8V Enable */
  Serial.println("1.8V Eanble");
  pinMode(POWER_1V8_ENABLE, OUTPUT);
  digitalWrite(POWER_1V8_ENABLE, HIGH);
  delay(5);                                /* delay 無しだとエラーとなる */

  /* Initialize eMMC */
  Serial.println("eMMC Initialize");
  eMMC.begin();

  /* FAT32 format eMMC*/
  Serial.println("eMMC FAT32 format");
  int ret = eMMC.format();

  if (ret) {
    Serial.println("Failure!!");
  } else {
    Serial.println("Success!!");
  }
}

/**
 * @brief Run repeatedly.
 * 
 * @details Does not do anything.
 */
void loop() {

}
