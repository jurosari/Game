#include <iostream>
#include <type_traits>
#include <string>
#include <limits>
#include <vector>

#include "Character.h"

class Player: public Character{
    public:
        void MoveUse3(){ //FUSION HA
            std::cout << "You Fused with you ally!" << std::endl;
        }
        
};