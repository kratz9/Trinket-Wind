/* Main data class */
#include "Structs.h"

/*	PINOUT SETUP 
 A0 - A7 - Analog Inputs
 3		 - Control Output


*/

class GlobalData
{
public:

	GlobalData* Instance()
	{
		return _instance;
	}

	static void Init()
	{
		_instance = new GlobalData;
		Serial.begin(9600);
	}

	static void RunLoop()
	{
		_instance->SetThermistorPower();
		_instance->ReadRawSensorData();
		_instance->AnalyzeData();

	}

private:

	Raw SensorData;
	Wind WindData;
	int ThermistorPower;


	int ThermistorAdjustDelay; //counter to delay how often PWM control is updated
	static GlobalData* _instance;

	const int TARGET_AVG_VALUE = 800; 
	const int THERM_POWER_ADJ_THRESHOLD = 100;
	

	void ReadRawSensorData()
	{
		//Get analog sensor data
		SensorData.North = analogRead(A0); 
		SensorData.NorthEast = analogRead(A1);
		SensorData.East = analogRead(A2);
		SensorData.SouthEast = analogRead(A3);
		SensorData.South = analogRead(A4);
		SensorData.SouthWest = analogRead(A5);
		SensorData.West = analogRead(A6);
		SensorData.NorthWest = analogRead(A7);
	}

	void AnalyzeData()
	{
		/* MAGIC! */
		int AverageValue = (SensorData.North +
			SensorData.NorthEast + 
			SensorData.East +
			SensorData.SouthEast +
			SensorData.South +
			SensorData.SouthWest +
			SensorData.West +
			SensorData.NorthWest) / 8;

		if(AverageValue > TARGET_AVG_VALUE && ThermistorAdjustDelay > THERM_POWER_ADJ_THRESHOLD)
		{	
			ThermistorPower = max(ThermistorPower -1, 1);
			ThermistorAdjustDelay = 0;
		}

		if(AverageValue < TARGET_AVG_VALUE && ThermistorAdjustDelay > THERM_POWER_ADJ_THRESHOLD)
		{
			ThermistorPower = min(ThermistorPower+1, 255);
			ThermistorAdjustDelay = 0;
		}
		
		int MinValue = min(SensorData.North, 
			min(SensorData.NorthEast,
			min(SensorData.East,
			min(SensorData.SouthEast,
			min(SensorData.South,
			min(SensorData.SouthWest,
			min(SensorData.West,
			SensorData.NorthWest)))))));

		if(MinValue = SensorData.North)
		{
			WindData.Direction = 0;
			WindData.Speed = abs(SensorData.North - (SensorData.East + SensorData.West)/2);
		}
		else if(MinValue = SensorData.NorthEast)
		{
			WindData.Direction = 0;
			WindData.Speed = abs(SensorData.NorthEast - (SensorData.SouthEast + SensorData.NorthWest)/2);
		}
		else if(MinValue = SensorData.East)
		{
			WindData.Direction = 0;
			WindData.Speed = abs(SensorData.East - (SensorData.North + SensorData.South)/2);
		} 
		else if(MinValue = SensorData.SouthEast)
		{
			WindData.Direction = 0;
			WindData.Speed = abs(SensorData.SouthEast - (SensorData.NorthEast + SensorData.SouthWest)/2);
		}

	}

	void SetThermistorPower()
	{
		analogWrite(3, ThermistorPower);
	}

	void OutputStatusSerial()
	{
		//CLS
		Serial.write("\u001B[2J");
		Serial.println(SensorData.North);
		Serial.println(SensorData.NorthEast);
		Serial.println(SensorData.East);
		Serial.println(SensorData.SouthEast);
		Serial.println(SensorData.South);
		Serial.println(SensorData.SouthWest);
		Serial.println(SensorData.West);
		Serial.println(SensorData.NorthWest);
		Serial.println(ThermistorPower);
	}


	GlobalData()
	{
		ThermistorPower = 128;
	}
};