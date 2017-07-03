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
    std::string name;


    //forbidden Ctors
    Uboot(Uboot&& src) = delete;
    Uboot& operator=(Uboot&& src) = delete;

public:
    Uboot();
    Uboot(const Uboot& src) = default;
    Uboot& operator=(const Uboot& src) = default;
    Uboot(std::string name);
    virtual ~Uboot() = default;

    static short uboot_counter;

};

} // end namespace battleship


#endif
