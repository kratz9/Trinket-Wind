/* Main data class */
#include "Structs.h"
#include "HardwareSerial.h"
#include "Arduino.h"


/*	PINOUT SETUP 
 A0 - A7 - Analog Inputs
 3		 - Control Output


*/

class GlobalData
{
public:
	void SetThermistorPower();
	void ReadRawSensorData();
	void AnalyzeData();
	void OutputStatusSerial();
	int analogNoiseReducedRead(int pinNumber);
	GlobalData();
	~GlobalData();
	
	Raw SensorData;
	Wind WindData;
	int ThermistorPower;


	int ThermistorAdjustDelay; //counter to delay how often PWM control is updated
	int SerialUpdateDelay;

	const static int TARGET_AVG_VALUE = 500; 
	const static int THERM_POWER_ADJ_THRESHOLD = 1;
	const static int SERIAL_UPDATE_DELAY = 1;

public:
	void Init();
	void RunLoop();


};
