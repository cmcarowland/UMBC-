#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include "Product.h"

class Media : public Product 
{
protected: 
    std::string format = "";

public:
	Media(std::string name = "", double price = 0.0,  int disc_pct = 0, std::string _format = "") : Product(name, price, disc_pct) 
    {
        format = _format;
    }
};
#endif
