/*
 * field.h
 *
 *  Created on: Mar 1, 2017
 *      Author: andrewerner
 */

#include "ShipBase.h"
#include "Element.h"
#include <vector>
#include <iostream>

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

    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};

}


#endif // FIELD_H_
