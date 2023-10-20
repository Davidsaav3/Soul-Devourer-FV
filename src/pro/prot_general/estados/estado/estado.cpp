#include "estado.h"
#include <iostream>
#include "../../run/run.h"

Estado::Estado(Run* juego):run(juego) {}

Estado::~Estado() {
	//delete run;
}

Run* Estado::getRun(){
	return run;
}
