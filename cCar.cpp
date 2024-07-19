#include <iostream>
#include <cstdlib>
#include <string.h>
#include "cCar.h"
using namespace std;

// Constructor.
cCar::cCar(void)
{
	pName = nullptr;
	Age = 0;
	pManufacturer = nullptr;
	TopSpeed = 0;
}

// Overloaded constructor.
cCar::cCar(const char* pNewName, unsigned int NewAge, const char* pNewManufacturer, unsigned int NewTopSpeed)
{
	// _strdup() (short for "string duplication") is a library function which allocates new memory
	// and copies the string pointed to by the pNewName pointer into the newly allocated memory.
	pName = _strdup(pNewName);
	Age = NewAge;
	pManufacturer = _strdup(pNewManufacturer);
	TopSpeed = NewTopSpeed;
}

// Destructor.
cCar::~cCar(void)
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
		pName = nullptr;
	}
	if (pManufacturer)
	{
		delete pManufacturer;
		pManufacturer = nullptr;
	}
}

void cCar::OutputDetails(void)
{
	cout << pName << ", " << Age << ", " << pManufacturer << ", " << TopSpeed << endl;
}

// Copy constructor.
/*	This does a deep copy of the original cCar object, so the original car's Name
	can change independently of the Name of this new car.
	Copy constructors are called implicitly when you construct a new cCar instance using: cCar Saloon(Hatchback)
	i.e. the copy constructor is called to copy everything from Hatchback to Saloon.
	Copy constructors are also called implicitly when an instance of cCar is passed by value into a function, since that
	function creates its own local copy of the object and only works on that. (Same as it does if you pass in an int or anything
	else by value.)
*/
cCar::cCar(cCar& Original)
{
	pName = _strdup(Original.pName);
	Age = Original.Age;
	pManufacturer = _strdup(Original.pManufacturer);
	TopSpeed = Original.TopSpeed;
}

// This is called when you use the assignment operator ('=') between cCar instances, e.g. Dragster = Runaround.
void cCar::operator=(cCar& Original)
{
	// This does a deep copy of the original cCar object, so the original car's Name
	// can change independently of the Name of this new car.
	// First we check whether the already-existing vehicle to be modified already has a name. If so, we
	// need to delete it because we're going to be giving it a new name copied from the Original car.
	if (pName)
	{
		delete pName;
	}
	pName = _strdup(Original.pName);
	Age = Original.Age;
	if (pManufacturer)
	{
		delete pManufacturer;
	}
	pManufacturer = _strdup(Original.pManufacturer);
	TopSpeed = Original.TopSpeed;
}

void cCar::StartMoving(void)
{
	cout << "Car starts moving." << endl;
}
