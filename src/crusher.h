/*
 * crusher.h
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#include <string>

#include "../../battleship_src/src/ShipBase.h"
#ifndef CRUSHER_H_
#define CRUSHER_H_


namespace battleship {

class Crusher : public Ship_Base
{
private:
    std::string shipName;


    //forbidden Ctors
    Crusher(Crusher&& src) = delete;
    Crusher& operator=(Crusher&& src) = delete;

public:
    //Ctors and Dtor:
    Crusher();
    Crusher(const Crusher& src) = default;
    Crusher& operator=(const Crusher& src) = default;

    /*
     * Name initializes the name of the ship.
     */
    Crusher(std::string name);
    virtual ~Crusher() = default;

    /*
     * This counter counts the number of Uboots
     * within the battlefield.
     */
    static unsigned short crusher_counter;

   /*
    * Return the current ship-class as a string.
    */
    virtual inline std::string getShipClass(void) const override
    {
    	return std::string("Crusher");
    }



};

} // end namespace battleship


#endif

