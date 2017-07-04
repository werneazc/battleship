/*
 * battleship.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "battleship.h"

namespace battleship
{

/*
 * This sets the size of an battleship within the battle field.
 */
static constexpr unsigned short BATTLESHIPSIZE = 4;

//Initialize static class variable for number of ships
unsigned short Battleship::battleship_counter{0};

Battleship::Battleship() : Battleship(("Battleship" + std::to_string(battleship_counter)))
{}

Battleship::Battleship(std::string init_name) : Ship_Base(SHIPCLASS::BATTLESHIP, BATTLESHIPSIZE), shipName(init_name)
{
  battleship_counter++;
}

} /* namespace battleship */
