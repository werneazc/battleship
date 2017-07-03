/*
 * battleship.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "battleship.h"

namespace battleship
{

static constexpr unsigned short BATTLESHIPSIZE = 4;

short Battleship::battleship_counter{0};

Battleship::Battleship() : Battleship(("Battleship" + std::to_string(battleship_counter)))
{

}

Battleship::Battleship(std::string init_name) : Ship_Base(SHIPCLASS::BATTLESHIP, BATTLESHIPSIZE), name(init_name)
{
  battleship_counter++;
}

} /* namespace battleship */
