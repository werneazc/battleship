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
    std::string name;

    static short crusher_counter;

    //forbidden Ctors
    Crusher(Crusher&& src) = delete;
    Crusher& operator=(Crusher&& src) = delete;

public:
    Crusher();
    Crusher(const Crusher& src) = default;
    Crusher& operator=(const Crusher& src) = default;
    Crusher(std::string name);
    virtual ~Crusher() = default;


};

} // end namespace battleship


#endif

