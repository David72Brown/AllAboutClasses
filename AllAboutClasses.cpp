#include <iostream>
#include "cPerson.h"
#include "cAnimal.h"
#include "cVehicle.h"
using namespace std;

void TestPeople(void)
{
    cPerson Johnathan("Johnny", 51);
    cPerson Michael;
    cPerson William("Bill", 53);

    Michael = Johnathan;

    cPerson Jill(William);
    Jill.SetInitial('J');

    cout << "Johnathan: ";
    Johnathan.OutputDetails();
    cout << "Michael:   ";
    Michael.OutputDetails();
    cout << "William:   ";
    William.OutputDetails();
    cout << "Jill:      ";
    Jill.OutputDetails();
    cout << endl;
}

void TestAnimals(void)
{
    cAnimal Dog("Rex", 3);
    cAnimal Mouse("Nibbles", 1);
    cAnimal Cat("Catty", 2);

    Mouse = Dog;

    cAnimal Rat(Cat);
    Rat.SetInitial('R');

    cout << "Dog:      ";
    Dog.OutputDetails();
    cout << "Mouse:    ";
    Mouse.OutputDetails();
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

int main()
{
    TestPeople();
    TestAnimals();
    TestVehicles();
}
