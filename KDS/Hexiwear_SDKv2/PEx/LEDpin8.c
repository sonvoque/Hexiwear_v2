/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LEDpin8.c
**     Project     : Hexiwear_PEx_2_SDKv2
**     Processor   : MK64FN1M0VDC12
**     Component   : SDK_BitIO
**     Version     : Component 01.017, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-18, 19:44, # CodeGen: 22
**     Abstract    :
**
**     Settings    :
**          Component name                                 : LEDpin8
**          SDK                                            : KSDK1
**          GPIO Name                                      : GPIOD
**          PORT Name                                      : PORTD
**          Pin Number                                     : 0
**          Pin Symbol                                     : RGB_R
**          Do Pin Muxing                                  : no
**     Contents    :
**         GetDir    - bool LEDpin8_GetDir(void);
**         SetDir    - void LEDpin8_SetDir(bool Dir);
**         SetInput  - void LEDpin8_SetInput(void);
**         SetOutput - void LEDpin8_SetOutput(void);
**         GetVal    - bool LEDpin8_GetVal(void);
**         PutVal    - void LEDpin8_PutVal(bool Val);
**         ClrVal    - void LEDpin8_ClrVal(void);
**         SetVal    - void LEDpin8_SetVal(void);
**         NegVal    - void LEDpin8_NegVal(void);
**         Init      - void LEDpin8_Init(void);
**         Deinit    - void LEDpin8_Deinit(void);
**
**     (c) Copyright Erich Styger, 2016
**     http      : www.mcuoneclipse.com
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     This is a free software and there is NO WARRANTY.
**     No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file LEDpin8.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup LEDpin8_module LEDpin8 module documentation
**  @{
*/         

/* MODULE LEDpin8. */

#include "LEDpin8.h"
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  #include "fsl_port.h" /* include SDK header file for port muxing */
  #include "fsl_gpio.h" /* include SDK header file for GPIO */
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  #include "fsl_gpio_driver.h" /* include SDK header file for GPIO */
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_NONE
  #error "This component only works with the Kinetis SDK!"
#endif

#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  #define LEDpin8_PORTName   PORTD /* name of PORT, is pointer to PORT_Type */
  #define LEDpin8_GPIOName   GPIOD /* name of GPIO, is pointer to GPIO_Type */
  #define LEDpin8_PinNumber  0u   /* number of pin, type unsigned integer */

  static const gpio_pin_config_t LEDpin8_configOutput = {
    kGPIO_DigitalOutput,  /* use as output pin */
    1,  /* initial value */
  };

  static const gpio_pin_config_t LEDpin8_configInput = {
    kGPIO_DigitalInput,  /* use as input pin */
    0,  /* initial value */
  };
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  const gpio_output_pin_user_config_t LEDpin8_OutputConfig[] = {
    {
      .pinName = RGB_R,
      .config.outputLogic = 0,
    #if FSL_FEATURE_PORT_HAS_SLEW_RATE
      .config.slewRate = kPortSlowSlewRate,
    #endif
    #if FSL_FEATURE_PORT_HAS_OPEN_DRAIN
      .config.isOpenDrainEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH
      .config.driveStrength = kPortLowDriveStrength,
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

  const gpio_input_pin_user_config_t LEDpin8_InputConfig[] = {
    {
      .pinName = RGB_R,
    #if FSL_FEATURE_PORT_HAS_PULL_ENABLE
      .config.isPullEnable = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_PULL_SELECTION
      .config.pullSelect = kPortPullDown,
    #endif
    #if FSL_FEATURE_PORT_HAS_PASSIVE_FILTER
      .config.isPassiveFilterEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DIGITAL_FILTER
      .config.isDigitalFilterEnabled = true,
    #endif
    #if FSL_FEATURE_GPIO_HAS_INTERRUPT_VECTOR
      .config.interrupt = kPortIntDisabled
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

#endif

static bool LEDpin8_isOutput = false;
/*
** ===================================================================
**     Method      :  LEDpin8_ClrVal (component SDK_BitIO)
**     Description :
**         Clears the pin value (sets it to a low level)
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_ClrVal(void)
{
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  GPIO_ClearPinsOutput(LEDpin8_GPIOName, 1<<LEDpin8_PinNumber);
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  GPIO_DRV_ClearPinOutput(RGB_R);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin8_SetVal (component SDK_BitIO)
**     Description :
**         Sets the pin value to a high value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_SetVal(void)
{
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  GPIO_SetPinsOutput(LEDpin8_GPIOName, 1<<LEDpin8_PinNumber);
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  GPIO_DRV_SetPinOutput(RGB_R);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin8_NegVal (component SDK_BitIO)
**     Description :
**         Toggles/negates the pin value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_NegVal(void)
{
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  GPIO_TogglePinsOutput(LEDpin8_GPIOName, 1<<LEDpin8_PinNumber);
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  GPIO_DRV_TogglePinOutput(RGB_R);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin8_GetVal (component SDK_BitIO)
**     Description :
**         Returns the pin value
**     Parameters  : None
**     Returns     :
**         ---             - Returns the value of the pin:
**                           FALSE/logical level '0' or TRUE/logical
**                           level '1'
** ===================================================================
*/
bool LEDpin8_GetVal(void)
{
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  return GPIO_ReadPinInput(LEDpin8_GPIOName, LEDpin8_PinNumber)!=0;
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  return GPIO_DRV_ReadPinInput(RGB_R)!=0;
#else
  return FALSE;
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin8_GetDir (component SDK_BitIO)
**     Description :
**         Return the direction of the pin (input/output)
**     Parameters  : None
**     Returns     :
**         ---             - FALSE if port is input, TRUE if port is
**                           output
** ===================================================================
*/
bool LEDpin8_GetDir(void)
{
  return LEDpin8_isOutput;
}

/*
** ===================================================================
**     Method      :  LEDpin8_SetDir (component SDK_BitIO)
**     Description :
**         Sets the direction of the pin (input or output)
**     Parameters  :
**         NAME            - DESCRIPTION
**         Dir             - FALSE: input, TRUE: output
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_SetDir(bool Dir)
{
  if (Dir) {
    LEDpin8_SetOutput();
  } else {
    LEDpin8_SetInput();
  }
}

/*
** ===================================================================
**     Method      :  LEDpin8_SetInput (component SDK_BitIO)
**     Description :
**         Sets the pin as input
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_SetInput(void)
{
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  GPIO_PinInit(LEDpin8_GPIOName, LEDpin8_PinNumber, &LEDpin8_configInput);
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  GPIO_DRV_SetPinDir(RGB_R, kGpioDigitalInput);
#endif
  LEDpin8_isOutput = false;
}

/*
** ===================================================================
**     Method      :  LEDpin8_SetOutput (component SDK_BitIO)
**     Description :
**         Sets the pin as output
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_SetOutput(void)
{
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  GPIO_PinInit(LEDpin8_GPIOName, LEDpin8_PinNumber, &LEDpin8_configOutput);
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  GPIO_DRV_SetPinDir(RGB_R, kGpioDigitalOutput);
#endif
  LEDpin8_isOutput = true;
}

/*
** ===================================================================
**     Method      :  LEDpin8_PutVal (component SDK_BitIO)
**     Description :
**         Sets the pin value
**     Parameters  :
**         NAME            - DESCRIPTION
**         Val             - Value to set. FALSE/logical '0' or
**                           TRUE/logical '1'
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_PutVal(bool Val)
{
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  if (Val) {
    GPIO_SetPinsOutput(LEDpin8_GPIOName, 1<<LEDpin8_PinNumber);
  } else {
    GPIO_ClearPinsOutput(LEDpin8_GPIOName, 1<<LEDpin8_PinNumber);
  }
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  GPIO_DRV_WritePinOutput(RGB_R, Val);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin8_Init (component SDK_BitIO)
**     Description :
**         Driver initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_Init(void)
{
#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_2_0
  #if LEDpin8_DO_PIN_MUXING
  PORT_SetPinMux(LEDpin8_PORTName, LEDpin8_PinNumber, kPORT_MuxAsGpio); /* mux as GPIO */
  #endif
  LEDpin8_SetOutput();
#elif KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_1_3
  /*! \todo Pin Muxing not implemented */
  GPIO_DRV_Init(LEDpin8_InputConfig, LEDpin8_OutputConfig);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin8_Deinit (component SDK_BitIO)
**     Description :
**         Driver de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin8_Deinit(void)
{
  /* nothing needed */
}

/* END LEDpin8. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/