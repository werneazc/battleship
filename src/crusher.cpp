#include "../../battleship_src/src/crusher.h"

namespace battleship {

static constexpr unsigned short CRUSHERSHIPSIZE = 3;
short Crusher::crusher_counter{0};

Crusher::Crusher() : Crusher(("Crusher" + std::to_string(crusher_counter)))
{

}

Crusher::Crusher(std::string init_name) : Ship_Base(SHIPCLASS::CRUSHER, CRUSHERSHIPSIZE), name(init_name)
{
    crusher_counter++;
}

}

