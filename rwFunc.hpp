#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <string>

//структура для хранения данных из building.db
struct Building_spec
{
    int s_num;
    std::string cont_num;
    std::string obj_type;
    std::string proj_name;
    std::string obj_adr;
    std::string beg_date;
    std::string end_date;
    int proj_cost;
    int mast_fund;
};

bool read_file(Building_spec* st); //прототип функции чтения данных из файла
void write_file(Building_spec* st, int size); //прототип функции записи данных в файл

#endif // RWFUNC_HPP
