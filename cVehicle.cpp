#include <iostream>
#include <cstdlib>
#include <string.h>
#include "cVehicle.h"
using namespace std;

// Constructor.
cVehicle::cVehicle(void)
{
	pName = nullptr;
	Age = 0;
}

// Overloaded constructor.
cVehicle::cVehicle(const char* pNewName, unsigned int NewAge)
{
	// _strdup() (short for "string duplication") is a library function which allocates new memory
	// and copies the string pointed to by the pNewName pointer into the newly allocated memory.
	pName = _strdup(pNewName);
	this->Age = NewAge;
}

// Destructor.
cVehicle::~cVehicle(void)
{
	/*	If pName points to memory containing a string, we need to free that up before this instance of cAnimal itself is freed up.
		Otherwise the name string will sit in memory indefinitely with no pointers pointing to it, so it will be using memory but
		will be of no use to any part of the program and no code will ever be able to find it again.
		If this keeps happening and we keep using up memory and never freeing it up, that's called a "memory leak" and we will
		eventually run out of memory and the program will crash.
	*/
	if (pName)
	{
		delete pName;
	}
}

void cVehicle::SetInitial(const char Initial)
{
	// The (one) character at the start of the string pointed to by pName should be changed.
	// Let's only do this if there is actually a name present of length >= 1.
	if (strlen(pName) >= 1)
	{
		*pName = Initial;
	}
}

void cVehicle::OutputDetails(void)
{
	cout << pName << ", " << Age << endl;
}

// Copy constructor.
/*	This does a deep copy of the original cVehicle object, so the original vehicle's Name
	can change independently of the Name of this new vehicle.
	Copy constructors are called implicitly when you construct a new cVehicle instance using: cVehicle Skateboard(Bike)
	i.e. the copy constructor is called to copy everything from Bike to Skateboard.
	Copy constructors are also called implicitly when an instance of cVehicle is passed by value into a function, since that
	function creates its own local copy of the object and only works on that. (Same as it does if you pass in an int or anything
	else by value.)
*/
cVehicle::cVehicle(cVehicle& Original)
{
	pName = _strdup(Original.pName);
	Age = Original.Age;
}

// This is called when you use the assignment operator ('=') between cVehicle instances, e.g. Car = Bike.
void cVehicle::operator=(cVehicle& Original)
{
	// This does a deep copy of the original cVehicle object, so the original vehicle's Name
	// can change independently of the Name of this new vehicle.
	// First we check whether the already-existing vehicle to be modified already has a name. If so, we
	// need to delete it because we're going to be giving it a new name copied from the Original vehicle.
	if (pName)
	{
		delete pName;
	}
	pName = _strdup(Original.pName);
	Age = Original.Age;
}

void cVehicle::StartMoving(void)
{
	// Do nothing - there is no generic cVehicle version of this function.
}
