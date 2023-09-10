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
 * This file contains the implementation of functions for communication status checking and LED alarm control.
 *
 * These functions are designed to:
 * - `checkComStatus`: Check communication status within a specified time interval. It triggers an alarm if communication is not established.
 * - `setComAlarm`: Set up an alarm LED to blink at a specified interval to indicate a communication issue.
 *
 */

#include "functions.h"

/**
 * @brief Check communication status within a specified time interval.
 *
 * This function checks if it has been called at least once within the specified timer interval.
 *
 * @param pin The pin associated with the communication status check.
 * @param lastResetTime The time when the communication status was last reset.
 * @param timer The time interval in milliseconds within which the function should be called.
 */
void checkComStatus(const uint8_t pin, unsigned long lastResetTime, unsigned long timer)
{
    unsigned long currentMillis = millis();
    // Calculate the time elapsed since the last call
    unsigned long elapsedTime = currentMillis - lastResetTime;
    // Check if the elapsed time exceeds the specified timer
    if (elapsedTime >= timer)
    {
        // Communication is bad
        setComAlarm(pin);
    }
    else
    {
        digitalWrite(pin, LOW);
    }
}

/**
 * @brief Set up an alarm LED to blink at a specified interval.
 *
 * This function controls an LED connected to the specified pin, making it blink at the given interval.
 *
 * @param pin The pin connected to the alarm LED.
 * @param blinkInterval The time interval in milliseconds between LED state changes (blinking).
 */
void setComAlarm(const uint8_t pin, unsigned long blinkInterval)
{
    static unsigned long previousMillis = 0; // Static to preserve state between function calls
    unsigned long currentMillis = millis();  // Get the current time
    // Check if it's time to toggle the LED while handling rollover
    if (currentMillis - previousMillis >= blinkInterval)
    {
        // Save the last time the LED was updated
        previousMillis = currentMillis;

        // Toggle the LED state
        if (digitalRead(pin) == LOW)
        {
            digitalWrite(pin, HIGH); // Turn the LED on
        }
        else
        {
            digitalWrite(pin, LOW); // Turn the LED off
        }
    }
}
