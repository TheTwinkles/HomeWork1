#include "menu.hpp"
#include "rwFunc.hpp"

//#include <iostream>

//using namespace std;
//using std::cout;
//using std::endl;

int main()
{
    setlocale(LC_ALL,"Russian_Russia.1251");

    const int arr_size = 10;
    Building_spec* building = new Building_spec[arr_size];

    //read_file(building);

    return menu(building, arr_size);
}
