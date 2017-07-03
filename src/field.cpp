#include "../../battleship_src/src/field.h"

#include <iomanip>
#include <cstdint>
#include <tuple>

namespace battleship {

Field::Field() : Field(0, 0)
{

}


Field::Field(unsigned short init_sizeX, unsigned short init_sizeY) :
    fieldSizeX(init_sizeX), fieldSizeY(init_sizeY),
    element_vector(init_sizeY, std::vector<Element>(init_sizeX)),
    ships_vector(0)
{
    for (uint32_t row = 0; row < fieldSizeY; ++row )
        for(uint32_t column = 0; column < fieldSizeX; ++column)
            element_vector[row][column].setCoordinates(std::make_tuple(column, row));
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

bool Field::initialize_field_with_ship(Ship_Base* ship, unsigned short coordX, unsigned short coordY, bool direction)
{
    auto shipSize = ship->getShipsSize();

    if(shipSize - 1 + coordX >= fieldSizeX || shipSize - 1 + coordY >= fieldSizeY)
        return false;

    if (direction)
    {
        for (unsigned short column = coordX; column < coordX + shipSize; ++column)
            if (element_vector[coordY][column].is_ship_placed())
                return false;
        for (unsigned short column = coordX; column < coordX+ shipSize; ++column)
            element_vector[coordY][column].setShip(ship);
    }
    else
    {
        for (unsigned short row = coordY; row < coordY + shipSize; ++row)
            if (element_vector[row][coordX].is_ship_placed())
                return false;
        for (unsigned short row = coordY; row < coordY + shipSize; ++row)
            element_vector[row][coordX].setShip(ship);
    }

    ships_vector.push_back(ship);

    return true;
}

bool Field::fire(unsigned short coordX, unsigned short coordY,
		 Field& enemyField, Field& myField)
{
    if (coordX >= enemyField.fieldSizeX || coordY >= enemyField.fieldSizeY)
        return false;

    if(&enemyField == &myField)
      return false;

    auto& tempElemEnemy = enemyField.element_vector[coordY][coordX];
    auto& tempElemSelf = myField.element_vector[coordY][coordX];

    if (tempElemEnemy.is_ship_placed())
    {
        if(tempElemEnemy.getShip()->is_ship_destroyed())
        {
            auto startCoords = tempElemEnemy.getShip()->getStartCoordinates();
            if (tempElemEnemy.getShip()-> getDirection())
            {
                for (auto column = std::get<0>(startCoords);
                        column < std::get<0>(startCoords) + tempElemEnemy.getShip()->getShipsSize();
                        ++column
                    )
                    myField.element_vector[std::get<1>(startCoords)][column].change_symbol(SYMBOL::SANK);
            }
            else
            {
                for (auto row = std::get<1>(startCoords);
                        row < std::get<1>(startCoords) + tempElemEnemy.getShip()->getShipsSize();
                        ++row
                    )
                    myField.element_vector[row][std::get<0>(startCoords)].change_symbol(SYMBOL::SANK);
            }

        }
        else
            tempElemSelf.change_symbol(SYMBOL::HIT);
    }
    else
        tempElemSelf.change_symbol(SYMBOL::FIRE);


    return true;
}

}
