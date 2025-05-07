#pragma once
#include "stdafx.h"
#include "third-party/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal.h"
#include "arm_math.h"
#include "mcu/src/mcu_IAdcChannelSingle.h"
#include <memory>        
#include "components/tacho-main-logic/System/Config/Debug.h"

#define MAX_VOLTAGE_ADC				3.3f
#define MAX_VALUE_ADC				4096
#define CONSTANT_COMPONENT_SINUS	1.6f

namespace driver
{
namespace integration_stand
{
class FrequencyCalculator
{
public:
	FrequencyCalculator(mcu::IAdcChannelSingle* channelSpkCurrent,
	           TIM_HandleTypeDef tim,
	           uint16_t fftLength,
	           uint16_t samplingRate);
	~FrequencyCalculator();
	uint16_t GetSpkCurrentAdcMv();
	void SetFrequency(uint32_t frequency);
	uint32_t GetFrequency();
	void receiptAdcData(); // collection data vice ADC. Is colled from bsp::StartSignalAudition().
	void StartFrequencyCalculation();
	uint32_t GetResultFrequencyHz();
	bool GetDataReady();   // to wait for data to be received 
	void startTimerAdc(); 
	void stopTimerAdc();

private:
	mcu::IAdcChannelSingle* m_chanelAdc = nullptr;
	TIM_HandleTypeDef m_timHandle;
	IRQn_Type m_irqTim;
	static constexpr uint16_t k_sampleCount = 5;
	std::unique_ptr<float32_t[]> m_input_fft;
	std::unique_ptr<float32_t[]> m_output_fft;
	std::unique_ptr<float32_t[]> m_output_fft_mag;
	float32_t freq = 500.0;
	arm_rfft_fast_instance_f32 fft_instance;
	uint32_t m_frequency; // frequency ADC samples
	uint16_t m_fftLength;
	uint16_t m_samplingRate;
	bool m_flagReadiCalculation = false;
	bool is_AdcAudition = false;

	uint16_t counter = 0;
};

} // namespace integration_stand
} // namespace driver