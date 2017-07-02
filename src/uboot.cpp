#include "uboot.h"

namespace battleship {

short Uboot::uboot_counter{0};

Uboot::Uboot() : Uboot(("Uboot" + std::to_string(uboot_counter)))
{

}

Uboot::Uboot(std::string init_name) : Ship_Base(SHIPCLASS::UBOOT, 1), name(init_name)
{
    uboot_counter++;
}

}
