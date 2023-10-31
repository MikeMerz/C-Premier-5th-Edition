//
// Created by Michaelmer on 31/10/2023.
//

#ifndef C__BOOK_PERSON_H
#define C__BOOK_PERSON_H

/*Exercise 7.9: Add operations to read and print Person objects to the code
you wrote for the exercises in § 7.1.2 (p. 260).*/

#include <string>
#include <iostream>

struct Person
{
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


#endif //C__BOOK_PERSON_H
