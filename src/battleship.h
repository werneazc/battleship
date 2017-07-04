/*
 * battleship.h
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#ifndef BATTLESHIP_SRC_SRC_BATTLESHIP_H_
#define BATTLESHIP_SRC_SRC_BATTLESHIP_H_

#include "ShipBase.h"

namespace battleship
{

class Battleship : public Ship_Base
{
private:
    std::string shipName;

    //forbidden Ctors
    Battleship(Battleship&& src) = delete;
    Battleship& operator=(Battleship&& src) = delete;

public:
    //Ctors and Dtor:
    Battleship();
    Battleship(const Battleship& src) = default;
    Battleship& operator=(const Battleship& src) = default;

    /*
     * Name initializes the name of the ship.
     */
    Battleship(std::string name);
    virtual ~Battleship() = default;


    /*
     * This counter counts the number of battleships
     * within the battlefield.
     */
    static unsigned short battleship_counter;

   /*
    * Return the current ship-class as a string.
    */
    virtual inline std::string getShipClass(void) const override
    {
    	return std::string("Battleship");
    }

};

} /* namespace battleship */

#endif /* BATTLESHIP_SRC_SRC_BATTLESHIP_H_ */
