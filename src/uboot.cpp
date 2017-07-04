#include "../../battleship_src/src/uboot.h"


namespace battleship {

/*
 * This sets the size of an Uboot within the battle field.
 */
static constexpr unsigned short UBOOTSHIPSIZE = 3;

//Initialize static class variable for number of ships
unsigned short Uboot::uboot_counter{0};

Uboot::Uboot() : Uboot(("Uboot" + std::to_string(uboot_counter)))
{}

Uboot::Uboot(std::string init_name) : Ship_Base(SHIPCLASS::UBOOT, UBOOTSHIPSIZE), shipName(init_name)
{
    uboot_counter++;
}

} // End namespace battlefield
