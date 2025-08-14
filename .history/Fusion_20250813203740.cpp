#include <iostream>
#include <type_traits>
#include <string>
#include <limits>
#include <vector>

#include "Character.h"
#include "Player.h"


class Fusion: public Player{
    public:
        std::string Move4;
        int MoveEffect4;

        void Introduction(){
            std::cout<<"Name: " << Name << std::endl;
            std::cout<<"HP: " << HP << " ATK: " << ATK << " DEF: " << DEF << std::endl;
            std::cout<<"Moves: " << Move1 << ", " << Move2 << "," << Move3 << " , and " << Move4 << std::endl;  
        }
};