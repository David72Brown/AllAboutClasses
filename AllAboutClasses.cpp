#include <iostream>
#include "cPerson.h"
#include "cAnimal.h"
#include "cVehicle.h"
#include "cCar.h"
using namespace std;

void TestPeople(void)
{
    cPerson Johnathan("Johnny", 51);
    cPerson Jill;
    cPerson William("Bill", 53);

    Jill = William;

    Jill.SetInitial('J');

    cout << "Johnathan: ";
    Johnathan.OutputDetails();
    cout << "William:   ";
    William.OutputDetails();
    cout << "Jill:      ";
    Jill.OutputDetails();
    cout << endl;
}

void TestAnimals(void)
{
    cAnimal Dog("Rex", 3);
    cAnimal Rat;
    cAnimal Cat("Catty", 2);

    Rat = Cat;
    Rat.SetInitial('R');

    cout << "Dog:      ";
    Dog.OutputDetails();
    cout << "Cat:      ";
    Cat.OutputDetails();
    cout << "Rat:      ";
    Rat.OutputDetails();
    cout << endl;
}

void TestVehicles(void)
{
    cVehicle Car("Mustang", 40);
    cVehicle Aeroplane("Jumbo", 20);
    cVehicle Bike("Nippy", 5);

    Aeroplane = Car;

    cVehicle Skateboard(Bike);
    Skateboard.SetInitial('Z');

    cout << "Car:        ";
    Car.OutputDetails();
    cout << "Aeroplane:  ";
    Aeroplane.OutputDetails();
    cout << "Bike:       ";
    Bike.OutputDetails();
    cout << "Skateboard: ";
    Skateboard.OutputDetails();
    cout << endl;
}

void TestCars(void)
{
    cCar Car1 ("Touran", 5, "Volkswagen", 100);
    Car1.SetInitial('Z');
    Car1.OutputDetails();
    Car1.StartMoving();
}

void DemonstrateRunTimePolymorphism(void)
{
    // This function demonstrates run-time polymorphism (a.k.a. "dynamic polymorphism" or "late binding").
    cVehicle v("Honda", 70);
    cCar c("DadsCar", 30, "Citroen", 100);

    cVehicle* pV;
    pV = &v;
    pV->OutputDetails();    // Calls cVehicle version of the OutputDetails() method.
    pV = &c;
    pV->OutputDetails();    // Calls cCar version of OutputDetails().

    cCar* pC;
    pC = &v;                // Won't compile. Comment this line out so you can run this function and see how it works.
    pC = &c;
    pC->OutputDetails();    // Calls cCar version of OutputDetails().
}

int main()
{
    TestPeople();
    TestAnimals();	// Will crash until it is implemented properly with a copy constructor. See cVehicle for solution.
    TestVehicles();
    TestCars();
    DemonstrateRunTimePolymorphism();
}
