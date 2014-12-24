
/* Data type Definitions */


/*
Raw analog data from the sensors
oriented by board layout.
Values are 0-1024 returned by built-in
10 bit adc on the atmega
*/
struct Raw
{
	int North;
	int NorthEast;
	int East;
	int SouthEast;
	int South;
	int SouthWest;
	int West;
	int NorthWest;

	Raw(int North,
		int NorthEast,
		int East,
		int SouthEast,
		int South,
		int SouthWest,
		int West,
		int NorthWest)
	{
		North = North;
		NorthEast = NorthEast;
		East = East;
		SouthEast = SouthEast;
		South = South;
		SouthWest = SouthWest;
		West = West;
		NorthWest = NorthWest;
	}
};

/*
Calculated wind direction and speed
*/
struct Wind
{
	int Direction;  // 0 to 360 
	int Speed;		// 0 to 100
};