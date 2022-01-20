#include <iostream>
#include <string.h>

using namespace std;

class Person{
private:
    int id;
    char name[21];

public:
    Person(){
        id = 0;
        strcpy(name, "");
    }

public:
    Person(int id, char name[]){
        this->id = id;
        strcpy(this->name,name);
    }

    void setId(int id){
        this -> id = id;
    }
    int getId(){
        return this -> id;
    }
    void setName(char name[]){
        strcpy(this -> name, name);
    }
    char *getName(){
        return this -> name;
    }

    void printData(){
        cout << "ID = " << getId() << endl;
        cout << "Name = " << getName() << endl;
    }
};

class Employee:public Person{
private:
    int salary;

public:
    Employee():Person(){
        this->salary = 0;
    }
public:
    Employee(int salary):Person(0,""){
        this->salary = salary;
    }

    void setSalary(int salary){
        this -> salary = salary;
    }
    int getSalary(){
        return this -> salary;
    }

    void printData(){
        cout << "ID = " << getId() << endl;
        cout << "Name = " << getName() << endl;
        cout << "Salary = " << getSalary() << endl;
    }
};

class Customer:public Person{
private:
    int contactNum;

public:
    Customer():Person(){
        contactNum = 0;
    }
public:
    Customer(int contactNum):Person(0, ""){
        this->contactNum = contactNum;
    }
    void setContactNum(int contactNum){
        this->contactNum = contactNum;
    }
    int getContactNum(){
        return this->contactNum;
    }

    void printData(){
        cout << "ID = " << getId() << endl;
        cout << "Name = " << getName() << endl;
        cout << "Contact Number = " << getContactNum() << endl;
    }
};

int main()
{
    int select;
    cout << "Select What To Use" << endl;
    cout << "1. Employee" << endl;
    cout << "2. Customer" << endl;
    cin >> select;
    if(select == 1){
        int id, salary;
        char name[21];
        cout << "Enter Id: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
        Employee emp(salary);
        emp.setId(id);
        emp.setName(name);
        emp.printData();
    }
    else{
        int id, contactNum;
        char name[21];
        cout << "Enter Id: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Contact Number: ";
        cin >> contactNum;
        Customer cust(contactNum);
        cust.setId(id);
        cust.setName(name);
        cust.printData();
    }


    return 0;
}
