//Exercise 13.18: Define an Employee class that contains an employee name
//and a unique employee identifier. Give the class a default constructor and a
//constructor that takes a string representing the employee’s name. Each
//constructor should generate a unique ID by incrementing a static data
//member.

#include <string>

int static id = 1;
class Employee
{
    public:
    Employee():idEmp(id++){}
    Employee(const std::string& EmployeeName):name(EmployeeName),idEmp(id++){}
    private:
    std::string name;
    int idEmp;

};
