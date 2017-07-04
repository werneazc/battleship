/*
 * field.h
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#include <vector>
#include <iostream>
#include "../../battleship_src/src/Element.h"
#include "../../battleship_src/src/ShipBase.h"

#ifndef FIELD_H_
#define FIELD_H_

namespace battleship {

class Field {

public:
	typedef std::vector<std::vector<Element> > element_vector_t;
	typedef std::vector<Ship_Base*> ships_vector_t;
	typedef std::vector<Element> element_line_t;

private:
    element_vector_t element_vector; //Battlefield of Elements
    ships_vector_t ships_vector;	 //Vector of placed ships

public:
    //Public Members:
    unsigned short fieldSizeX, fieldSizeY;

    //Ctors and Dtor
    Field();
    /*
     * Define dimensions of battle field.
     * init_sizeX times init_sizeY Elements will be created.
     */
    Field(unsigned short init_sizeX, unsigned short init_sizeY);
    ~Field() = default;

    /*
     * This will place a ship at the coordinates given by coord X/Y.
     * direction true will place the ship vertically, false will place
     * the ship horizontally.
     */
    bool initialize_field_with_ship(Ship_Base* ships,
            unsigned short coordX, unsigned short coordY, bool direction);
    /*
     * Static function to play a game round.
     * The coordinates define the place of the shoot.
     * enemyField is the reference field with the placed ships, while myField
     * will draw the results of the shoot.
     */
    static bool fire(unsigned short coordX, unsigned short coordY, Field& enemyField, Field& myField);

    /*
     * This will return a referenced row of Elements
     * accessed by lineNumber.
     */
    element_line_t& operator[](const unsigned short lineNumber);

    /*
     * This will return an Element within the battle field.
     */
    Element& operator[](const Element::coords_t coords);

    /*
     * This operation overloading will print out the whole battle field.
     */
    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};

}


#endif // FIELD_H_
