#include <iostream>
using namespace std;

void strcpy1(char *destionation, const char *source);

enum GraphicsCard
{
    Integrated,
    Dedicated
};

enum CPU
{
  IntelCorei3,
  IntelCorei9,
  IntelCeleron,
  AMDRyzen5,
  AMDRyzen7
};

enum Cores
{
    Two,
    Four,
    Six,
    Eight
};

enum Brand
{
    Lenovo,
    Hp,
    Dell,
    Asus,
    Apple
};

enum Colour
{
    White,
    Grey,
    Black,
    Blue
};

struct Computer
{
    char brandName[20];
    int batteryCapacity;
    double screenSize;
    char description[30];

    GraphicsCard graphicsCard;
    CPU cpu;
    Cores cores;
    Brand brand;
    Colour colour;

    Computer(const char _brandName[], int _batteryCapacity, double _screenSize, const char _description[])
    {
        strcpy1(brandName, _brandName);
        batteryCapacity = _batteryCapacity;
        screenSize = _screenSize;
        strcpy1(description, _description);
    }

    void printComp()
    {
        cout << brandName << endl;
        cout << batteryCapacity << endl;
        cout << screenSize << endl;
        cout << description << endl;
    }

    void getCPU()
    {
        switch (cpu)
        {
        case IntelCorei3:
            break;
        case IntelCorei9:
            break;
        case IntelCeleron:
            break;
        case AMDRyzen5:
            break;
        case AMDRyzen7:
            break;
        }
    }
};

int main()
{
    Computer* comp;
    Computer myComputer("Lenovo", 5200, 15.6, "Cool");
    myComputer.printComp();
}

void strcpy1(char *destionation, const char *source)
{
    for(int i = 0; source[i] != '\0'; i++)
    {
        destionation[i] = source[i];
    }
}