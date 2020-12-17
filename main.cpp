#include "menu.hpp"
#include "rwFunc.hpp"

int main()
{
    system("title HomeWork1");
    system("mode con cols=89 lines=27");
    setlocale(LC_ALL,"rus");


    const int arr_size = 10;
    Building_spec* building = new Building_spec[arr_size];

    return menu(building, arr_size);
}
