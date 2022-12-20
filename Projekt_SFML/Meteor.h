#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"

class Meteor: public Beeing{

public:
    Meteor(std::string, std::string);
    void update();
    
};

