/* Main data class */
#include "Structs.h"

class GlobalData
{
public:

	GlobalData* Instance()
	{
		return _instance;
	}

	void Init()
	{
		_instance = new GlobalData;
	}

	void SetRawSensorData(Raw data)
	{

	}

private:

	Raw SensorData;
	Wind WindData;

	GlobalData* _instance;

	GlobalData()
	{
	}
};