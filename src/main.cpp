/*
 * main.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#include <iostream>
#include <cstdlib>
#include <random>
#include <functional>
#include <chrono>

#include "../../battleship_src/src/crusher.h"
#include "../../battleship_src/src/field.h"
#include "../../battleship_src/src/uboot.h"
#include "../../battleship_src/src/destroyer.h"
#include "../../battleship_src/src/battleship.h"
#include "../../battleship_src/src/carrier.h"

int main (int argc, char* argv[])
{
    //create battle fields
    battleship::Field myField(20, 20);
    battleship::Field enemyField(20, 20);

    //create ships
    battleship::Destroyer myDestroyer_01("Destroyer_01");
    battleship::Destroyer myDestroyer_02("Destroyer_02");
    battleship::Carrier myCarrier_01("Carrier_01");
    battleship::Uboot myUboot_01("Uboot_01");
    battleship::Uboot myUboot_02("Uboot_02");
    battleship::Battleship myBattleShip_01("Battleship_01");
    battleship::Crusher myCrusher_01("Crusher_01");

    //random place ships
    {
      unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();

      std::default_random_engine generator(seed1);
      std::uniform_int_distribution<unsigned short> distribution(0,19);
      auto dice = std::bind ( distribution, generator );

      std::vector<battleship::Ship_Base*> tempVector;
      tempVector.push_back(&myDestroyer_01);
      tempVector.push_back(&myDestroyer_02);
      tempVector.push_back(&myUboot_01);
      tempVector.push_back(&myUboot_02);
      tempVector.push_back(&myCrusher_01);
      tempVector.push_back(&myBattleShip_01);
      tempVector.push_back(&myCarrier_01);


      unsigned short tempCoordX;
      unsigned short tempCoordY;
      unsigned short tempDirection;

      for(unsigned short iter = 0; iter < tempVector.size(); ++iter)
	{
	   bool ready = false;
	   do
	     {
		 tempCoordX = dice();
		 tempCoordY = dice();
		 tempDirection = dice();

		 ready = enemyField.initialize_field_with_ship(
		     tempVector[iter],
		     tempCoordX, tempCoordY,
		     (tempDirection >= 10 ? true : false));

	     }
	   while(!ready);
	}

    }

    // play
    battleship::Field::fire(0, 0, enemyField, myField);
    battleship::Field::fire(10, 0, enemyField, myField);

    std::cout << myField << std::endl;
    std::cout << enemyField << std::endl;

    return EXIT_SUCCESS;
}

