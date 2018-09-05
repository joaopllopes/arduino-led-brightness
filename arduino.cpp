// -----------------------------------------------------------------------------
// Arduino Led Brightness Control
// 
// Copyright (c) 2017 Datapoint - Sistemas de Informação, Unipessoal, Lda.
// https://www.datapoint.pt/
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// -----------------------------------------------------------------------------
//
// DESCRIPTION
//
// In this example, we will be controlling the brightness of a LED connected
// to "PWM-" PIN 3 based on the value read from a Potentiometer connected to
// "ANALOG INPUT" PIN 0 on a Arduino framework.
//
// You can see how these components connect to each other by opening the
// "arduino.jpg" image included in this repository.
// ----------------------------------------------------------------------------- 

#define PIN_ANALOG_POTENTIOMETER 0
#define PIN_PWM_LED 3

#define COM_SERIAL_BAUD 9600

/**
 * Setup.
 */
void setup()
{
	// Set the data rate in bits per second (BAUD) for serial data transmission
	Serial.begin(COM_SERIAL_BAUD);
}

/**
 * Loop.
 */
void loop()
{
	// According to the official documentation, the voltage is returned by 
	// "analogRead" as an integer between 0 and 1023, where 0 is no voltage and
	// 1023 is the maximum voltage supported by the pin.
	int input = analogRead(PIN_ANALOG_POTENTIOMETER);

	// According to the official documentation, the voltage is set by 
	// "analogWrite" as an integer between 0 and 255, where 0 is no voltage and
	// 255 is the maximum voltage supported by the pin.
	int output = (((long) input * 255) / 1023);

	// Show some debug information through the serial interface so we can
	// be sure the output is calculated as expected.
	Serial.print(input);
	Serial.print(" --> ");
	Serial.print(output);
	Serial.print("\r\n");

	// Set the output voltage
	analogWrite(PIN_PWM_LED, output);

	// Since this is a short procedure and immediate response is not important,
	// we can delay the next loop entry for a while
	delay(250);
}
