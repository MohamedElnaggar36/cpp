#include <iostream>
#include <string.h>

using namespace std;

class Employee{
private:
    int id;
    char *name;
    int nameSize;
    int salary;

public:
    Employee (){
        id = 0;
        salary = 0;
        nameSize = strlen(name);
        name = new char(nameSize + 1);
        strcpy(name,"");
        cout << "Default Constructor" << endl;
    }
    Employee(int empId){
        id = empId;
        salary = 0;
        nameSize = strlen(name);
        name = new char(nameSize + 1);
        strcpy(name,"");
        cout << "ID Constructor" << endl;
    }
    Employee(int empId, char *empName){
        id = empId;
        salary = 0;
        nameSize = strlen(empName);
        name = new char[nameSize + 1];
        strcpy(name, empName);
        cout << "ID and Name Constructor" << endl;
    }
    Employee(int empId, int empSalary, char *empName){
        id = empId;
        salary = empSalary;
        nameSize = strlen(empName);
        name = new char[nameSize + 1];
        strcpy(name, empName);
        cout << "General Constructor  " << endl;
    }

    //copy constructor
    Employee (const Employee &emp){
        id = emp.id;
        salary = emp.salary;
        nameSize = emp.nameSize;
        name = new char[nameSize];
        strcpy(name, emp.name);
    }

    Employee operator++(){
        ++id;
        return Employee(id, salary, name);
    }
    Employee operator++(int){
        id++;
        return Employee(id, salary, name);
    }
    Employee operator+(int num){
        Employee temp(id, salary + num, name);
        return temp;
    }
    Employee& operator=(Employee emp){
        id = emp.id;
        salary = emp.salary;
        strcpy(name, emp.name);
        return *this;
    }
    int operator==(Employee emp){
        return(id == emp.id && salary == emp.salary && name[nameSize] == emp.name[nameSize]);
    }
    int operator!=(Employee emp){
        return(id != emp.id && salary != emp.salary && name != emp.name);
    }
    friend Employee operator+(int num, Employee emp);
    ~Employee(){
        id = 0;
        salary = 0;
        delete[] name;
        cout << "Destructor" << endl;
    }
    void setId(int empId){
        this->id = empId;
    }
    int getIdValue(){
        return id;
    }
    void setSalary(int empSalary){
        empSalary = salary;
    }
    int getSalaryValue(){
        return salary;
    }
    void setName(char empName[]){
        strcpy(name, empName);
    }
    char* getNameValue(){
        return name;
    }
};

Employee operator+(int num, Employee emp){
    Employee temp(emp.id,(emp.salary + num), emp.name);
    return temp;
}


int main()
{

    Employee emp1(5, 2000, "Mohamed");
    Employee emp2 = emp1;
    cout << emp1.getIdValue() << endl;
    cout << emp1.getNameValue() << endl;
    cout << emp1.getSalaryValue() << endl;
    Employee emp = emp1++;              //increase id by 1 in emp and emp1
    emp = emp + 500;                    //increase salary by 500 in emp
    emp = 500 + emp;                    //prefix increment
    cout << emp.getIdValue() << endl;
    cout << emp.getNameValue() << endl;
    cout << emp.getSalaryValue() << endl;
    Employee e = emp;
    cout << e.getIdValue() << endl;
    cout << e.getNameValue() << endl;
    cout << e.getSalaryValue() << endl;
    Employee emp3(7, 5000, "Ahmed");    //different object and data
    emp1 = emp3;                        //equal new object data
    cout << emp1.getIdValue() << endl;  //7

    cout << (int)(emp1 == emp) << endl; // returns 0
    cout << (int)(emp1 != emp) << endl; // return 1
    Employee e2(5);
    e2++;
    cout << e2.getIdValue() << endl;


    return 0;
}
