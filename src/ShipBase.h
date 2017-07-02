/*
 * ShipBase.h
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#ifndef SHIPBASE_H_
#define SHIPBASE_H_

#include <cstdint>


namespace battleship {

#ifndef SHIPCLASSES
#define SHIPCLASSES
enum class SHIPCLASS : uint8_t {UBOOT, CRUSHER};
#endif

class Ship_Base {
private:
	SHIPCLASS shipClass;
	uint8_t shipSize;
	int8_t hit_counter;

	//forbidden constructors
	Ship_Base(Ship_Base&& source) = delete;
	Ship_Base& operator=(Ship_Base&& source) = delete;

	//helper functions
	inline bool is_ship_destroyed(void) { return (--hit_counter <= 0) ? true : false; }

public:
	//Constructor and Destructor
    Ship_Base();
	Ship_Base(const Ship_Base& source) = default;
	Ship_Base& operator=(const Ship_Base& source) = default;
	Ship_Base(SHIPCLASS init_class, uint8_t size);
	virtual ~Ship_Base() = default;

	//Ship Action
	inline void fireAtShip(void) { --hit_counter; }

};

} /* namespace battleship */

#endif /* SHIPBASE_H_ */
