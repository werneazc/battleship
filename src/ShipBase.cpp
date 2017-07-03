/*
 * ShipBase.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#include "../../battleship_src/src/ShipBase.h"

namespace battleship {

Ship_Base::Ship_Base() : Ship_Base(SHIPCLASS::UBOOT, 1)
{
	// TODO Auto-generated constructor stub
}

Ship_Base::Ship_Base(SHIPCLASS init_class, uint8_t size) :
    shipClass(init_class), shipSize(size), hit_counter(size), startX(0), startY(0), direction(false)
{

}

} /* namespace battleship */
