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
#include <vector>
#include <cmath>

class Character{
    public:
        std::string Name; 
        int HP;
        int ATK;
        int DEF;
        std::string Move1;
        std::string Move2;
        std::string Move3;
        std::string Move4;
        int MoveEffect1;//Its fixed to heroes = 100, Monster = 50 or 25 (?)
        int MoveEffect2; //Fixed: Hero = 5, Monster = 10;
        int MoveEffect2_stat; //This will let us know what stat is being buffed 1 = HP; 2 = ATK; 3 = DEF
        int MoveEffect3;
        int MoveEffect4;
        int fuse_check = 0; //This can used to go through the turns without mentioned the characters that were fused

        
        

        
        void Introduction(){
            std::cout<<"Name: " << Name << std::endl;
            std::cout<<"HP: " << HP << " ATK: " << ATK << " DEF: " << DEF << std::endl;
            std::cout<<"Moves: " << Move1 << ", " << Move2 << ", and " << Move3 << std::endl; 
            //std::cout<<"Move_effect_1: " << MoveEffect1 << " and Move_effect_2: " << MoveEffect2 << " and Move_effect_stats2: " << MoveEffect2_stat << std::endl;
            
        }

        void MoveUse1(Character attacker, Character receiver){ //Mainly the attack towards someone
            std::cout << attacker.Name << " used " << attacker.Move1 << "!" << std::endl;
            int damage = static_cast<int>(std::round(attacker.MoveEffect1 *((float)attacker.ATK/100))) - receiver.DEF;
            std::cout << "It did " << damage << " Damage" << "!" << std::endl;
            receiver.HP -= damage;
            //return damage;
        }

        void MoveUse2(){ //Mainly a buff towards someone
            std::cout << Name << " buffed his ally using " << Move2 << "!" << std::endl;
            if (MoveEffect2_stat == 1){
                std::cout << "It added " << MoveEffect2 << " more to its HP" << std::endl;
                HP+=5;
            } else if (MoveEffect2_stat == 2){
                std::cout << "It added " << MoveEffect2 << " more to its ATK" << std::endl;
                ATK+=5;
            } else{
                std::cout << "It added " << MoveEffect2 << " more to its DEF" << std::endl;
                DEF+=5;
            
            } 
        }

        int MoveUse3(Character attacker, Character receiver){ //Mainly the attack towards someone
            std::cout << attacker.Name << " used " << attacker.Move3 << "!" << std::endl;
            int damage = static_cast<int>(std::round(attacker.MoveEffect3 *((float)attacker.ATK/100))) - receiver.DEF;
            std::cout << "It did " << damage << " Damage" << "!" << std::endl;
            return damage;
        }

        int MoveUse4(Character attacker, Character receiver){ //Mainly the attack towards someone
            std::cout << attacker.Name << " used " << attacker.Move4 << "!" << std::endl;
            int damage = static_cast<int>(std::round(attacker.MoveEffect4 *((float)attacker.ATK/100))) - receiver.DEF;
            std::cout << "It did " << damage << " Damage" << "!" << std::endl;
            return damage;
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


        Player MoveUse3(Player x, Player y){ //FUSION HA
            if (x.fuse_check == 1|| y.fuse_check == 1){
                std::cout << x.Name << " used " << x.Move1 << "!" << std::endl;
                int damage = static_cast<int>(std::round(x.MoveEffect1 *((float)x.ATK/100))) - y.DEF;
                std::cout << "It did " << damage << " Damage" << "!" << std::endl;
                y.HP -= damage;
            }
            
            std::cout << "You Fused with you ally!" << std::endl;

            x.fuse_check = 1;
            y.fuse_check = 1;
            Player Fuse;
            Fuse.Name = "Fusion";
            Fuse.ATK = x.ATK + y.ATK;
            Fuse.DEF = x.DEF + y.DEF;
            Fuse.HP = x.HP + y.HP;
            Fuse.Move1 = x.Move1;
            Fuse.Move2 = x.Move2;
            Fuse.Move3 = y.Move1;
            Fuse.Move4 = y.Move2;
            Fuse.MoveEffect1 = x.MoveEffect1 + y.MoveEffect1;
            Fuse.MoveEffect2 = x.MoveEffect2;
            Fuse.MoveEffect3 = y.MoveEffect1 + x.MoveEffect1;
            Fuse.MoveEffect4 = y.MoveEffect2;

            return Fuse;
        }
        
};
/*
class Fusion: public Player{
    public:
        std::string Move4;
        int MoveEffect4;

        void Introduction(Player Fuse){
            if(fuse_check = 1){
                

            }
            std::cout<<"Name: " << Name << std::endl;
            std::cout<<"HP: " << HP << " ATK: " << ATK << " DEF: " << DEF << std::endl;
            std::cout<<"Moves: " << Move1 << ", " << Move2 << "," << Move3 << " , and " << Move4 << std::endl;  
        }
};
*/

class Enemy: Character{
    
       
};


std::string stat_choice;
int points = 100;
int points_used;
std::string MoveSet;
std::string choose_HP_ATK_or_DEF;

void demo_play(Player P1, Player P2){
        while(true){
        if(P1.HP <= 0){
            P1.Faint();
            Player Fuse = P2.MoveUse3(P2,P1);
            Fuse.Introduction();
            break;
        }else if (P2.HP <= 0){
            P2.Faint();
            Player Fuse = P1.MoveUse3(P1,P2);
            Fuse.Introduction();
            break;
        }else{
            P1.Introduction();
            int damage_1 = P1.MoveUse1(P1,P2);
            P2.HP = P2.HP - damage_1; //Formula for damage towards
            P2.Introduction();
            P2.MoveUse2();
            
            P1.Introduction();
            P1.MoveUse2();
            
            P2.Introduction();
            int damage_2 = P2.MoveUse1(P2,P1);
            P1.HP = P1.HP - damage_2;
            
        }
    }

    
        std::cout << std::endl << "Demo done!" << std::endl;
    }


void customize_stats(Player &p){
        std::string name;
        std::cout << "Name your Hero: ";
        while(true){
            if(name.size() == 0){
                std::getline(std::cin, name);
                p.Name = name;
            }else{
                break;
            }      
            }
        
        
        
        
        std::cout << std::endl;
        std::cout << "Customize your character's stats and moves from the get-go and see how many bossess you can defeat!" << std::endl << std::endl;
        while(points != 0){
            std::cout << "HP: " <<  p.HP << " ATK: " << p.ATK << " DEF: " << p.DEF << std::endl;
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
                        p.HP += points_used;
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
                        p.HP += points_used;
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
                        p.ATK += points_used;
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
                        p.ATK += points_used;
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
                        p.ATK += points_used;
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
                        p.ATK += points_used;
                        points -= points_used;
                    }
                    
                }
            }else{
                std::cout << "Bro really doesn't know how to write LOL!" << std::endl;
            }
        }

        }

