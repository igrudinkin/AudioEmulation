#pragma once

#include "stdafx.h"
#include "driver/src/DacSinusGeneration/driver_integrationstand_sinusGeneration.h"
#include "driver/src/FrequencyCalculator/driver_integrationstand_frequencyCalculator.h"
#include "components/bsp/src/IntegrationStand/bsp_integrationstand_Adc.h"
#include "third-party/CMSIS/Include/arm_math.h"

#define DAC_FREQUENCY			1500
#define DAC_NUMBER_SAMPLES		256
#define FFT_NUMBER_SAMPLES		512
#define ADC_FREQUENCY_RATE		64000


namespace bsp
{

static mcu::stm32h7a3::Gpio* s_dacGpio = nullptr;
static mcu::stm32h7a3::DacChannel* s_dac = nullptr;
static driver::SinusGenerator* s_sinus = nullptr;
static TIM_HandleTypeDef s_htim;
static driver::integration_stand::FrequencyCalculator* s_adc = nullptr;

void TestAudioInOut();
void SetFrequencySinus(uint16_t frequency);
void StartSinusGeneration();
void StopSinusGeneration();
void StartSignalAudition(); 
void StopSignalAudition();  
void InitAdcAudio();
void CalculationInFrequency();
bool GetAdcDataReady();
uint32_t GetResultFrequency();


} // namespace bsp
	