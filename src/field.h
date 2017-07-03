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
private:
    unsigned short fieldSizeX, fieldSizeY;
    std::vector<std::vector<Element> > element_vector;
    std::vector<Ship_Base*> ships_vector;

public:
    Field();
    Field(unsigned short init_sizeX, unsigned short init_sizeY);
    ~Field() = default;

    bool initialize_field_with_ship(Ship_Base* ships,
            unsigned short coordX, unsigned short coordY, bool direction);

    static bool fire(unsigned short coordX, unsigned short coordY, Field& enemyField, Field& myField);

    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};

}


#endif // FIELD_H_
