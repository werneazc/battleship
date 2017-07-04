/*
 * element.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: andrewerner
 */

#include "../../battleship_src/src/Element.h"

#include <exception>

namespace battleship {

Element::Element() : Element(0, 0, false, nullptr)
{

}

Element::Element(uint32_t init_x, uint32_t init_y) : Element(init_x, init_y, false, nullptr)
{

}

Element::Element(uint32_t init_x, uint32_t init_y, bool ship_is_placed, Ship_Base* const init_shipPtr) :
		coord_x(init_x), coord_y(init_y), ship_placed(ship_is_placed)
{
    if (ship_is_placed)
    {
        if(!(init_shipPtr == nullptr))
        {
            current_symbol = SYMBOL::SHIP;
            shipPtr = init_shipPtr;
            ship_placed = true;
        }
        else
            throw std::invalid_argument("Element cannot be initialized. No valid pointer to ship.");
    }
    else
        current_symbol=SYMBOL::WATER;
}

std::ostream& operator<<(std::ostream& os, const Element& elem)
{
	switch (elem.current_symbol)
	{
	case SYMBOL::WATER:
		os << '~';
		break;
	case SYMBOL::HIT:
		os << '!';
		break;
	case SYMBOL::FIRE:
		os << '?';
		break;
	case SYMBOL::SANK:
		os << 'X';
		break;
	case SYMBOL::SHIP:
		os << '#';
		break;
	};

	return os;
}

void Element::setShip(Ship_Base* ship)
{
    if(ship != nullptr)
    {
        shipPtr = ship;
        change_symbol(SYMBOL::SHIP);
        ship_placed = true;
    }
    else
        throw std::invalid_argument("Ship Pointer is empty.");
}


} /* namespace battleship */
