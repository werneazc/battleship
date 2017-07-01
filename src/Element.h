/*
 * element.h
 *
 *  Created on: Feb 28, 2017
 *      Author: andrewerner
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <cstdint>
#include "ShipBase.h"
#include <iostream>

namespace battleship {

#ifndef ELEM_SYMBOLS
#define ELEM_SYMBOLS
enum class SYMBOL : char { WATER='~', SHIP='#', HIT='!', SANK='X', FIRE='?' };
#endif

class Element {
private:
	const uint32_t coord_x;
	const uint32_t coord_y;
	const bool ship_placed;
	Ship_Base* const shipPtr;
	SYMBOL current_symbol;
	
	//hidden constructors
	Element() = delete;
	Element( const Element& source ) = delete;
	Element& operator= (const Element& source) = delete;
	Element& operator= (Element&& source) = delete;
	Element( Element&& source) = delete;

public:
	//Constructor
	Element(uint32_t init_x, uint32_t init_y);
	Element(uint32_t init_x, uint32_t init_y, bool ship_is_placed, Ship_Base* const init_shipPtr);

	//Destructor
	~Element() = default;

	//Streaming Operator
	friend std::ostream& operator<<(std::ostream& os , const Element& elem);

	//Access functions
	inline bool is_ship_placed(void) const { return this->ship_placed; };
	inline Ship_Base* const getShip(void) { return shipPtr; };
	inline void change_symbol (const SYMBOL sym) { this->current_symbol = sym; };
};

} /* namespace battleship */

#endif /* ELEMENT_H_ */
