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
    std::string name;
    static short battleship_counter;

    //forbidden Ctors
    Battleship(Battleship&& src) = delete;
    Battleship& operator=(Battleship&& src) = delete;

public:
    Battleship();
    Battleship(const Battleship& src) = default;
    Battleship& operator=(const Battleship& src) = default;
    Battleship(std::string name);
    virtual ~Battleship() = default;
};

} /* namespace battleship */

#endif /* BATTLESHIP_SRC_SRC_BATTLESHIP_H_ */
