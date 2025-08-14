#include <iostream>
#include <type_traits>
#include <string>
#include <limits>
#include <vector>

#ifdef CHARACTER_H

#define CHARACTER_H

class Character{
    public:
        std::string Name;
        int HP;
        int ATK;
        int DEF;
        std::string Move1;
        std::string Move2;
        std::string Move3;
        int MoveEffect1;
        int MoveEffect2;
        int MoveEffect3;

        void MoveUse1();
        void MoveUse2();
        void MoveUse3();
        void Faint();
};
#endif