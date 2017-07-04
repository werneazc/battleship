/*
 * uboot.h
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#include <string>

#include "../../battleship_src/src/ShipBase.h"
#ifndef UBOOT_H_
#define UBOOT_H_


namespace battleship {

class Uboot : public Ship_Base
{
private:
    std::string shipName;


    //forbidden Ctors
    Uboot(Uboot&& src) = delete;
    Uboot& operator=(Uboot&& src) = delete;

public:
    //Ctors and Dtor:
    Uboot();
    Uboot(const Uboot& src) = default;
    Uboot& operator=(const Uboot& src) = default;

    /*
     * Name initializes the name of the ship.
     */
    Uboot(std::string name);
    virtual ~Uboot() = default;

    /*
     * This counter counts the number of Uboots
     * within the battlefield.
     */
    static unsigned short uboot_counter;

   /*
    * Return the current ship-class as a string.
    */
    virtual inline std::string getShipClass(void) const override
    {
    	return std::string("Uboot");
    }

};

} // end namespace battleship


#endif
