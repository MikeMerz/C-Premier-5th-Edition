#include "14.5.h"

bool operator==(const Book& lhs, const Book& rhs)
{
    return lhs.title == rhs.title && lhs.author == rhs.author;
}

bool operator!=(const Book& lhs, const Book& rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& stream, const Book& obj)
{
    stream << (obj.title + " " + obj.author);
    return stream;
}

std::istream& operator>>(std::istream& stream, Book& obj)
{
    stream >> obj.title >>  obj.author >> obj.publishCompany;
    return stream;
}
