/*
 * destroyer.h
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#ifndef BATTLESHIP_SRC_SRC_DESTROYER_H_
#define BATTLESHIP_SRC_SRC_DESTROYER_H_

#include "ShipBase.h"

namespace battleship
{

class Destroyer : public Ship_Base
{
private:
      std::string name;

      static short destroyer_counter;

      //forbidden Ctors
      Destroyer(Destroyer&& src) = delete;
      Destroyer& operator=(Destroyer&& src) = delete;

public:
      Destroyer();
      Destroyer(const Destroyer& src) = default;
      Destroyer& operator=(const Destroyer& src) = default;
      Destroyer(std::string name);
      virtual ~Destroyer() = default;


};

} /* namespace battleship */

#endif /* BATTLESHIP_SRC_SRC_DESTROYER_H_ */
