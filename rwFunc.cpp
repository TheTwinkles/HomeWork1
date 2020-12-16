#include "rwFunc.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//функция чтения данных из файла
bool read_file(Building_spec* st)
{
    fstream in_file("building1251.db", ios_base::in); //открытие файлового потока

    //проверка открытия файла
    if(!in_file.is_open())
    {
        cerr << "Error opening file!" << endl;
        exit(EXIT_FAILURE);
    }

    //заполнение полей структуры парсингом строки
    string in_str; //цельная строка получаемая из файла
    int i = 0; //счетчик для массива структур
    while (!in_file.eof())
    {
        getline(in_file, in_str); //получение строки вида "...;...;...;...;"
        if (in_str.empty()) continue;

        stringstream file_str(in_str); //создание потока строк
        string record; //строка для хранения конкретной записи (;...;)
        const int num_of_rec = 9; //количество записей в цельной строке из файла
        string temp[num_of_rec]; //массив строк для хранения записей полученной парсингом
        int j = 0; //счетчик индекса для массива строк
        while (getline(file_str, record, ';')) //парсинг потока строк, запись в строку record с разделителем ;
        {
            temp[j] = record;
            j++;
        }
        //записи в поля структур
        st[i].s_num = stoi(temp[0]);
        st[i].cont_num = temp[1];
        st[i].obj_type = temp[2];
        st[i].proj_name = temp[3];
        st[i].obj_adr = temp[4];
        st[i].beg_date = temp[5];
        st[i].end_date = temp[6];
        st[i].proj_cost = stoi(temp[7]);
        st[i].mast_fund = stoi(temp[8]);
        i++; //увеличение счетчика для массива структур
    }
    in_file.close();
    return true;
}

//функция сохранения данных в файл
void write_file(Building_spec* st, int size)
{
    fstream out_file("building_output.db", ios::out); //открытие файлового потока

    //проверка открытия файла
    if (!out_file.is_open())
    {
        cerr << "Error opening file!" << endl;
        exit(EXIT_FAILURE);
    }

    //заполнение файла массивом структур
    for (int i = 0; i < size; i++)
    {
        if (i != 9)
            out_file << st[i].s_num << ';' << st[i].cont_num << ';'
                     << st[i].obj_type << ';' << st[i].proj_name << ';'
                     << st[i].obj_adr << ';' << st[i].beg_date << ';'
                     << st[i].end_date << ';' << st[i].proj_cost << ';'
                     << st[i].mast_fund << ';' << '\n';
        else
            out_file << st[i].s_num << ';' << st[i].cont_num << ';'
                     << st[i].obj_type << ';' << st[i].proj_name << ';'
                     << st[i].obj_adr << ';' << st[i].beg_date << ';'
                     << st[i].end_date << ';' << st[i].proj_cost << ';'
                     << st[i].mast_fund << ';';

    }
    out_file.close();
    return;
}
