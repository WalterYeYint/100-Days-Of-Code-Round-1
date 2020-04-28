#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
    public:
        Employee();
        Employee(std::string new_name,int new_id, std::string new_address, double new_salary, int new_years_worked);
        //don't have to declare getters again in cpp file
        //because they're already declared here
        std::string get_name(){return name;}
        int get_id_number(){return id_number;}
        std::string get_address(){return address;}
        double get_salary(){return salary;}
        int get_years_worked(){return years_worked;}
        void output(std::ostream& outs);
        void input(std::istream& ins);

    protected:

    private:
        std::string name;
        int id_number;
        std::string address;
        double salary;
        int year_worked;
};

std::ostream& operator <<(std::ostream, Employee& emp);
std::istream& operator >>(std::istream, Employee& emp);


#endif // EMPLOYEE_H
