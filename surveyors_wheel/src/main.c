#include <libopencm3/cm3/systick.h>
#include <libopencm3/lm4f/gpio.h>
#include <libopencm3/lm4f/systemcontrol.h>
#include "SURVEYORSWHEEL_PIO_util.h"

int main(void) { // use the 3.3v as vcc instead of the 5v.
	UARTsetup(9600); //uart setup from 251 labs
	GPIOF_setup();
	UARTstring("Surveyor's Wheel Initialized\n");
	encoder_setup();// method defined in util.c

	int count = 0; //counter for clicks of rotation; later this will be multiplied by the degree value and radius to get distance.

    while (1) { //this while loop has the main body of the counter, each time pin B on the encoder goes low (the sensor is turned clockwise) it increments.
        if ((gpio_port_read(GPIOB) & GPIO2) == 0) {
            count++;
            UARTprintf("Count: %d\n", count);
            gpio_set(GPIOF, LED_B);
            while ((gpio_port_read(GPIOB) & GPIO2) == 0); // wait for release
        }
        gpio_clear(GPIOF, LED_B);
        for (int i = 0; i < 100000; i++); //crude delay
    }
}