// Exercise 7.22: Update your Person class to hide its implementation.

#include <string>
#include <iostream>

class Person
{
    friend std::istream &read(std::istream& in, Person& person);

public: //Constructors and members that are part of the API
    Person() = default;
    Person(const std::string &name):name(name){}
    Person(const std::string &name, const std::string &address):name(name), address(address){}
    Person(std::istream &is);
    std::string getName() const {return name;}
    std::string getAddress() const {return address;}
private: //data members that are part of the implemantation and thus are private
    std::string name;
    std::string address;
};

std::istream &read(std::istream& in, Person& person)
{
    in >> person.name >> person.address;
    return in;
}

std::ostream &print(std::ostream& out, Person& person)
{
    out << "The Name is: " << person.getName() << " " << "Address is: "<<person.getAddress();
    return out;
}
