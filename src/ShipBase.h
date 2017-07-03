/*
 * ShipBase.h
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#ifndef SHIPBASE_H_
#define SHIPBASE_H_

#include <cstdint>
#include <tuple>


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
    unsigned short startX, startY;
    bool direction;

	//forbidden constructors
	Ship_Base(Ship_Base&& source) = delete;
	Ship_Base& operator=(Ship_Base&& source) = delete;


public:
	//Constructor and Destructor
    Ship_Base();
	Ship_Base(const Ship_Base& source) = default;
	Ship_Base& operator=(const Ship_Base& source) = default;
	Ship_Base(SHIPCLASS init_class, uint8_t size);
	virtual ~Ship_Base() = default;

	//Ship Action
    inline uint8_t getShipsSize(void) {return shipSize; }
    inline void setDirection(const bool direc) { direction = direc; }
    inline void setStartCoordinates(const unsigned short coordX, const unsigned short coordY)
    {
        startX = coordX;
        startY = coordY;
    }
    inline std::tuple<unsigned short, unsigned short> getStartCoordinates() const
    {
        return std::make_tuple(startX, startY);
    }
    inline bool getDirection(void) const {return direction;}
    inline bool is_ship_destroyed(void) { return (--hit_counter <= 0) ? true : false; }

};

} /* namespace battleship */

#endif /* SHIPBASE_H_ */
