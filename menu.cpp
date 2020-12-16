#include "menu.hpp"
#include "rwFunc.hpp"

#include <iostream>
#include <windows.h>

using namespace std;

int menu(Building_spec *st, int arr_size)
{
    char n = '\0';
    bool file_open = false;
    while (true)
    {
        system("cls");
        cout << "1) Read File\n2) Write File\n3) Print File\n4) About Program\nq) Exit\n" << endl;
        cin >> n; //выбор пункта меню
        switch (n)
        {
        //вызов функций соответствующих пунктам меню
            case 49: // 49 = "1"
                file_open = read_file(st);
                break;
            case 50: // 50 = "2"
                write_file(st, arr_size);
                break;
            case 51: // 51 = "3"
                print_to_scr(file_open, st, arr_size);
                break;
            case 52: // 52 = "4"
                about();
                break;
            case 113: // 113 = "q"
                exit(EXIT_SUCCESS);
                break;
        default:
            cerr << "Error: command is not defined" << endl;
            break;
        }
    }
    return 0;
}

void print_to_scr(bool file_open, Building_spec *pr_st, int arr_size)
{
    if (!file_open)
    {
        cerr << "Error: file is not open" << endl;
        return;
    }
    for (int i = 0; i < arr_size; i++)
    {
        cout << pr_st[i].s_num << ' ' << pr_st[i].cont_num << ' '
                 << pr_st[i].obj_type << ' ' << pr_st[i].proj_name << ' '
                 << pr_st[i].obj_adr << ' ' << pr_st[i].beg_date << ' '
                 << pr_st[i].end_date << ' ' << pr_st[i].proj_cost << ' '
                 << pr_st[i].mast_fund << ' ' << '\n';
    }
    system("pause");
}

void about()
{
    cout << "Заболотнов Николай Владимирович, ИЭУИС-2-6, Вариант Список объектов строительсва" << endl;
    system("pause");
    return;
}
