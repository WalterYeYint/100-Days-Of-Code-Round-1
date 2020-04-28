#include <iostream>
#include <fstream>
#include <string>
#include "Employee.h"
#include "database.h"

using namespace std;

int menu();
int main()
{
    database Database
    Employee emp;
    string filename;
    cout << "Enter the name of the file: ";
    getline(cin,filename);
    filename + ".txt";
    ifstream fin(filename.c_str());
    if(!fin.fail()){
        Database.load(fin);
        fin.close();
        while(choice!=8){
            int choice = menu();
            switch(choice){
                case 1:{
                    cin >> emp;
                    Database.add(emp);
                    break;
                }
                case 2:{
                    system("cls");
                    string name;
                    cout << "Enter the employee's name: ";
                    if(cin.peek() == '\n')cin.ignore();
                    getline(cin,name);
                    Database.search(name);
                    break;
                }
                case 3:{
                    system("cls");
                    int id;
                    cout << "Enter id number: ";
                    cin >> id;
                    Database.search_id(id);
                    break;
                }
                case 4:{
                    system("cls");
                    cout << "All the employees in the database!" << endl;
                    Database.display_all();
                    break;
                }
                case 5:{

                }
            }
        }
    }
}


int menu(){
    int choice;
    cout << "1. Add new employee." << endl;
    cout << "2. Search employee by name." << endl;
    cout << "3. Search employee by id." << endl;
    cout << "4. Display all current employees." << endl;
    cout << "5. Remove employee from database." << endl;
    cout << "6. Sort employee by salary (Richest First)." << endl;
    cout << "7. Sort employee by First Name." << endl;
    cout << "8. Quit." << endl;
}
