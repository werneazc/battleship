/*
 * destroyer.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "destroyer.h"

namespace battleship
{

/*
 * This sets the size of an destroyer within the battle field.
 */
static constexpr unsigned short DESTROYERSHIPSIZE = 2;

//Initialize static class variable for number of ships
unsigned short Destroyer::destroyer_counter{0};

Destroyer::Destroyer() : Destroyer(("Destroyer" + std::to_string(destroyer_counter)))
{}

Destroyer::Destroyer(std::string init_name) : Ship_Base(SHIPCLASS::DESTROYER, DESTROYERSHIPSIZE), shipName(init_name)
{
    destroyer_counter++;
}

} /* namespace battleship */
