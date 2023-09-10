/*
 * Author: Pierre-Étienne Petit
 * Date: September 10, 2023
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
 * This file contains the declaration of functions for communication status checking and LED alarm control.
 *
 * These functions are designed to:
 * - `checkComStatus`: Check communication status within a specified time interval. It triggers an alarm if communication is not established.
 * - `setComAlarm`: Set up an alarm LED to blink at a specified interval to indicate a communication issue.
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>

/**
 * @brief Check communication status within a specified time interval.
 *
 * This function checks if it has been called at least once within the specified timer interval.
 *
 * @param pin The pin associated with the communication status check.
 * @param lastResetTime The time when the communication status was last reset.
 * @param timer The time interval in milliseconds within which the function should be called.
 */
void checkComStatus(const uint8_t pin, unsigned long lastResetTime, unsigned long timer = 10000);

/**
 * @brief Set up an alarm LED to blink at a specified interval.
 *
 * This function controls an LED connected to the specified pin, making it blink at the given interval.
 *
 * @param pin The pin connected to the alarm LED.
 * @param blinkInterval The time interval in milliseconds between LED state changes (blinking).
 */
void setComAlarm(const uint8_t pin, unsigned long blinkInterval = 500);

#endif
