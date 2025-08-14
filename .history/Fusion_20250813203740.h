#include <iostream>
#include <type_traits>
#include <string>
#include <limits>
#include <vector>

#ifndef FUSION_H
#define FUSION_H

#include "Character.h"
#include "Player.h"

class Fusion: public Player{
    public:
        std::string Move4;
        int MoveEffect4;

        void Introduction();
};
#endif