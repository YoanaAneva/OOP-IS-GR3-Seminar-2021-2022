#include <iostream>
using namespace std;

const int CAPACITY = 40;

enum Brand
{
    Honda,
    Volkswagen,
    Ford,
    BMW
};

enum Fuel
{
    Fuel1,
    Fuel2,
    Fuel3
};

enum CarColour
{
    Red,
    White,
    Black,
    Blue,
    Yellow
};

struct Car
{
    int km;
    int avgFuelBurn;
    char brandName[CAPACITY];
    char description[CAPACITY];

    Brand brand;
};


int main()
{

}