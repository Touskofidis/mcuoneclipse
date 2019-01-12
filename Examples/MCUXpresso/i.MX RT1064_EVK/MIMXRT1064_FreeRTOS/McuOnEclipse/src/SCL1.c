/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : SCL1.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : SDK_BitIO
**     Version     : Component 01.024, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-08-28, 07:32, # CodeGen: 351
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         GetDir    - bool SCL1_GetDir(void);
**         SetDir    - void SCL1_SetDir(bool Dir);
**         SetInput  - void SCL1_SetInput(void);
**         SetOutput - void SCL1_SetOutput(void);
**         GetVal    - bool SCL1_GetVal(void);
**         PutVal    - void SCL1_PutVal(bool Val);
**         ClrVal    - void SCL1_ClrVal(void);
**         SetVal    - void SCL1_SetVal(void);
**         NegVal    - void SCL1_NegVal(void);
**         Init      - void SCL1_Init(void);
**         Deinit    - void SCL1_Deinit(void);
**
** * Copyright (c) 2015-2018, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file SCL1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup SCL1_module SCL1 module documentation
**  @{
*/         

/* MODULE SCL1. */

#include "SCL1.h"
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  #if SCL1_CONFIG_DO_PIN_MUXING
  #include "fsl_port.h" /* include SDK header file for port muxing */
  #endif
  #include "fsl_gpio.h" /* include SDK header file for GPIO */
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  #include "fsl_gpio_driver.h" /* include SDK header file for GPIO */
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  #include "pins_gpio_hw_access.h"
  #include "pins_driver.h" /* include SDK header file for GPIO */
#else
  #error "Unsupported SDK!"
#endif

#if McuLib_CONFIG_NXP_SDK_2_0_USED

  static const gpio_pin_config_t SCL1_configOutput = {
    kGPIO_DigitalOutput,  /* use as output pin */
    SCL1_CONFIG_INIT_PIN_VALUE,  /* initial value */
  };

  static const gpio_pin_config_t SCL1_configInput = {
    kGPIO_DigitalInput,  /* use as input pin */
    SCL1_CONFIG_INIT_PIN_VALUE,  /* initial value */
  };
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  const gpio_output_pin_user_config_t SCL1_OutputConfig[] = {
    {
      .pinName = SCL1_CONFIG_PIN_SYMBOL,
      .config.outputLogic = SCL1_CONFIG_INIT_PIN_VALUE,
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

  const gpio_input_pin_user_config_t SCL1_InputConfig[] = {
    {
      .pinName = SCL1_CONFIG_PIN_SYMBOL,
    #if FSL_FEATURE_PORT_HAS_PULL_ENABLE
      #if SCL1_CONFIG_PULL_RESISTOR==0 /* 0: no pull resistor, 1: pull-up, 2: pull-down, 3: pull-up or no pull, 4: pull-down or no pull: 4: autoselect-pull */
      .config.isPullEnable = false,
      #else
      .config.isPullEnable = true,
      #endif
    #endif
    #if FSL_FEATURE_PORT_HAS_PULL_SELECTION
      #if SCL1_CONFIG_PULL_RESISTOR==1
      .config.pullSelect = kPortPullUp,
      #else
      .config.pullSelect = kPortPullDown,
      #endif
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

static bool SCL1_isOutput = false;
/*
** ===================================================================
**     Method      :  ClrVal (component SDK_BitIO)
**
**     Description :
**         Clears the pin value (sets it to a low level)
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_ClrVal(void)
{
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  GPIO_ClearPinsOutput(SCL1_CONFIG_GPIO_NAME, 1<<SCL1_CONFIG_PIN_NUMBER);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_ClearPinOutput(SCL1_CONFIG_PIN_SYMBOL);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  PINS_GPIO_WritePin(SCL1_CONFIG_PORT_NAME, SCL1_CONFIG_PIN_NUMBER, 0);
#endif
}

/*
** ===================================================================
**     Method      :  SetVal (component SDK_BitIO)
**
**     Description :
**         Sets the pin value to a high value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_SetVal(void)
{
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  GPIO_SetPinsOutput(SCL1_CONFIG_GPIO_NAME, 1<<SCL1_CONFIG_PIN_NUMBER);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinOutput(SCL1_CONFIG_PIN_SYMBOL);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  PINS_GPIO_WritePin(SCL1_CONFIG_PORT_NAME, SCL1_CONFIG_PIN_NUMBER, 1);
#endif
}

/*
** ===================================================================
**     Method      :  NegVal (component SDK_BitIO)
**
**     Description :
**         Toggles/negates the pin value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_NegVal(void)
{
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  GPIO_TogglePinsOutput(SCL1_CONFIG_GPIO_NAME, 1<<SCL1_CONFIG_PIN_NUMBER);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_TogglePinOutput(SCL1_CONFIG_PIN_SYMBOL);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  pins_channel_type_t val;

  val = PINS_GPIO_GetPinsOutput(SCL1_CONFIG_PORT_NAME);
  if (val&(1<<SCL1_CONFIG_PIN_NUMBER)) {
    PINS_GPIO_WritePin(SCL1_CONFIG_PORT_NAME, SCL1_CONFIG_PIN_NUMBER, 0);
  } else {
    PINS_GPIO_WritePin(SCL1_CONFIG_PORT_NAME, SCL1_CONFIG_PIN_NUMBER, 1);
  }
#endif
}

/*
** ===================================================================
**     Method      :  GetVal (component SDK_BitIO)
**
**     Description :
**         Returns the pin value
**     Parameters  : None
**     Returns     :
**         ---             - Returns the value of the pin:
**                           FALSE/logical level '0' or TRUE/logical
**                           level '1'
** ===================================================================
*/
bool SCL1_GetVal(void)
{
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  return GPIO_ReadPinInput(SCL1_CONFIG_GPIO_NAME, SCL1_CONFIG_PIN_NUMBER)!=0;
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  return GPIO_DRV_ReadPinInput(SCL1_CONFIG_PIN_SYMBOL)!=0;
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  return (PINS_DRV_ReadPins(SCL1_CONFIG_PORT_NAME)&(1<<SCL1_CONFIG_PIN_NUMBER))!=0;
#else
  return FALSE;
#endif
}

/*
** ===================================================================
**     Method      :  GetDir (component SDK_BitIO)
**
**     Description :
**         Return the direction of the pin (input/output)
**     Parameters  : None
**     Returns     :
**         ---             - FALSE if port is input, TRUE if port is
**                           output
** ===================================================================
*/
bool SCL1_GetDir(void)
{
  return SCL1_isOutput;
}

/*
** ===================================================================
**     Method      :  SetDir (component SDK_BitIO)
**
**     Description :
**         Sets the direction of the pin (input or output)
**     Parameters  :
**         NAME            - DESCRIPTION
**         Dir             - FALSE: input, TRUE: output
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_SetDir(bool Dir)
{
  if (Dir) {
    SCL1_SetOutput();
  } else {
    SCL1_SetInput();
  }
}

/*
** ===================================================================
**     Method      :  SetInput (component SDK_BitIO)
**
**     Description :
**         Sets the pin as input
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_SetInput(void)
{
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(SCL1_CONFIG_GPIO_NAME, SCL1_CONFIG_PIN_NUMBER, &SCL1_configInput);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(SCL1_CONFIG_PIN_SYMBOL, kGpioDigitalInput);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  pins_channel_type_t val;

  val = PINS_GPIO_GetPinsDirection(SCL1_CONFIG_PORT_NAME); /* bit 0: pin is input; 1: pin is output */
  val &= ~(1<<SCL1_CONFIG_PIN_NUMBER); /* clear bit ==> input */
  PINS_DRV_SetPinsDirection(SCL1_CONFIG_PORT_NAME, val);
#endif
  SCL1_isOutput = false;
}

/*
** ===================================================================
**     Method      :  SetOutput (component SDK_BitIO)
**
**     Description :
**         Sets the pin as output
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_SetOutput(void)
{
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(SCL1_CONFIG_GPIO_NAME, SCL1_CONFIG_PIN_NUMBER, &SCL1_configOutput);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(SCL1_CONFIG_PIN_SYMBOL, kGpioDigitalOutput);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  pins_channel_type_t val;

  val = PINS_GPIO_GetPinsDirection(SCL1_CONFIG_PORT_NAME); /* bit 0: pin is input; 1: pin is output */
  val |= (1<<SCL1_CONFIG_PIN_NUMBER); /* set bit ==> output */
  PINS_DRV_SetPinsDirection(SCL1_CONFIG_PORT_NAME, val);
#endif
  SCL1_isOutput = true;
}

/*
** ===================================================================
**     Method      :  PutVal (component SDK_BitIO)
**
**     Description :
**         Sets the pin value
**     Parameters  :
**         NAME            - DESCRIPTION
**         Val             - Value to set. FALSE/logical '0' or
**                           TRUE/logical '1'
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_PutVal(bool Val)
{
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  if (Val) {
    GPIO_SetPinsOutput(SCL1_CONFIG_GPIO_NAME, 1<<SCL1_CONFIG_PIN_NUMBER);
  } else {
    GPIO_ClearPinsOutput(SCL1_CONFIG_GPIO_NAME, 1<<SCL1_CONFIG_PIN_NUMBER);
  }
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_WritePinOutput(SCL1_CONFIG_PIN_SYMBOL, Val);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  PINS_DRV_WritePin(SCL1_CONFIG_PORT_NAME, SCL1_CONFIG_PIN_NUMBER, Val);
#endif
}

/*
** ===================================================================
**     Method      :  Init (component SDK_BitIO)
**
**     Description :
**         Driver initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_Init(void)
{
#if McuLib_CONFIG_NXP_SDK_2_0_USED
  #if SCL1_CONFIG_DO_PIN_MUXING
  PORT_SetPinMux(SCL1_CONFIG_PORT_NAME, SCL1_CONFIG_PIN_NUMBER, kPORT_MuxAsGpio); /* mux as GPIO */
  #endif
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_KINETIS_1_3
  /*! \todo Pin Muxing not implemented */
  GPIO_DRV_Init(SCL1_InputConfig, SCL1_OutputConfig);
#elif McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_S32K
  /* the following needs to be called in the application first:
  PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
  */
#endif
#if SCL1_CONFIG_INIT_PIN_DIRECTION == SCL1_CONFIG_INIT_PIN_DIRECTION_INPUT
  SCL1_SetInput();
#elif SCL1_CONFIG_INIT_PIN_DIRECTION == SCL1_CONFIG_INIT_PIN_DIRECTION_OUTPUT
  SCL1_SetOutput();
#endif
}

/*
** ===================================================================
**     Method      :  Deinit (component SDK_BitIO)
**
**     Description :
**         Driver de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SCL1_Deinit(void)
{
  /* nothing needed */
}

/* END SCL1. */

/*!
** @}
*/
