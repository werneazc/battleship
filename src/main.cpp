/*
 * main.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#include <iostream>
#include <cstdlib>

#include "../../battleship_src/src/crusher.h"
#include "../../battleship_src/src/field.h"
#include "../../battleship_src/src/uboot.h"
#include "../../battleship_src/src/destroyer.h"
#include "../../battleship_src/src/battleship.h"

int main (int argc, char* argv[])
{
    battleship::Field myField(20, 20);
    battleship::Field enemyField(20,20);

    battleship::Destroyer myDestroyer_01("Destroyer_01");
    battleship::Uboot myUboot_01("Uboot_01");
    battleship::Battleship myBattleShip_01("Battleship_01");
    battleship::Crusher myCrusher_01("Crusher_01");

    enemyField.initialize_field_with_ship(&myUboot_01, 0, 0, false);
    enemyField.initialize_field_with_ship(&myDestroyer_01, 4, 5, true);
    enemyField.initialize_field_with_ship(&myBattleShip_01, 8, 10, false);
    enemyField.initialize_field_with_ship(&myCrusher_01, 10, 0, true);


    battleship::Field::fire(0, 0, enemyField, myField);
    battleship::Field::fire(10, 0, enemyField, myField);

    std::cout << myField << std::endl;
    std::cout << enemyField << std::endl;

	return EXIT_SUCCESS;
}

