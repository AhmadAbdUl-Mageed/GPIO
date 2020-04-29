#include "GPIO/_GPIO.h"

void _GPIO_ENABLE_CLK(uint32_t GPIO_PORT){
    if(GPIO_PORT == GPIO_PORT_A){
        set_bit_Add((RCC_BASE + RCC_APB2ENR), 2);
    }
    else if(GPIO_PORT == GPIO_PORT_B){
        set_bit_Add((RCC_BASE + RCC_APB2ENR), 3);
    }
    else if(GPIO_PORT == GPIO_PORT_C){
        set_bit_Add((RCC_BASE + RCC_APB2ENR), 4);
    }
}
void _GPIO_DISABLE_CLK(uint32_t GPIO_PORT);
void _GPIO_SET_MODE(uint32_t GPIO_PORT, uint8_t GPIO_PIN, uint8_t SETUP, uint8_t MODE){
	if(GPIO_PIN > 7){
		GPIO_PIN -= 8;
		GPIO_PORT += 0x04;
	}
	*((uint32_t*)GPIO_PORT) &= ~((0b1111) << (GPIO_PIN * 4));
    *((uint32_t*)GPIO_PORT) |=  (((MODE << 2) + SETUP) << (GPIO_PIN * 4));
}
void _GPIO_WRITE_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN, uint8_t STATE){
	GPIO_PORT += 0x0C;
    if(STATE == HIGH){
        *((uint32_t*)GPIO_PORT) &= ~(1 << GPIO_PIN);
    }
    else{
        *((uint32_t*)GPIO_PORT) |=  (1 << GPIO_PIN);
    }
}
uint8_t _GPIO_READ_PIN(uint32_t GPIO_PORT, uint8_t GPIO_PIN);
