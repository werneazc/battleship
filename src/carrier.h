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
    std::string name;


    //forbidden Ctors
    Carrier(Carrier&& src) = delete;
    Carrier& operator=(Carrier&& src) = delete;

public:
    Carrier();
    Carrier(const Carrier& src) = default;
    Carrier& operator=(const Carrier& src) = default;
    Carrier(std::string name);
    virtual ~Carrier() = default;
    static short carrier_counter;

};

} /* namespace battleship */

#endif /* BATTLESHIP_SRC_SRC_CARRIER_H_ */
