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
		void OutputDetails(void);
	private:
		char* pName;
		unsigned int Age;
};
