#pragma once

class cVehicle
{
	public:
		cVehicle(void);											// Constructor.
		cVehicle(const char *NewName, unsigned int NewAge);		// Overloaded constructor.
		~cVehicle(void);										// Destructor.
		cVehicle(cVehicle& Original);							// Copy constructor.
		void operator=(cVehicle& Original);						// Does deep copy when we use the assignment operator e.g. VehicleA = VehicleB.
		void SetInitial(const char Initial);
		virtual void OutputDetails(void);
		virtual void StartMoving(void);
	protected:
		char* pName;
		unsigned int Age;
};
