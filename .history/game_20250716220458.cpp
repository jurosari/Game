/*
I want to build a video game where you are controlling 2 character in a turn based game.
- The only 2 thing that the user can customize is the type of warrior and name you'll be using
- Each warrior have 3 moves (1 attack, 1 buff (ally) or debuff (enemy) and 1 fusion)
- Fusion combines all stats (Health Points, attack, defense and speed), moves (instead of 2 moves, it will be 4) and their names! (First Half and Second Half)

*/ 

#include <iostream>
#include <type_traits>
#include <string>
#include <limits>

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

class Player: public Character{
    public:
        void MoveUse3(){ //FUSION HA
            std::cout << "You Fused with you ally!" << std::endl;
        }
        
};

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

class Enemy: Character{
    
       
};

Player P1;
Player P2;
std::string stat_choice;
int points = 100;
int points_used;
std::string MoveSet;
std::string choose_HP_ATK_or_DEF;

void demo_play(){
        while(true){
        if(P1.HP <= 0){
            P1.Faint();
            break;
        }else if (P2.HP <= 0){
            P2.Faint();
            break;
        }else{
            P1.Introduction();
            P1.MoveUse1();
            P2.HP = P2.HP - (P1.MoveEffect1*((float)P1.ATK/100)/((float)P2.DEF/100)); //Formula for damage towards 
            P2.Introduction();
            P2.MoveUse2();
            P2.DEF = P2.DEF + 5;
            P1.Introduction();
            P1.MoveUse2();
            P1.ATK = P1.ATK + 5;
            P2.Introduction();
            P2.MoveUse1();
            P1.HP = P1.HP - (P2.MoveEffect1*((float)P2.ATK/100)/((float)P1.DEF/100));
        }
    }

    
        std::cout << std::endl << "Demo done!" << std::endl;
    }


    void customize_stats(){
        std::cout << "You can customize your character's name, stats, and move from the get-go and see how many bossess you can defeat!" << std::endl << std::endl;
        while(points != 0){
            points_used = 0;
            std::cout << "You have a total of " << points << " points to customize your (1) HP, (2) ATK, and (3) DEF, where do you want to start?" << std::endl;
            std::cin >> stat_choice;
            std::cout << std::endl;
            if(stat_choice == "HP" || stat_choice == "hp" || stat_choice == "1"){
                if(points == 100){
                    std::cout << "How many points points will you be using? Don't put all eggs in one basket!: ";
                    std::cin >> points_used;
                    std::cout << std::endl;
                    if (points_used >= 100 || std::cin.fail()){ //
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Don't do that. You probably forgot how to read." << std::endl;
                    }else{
                        P1.HP += points_used;
                        points -= points_used; 
                    }
                    
                }else{
                    std::cout << std::endl << "How many points are will you be using? ";
                    std::cin >> points_used;
                    if(points_used > points || std::cin.fail()){ //
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "I guess YOU never had a Math Minor lol" << std::endl;
                    }else{
                        P1.HP += points_used;
                        points -= points_used;
                    }
                    
                }
                
            }else if(stat_choice == "ATK" || stat_choice == "atk" || stat_choice == "2"){
                if(points == 100){
                    std::cout << "How many points points will you be using? Don't put all eggs in one basket!: ";
                    std::cin >> points_used;
                    std::cout << std::endl;
                    if (points_used >= 100 || std::cin.fail()){ //
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Don't do that. You probably forgot how to read." << std::endl;
                    }else{
                        P1.ATK += points_used;
                        points -= points_used; 
                    }
                    
                }else{
                    std::cout << std::endl << "How many points are will you be using? ";
                    std::cin >> points_used;
                    if(points_used > points || std::cin.fail()){ //
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "I guess YOU never had a Math Minor lol" << std::endl;
                    }else{
                        P1.ATK += points_used;
                        points -= points_used;
                    }
                    
                }
            }else if(stat_choice == "DEF" || stat_choice == "def" || stat_choice == "3"){
                if(points == 100){
                    std::cout << "How many points points will you be using? Don't put all eggs in one basket!: ";
                    std::cin >> points_used;
                    std::cout << std::endl;
                    if (points_used >= 100 || std::cin.fail()){ //
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Don't do that. You probably forgot how to read." << std::endl;
                    }else{
                        P1.ATK += points_used;
                        points -= points_used; 
                    }
                    
                }else{
                    std::cout << std::endl << "How many points are will you be using? ";
                    std::cin >> points_used;
                    if(points_used > points || std::cin.fail()){ //
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "I guess YOU never had a Math Minor lol" << std::endl;
                    }else{
                        P1.ATK += points_used;
                        points -= points_used;
                    }
                    
                }
            }else{
                std::cout << "Bro really doesn't know how to write LOL!" << std::endl;
            }
        }

        }

    void customize_moves(){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Name your first move (Context: This one is for damaging foes!): ";
        std::getline(std::cin, MoveSet);
        P1.Move1 = MoveSet;
        std::cout << std::endl;
        std::cout << "Name your second move (Context: This one is buff YOUR HP, ATK and/or DEF!): ";
        std::getline(std::cin, MoveSet);
        P1.Move2 = MoveSet;
        
        while(true){
            std::cout << std::endl;
            std::cout << "Would you like this move to buff HP(1), ATK(2) or DEF(3)? ";
            std::cin >> choose_HP_ATK_or_DEF;
            std::cout << std::endl;
            if(choose_HP_ATK_or_DEF == "3"  || choose_HP_ATK_or_DEF == "DEF" || choose_HP_ATK_or_DEF == "def" || choose_HP_ATK_or_DEF == "Def" || choose_HP_ATK_or_DEF == "DEf" || choose_HP_ATK_or_DEF == "dEf" 
        || choose_HP_ATK_or_DEF == "deF" ){
                std::cout << "This move increases DEF by 5" << std::endl;
                break;
            }else if(choose_HP_ATK_or_DEF == "1" || choose_HP_ATK_or_DEF == "HP" || choose_HP_ATK_or_DEF == "hp" || choose_HP_ATK_or_DEF == "Hp"  || choose_HP_ATK_or_DEF == "hP"){
                std::cout << "This move increases HP by 5" << std::endl;
                break;
            }else if(choose_HP_ATK_or_DEF == "2" || choose_HP_ATK_or_DEF == "ATK" || choose_HP_ATK_or_DEF == "atk" || choose_HP_ATK_or_DEF == "Atk" || choose_HP_ATK_or_DEF == "ATk" || choose_HP_ATK_or_DEF == "aTk" 
            || choose_HP_ATK_or_DEF == "aTK"){
                std::cout << "This move increases ATK by 5" << std::endl;
                break;
            }else{
                std::cout << "Imma pretend I didn't see that..." << std::endl;
                
            }
        }
        
        



    }
