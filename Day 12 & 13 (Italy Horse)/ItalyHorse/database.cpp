#include "database.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
database::database()
{
    //ctor
    used = 0;
    capacity = 5;
    data = new Employee[capacity];
}

database::database(const database& other){
    used = other.used;
    capacity = other.capacity;
    data = new Employee[capacity];
    //copy func from algorithm
    copy(other.data, other.data+used, data);
}

database::~database()
{
    //dtor
    delete []data;
}

void database::operator = (const database& other){
    if(&other == this){
        return;
    }
    delete []data;
    capacity = other.capacity;
    used = other.used;
    data = new Employee[capacity];
    copy(other.data, other.data+used, data);
}
void database::make_bigger(){
    Employee *tmp;
    tmp = new Employee[capacity+5];
    copy(data, data+used, tmp);
    delete []data;
    data = tmp;
    capacity += 5;
}
void database::search_name(string name){
    int num_found = 0;
    for(int i=0; i<used; i++){
        if(data[i].get_name() == name){
            cout << "Employee Found!" << endl;
            data[i].output(cout);
            num_found++;
        }
    }
    if(num_found == 0){
        cout << "No employee by that name!" << endl;
    }
}
void database::search_id(int id){
    int num_found = 0;
    for(int i=0; i<used; i++){
        if(data[i].get_id_number() == id){
            cout << "Employee Found!" << endl;
            data[i].output(cout);
            num_found++;
        }
    }
    if(num_found == 0){
        cout << "No employee by that id!" << endl;
    }
}
void add(const Employee& emp){
    if(used >= capacity){
        make_bigger();
    }
    data[used] = emp;
    used++;
}
void database::display_all(){
    for(int i=0; i<used; i++){
        data[i].output(cout);
    }
}
void database::remove_name(string name){
    for(int i=0; i<used; i++){
        if(data[i].get_name() == name){
            data[i] = data[used-1];
            used--;
        }
    }
}
void database::save(ostream& outs){
    sort_name();
    for(int i=0; i<used; i++){
        outs << data[i];
    }
}
void database::load(istream& ins){
    Employee tmp;
    while(ins >> tmp){
        if(used >= capacity){
            make_bigger();
        }
        data[used] = tmp;
        used++;
    }
}
void sort_name(){
    bool done = false;
    Employee tmp;
    while(!done){
        done = true;
        for(int i=0; i<used-1; i++){
            if(data[i].get_name() > data[i+1].get_name()){
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}
void database::sort_salary(){
bool done = false;
    Employee tmp;
    while(!done){
        done = true;
        for(int i=0; i<used-1; i++){
            if(data[i].get_salary() > data[i+1].get_salary()){
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}




