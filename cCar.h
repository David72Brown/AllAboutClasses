#pragma once

#include "cVehicle.h"

class cCar : public cVehicle
{
	public:
		cCar(void);											// Constructor.
		cCar(const char* pNewName, unsigned int NewAge,		// Overloaded constructor.
			 const char* pNewManufacturer, unsigned int NewTopSpeed);
		~cCar(void);										// Destructor.
		cCar(cCar& Original);								// Copy constructor.
		void operator=(cCar& Original);						// Does deep copy when we use the assignment operator e.g. CarA = CarB.
		void OutputDetails(void);
		void StartMoving(void);
private:
		// cCar inherits pName and Age from the base class cVehicle, so we don't need to repeat them here.
		char* pManufacturer;
		int TopSpeed;
		bool TyresPumpedUpOK;
};
