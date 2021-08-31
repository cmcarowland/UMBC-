#ifndef MURACH_ALBUM_H
#define MURACH_ALBUM_H

#include <string>
#include "Media.h"

class Album : public Media 
{
private:
    std::string artist;

public:
    Album(std::string name = "", double price = 0.0, int disc_pct = 0, std::string artist = "", std::string _format = "") : Media(name, price, disc_pct, _format) 
    {
        this->artist = artist;
    }

    std::string get_description() const {
        return name + " by " + " " + artist + " " + format;
    }
};
#endif 
