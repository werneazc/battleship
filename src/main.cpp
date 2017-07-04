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
    battleship::Field myField(15, 15);
    battleship::Field enemyField(15, 15);

    //create ships and random placement
    std::vector<battleship::Ship_Base*> shipVec;

    shipVec.push_back(new battleship::Destroyer("Destroyer_01"));
    shipVec.push_back(new battleship::Destroyer("Destroyer_02"));
    shipVec.push_back(new battleship::Uboot("Uboot_01"));
    shipVec.push_back(new battleship::Uboot("Uboot_02"));
    shipVec.push_back(new battleship::Crusher("Crusher_01"));
    shipVec.push_back(new battleship::Battleship("Battleship_01"));
    shipVec.push_back(new battleship::Carrier("Carrier_01"));

    // extra scope to delete unused variables after random placement
    {
		auto seed1{std::chrono::system_clock::now().time_since_epoch().count()};

		std::default_random_engine generator(seed1);
		std::uniform_int_distribution<unsigned short> distribution(0,14);
		auto dice{std::bind ( distribution, generator )};


		  unsigned short tempCoordX;
		  unsigned short tempCoordY;
		  unsigned short tempDirection;

		for(unsigned short iter = 0; iter < shipVec.size(); ++iter)
		{
		   bool ready{false};

		   do
			{
			 tempCoordX = dice();
			 tempCoordY = dice();
			 tempDirection = dice();

			 ready = enemyField.initialize_field_with_ship(
				 shipVec[iter],
				 tempCoordX, tempCoordY,
				 (tempDirection >= 10 ? true : false));

			}
		   	while(!ready);
		}

    }


    //Play game
    //=========

    bool win{false};
    unsigned short tempCoordX;
    unsigned short tempCoordY;

    //draw empty Field:
    std::cout << myField << std::endl;

    //Run game until all ships are sunk or user types quit.
    do
    {
		using std::cout;
		using std::cin;
		using std::endl;

		cout << "Please enter coordinates of your draw: " << endl;
		cout << "If you enter \'q\', you quit!" << endl;
		cout << "X coordinate: ";
		cin >> std::dec >> tempCoordX;
		if (!tempCoordX )
		  {
			win = true;
			cout << "###############\n#You quit game!#\n###############" << endl;
			continue;
		  }
		cout << "Y coordinate: ";
		cin >> std::dec >> tempCoordY;
		if (!tempCoordY )
		  {
			win = true;
			cout << "You quit game!" << endl;
			continue;
		  }
		cout << endl;

		if(tempCoordX > enemyField.fieldSizeX || tempCoordY > enemyField.fieldSizeY)
		{
		  cout << "Coordinates are not within the battle field. Please enter new coordinates." << endl;
		  continue;
		}

		win = battleship::Field::fire(--tempCoordX, --tempCoordY, enemyField, myField);

		cout << myField << endl;


    }while(!win);

    // Print latest battle field and the reference field before quit.
    std::cout << myField << std::endl;
    std::cout << enemyField << std::endl;

    std::cout << "END GAME" << std::endl;

    //Erase all used ships before quit application
    for (auto ship : shipVec)
    	delete ship;

    return EXIT_SUCCESS;
}

