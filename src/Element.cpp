/*
 * element.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: andrewerner
 */

#include "Element.h"

namespace battleship {

Element::Element(uint32_t init_x, uint32_t init_y) : Element(init_x, init_y, false, nullptr)
{
	this->current_symbol = SYMBOL::WATER;
}

Element::Element(uint32_t init_x, uint32_t init_y, bool ship_is_placed, Ship_Base* const init_shipPtr) :
		coord_x(init_x), coord_y(init_y), ship_placed(ship_is_placed), shipPtr(init_shipPtr)
{
	this->current_symbol = SYMBOL::SHIP;
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

} /* namespace battleship */