void customize_moves(Player &p){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Name your first move (Context: This one is for damaging foes!): ";
        std::getline(std::cin, MoveSet);
        p.Move1 = MoveSet;
        std::cout << std::endl;
        std::cout << "Name your second move (Context: This one is to buff YOUR HP, ATK and/or DEF!): ";
        std::getline(std::cin, MoveSet);
        p.Move2 = MoveSet;
        p.Move3 = "Fusion";
        
        while(true){
            std::cout << std::endl;
            std::cout << "Would you like this move to buff HP(1), ATK(2) or DEF(3)? ";
            std::cin >> choose_HP_ATK_or_DEF;
            std::cout << std::endl;
            if(choose_HP_ATK_or_DEF == "3"  || choose_HP_ATK_or_DEF == "DEF" || choose_HP_ATK_or_DEF == "def" || choose_HP_ATK_or_DEF == "Def" || choose_HP_ATK_or_DEF == "DEf" || choose_HP_ATK_or_DEF == "dEf" 
        || choose_HP_ATK_or_DEF == "deF" ){
                std::cout << "This move increases DEF by 5" << std::endl;
                p.MoveEffect2_stat = 3;
                break;
            }else if(choose_HP_ATK_or_DEF == "1" || choose_HP_ATK_or_DEF == "HP" || choose_HP_ATK_or_DEF == "hp" || choose_HP_ATK_or_DEF == "Hp"  || choose_HP_ATK_or_DEF == "hP"){
                std::cout << "This move increases HP by 5" << std::endl;
                p.MoveEffect2_stat = 1;
                break;
            }else if(choose_HP_ATK_or_DEF == "2" || choose_HP_ATK_or_DEF == "ATK" || choose_HP_ATK_or_DEF == "atk" || choose_HP_ATK_or_DEF == "Atk" || choose_HP_ATK_or_DEF == "ATk" || choose_HP_ATK_or_DEF == "aTk" 
            || choose_HP_ATK_or_DEF == "aTK"){
                std::cout << "This move increases ATK by 5" << std::endl;
                p.MoveEffect2_stat = 2;
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


    Player P1;
    Player P2;
    P1.Name = "Juan";
    P1.HP = 100;
    P1.ATK = 25; 
    P1.DEF = 25;
    P1.Move1 = "Dempsey Roll"; 
    P1.Move2 = "Charge";
    P1.Move3 = "Fusion";    
    P1.MoveEffect1 = 500; 
    P1.MoveEffect2 = 5;  
    P1.MoveEffect2_stat = 2;
    //P1.MoveEffect3 = 0;

    //P1.Introduction();
    //P1.MoveUse1();
    //P1.MoveUse2();
    //P1.MoveUse3(); //Fix this, it should return an int

    
    P2.Name = "Tos";
    P2.HP = 75;
    P2.ATK = 25; 
    P2.DEF = 50;
    P2.Move1 = "Gazelle Punch"; 
    P2.Move2 = "Block";
    P2.Move3 = "Fusion";    
    P2.MoveEffect1 = 100; 
    P2.MoveEffect2 = 5;  
    P2.MoveEffect2_stat = 3;
    //P2.MoveEffect3 = 0;

    //P2.Introduction();
    //P2.MoveUse1();
    //P2.MoveUse2();
    //P2.MoveUse3(); //Fix this, it should return an int
    std::cout << std::endl << std::endl;

    demo_play(P1,P2);
    std::cout << std::endl;

    
    

    int num_of_player = 2; //The amount of players
    std::vector<Player> players;
/*
    std::cout << "Welcome to The Game!" << std::endl;
    for (int i = 1; i <= num_of_player; i++){
        points = 100;
        Player temp;
        temp.ATK = 0;
        temp.DEF = 0;
        temp.HP = 0;
        temp.Move3 = "Fusion";
        temp.Name = "Juan";
        
        customize_stats(temp);
        customize_moves(temp);
        if (temp.HP == 100 || temp.ATK == 100 || temp.DEF == 100){ //We can do this as a function


            std::cout << "I feel sorry that you think you outsmarted me." << std::endl;


            std::cout <<"You got 1 point for the left-out attributes, yet you know that you are screwed regardless..." << std::endl;

            

        }
        players.push_back(temp);
        temp.Introduction();
        std::cout << std::endl;    
        }

        for(Player p : players){
            p.Introduction();
        }

    
    




    
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