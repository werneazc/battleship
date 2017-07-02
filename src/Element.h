/*
 * element.h
 *
 *  Created on: Feb 28, 2017
 *      Author: andrewerner
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <cstdint>
#include <iostream>

namespace battleship {

#ifndef ELEM_SYMBOLS
#define ELEM_SYMBOLS
enum class SYMBOL : char { WATER='~', SHIP='#', HIT='!', SANK='X', FIRE='?' };
#endif

class Ship_Base;

class Element {
private:
	uint32_t coord_x;
	uint32_t coord_y;
	bool ship_placed;
	Ship_Base* shipPtr;
	SYMBOL current_symbol;

	//hidden constructors
	Element& operator= (Element&& source) = delete;
	Element( Element&& source) = delete;

public:
	//Constructor
    Element();
	Element( const Element& source ) = default;
	Element& operator= (const Element& source) = default;
	Element(uint32_t init_x, uint32_t init_y);
	Element(uint32_t init_x, uint32_t init_y, bool ship_is_placed, Ship_Base* const init_shipPtr);

	//Destructor
	~Element() = default;

	//Streaming Operator
	friend std::ostream& operator<<(std::ostream& os , const Element& elem);

	//Access functions
	inline bool is_ship_placed(void) const { return this->ship_placed; };
	inline Ship_Base* getShip(void) { return this->shipPtr; };
	inline void change_symbol (const SYMBOL sym) { this->current_symbol = sym; };
};

} /* namespace battleship */

#endif /* ELEMENT_H_ */
