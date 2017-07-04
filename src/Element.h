/*
 * element.h
 *
 *  Created on: Feb 28, 2017
 *      Author: andrewerner
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <iostream>
#include <utility>

namespace battleship {

#ifndef ELEM_SYMBOLS
#define ELEM_SYMBOLS
enum class SYMBOL : char { WATER='~', SHIP='#', HIT='!', SANK='X', FIRE='?' };
#endif

class Ship_Base;

class Element {
public:
	typedef std::pair<unsigned short, unsigned short> coords_t;

private:
	unsigned short coord_x;		//Element position in horizontal direction
	unsigned short coord_y; 		//Element position in vertical direction
	bool ship_placed; 		//True if ship is placed
	Ship_Base* shipPtr; 	//Ptr to placed ship
	SYMBOL current_symbol; 	//The current drawing symbol of this Element

	//hidden constructors
	Element& operator= (Element&& source) = delete;
	Element( Element&& source) = delete;

public:
	//Constructor
    Element();

    //note: default copy constructor allowed, because pointer allocates no memory.
    Element( const Element& source ) = default;
	Element& operator= (const Element& source) = default;

	//Common Ctors
	Element(uint32_t init_x, uint32_t init_y);
	Element(coords_t coords);
	Element(uint32_t init_x, uint32_t init_y, bool ship_is_placed, Ship_Base* const init_shipPtr);
	Element(coords_t coords, bool ship_is_placed, Ship_Base* const init_shipPtr);

	//Destructor
	~Element() = default;

	//Streaming Operator
	friend std::ostream& operator<<(std::ostream& os , const Element& elem);

	//Access functions
	//================

	/*
	 * Return true if ship is placed and false if Element is not a ship.
	 */
	inline bool is_ship_placed(void) const { return ship_placed; }

	/*
	 * Initialization of ships is after the generation of a field. Therefore, the
	 * pointer to the placed ship has to be set later.
	 * Empty pointers will throw an invalid_argument exception.
	 */
	void setShip(Ship_Base* ship);

	/*
	 * Function will return the pointer to the placed ship.
	 */
	inline Ship_Base* getShip(void) const { return this->shipPtr; }

	/*
	 * There are different stages of a field. It can be WATER,
	 * already under FIRE, a HITed ship or the ship can be sunk.
	 * Therefore, this function will change the symbol if necessary.
	 */
	inline void change_symbol (const SYMBOL sym) { this->current_symbol = sym; }

	/*
	 * This function returns the Element's coordinates.
	 */
    inline coords_t getCoords(void) const { return std::make_pair(coord_x, coord_y); }

    /*
     * This function will change the Elements coordinates.
     */
    inline void setCoordinates(coords_t coords)
    {
        coord_x = coords.first;
        coord_y = coords.second;
    }
    inline void setCoordinates(unsigned short coordX, unsigned short coordY)
    {
    	coord_x = coordX;
    	coord_y = coordY;
    }

};

} /* namespace battleship */

#endif /* ELEMENT_H_ */