int main(){
    
    
    
    //std::string MoveSet
    //std::int Stats
    //std::string Category[2] = ["Warrior", "Mage"]; //I want the player to select one of the 2 or both of the category

    
    P1.Name = "Juan";
    P1.HP = 100;
    P1.ATK = 25; 
    P1.DEF = 25;
    P1.Move1 = "Dempsey Roll"; 
    P1.Move2 = "Charge";
    P1.Move3 = "Fusion";    
    P1.MoveEffect1 = 40; 
    P1.MoveEffect2 = 5;  
    P1.MoveEffect3 = 0;

    P1.Introduction();
    P1.MoveUse1();
    P1.MoveUse2();
    P1.MoveUse3();

    
    P2.Name = "Tos";
    P2.HP = 75;
    P2.ATK = 25; 
    P2.DEF = 50;
    P2.Move1 = "Gazelle Punch"; 
    P2.Move2 = "Block";
    P2.Move3 = "Fusion";    
    P2.MoveEffect1 = 40; 
    P2.MoveEffect2 = 5;  
    P2.MoveEffect3 = 0;

    P2.Introduction();
    P2.MoveUse1();
    P2.MoveUse2();
    P2.MoveUse3();
    std::cout << std::endl << std::endl;

    demo_play();
    std::cout << std::endl;

    
    P1.HP = 0;
    P1.ATK = 0; 
    P1.DEF = 0;

    
    P2.HP = 0;
    P2.ATK = 0; 
    P2.DEF = 0;

    std::cout << "Welcome to The Game!" << std::endl;
    customize_stats();
    customize_moves();
    std::cout << std::endl;
    

    P1.Introduction();
    




    
    /*
    for(int i = 10; P1.HP >= 0; P1.HP = P1.HP - i){ //See why its behaving differrent when ==
        if(P1.HP == 0){
            P1.Faint();
        }
        else{
            std::cout << P1.Name << "'s HP = " << P1.HP << std::endl;
        }
    }

    P1.Introduction();
    */
    return 0;
}