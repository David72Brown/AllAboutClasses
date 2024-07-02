#include <iostream>
#include <cstdlib>
#include <string.h>
#include "cAnimal.h"
using namespace std;

// Constructor.
cAnimal::cAnimal(void)
{
	pName = nullptr;
	Age = 0;
}

// Overloaded constructor.
cAnimal::cAnimal(const char* pNewName, unsigned int NewAge)
{
	// _strdup() (short for "string duplication") is a library function which allocates new memory
	// and copies the string pointed to by the pNewName pointer into the newly allocated memory.
	pName = _strdup(pNewName);
	this->Age = NewAge;
}

// Destructor.
cAnimal::~cAnimal(void)
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

void cAnimal::SetInitial(const char Initial)
{
	// The (one) character at the start of the string pointed to by pName should be changed.
	// Let's only do this if there is actually a name present of length >= 1.
	if (strlen(pName) >= 1)
	{
		*pName = Initial;
	}
}

void cAnimal::OutputDetails(void)
{
	cout << pName << ", " << Age << endl;
}
