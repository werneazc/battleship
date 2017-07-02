#include "field.h"
#include <iomanip>

namespace battleship {

Field::Field() : Field(0, 0)
{

}


Field::Field(unsigned short init_sizeX, unsigned short init_sizeY) :
    fieldSizeX(init_sizeX), fieldSizeY(init_sizeY),
    element_vector(init_sizeY, std::vector<Element>(init_sizeX)),
    ships_vector(0)
{

}

std::ostream& operator<<(std::ostream& os, const Field& field)
{
    using namespace std;

    os << setw(2);
    os << setfill(' ') << ' ';
    for (unsigned short iter = 0; iter < field.fieldSizeX; ++iter)
        os << setw(3) << setfill(' ') << right << iter;
    os << endl;

    unsigned short lineNumber{0};
    for (auto& line : field.element_vector)
    {
        os << std::setw(2) << setfill(' ') << lineNumber++;
        for (auto& elem : line)
            os <<  setw(3) << setfill(' ') << right << elem;
        os << endl;
    }

    os << setw(2) << setfill('=') <<  '=';
    for (unsigned short iter = 0; iter < field.fieldSizeX; ++iter)
        os << setw(3) << setfill('=') << right <<  "=";
    os << endl;

    return os;
}

}
