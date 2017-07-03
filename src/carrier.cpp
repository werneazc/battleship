/*
 * carrier.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "carrier.h"

namespace battleship
{

static constexpr unsigned short CARRIERSHIPSIZE = 5;
short Carrier::carrier_counter{0};

Carrier::Carrier() : Carrier(("Carrier" + std::to_string(carrier_counter)))
{

}

Carrier::Carrier(std::string init_name) : Ship_Base(SHIPCLASS::CARRIER, CARRIERSHIPSIZE), name(init_name)
{
    carrier_counter++;
}

} /* namespace battleship */
