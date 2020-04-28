#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee()
{
    //ctor
    id_number = 0;
    salary = 0;
    years_worked = 0;
}

Employee::Employee(std::string new_name,int new_id, std::string new_address, double new_salary, int new_years_worked){
    name = new_name;
    id_number = new_id;
    address = new_address;
    salary = new_salary;
    year_worked = new_years_worked;
}

void Employee::output(ostream& outs){
    if(outs == cout){
        outs << "Name: " << name << endl;
        outs << "ID number: " << id_number << endl;
        outs << "Address: " << address << endl;
        outs << "Salary: " << salary << endl;
        outs << "Years worked at company: " << year_worked << endl;
    }
    else{
        outs << name << endl;
        outs << id_number << endl;
        outs << address << endl;
        outs << salary << endl;
        outs << year_worked << endl;
    }
}

void Employee::input(istream& ins){
    if(ins == cin){
        if(ins.peek() == '\n')ins.ignore();
        cout << "Name: ";
        getline(ins, name);
        cout << "Enter ID number: ";
        ins >> id_number;
        cout << "Enter address: ";
        if(ins.peek() == '\n')ins.ignore();
        getline(ins, address);
        cout << "Enter salary: ";
        ins >> salary;
        cout << "Enter the number of years the employee has worked for the company: ";
        ins >> year_worked;
    }
    else{
        if(ins.peek() == '\n')ins.ignore();
        getline(ins, name);
        ins >> id_number;
        if(ins.peek() == '\n')ins.ignore();
        getline(ins, address);
        ins >> salary;
        ins >> year_worked;
    }
}

ostream& operator <<(ostream& outs, Employee& emp){
    tmp.output(outs);
    return outs;
}

istream& operator <<(istream& ins, Employee& emp){
    tmp.input(ins);
    return ins;
}

Employee::~Employee()
{
    //dtor
}
