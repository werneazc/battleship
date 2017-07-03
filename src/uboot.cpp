#include "../../battleship_src/src/uboot.h"

namespace battleship {

static constexpr unsigned short UBOOTSHIPSIZE = 3;
short Uboot::uboot_counter{0};

Uboot::Uboot() : Uboot(("Uboot" + std::to_string(uboot_counter)))
{

}

Uboot::Uboot(std::string init_name) : Ship_Base(SHIPCLASS::UBOOT, UBOOTSHIPSIZE), name(init_name)
{
    uboot_counter++;
}

}
