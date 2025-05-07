#include "bsp_integrationstand_MicEmulation.h"
#include "mcu/src/Gpio/mcu_GpioCommon.h"
#include "mcu/src/Gpio/stm32h7a3/mcu_stm32h7a3_Gpio.h"
#include "mcu/src/dac/stm32h7a3/mcu_stm32h7a3_DacChannel.h"

namespace bsp
{

bool isPlaybackDac = false;
bool isAuditionAdc = false;
void TestAudioInOut()
{
	if (bsp::s_dac != nullptr && bsp::s_dacGpio != nullptr && s_sinus != nullptr)
	{
		return;
	}
	// init GPIO for DAC
	__HAL_RCC_GPIOA_CLK_ENABLE();
	s_dacGpio = new mcu::stm32h7a3::Gpio(GPIOA, 6);
	s_dacGpio->SetMode(mcu::IGpioExtended::Mode::k_analog);

	// init DAC peripheral
	s_dac = new mcu::stm32h7a3::DacChannel(
	    mcu::stm32h7a3::DacModuleNumber::k_dac2,
	    mcu::stm32h7a3::DacChannelNumber::k_channel1,
	    mcu::stm32h7a3::DacOutputBufferMode::k_outputBufferEnable,
	    mcu::stm32h7a3::DacConnectPeripheralMode::k_chipConnectDisable,
	    0);
	s_dac->InitHardware();

	// init TIM4 for generation sinus
	__HAL_RCC_TIM4_CLK_ENABLE();
	s_htim.Instance = TIM4;
	s_htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	s_htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	s_htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	s_htim.Init.Prescaler = 0; // Prescaler 0+1=1. The TIM4 is clocked system frequency (280mHz)

	if (HAL_TIM_Base_Init(&s_htim) != HAL_OK)
	{
		ASSERT(false);
	}

	s_sinus = new driver::SinusGenerator(*s_dac, s_htim);
	s_sinus->InitSinus(DAC_NUMBER_SAMPLES, DAC_FREQUENCY);
}

void SetFrequencySinus(uint16_t frequency)
{
	ASSERT(s_sinus != nullptr);
	ASSERT(frequency > 0);
	s_sinus->SetFrequency(frequency);
}

void StartSinusGeneration()
{
	ASSERT(s_sinus != nullptr);
	s_sinus->SinusStartGeneration();
	isPlaybackDac = true;
}

void StopSinusGeneration()
{
	ASSERT(s_sinus != nullptr);
	s_sinus->SinusStopGeneration();
	isPlaybackDac = false;
}

void InitAdcAudio()
{
	s_adc = new driver::integration_stand::FrequencyCalculator(
	    GetSpkCurrentP(),
	    s_htim,
	    FFT_NUMBER_SAMPLES,
	    ADC_FREQUENCY_RATE); 
}


void StartSignalAudition()
{
	if (s_adc == nullptr)
	{
		return;
	}

	s_adc->startTimerAdc();
	isAuditionAdc = true;
}

void StopSignalAudition()
{
	if (s_adc == nullptr)
	{
		return;
	}
	s_adc->stopTimerAdc();
	isAuditionAdc = false;
}

void CalculationInFrequency()
{
	s_adc->StartFrequencyCalculation();
}

uint32_t GetResultFrequency()
{
	return s_adc->GetResultFrequencyHz();
}

bool GetAdcDataReady()
{
	return s_adc->GetDataReady();
}
extern "C" void TIM4_IRQHandler(void)
{
	if (isPlaybackDac)
	{
		s_sinus->Interrupt();
	}

	if (isAuditionAdc)
	{
		bsp::s_adc->receiptAdcData();
	}

	__HAL_TIM_CLEAR_IT(&bsp::s_htim, TIM_IT_UPDATE);
}



} // namespace bsp