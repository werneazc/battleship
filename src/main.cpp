/*
 * main.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#include <iostream>
#include <cstdlib>
#include "field.h"
#include "uboot.h"
#include "crusher.h"

int main (int argc, char* argv[])
{
    battleship::Field myField(20, 20);

    battleship::Uboot myUboot_01("Uboot_01");
    battleship::Uboot myUboot_02("Uboot_02");
    battleship::Crusher myCrusher_01("Crusher_01");
    battleship::Crusher myCrusher_02("Crusher_02");

    myField.initialize_field_with_ship(&myUboot_01, 0, 0, false);
    myField.initialize_field_with_ship(&myUboot_02, 4, 5, true);
    myField.initialize_field_with_ship(&myCrusher_01, 8, 10, false);
    myField.initialize_field_with_ship(&myCrusher_02, 10, 0, true);


    myField.fire(0, 0);
    myField.fire(10, 0);

    std::cout << myField << std::endl;

	return EXIT_SUCCESS;
}

