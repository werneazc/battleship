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


    std::cout << myField << std::endl;

	return EXIT_SUCCESS;
}

