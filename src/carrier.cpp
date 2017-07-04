/*
 * carrier.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "carrier.h"

namespace battleship
{

/*
 * This sets the size of an carrier within the battle field.
 */
static constexpr unsigned short CARRIERSHIPSIZE = 5;

//Initialize static class variable for number of ships
unsigned short Carrier::carrier_counter{0};

Carrier::Carrier() : Carrier(("Carrier" + std::to_string(carrier_counter)))
{}

Carrier::Carrier(std::string init_name) : Ship_Base(SHIPCLASS::CARRIER, CARRIERSHIPSIZE), shipName(init_name)
{
    carrier_counter++;
}

} /* namespace battleship */
