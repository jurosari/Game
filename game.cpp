/*
I want to build a video game where you are controlling 2 character in a turn based game.
- The only 2 thing that the user can customize is the type of warrior and name you'll be using
- Each warrior have 3 moves (1 attack, 1 buff (ally) or debuff (enemy) and 1 fusion)
- Fusion combines all stats (Health Points, attack, defense and speed), moves (instead of 2 moves, it will be 4) and their names! (First Half and Second Half)

*/ 

#include <iostream>

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
            std::cout<<"Moves: " << Move1 << " " << Move2 << " " << Move3 << std::endl;  
        }

        void MoveUse1(){ //Mainly the attack towards someone
            std::cout << "You attacked "  << Name << " using" << Move1 << "!" << std::endl;
            std::cout << "It did " << MoveEffect1 << " Damage" << "!" << std::endl;
        }

        void MoveUse2(){ //Mainly a buff towards someone
            std::cout << "You buffed " << Name << " using " << Move1 << "!" << std::endl;
            std::cout << "It added " << MoveEffect1 << " more to what you've selected to buff" << "! (Don't ask me what... you made the move)" << std::endl;

        }

        void MoveUse3(){ //Ultimate move, use polymorphism if the one using is the player (fusion) or Enemy (Another move)
            std::cout << "You used " << Move3 << " to " << Name << "!" << std::endl;
        }

        void Faint(){
            std::cout<< Name << " has fainted!" << std::endl;
        }
};

class Player: public Character{
    public:
        void MoveUse3(){ //FUSION HA
            std::cout << "You Fused with " << Name <<  "!" << std::endl;
        }
        
};

class Fusion: public Player{
    public:
        int MoveEffect4;
};

class Enemy: Character{
    
       
};


int main(){
    //std::string MoveSet
    //std::int Stats
    //std::string Category[2] = ["Warrior", "Mage"]; //I want the player to select one of the 2 or both of the category

    Player P1 = {P1.Name = "Juan", 
        P1.HP = 100, P1.ATK = 25, P1.DEF = 25, 
        P1.Move1 = "Dempsey Roll", P1.Move2 = "Taunt", P1.Move3 = "Fusion", 
        P1.MoveEffect1 = 40, P1.MoveEffect2 = 25,  P1.MoveEffect3 = 0};

    P1.Introduction();
    

    return 0;
}