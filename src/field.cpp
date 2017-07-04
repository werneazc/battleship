#include "../../battleship_src/src/field.h"

#include <iomanip>
#include <cstdint>
#include <utility>
#include <exception>

namespace battleship {

Field::Field() : Field(0, 0)
{}


Field::Field(unsigned short init_sizeX, unsigned short init_sizeY) :
    element_vector(init_sizeY, Field::element_line_t(init_sizeX)),
    ships_vector(0),
    fieldSizeX(init_sizeX), fieldSizeY(init_sizeY)
{

	Element::coords_t tempCoords;

	for (uint32_t row = 0; row < fieldSizeY; ++row )
        for(uint32_t column = 0; column < fieldSizeX; ++column)
        {
        	tempCoords = std::make_pair(column, row);
        	this->operator [](tempCoords).setCoordinates(std::make_pair(column, row));
        }

}


Field::element_line_t& Field::operator[](const unsigned short lineNumber)
{
	return element_vector.at(lineNumber);
}

Element& Field::operator[](const Element::coords_t coords)
{
	return element_vector[coords.second][coords.first];
}


std::ostream& operator<<(std::ostream& os, const Field& field)
{
    using namespace std;

    os << setw(2);
    os << setfill(' ') << ' ';
    for (unsigned short iter = 0; iter < field.fieldSizeX; ++iter)
        os << setw(3) << setfill(' ') << right << iter + 1;
    os << endl;

    unsigned short lineNumber{0};
    for (auto& line : field.element_vector)
    {
        os << std::setw(2) << setfill(' ') << ++lineNumber;
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

    /*
     * Check if start position within battle field and ship size crosses field borders.
     */
    if(shipSize - 1 + coordX >= fieldSizeX || shipSize - 1 + coordY >= fieldSizeY)
        return false;

    /*
     * If direction is true, ship is placed vertically, otherwise horizontally.
     */
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

    /*
     * Save direction and start position within ship object.
     */
    ship->setStartCoordinates(coordX, coordY);
    ship->setDirection(direction);

    /*
     * Save pointers to ships within field.
     */
    ships_vector.push_back(ship);

    return true;
}

bool Field::fire(unsigned short coordX, unsigned short coordY,
		 Field& enemyField, Field& myField)
{

	/*
	 * Check that coordinates fit into battle field borderline
	 */
    if (coordX >= enemyField.fieldSizeX || coordY >= enemyField.fieldSizeY)
      throw std::invalid_argument(std::string(__FILE__) + ":" + std::to_string( __LINE__) + " :Coordinates cross borders.");

    /*
     * Check that used fields are not identically: enemyField is reference and myField is drawn.
     */
    if(&enemyField == &myField)
      throw std::invalid_argument(std::string(__FILE__) + ":" + std::to_string( __LINE__) + " :Enemy-field and drawing field are the same.");

    // Get field Elements from coordinates parameters
    auto& tempElemEnemy = enemyField.element_vector[coordY][coordX];
    auto& tempElemSelf = myField.element_vector[coordY][coordX];

    /*
     * First check that a ship is placed.
     * Afterwards check if ship is destroyed.
     * Then draw or refresh all necessary Elements.
     */
    if (tempElemEnemy.is_ship_placed())
    {

    	tempElemEnemy.getShip()->shipHit();

        if(tempElemEnemy.getShip()->is_ship_destroyed())
        {
            auto startCoords = tempElemEnemy.getShip()->getStartCoordinates();
            if (tempElemEnemy.getShip()-> getDirection())
            {
                for (auto column = startCoords.first;
                        column < startCoords.first + tempElemEnemy.getShip()->getShipsSize();
                        ++column
                    )
                    myField.element_vector[startCoords.second][column].change_symbol(SYMBOL::SANK);
            }
            else
            {
                for (auto row = startCoords.second;
                        row < startCoords.second + tempElemEnemy.getShip()->getShipsSize();
                        ++row
                    )
                    myField.element_vector[row][startCoords.first].change_symbol(SYMBOL::SANK);
            }

            std::cout << "############\n#Ship sank!#\n############" << std::endl;

        }
        else
        {
            tempElemSelf.change_symbol(SYMBOL::HIT);
            std::cout << "#################\n#You hit a ship!#\n#################" << std::endl;
        }

        /*
         * Check if all ships are sunk.
         */
        for (auto ship : enemyField.ships_vector)
			if(!ship->is_ship_destroyed())
				return false;

        // You win!
        return true;
    }
    else
        tempElemSelf.change_symbol(SYMBOL::FIRE);


    return false;
}

}
