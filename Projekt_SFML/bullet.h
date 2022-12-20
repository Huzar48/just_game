#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"

class Bullet: public Beeing
{
public:
    Bullet(){};
    Bullet(std::string name, std::string tex);
    void  update();
    
};

