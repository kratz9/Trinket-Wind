#include "Global.h"




GlobalData *GD;

void setup()
{

    GD = new GlobalData();
	/* add setup code here */
	GD->Init();

}

void loop()
{

  /* add main program code here */
	GD->RunLoop();	
	delay(1000);

}



