#ifndef MURACH_DIE_H
#define MURACH_DIE_H

#include <string>
#include <iostream>

class Die {
private:
    int value;
    const std::string six = " _____ \n|o   o|\n|o   o|\n|o___o|\n";
    const std::string five = " _____ \n|o   o|\n|  o  |\n|o___o|\n";
    const std::string four = " _____ \n|o   o|\n|     |\n|o___o|\n";
    const std::string three = " _____ \n|o    |\n|  o  |\n|____o|\n";
    const std::string two = " _____ \n|o    |\n|     |\n|____o|\n";
    const std::string one = " _____ \n|     |\n|  o  |\n|____ |\n";
    
    

public:
    Die();
    void roll();
    int get_value() const;
    void set_value(int i);
    std::string get_image(int i);
};

#endif // MURACH_DIE_H
