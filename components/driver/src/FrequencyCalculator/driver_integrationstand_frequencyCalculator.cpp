#include "stdafx.h"

#include "Application/APP_Os.h"
#include "components/driver/src/FrequencyCalculator/driver_integrationstand_frequencyCalculator.h"
#include <memory.h>

namespace driver
{
namespace integration_stand
{

FrequencyCalculator::FrequencyCalculator(mcu::IAdcChannelSingle* channelSpkCurrent,
                                         TIM_HandleTypeDef tim,
                                         uint16_t fftLength,
                                         uint16_t samplingRate)
    : m_chanelAdc(channelSpkCurrent)
    , m_timHandle(tim)
    , m_fftLength(fftLength)
    , m_samplingRate(samplingRate)
{
	if (m_timHandle.Instance == TIM4)
	{
		m_irqTim = TIM4_IRQn;
	}
	else
	{
		ASSERT(false);
	}

	m_input_fft.reset(new float32_t[m_fftLength]);
	m_output_fft.reset(new float32_t[m_fftLength]);
	m_output_fft_mag.reset(new float32_t[m_fftLength / 2]);

	SetFrequency(m_samplingRate);
	arm_rfft_fast_init_f32(&fft_instance, m_fftLength);

	stopTimerAdc();
}

uint16_t FrequencyCalculator::GetSpkCurrentAdcMv()
{
	if (!m_chanelAdc)
	{
		return 0;
	}
	uint32_t value = m_chanelAdc->GetValue();

	return value;
}

void FrequencyCalculator::receiptAdcData()
{
	if (!m_chanelAdc)
	{
		return;
	}

	if (counter < m_fftLength)
	{
		m_input_fft[counter] = (m_chanelAdc->GetValue() * MAX_VOLTAGE_ADC / MAX_VALUE_ADC)
		                       - CONSTANT_COMPONENT_SINUS;
		counter++;
	}

	if (counter == m_fftLength)
	{
		m_flagReadiCalculation = true;
		stopTimerAdc();
	}
}

void FrequencyCalculator::SetFrequency(uint32_t frequency)
{
	m_frequency = frequency;
	if (is_AdcAudition)
	{
		stopTimerAdc();
	}
	__HAL_TIM_SET_PRESCALER(&m_timHandle, 1);
	__HAL_TIM_SET_AUTORELOAD(&m_timHandle, (SystemCoreClock / m_frequency) - 1);
}

void FrequencyCalculator::startTimerAdc()
{
	if (!is_AdcAudition)
	{
		HAL_TIM_Base_Start_IT(&m_timHandle);
		NVIC_EnableIRQ(m_irqTim);
		m_flagReadiCalculation = false;
		is_AdcAudition = true;
	}
	else
	{
		return;
	}
}

void FrequencyCalculator::stopTimerAdc()
{
	HAL_TIM_Base_Stop_IT(&m_timHandle);
	NVIC_DisableIRQ(m_irqTim);
	is_AdcAudition = false;
}

bool FrequencyCalculator::GetDataReady()
{
	return m_flagReadiCalculation;
}

uint32_t FrequencyCalculator::GetResultFrequencyHz()
{
	float32_t* maxValue = std::max_element(
	    m_output_fft_mag.get() + 3,
	    m_output_fft_mag.get()
	        + (m_fftLength / 2)); // irnore firsts elements to exclude constant component

	auto resultFrequency = (maxValue - m_output_fft_mag.get()) * m_samplingRate / m_fftLength;

	return (uint32_t)resultFrequency;
}

void FrequencyCalculator::StartFrequencyCalculation()
{
	if (!m_flagReadiCalculation)
	{
		return;
	}

	arm_rfft_fast_f32(&fft_instance, m_input_fft.get(), m_output_fft.get(), 0);
	arm_cmplx_mag_f32(m_output_fft.get(), m_output_fft_mag.get(), (m_fftLength / 2));
	
		// uncomment for debug FFT algoritm
	//	for (int i = 0; i < m_fftLength / 2; i++)
	//	{ 
	//		fr[i] = ((float32_t)(i * m_samplingRate) / m_fftLength);
	//		PDEBUG("index: %d - freq: %f: %f \n",
	//		       i,
	//		       ((float32_t)(i * m_samplingRate) / m_fftLength),
	//		       m_output_fft_mag[i]);
	//		//				if (i > 512)
	//		//				{
	//		//					PDEBUG("---");
	//		//				}
	//		os::app::GetOs()->SleepFor(50);
	//	}
}

} // namespace integration_stand
} // namespace driver
