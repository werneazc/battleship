/*
 * destroyer.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "destroyer.h"

namespace battleship
{

  short Destroyer::destroyer_counter{0};

  Destroyer::Destroyer() : Destroyer(("Destroyer" + std::to_string(destroyer_counter)))
  {

  }

  Destroyer::Destroyer(std::string init_name) : Ship_Base(SHIPCLASS::DESTROYER, 2), name(init_name)
  {
      destroyer_counter++;
  }

} /* namespace battleship */
