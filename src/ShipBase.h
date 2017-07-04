/*
 * ShipBase.h
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#ifndef SHIPBASE_H_
#define SHIPBASE_H_

#include <cstdint>
#include <utility>
#include <string>
#include "../../battleship_src/src/Element.h"

namespace battleship {

#ifndef SHIPCLASSES
#define SHIPCLASSES
enum class SHIPCLASS : uint8_t {UNDEFINED, DESTROYER, UBOOT, CRUSHER, BATTLESHIP, CARRIER};
#endif

class Ship_Base {
private:
	SHIPCLASS shipClass; 			//Ship-class of ship
	uint8_t shipSize; 				//Size of ship
	int8_t hit_counter; 			//If 0, ship is sunk
    unsigned short startX, startY;  //Coordinates of start Element
    bool direction; 				//True = vertical, false = horizontal direction

	//forbidden constructors
	Ship_Base(Ship_Base&& source) = delete;
	Ship_Base& operator=(Ship_Base&& source) = delete;


public:
	//Constructor and Destructor
    Ship_Base();
	Ship_Base(const Ship_Base& source) = default;
	Ship_Base& operator=(const Ship_Base& source) = default;

	/*
	 * Common constructor for normal usage. Size initializes
	 * hit_counter and shipSize.
	 * Coordinates and direction are initialized later, because
	 * ships are placed random at the initialization of the game
	 * with Field class function.
	 */
	Ship_Base(SHIPCLASS init_class, uint8_t size);
	virtual ~Ship_Base() = default;

	//Ship Action
	//============
	/*
	 * Return size of the current ship.
	 */
    inline uint8_t getShipsSize(void) const {return shipSize; }

    /*
     * Set direction of a ship within battle field.
     * True = vertical, false = horizontal placement.
     */
    inline void setDirection(const bool direc) { direction = direc; }


   /*
    *	Set coordinates of the start Element of a ship.
    *	Values are not proofed if they are fit to a size of the field.
    *	This has to be done before call of the function.
    */
    inline void setStartCoordinates(const unsigned short coordX, const unsigned short coordY)
    {
        startX = coordX;
        startY = coordY;
    }
    inline void setStartCoordinates(const Element::coords_t& coords)
    {
    	setStartCoordinates(coords.first, coords.second);
    }

    /*
     * Return the coordinates of the start Element of the ship.
     */
    inline Element::coords_t getStartCoordinates() const
    {
        return std::make_pair(startX, startY);
    }

    /*
     * Return the direction of the ship within the battle field.
     * True = vertical, false = horizontal direction.
     */
    inline bool getDirection(void) const {return direction;}

    /*
     * Return true if ship is destroyed.
     */
    inline bool is_ship_destroyed(void) const { return (hit_counter <= 0) ? true : false; }

    /*
     * If ship is hit, return the number of possible hits towards zero.
     */
    inline void shipHit(void) { hit_counter > 0 ? --hit_counter : false; }

    /*
     * Return the current ship-class as a string.
     */
    virtual inline std::string getShipClass(void) const {return std::string("Undefined"); }

};

} /* namespace battleship */

#endif /* SHIPBASE_H_ */
