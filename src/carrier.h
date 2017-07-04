/*
 * carrier.h
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#ifndef BATTLESHIP_SRC_SRC_CARRIER_H_
#define BATTLESHIP_SRC_SRC_CARRIER_H_

#include "ShipBase.h"

namespace battleship
{

class Carrier : public Ship_Base
{
private:
    std::string shipName;


    //forbidden Ctors
    Carrier(Carrier&& src) = delete;
    Carrier& operator=(Carrier&& src) = delete;

public:
    //Ctors and Dtor:
    Carrier();
    Carrier(const Carrier& src) = default;
    Carrier& operator=(const Carrier& src) = default;

    /*
     * Name initializes the name of the ship.
     */
    Carrier(std::string name);
    virtual ~Carrier() = default;

    /*
     * This counter counts the number of carriers
     * within the battlefield.
     */
    static unsigned short carrier_counter;


   /*
    * Return the current ship-class as a string.
    */
    virtual inline std::string getShipClass(void) const override
    {
    	return std::string("Carrier");
    }
};

} /* namespace battleship */

#endif /* BATTLESHIP_SRC_SRC_CARRIER_H_ */
