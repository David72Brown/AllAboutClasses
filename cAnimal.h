#pragma once

class cAnimal
{
	public:
		cAnimal(void);											// Constructor.
		cAnimal(const char *NewName, unsigned int NewAge);		// Overloaded constructor.
		~cAnimal(void);											// Destructor.
		void SetInitial(const char Initial);
		void OutputDetails(void);
	private:
		char* pName;
		unsigned int Age;
};
