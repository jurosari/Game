/*
I want to build a video game where you are controlling 2 character in a turn based game.
- The only 2 thing that the user can customize is the type of warrior and name you'll be using
- Each warrior have 3 moves (1 attack, 1 buff (ally) or debuff (enemy) and 1 fusion)
- Fusion combines all stats (Health Points, attack, defense and speed), moves (instead of 2 moves, it will be 4) and their names! (First Half and Second Half)

*/ 

#include <iostream>

class Character{
    public:
        int Name;
        int HP;
        int ATK;
        int DEF;
        //int Stats[2] = [HP,ATK,DEF]; //I want to store the selected variables here, but there's an error
        //std::string Category[2] = ["Warrior", "Mage"]; //I want the player to select one of the 2 or both of the category
        std::string MoveSet[];
        

        
        void Introduction(){
                    
        }

        void MoveUse(){

        }

        void Faint(){

        }
};

class Player{
    public:
        std::string MoveEffect[4];
};

class Enemy{
    public:
        std::string MoveEffect[3];
};


int main(){
    

    return 0;
}