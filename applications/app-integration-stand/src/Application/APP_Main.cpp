#include "stdafx.h"

#include "APP_Bsp.h"
#include "APP_Communication.h"
#include "APP_Debug.h"
#include "APP_Driver.h"
#include "APP_IntegrationStand.h"
#include "APP_Os.h"
#include "APP_Usb.h"
#include "integration-stand/src/integrationstand_Interceptor.h"
#include "tacho-main-logic/Application/APP_Tracer.h"
#include "tacho-main-logic/Component/Card/MW_CardHal.h"
#include "tacho-main-logic/Tool/DateTime/DateTimeStr.h"
#include "tacho-main-logic/Tool/Log/SavedLog.h"

#include "arm_math.h"

namespace bsp
{
namespace app
{
void Init();
} // namespace app
} // namespace bsp

void vMainTask(void*)
{
	mcu::dbg::InitDebug();
	printf("Task vMainTask started!\n");

	os::app::Init();
	usb::app::GetComponent();

	// Initialistion ADC 
	bsp::InitAdcForHardwareVersion();
	bsp::InitAdcForSpkCurrent();

	bsp::app::Init();

	communication::app::Init();

	// Initialistion and started sinus generation
	bsp::TestAudioInOut();
	bsp::InitAdcAudio();

	// Start DAC generation
	bsp::StartSinusGeneration();
	// Start ADC audition
	bsp::StartSignalAudition();
	// Wait ready buffer for FFT
	while (!bsp::GetAdcDataReady())
	{
		Sleep(1);
	}
	// Start calculation received frequency
	bsp::StopSinusGeneration();
	Sleep(1000);
	bsp::CalculationInFrequency();
	PDEBUG("RESULT: %d\n",
	       bsp::GetResultFrequency()); // result frequency may differ from real by 1-2%
	


	while (true)
	{
		os::app::GetOs()->SleepFor(1000);
	}
}
