#ifndef DATABASE_H
#define DATABASE_H

#include "Employee.h"

class database
{
    public:
        database();
        //when using dynamic mem like making arrays bigger,
        // we allocate new mems and delete them
        // thus we need deconstructor here
        ~database();
        //copy constructor(gonna copy the entire Employee
        //use & here cause copying just the addr. is a lot smaller than copying entire class
        database(const database& other);
        void operator = (const database& other);
        void search_name(std::string name);
        void search_id(int id);
        void add(const Employee& emp);
        void display_all;
        void remove_name(std::string name);
        void save(std::ostream& outs);
        void load(std::istream& ins);
        void sort_name();
        void sort_salary();

    protected:

    private:
        void make_bigger();
        int capacity;
        Employee *data;
        int used;
};

#endif // DATABASE_H
