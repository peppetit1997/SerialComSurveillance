/*
 * Author: Your Name
 * Date: September 15, 2023
 * Version: 1.0
License: GNU GPLV3
 /             \
((__-^^-,-^^-__))
 `-_---' `---_-'
  `--|o` 'o|--'
     \  `  /
      ): :(
      :o_o:
       "-"
 * Description:
 * This Arduino sketch monitors incoming serial data for the 'T' keypress, indicating communication.
 * It uses the functions defined in "functions.h" and "functions.cpp" to manage communication status.
 * If 'T' is received, the communication timestamp is updated. The checkComStatus function monitors the
 * communication status and triggers an alarm LED if communication is not established within a
 * specified time interval.
 *
 * Hardware:
 * - An LED is connected to pin 13 (alarmLed).
 *
 * License: This code is provided under the MIT License. See the LICENSE file for details.
 */

#include <Arduino.h>
#include "functions.h"

#define alarmLed 13 // The pin connected to the LED
unsigned long lastComTime = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(alarmLed, OUTPUT);
}

void loop()
{
  // Check for incoming serial data
  if (Serial.available() > 0)
  {
    char receivedChar = Serial.read(); // Read the incoming character
    // Check if the received character is 'T'
    if (receivedChar == 'T' || receivedChar == 't')
    {
      lastComTime = millis(); // Update the timestamp for communication
    }
  }
  checkComStatus(alarmLed, lastComTime); // Check communication status
}
