#include <iostream>
#include <type_traits>
#include <string>
#include <limits>
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H   

#include "Character.h"
class Player: public Character{
    public:
        void MoveUse3();
};
#endif