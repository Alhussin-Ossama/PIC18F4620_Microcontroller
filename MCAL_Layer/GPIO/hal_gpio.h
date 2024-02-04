/* 
 * File:   hal_gpio.h
 * Author: user
 *
 * Created on January 11, 2024, 3:56 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*--------------------- Section : Includes ---------------------*/
#include "pic18f4620.h"
#include "../mcal_std_type.h"
#include "../../MCAL_Layer/device_config.h"
/********************* Section : Macro Declarations *********************/
#define BIT_MASK                        (uint8)1

#define PORT_PIN_MAX_NUMBER              8
#define PORT_MAX_NUMBER                  5

#define PORTC_MASK                       0xFF

#define GPIO_PORT_PIN_CONFIGURATIONS     CONFIG_ENABLE
#define GPIO_PORT_CONFIGURATIONS         CONFIG_ENABLE
/********************* Section : Macro Functions Declarations *********************/
#define HWREG8(_x)                       (*((volatile uint8*)(_x)))

#define SET_BIT(REG, BIT_POSN)           (REG |= BIT_MASK << BIT_POSN)
#define CLEAR_BIT(REG, BIT_POSN)         (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)        (REG ^= BIT_MASK << BIT_POSN)
#define READ_BIT(REG,BIT_POSN)           ((REG >> BIT_POSN) & BIT_MASK )

/********************* Section : Data Type Declarations *********************/
typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH
}logic_t;

typedef enum
{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef enum
{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7

}pin_index_t;

typedef enum
{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
            
}port_index_t;

typedef struct
{
    uint8 port      :3;     //@ref port_index_t
    uint8 pin       :3;     //@ref pin_index_t
    uint8 direction :1;     //@ref direction_t
    uint8 logic     :1;     //@ref logic_t
}pin_config_t;

/********************* Section :  Function Declarations *********************/

/*
 * @brief Initialize the direction for the specific pin @ref direction_t
 * @param pin_config : pointer to configurations @ref pin_config_t
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_pin_direction_initialize        (const pin_config_t*);

/**
 * 
 * @param pin_config : pointer to configurations @ref pin_config_t 
 * @param direction
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_pin_get_direction_status        (const pin_config_t*, direction_t*);

/**
 * 
 * @param pin_config : pointer to configurations @ref pin_config_t
 * @param logic
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_pin_write_logic                 (const pin_config_t*, logic_t);

/**
 * 
 * @param pin_config : pointer to configurations @ref pin_config_t
 * @param logic
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_pin_read_logic                  (const pin_config_t*, logic_t*);

/**
 * 
 * @param pin_config : pointer to configurations @ref pin_config_t
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_pin_toggle_logic                (const pin_config_t*);

/**
 * @brief 
 * @param pin_config : pointer to configurations @ref pin_config_t
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_pin_initialize                  (const pin_config_t*);

/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_port_direction_initialize       (port_index_t, uint8);

/**
 * 
 * @param port
 * @param direction_status
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_port_get_direction_status       (port_index_t, uint8*);

/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_port_write_logic                (port_index_t, uint8);

/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_port_read_logic                 (port_index_t, uint8*);

/**
 * 
 * @param port
 * @return Status of the function
 *          ( E_OK : the function done successfully)
 *          ( E_NOT_OK : the function has issue to perform this action)
 */
Std_ReturnType gpio_port_toggle_logic               (port_index_t);

#endif	/* HAL_GPIO_H */

