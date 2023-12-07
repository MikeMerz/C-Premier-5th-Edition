/* Exercise 7.15: Add appropriate constructors to your Person class.*/

#include <string>
#include <iostream>

struct Person
{
    Person() = default;
    Person(const std::string &name):name(name){}
    Person(const std::string &name, const std::string &address):name(name), address(address){}
    Person(std::istream &is);
    std::string getName() const {return name;}
    std::string getAddress() const {return address;}

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
    out << "The Name is: " << person.name << " " << "Address is: "<<person.address;
    return out;
}
