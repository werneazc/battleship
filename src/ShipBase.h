/*
 * ShipBase.h
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#ifndef SHIPBASE_H_
#define SHIPBASE_H_

#include "Element.h"

namespace battleship {

#ifndef SHIPCLASSES
#define SHIPCLASSES
enum class SHIPCLASS : uint8_t {UBOOT, CRUSHER};

class Ship_Base {
private:
	const SHIPCLASS shipClass;
	Element* const start_elem, end_elem;
	const uint8_t shipSize;
	int8_t hit_counter;

	//forbidden constructors
	Ship_Base() = delete;
	Ship_Base(const Ship_Base& source) = delete;
	Ship_Base& operator=(const Ship_Base& source) = delete;
	Ship_Base(Ship_Base&& source) = delete;
	Ship_Base& operator=(Ship_Base&& source) = delete;

	//helper functions
	inline bool is_ship_destroyed(void) { return (--hit_counter <= 0) ? true : false; }

public:
	//Constructor and Destructor
	Ship_Base(SHIPCLASS init_class, Element* const init_start, Element* const init_end, uint8_t size);
	virtual ~Ship_Base() = default;

	//Getter and Setter
	Element* const getStartElement(void) const;
	Element* const getEndElement(void) const;

	//Ship Action
	void fireAtShip(Element* const elem) const;

};

} /* namespace battleship */

#endif /* SHIPBASE_H_ */
