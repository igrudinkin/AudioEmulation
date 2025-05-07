set(DRIVER_FILES

	#Accel
	#${PROJECT_PACKAGES_DIR}/driver/src/Accel/driver_AccelerometerI2cLis3dh.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Accel/driver_AccelerometerI2cLis3dh.h
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IAccel.h

	# Backlight
	${PROJECT_PACKAGES_DIR}/driver/src/driver_IBacklight.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Backlight/driver_Backlight.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Backlight/driver_NoBacklight.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Backlight/driver_Backlight.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Backlight/driver_BacklightRetry.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Backlight/driver_BacklightRetry.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Backlight/driver_IBacklightLedControl.h
	${PROJECT_PACKAGES_DIR}/driver/src/Backlight/pca9624/driver_pca9624_BacklightLedControl.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/Backlight/pca9624/driver_pca9624_BacklightLedControl.h
	${PROJECT_PACKAGES_DIR}/driver/src/Backlight/pca9955/driver_pca9955_BacklightLedControl.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/Backlight/pca9955/driver_pca9955_BacklightLedControl.h
	${PROJECT_PACKAGES_DIR}/driver/src/Backlight/tlc59108/driver_tlc59108_BacklightLedControl.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/Backlight/tlc59108/driver_tlc59108_BacklightLedControl.h

	# BoardInfo
	${PROJECT_PACKAGES_DIR}/driver/src/driver_IBoardInfo.h
	${PROJECT_PACKAGES_DIR}/driver/src/BoardInfo/IntegrationStand/driver_IntegrationStand_BoardInfo.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/BoardInfo/IntegrationStand/driver_IntegrationStand_BoardInfo.h


	# BoardMonitor
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IBoardMonitor.h
	#${PROJECT_PACKAGES_DIR}/driver/src/BoardMonitor/pro/driver_pro_BoardMonitor.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/BoardMonitor/pro/driver_pro_BoardMonitor.h

	# Buzzer
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IBuzzer.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Buzzer/driver_Buzzer.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Buzzer/driver_Buzzer.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Buzzer/stm32h7a3/driver_stm32h7a3_Buzzer.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Buzzer/stm32h7a3/driver_stm32h7a3_Buzzer.h

	# Display
	${PROJECT_PACKAGES_DIR}/driver/src/Display/tic32a/driver_tic32a_Display.h
	${PROJECT_PACKAGES_DIR}/driver/src/Display/tic32a/reg_map_TIC120.h
	${PROJECT_PACKAGES_DIR}/driver/src/Display/tic32u/driver_tic32u_Display.h
	${PROJECT_PACKAGES_DIR}/driver/src/Display/tic32u/reg_map_TIC32U.h

	# Illumination
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IIlluminationSensor.h
	#${PROJECT_PACKAGES_DIR}/driver/src/IlluminationSensor/driver_IlluminationSensor.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/IlluminationSensor/driver_IlluminationSensor.h

	# Keyboard
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IKeyboard.h
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IKeyboardKeySender.h
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IKeyboardObserver.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Keyboard/driver_Keyboard.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Keyboard/driver_Keyboard.h

	# MovementModule
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IMovementSensorInput.h
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/MovementSensorInput/comparator/driver_comparator_MovementSensorInput.h
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/MovementSensorInput/comparator/driver_comparator_MovementSensorInput.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/MovementSensorInput/comparator/driver_comparator_IAdcAdapter.h
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/MovementSensorInput/comparator/driver_comparator_AdcAdapter.h
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/MovementSensorInput/comparator/driver_comparator_AdcAdapter.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IVelocitySensor.h
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IFrequencyMeter.h
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/FrequencyMeter/driver_FrequencyMeter.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/FrequencyMeter/driver_FrequencyMeter.h
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/OutSpeedPulse/driver_OutSpeedPulse.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/MovementModule/OutSpeedPulse/driver_OutSpeedPulse.h

	# Nand
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_INand.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Nand/driver_nandMx30lf1208.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Nand/driver_nandMx30lf1208.h
	#${PROJECT_PACKAGES_DIR}/driver/integration_test/Nand/driver_NandIntegrationTest.cpp
	#${PROJECT_PACKAGES_DIR}/driver/integration_test/Nand/driver_NandIntegrationTest.h

	# OutSpeedPulse
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IOutSpeedPulse.h

	# Printer
	#${PROJECT_PACKAGES_DIR}/driver/src/driver_IPrinter.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_Printer.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_Printer.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_PrinterDrv.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_PrinterDrv.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_PrinterDrvLine.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_PrinterDrvLine.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_printerFont_16x24.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_PrinterRasterizator.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_PrinterRasterizator.h
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_PrinterHead.cpp
	#${PROJECT_PACKAGES_DIR}/driver/src/Printer/driver_PrinterHead.h

	# SmartCard
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/driver_SmartCard.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/driver_SmartCard.h
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/atr.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/atr.h
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/buffer.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/buffer.h
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/checksum.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/checksum.h
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/pps.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/pps.h
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/t1_protocol.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/t1_protocol.h
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/t1_protocol_param.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/SmartCard/smartcard_t1/t1_protocol_param.h

	# Integration tests:
	#${PROJECT_PACKAGES_DIR}/driver/integration_test/SmartCard/driver_SmartCardIntegrationTest.cpp
	#${PROJECT_PACKAGES_DIR}/driver/integration_test/SmartCard/driver_SmartCardIntegrationTest.h

	# IntegrationStand
	${PROJECT_PACKAGES_DIR}/driver/src/DacSinusGeneration/driver_integrationstand_sinusGeneration.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/DacSinusGeneration/driver_integrationstand_sinusGeneration.h
	${PROJECT_PACKAGES_DIR}/driver/src/FrequencyCalculator/driver_integrationstand_frequencyCalculator.cpp
	${PROJECT_PACKAGES_DIR}/driver/src/FrequencyCalculator/driver_integrationstand_frequencyCalculator.h


)
