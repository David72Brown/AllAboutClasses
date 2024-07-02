#include <iostream>
#include <cstdlib>
#include <string.h>
#include "cPerson.h"
using namespace std;

// Constructor.
cPerson::cPerson(void)
{
	strcpy_s(Name, MaxNameLen, "");
	Age = 0;
}

// Overloaded constructor.
cPerson::cPerson(const char* pNewName, unsigned int NewAge)
{
	strcpy_s(Name, MaxNameLen, pNewName);
	this->Age = NewAge;
}

// Destructor.
cPerson::~cPerson(void)
{
}

// Changes the first letter of the person's name to be the character passed in as the parameter.
void cPerson::SetInitial(const char Initial)
{
	// The first character of the name should be changed.
	// Let's only do this if there is actually a name present of length >= 1.
	if (strlen(Name) >= 1)
	{
		Name[0] = Initial;
	}
}

void cPerson::OutputDetails(void)
{
	cout << Name << ", " << Age << endl;
}
