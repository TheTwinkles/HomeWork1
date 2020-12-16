#include "menu.hpp"
#include "rwFunc.hpp"

#include <iostream>

using namespace std;

void about()
{

    return;
}

int menu(Building_spec *st, int arr_size)
{
    char n = '\0';
    while (true)
    {
        system("cls");
        cout << "1) Read File\n2) Write File\nq) Exit" << endl;
        cin >> n;
        switch (n)
        {
            case 49: // 49 = "1"
                read_file(st);
                break;
            case 50: // 50 = "2"
                write_file(st, arr_size);
                break;
            case 51: // 51 = "3"
                about();
            case 113: // 113 = "q"
                exit(EXIT_SUCCESS);
                break;
        default:
            cerr << "Error: command is not"
                 << "defined in the menu" << endl;
            break;
        }
    }
    return 0;
}
