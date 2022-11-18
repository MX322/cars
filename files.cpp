#include <iostream>
#include "windows.h"
using namespace std;

struct car
{
    char color[10];
    char model[20];
    char number[9];

    void GiveColor()
    {
        cout << "Enter car's color: ";
        cin >> color;
    }


    void GiveModel()
    {
        cout << "Enter car's model: ";
        cin >> model;
    }


    void GiveNumber()
    {
        cout << "Enter car's number: ";
        cin >> number;
    }

    void PrintCar()
    {
        cout << "color of car: " << color << endl;
        cout << "model of car: " << model << endl;
        cout << "number of car: " << number << endl;
    }

};


void ChekNumber(car& structure);
void EditCar(car cars[3]);
void PrintAllCars(car cars[3]);
void SearchCar(car cars[3]);


int main()
{
    car audi{};
    car mercedez{};
    car bmw{};
    car cars[3] = { audi, mercedez, bmw};


    for (int i = 0; i < 3; i++)
    {
        cars[i].GiveColor();
        cars[i].GiveModel();
        cars[i].GiveNumber();

        car& ptr_car = cars[i];
        ChekNumber(ptr_car);

        cout << "\n";
    }

    Sleep(100);
    system("cls");

    EditCar(cars);

    Sleep(1000);
    system("cls");

    PrintAllCars(cars);

    Sleep(1000);
    system("cls");

    SearchCar(cars);
}


void SearchCar(car cars[3])
{
    char numberOfCar[9];
    bool find = false;
    while (!find)
    {
        
        cout << "Enter number of car: ";
        cin >> numberOfCar;

        for (int i = 0; i < 3; i++)
        {
            if (strcmp(numberOfCar, cars[i].number) == 0) 
            {
                cars[i].PrintCar();
                find = true;
            }
        }

        if (!find)
        {
            cout << "Wrong number of car" << endl;
        }
    }
  
}


void PrintAllCars(car cars[3])
{
    for (int i = 0; i < 3; i++)
    {
        cars[i].PrintCar();
        cout << "\n";
    }
}


void EditCar(car cars[3])
{
    int numOfCar;
    cout << "Enter car to edit it ( audi - 1, mercedez - 2, bmw - 3: ";
    cin >> numOfCar;

    numOfCar -= 1;

    cars[numOfCar].GiveColor();
    cars[numOfCar].GiveModel();
    cars[numOfCar].GiveNumber();

    car& ptr_car = cars[numOfCar];
    ChekNumber(ptr_car);
}



void ChekNumber(car& structure)
{
    char numbers[11] = { '1' , '2', '3' , '4', '5' , '6', '7' , '8', '9' , '0' };
    while (true)
    {
        int countOfNumber = 0;

        for (int i = 0; i < strlen(structure.number); i++)
        {

            for (int j = 0; j < strlen(numbers); j++)
            {

                if (structure.number[i] == numbers[j])
                {
                    countOfNumber++;
                }
            }
        }

        if (countOfNumber == strlen(structure.number) && strlen(structure.number) >= 5)
        {
            structure.GiveNumber();
        }

        else
        {
            break;
        }
    }
}