#pragma once

const unsigned int MaxNameLen = 50;

class cPerson
{
	public:
		cPerson(void);											// Constructor.
		cPerson(const char *NewName, unsigned int NewAge);		// Overloaded constructor.
		~cPerson(void);											// Destructor.
		void SetInitial(const char Initial);
		void OutputDetails(void);
	private:
		char Name[MaxNameLen+1];
		unsigned int Age;
};
