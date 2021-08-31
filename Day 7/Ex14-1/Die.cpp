#include <cstdlib>
#include <ctime>
#include "Die.h"

Die::Die() {
    srand(time(nullptr));  // seed the rand() function
    value = 1;
}

void Die::roll() {
    value = rand() % 6;    // value is >= 0 and < 6
    ++value;               // value is >= 1 and <= 6
}

int Die::get_value() const {
    return value;
}

void Die::set_value(int _value)
{
	if(value < 1 || value > 6)
	{
		throw std::invalid_argument("Die only have 6 sides!!! Enter number between 1 and 6");
	}
	
	value = _value;
}

std::string Die::get_image(int i)
{
	switch(i)
	{
		case 1:
			return Die::one;
		case 2:
			return Die::two;
		case 3:
			return Die::three;
		case 4:
			return Die::four;
		case 5:
			return Die::five;
		case 6:
			return Die::six;
			
	}
}
