/* Main data class */
#include "Global.h"
#include <avr/sleep.h>
#include <avr/power.h>

/*	PINOUT SETUP 
 A0 - A7 - Analog Inputs
 3		 - Control Output


*/


void GlobalData::Init()
{
	//instance = new GlobalData;
	Serial.begin(9600);
	analogReference(EXTERNAL);
}

void GlobalData::RunLoop()
{
	SetThermistorPower();
	ReadRawSensorData();
	AnalyzeData();
	OutputStatusSerial();
}


void GlobalData::ReadRawSensorData()
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

void GlobalData::AnalyzeData()
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
		//ThermistorPower = min(ThermistorPower +1, 255);
		ThermistorAdjustDelay = 0;
	}

	if(AverageValue < TARGET_AVG_VALUE && ThermistorAdjustDelay > THERM_POWER_ADJ_THRESHOLD)
	{
		//ThermistorPower = max(ThermistorPower -1, 1);
		ThermistorAdjustDelay = 0;
	}
		
	ThermistorAdjustDelay++;

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
		WindData.Direction = 45;
		WindData.Speed = abs(SensorData.NorthEast - (SensorData.SouthEast + SensorData.NorthWest)/2);
	}
	else if(MinValue = SensorData.East)
	{
		WindData.Direction = 90;
		WindData.Speed = abs(SensorData.East - (SensorData.North + SensorData.South)/2);
	} 
	else if(MinValue = SensorData.SouthEast)
	{
		WindData.Direction = 135;
		WindData.Speed = abs(SensorData.SouthEast - (SensorData.NorthEast + SensorData.SouthWest)/2);
	}
	else if(MinValue = SensorData.South)
	{
		WindData.Direction = 180;
		WindData.Speed = abs(SensorData.South - (SensorData.East + SensorData.West)/2);
	}
	else if(MinValue = SensorData.SouthWest)
	{
		WindData.Direction = 225;
		WindData.Speed = abs(SensorData.SouthWest - (SensorData.NorthWest + SensorData.SouthEast)/2);
	}
	else if(MinValue = SensorData.West)
	{
		WindData.Direction = 270;
		WindData.Speed = abs(SensorData.West - (SensorData.North + SensorData.South)/2);
	}
	else if(MinValue = SensorData.NorthWest)
	{
		WindData.Direction = 315;
		WindData.Speed = abs(SensorData.NorthWest - (SensorData.NorthEast + SensorData.SouthWest)/2);
	}
}

void GlobalData::SetThermistorPower()
{
	analogWrite(3, ThermistorPower);
	analogWrite(5, 112); //(255-ThermistorPower)*.8);
}

void GlobalData::OutputStatusSerial()
{
	if(SerialUpdateDelay < SERIAL_UPDATE_DELAY)
	{
		SerialUpdateDelay++;
		return;
	}
	SerialUpdateDelay = 0;
	//CLS
	//Serial.write("\x1B[2J");
	Serial.println("Data");
	Serial.println(SensorData.North);
	Serial.println(SensorData.NorthEast);
	Serial.println(SensorData.East);
	Serial.println(SensorData.SouthEast);
	Serial.println(SensorData.South);
	Serial.println(SensorData.SouthWest);
	Serial.println(SensorData.West);
	Serial.println(SensorData.NorthWest);
	Serial.println(ThermistorPower);
	Serial.println(WindData.Direction);
	Serial.println(WindData.Speed);
	Serial.flush();
}


GlobalData::GlobalData()
{
	ThermistorPower = 0;
}

GlobalData::~GlobalData()
{
}

