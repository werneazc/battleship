#include "../../battleship_src/src/crusher.h"

namespace battleship {

/*
 * This sets the size of an crusher within the battle field.
 */
static constexpr unsigned short CRUSHERSHIPSIZE = 3;

//Initialize static class variable for number of ships
unsigned short Crusher::crusher_counter{0};

Crusher::Crusher() : Crusher(("Crusher" + std::to_string(crusher_counter)))
{}

Crusher::Crusher(std::string init_name) : Ship_Base(SHIPCLASS::CRUSHER, CRUSHERSHIPSIZE), shipName(init_name)
{
    crusher_counter++;
}

} // namespace battlefield

