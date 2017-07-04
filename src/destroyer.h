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
      std::string shipName;


      //forbidden Ctors
      Destroyer(Destroyer&& src) = delete;
      Destroyer& operator=(Destroyer&& src) = delete;

public:
    //Ctors and Dtor:
      Destroyer();
      Destroyer(const Destroyer& src) = default;
      Destroyer& operator=(const Destroyer& src) = default;

    /*
     * Name initializes the name of the ship.
     */
      Destroyer(std::string name);
      virtual ~Destroyer() = default;

    /*
     * This counter counts the number of destroyers
     * within the battlefield.
     */
      static unsigned short destroyer_counter;

	/*
	* Return the current ship-class as a string.
	*/
	virtual inline std::string getShipClass(void) const override
	{
		return std::string("Destroyer");
	}


};

} /* namespace battleship */

#endif /* BATTLESHIP_SRC_SRC_DESTROYER_H_ */
