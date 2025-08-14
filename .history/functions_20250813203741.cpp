#include <iostream>
#include <type_traits>
#include <string>
#include <limits>
#include <vector>
#include "functions.h"

Player P1;
Player P2;
std::string stat_choice;
int points = 100;
int points_used;
std::string MoveSet;
std::string choose_HP_ATK_or_DEF;

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