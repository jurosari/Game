#include <iostream>
#include <type_traits>
#include <string>
#include <limits>
#include <vector>

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
        
        

        
        void Introduction(){
            std::cout<<"Name: " << Name << std::endl;
            std::cout<<"HP: " << HP << " ATK: " << ATK << " DEF: " << DEF << std::endl;
            std::cout<<"Moves: " << Move1 << ", " << Move2 << ", and " << Move3 << std::endl;  
        }

        void MoveUse1(){ //Mainly the attack towards someone
            std::cout << Name << " used " << Move1 << "!" << std::endl;
            //std::cout << "It did " << MoveEffect1 << " Damage" << "!" << std::endl;
        }

        void MoveUse2(){ //Mainly a buff towards someone
            std::cout << Name << " buffed his ally using " << Move2 << "!" << std::endl;
            std::cout << "It added " << MoveEffect2 << " more to what you've selected to buff" << "! (Don't ask me what... you made the move)" << std::endl;

        }

        void MoveUse3(){ //Ultimate move, use polymorphism if the one using is the player (fusion) or Enemy (Another move)
            std::cout << Name << " used " << Move3 << "!" << std::endl;
            //std::cout << "It did " << MoveEffect1 << " Damage" << "!" << std::endl;
        }

        //void DamageRecieve1(){
        //    std::cout << "It did " << MoveEffect1 << " Damage" << "!" << std::endl;  
        //}

        void Faint(){
            std::cout<< Name << " has fainted!" << std::endl;
        }
};