#include "Player.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include  <chrono>
#include <Windows.h>
#include <thread>

void clearScreen() {
	std::cout << "\033[2J\033[H";
}

void pause(int time) {

	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void write(std::string line)
{
	for (int i=0; i <= line.size(); i++)
	{
		std::cout << line[i];
		pause(50);
	}
}

const char* arrowArt = R"end_art(                                                                                                                  
                                                                                                                  
                                                                                                                  
                                                                                                                  
                                                                                                        ↑↘  ↘     
                                                                                                  →↑↑↑↑↑↑↑        
                                                                               ↑↑↑↑↓↑↑↑↑↑←    ↗↑↑↙       ↑   ↓    
                                                                             ↑↑↑↑↑↑↑↑↑  ↑↑→→↑↗  ↑↑↖    ↑ →↗  ↙    
                                                                           ↑↑↑         ↑ ↑↑↑ ↑            ↑       
                                                                          ↑↑  ↓↑↑↑↑↑ ↑↑↑↑↑↑↑↑  ↑↑        ↙        
                                                                         ↑↑ ↗↑→↑   ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑        ↑↑↓  
                                                                                 ↖ ↑↑↑    ↑↑↑↑↑↑↑↑↑↑↑↑↑↑          
                                                                       ↑↑↑ ↑↑↑  ←  ↑↑↑↑↑         ↑ ↑↑↑↑↑↑↑↘    ↙  
                                                                      ↑↑↑↑↑↑↑↑↑  ↑↑↑↑↑    ↑↑↑↑↑↑↑↑    ↑↑↑↑↑↑  ↗→  
                                                                      ↑↑↑    ↑↑↑↑↑↑↑↑  ↑↑↑↑↑↑↑↑↑↑↑↑     ↗↑↑↑  ↑↗  
                                                                     ↑↑↑ ↑↑ →↑↑ ↑↑↑    ↑↑↑      ↑↑↑↑↗    ↑↑↑↑     
                                                                     ↑↑↑ ↑↑↑ ↑↑↑↑↑    ↙↑↑↑↑↑↑ ↑↑  ↑↑↑↑  ↑↑ ↑↑     
                                                                      ↑↑↑  ↑↑ ↑↑↑       ↑↑ ↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑↑↑      
                                                                     ↑↑↑↑↑↑↑↑↑    ↑↑↑↑↑  ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑      
                                                                   ↙↑↑↑↑ ↑ ↑↑ ↑↑↑↑↑↑↑↑↑↑↑  ↑↑↑↑↑↑↑ ↑↑             
                                                                 ↑↑↑↑↑↑↑↑↑↑↑ ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑      ↑↑↑ ↑↑↑ ↑       
                                                              ↑↑↑↑↑↑↑↑ ↑↑↑  ↑↑↑↑↓     ↑↑ ↖  ↑↑↑↑↑↑↑↑↑ ↗ ↑↘        
                                                         ↑↑↑↑↑↑↑↑↑↑↑↑     ↑↑↑↑      ↑↑↑ ↑↑↑↑↑↑↑↑↑↑↑↑↑   ↑         
                                                 ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑       ↙↑↑↑  ↗↑  ↑↑↑    ↑↑↑ ↑↑ ↑↑↑↑   ↑          
                                    ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑        ↓     ↑↑↑↑↑ ↓↑↑  ↑↑↑↑↑↑↑↑↑↑↑      ↑↘          
                                  ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑             ↑↑   ↖↓  ↑↑  ↑↑ ↑↑↑↑↑↑↑↑↑↑↑↑↑↑ ↘  ↑↑↘           
                                ↑↑↑↑↑↑                          ↙↑↑↑   ↑↑   ↑ ↑↑ ↑↑↑↑↑            ↑↑↑             
                             ↑↑↑↑↑↑↑           ↘                →↑ ↑   ↑↑↑  ↑   ↑↑↑         ↑↑  ↑↑↑↑              
                          ↑↑↑↑↑↑↑↑           ↑↘                  ↑↑↑  ↑↑↑↑↘   ↑↑↑↑        ↑↑  ↑↑↑                 
                        ←↑↑↑↑↑↑            ↙↘        ↙↘              ↑↑↑ ↑↑  ↑↑ ↑↑      ↑↑  ↑↑↑                   
                       ↑↑↑↑↑              ↓                 ↙         ↑↑ ↑↑↑ ↑  ↑↑↑   →↑  ↘↑                      
                      ↑↑↑↑↑            ↑      ↘↗↗↓↑↗↑                 ↑↑↑ ↑↑ ↑↑↑ ↗↑↑ ↑↑  ↑                        
                     ↑↑↑↑               ↑↑↑↑↑↑↑↙←   ↙       ↗↓        ↑↑↑ ↑↑↑↑↑ ↑↑ ↑   ↘                          
                    ↑↑↑↑                                   ↙↙↑↑↑↑↑  ↑↑ ↑↑↑ ↑↑↑↑    ↑↑ ←                           
                    ↑↑↑         ←       ↘↑↑↑↑← ↙↑↑   ↑             ↑↑  ↑↑↑       ↑↑↑                              
                   ↑↑↑→ ↖      ↑                 ↓↑↑↑↑↑           ↑↑  ↑↑↑↑↑  ↑↑↑↑↑                                
                   ↑↑↑↑↑↖   ←  ↑ ↑  ↑↑↑↑↑↑↓           ↑         ←    ↑↑↑↑↗                                        
                  ↑↑↑↑         ↑ ↑      ↘↑↑↑↑↑↑↑     ↓         ←   ↑↑↑↑←↗                                         
                  ↑↑↑↑    ↑ ↗ ↑↑↑↑          ↑↑↑↑↑↑↑↑             ↘↑↑↑↑                                            
                 ↑↑↑↑     ↗ ↑ ↑↑ ↑    →  ↙↓    ↑↑↑↑↑↑↑           ↖↑↑↑↖                                            
                 ↑↑↑          ↖↑↑↑↑      ↖↑↑↑↑↑↑↑ →↑↑↑         ↓→↑↑↑↑↑                                            
                ↑↑↑    ↑        ↑ ↑           ↑↑↑↑↑ ↑↑ ←      ↖↑↑↑↑↑→                                             
                ↑↑↑  ↘ ↑ ↑↖↖    ↑↑↑            ↑↙↑↑ ↑↑       →↑↑↑↑↑↗                                              
               ↑↑↑     ↙         ↑ ↑       ↖   ↑ ↑↑↑↑↑  ↑   ↙↑↑↑↑↑→                                               
               ↑↑↑               ↑ ↑       ↑  ↖↑ ↑↑↑↑↑  ↗  ↑↑↑↑↑←                                                 
               ↑↑↑   ↑     ↙     ↑ ↘↑      ↑       ↑      ↑↑↑↑↑←→                                                 
              ↑↑↑    ↑            ↑ ↑  ↓ ← ↑  ↗   →↑     ↑↑↑↑↑ ↙                                                  
              ↑↑↑                 ↑    ↑ ↗ ↑  ↙↑↑ ↑↑     ↑↑↑↑  ↑                                                  
              ↑↑↑       →      ↘↑←↖↑   ↑↑  ↑↑   ↑↑↑      ↑↑↑  ↑                                                   
              ↑↑↑  ↙ ↖             ←    ↑ ← ↑  ↑ ↑↑     ↑↑↑↑ ↑↑                                                   
             ↙↑↑   ↖                ↙→  ↑→  ↑  ↑ ↑↑     ↑↑↑  ↑↓                                                   
             ↑↑↑   ↘             ↘  ↑ ↑ ↑    ←↑↑↑↑↑ ↓   ↑↑↑  ↑                                                    
            ↑↑↑↑   ↙   ↙        ↑↑↑ ↑    ↑ ↑↗↑↑ ↑↑     ↑↑↑↘↑ ↑                                                    
           ↑↑↑↙←  ↖ ↖           ↑ ↑  ↑ ↑ ↑  ↑↑↑↑↑↑     ↑↑  ↑↑                                                     
          ↑↑↑↑ ↑    ↖ ←         ↑  ↑  ↑↗↑  ↑↑  ↑↑     ↑↑ ↑↖↑↗                                                     
         ↑↑↑↑  ↑  ↑   ↙     ↖↘  ↘↑  ↑ ↑↓↗↑↑↑↑ ↑↑↑    ←↑↑  ↑↑                                                      
        ↑↑↑↑ ↑ ←  ↙   →       ↑↑  ↑  ↗ ↑ ↑↑↑  ↑↑↑    ↑↑  ↑↑↑                                                      
       ↑↑↑↑  ↑↗  ←    ↖            ↑    ↑    ↑↑↑     ↑↑  ↑↑                                                       
       ↑↑↑   ↑↑  ↑ ↓             ↑↑↙↑    ↑   ↑↑↑    ↑↑  ↑↑↑                                                       
       ↑↑↑↑  ↑↖  ↑ ↑→↑↑       ↑↑↑    ↑↑   ↑ ↑↑↑     ↑↑↘ ↑↑                                                        
     ↑↑ ↑↑↑  ↑   ↑    ↖   ↗↑↑↑     ↑↑↑↑↑↑←↑ ↑↑↑    ↑↑  ↑↑ ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↘←←↙↗↑↑↑↑↑↑↑↑↑↑↑↑↓                  
        ↑↑  ↑  ↑ ↑            ↑↑↑↑    ↑↑↑↑↑↑↑↑    ↑↑ ↑ ↑↑ ↖↑↑↗↙↓↗↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↙                     ↙ 
 ↑      ↑↑     ↑  ↖     ↖↑↑↑↑↑↑↑↑↑↑↑→  ↑↑↑↑↑↑↑    ↑ ↑ ↑↑↑                                       ←→↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 
 ↑↑↑↑↑↑↑↑↑↖ ↖ ↑↑ ↓↑   ↓            ↑↑←    →↘↑     ↑ ↑ ↑↑↑                           ↖↓→↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ 

                                                                                                                 
 )end_art";

int main()
{
	HWND console = GetConsoleWindow();
	MoveWindow(console, 1, 1, 1920, 1080, TRUE);
	Player veteran(3.5, 8.0, 6.5);
	Player schizo(0, 5.4, 9.5);
	Player regular(7, 5, 4);
	Player you(0,0,0);
	int playerInput;

	std::cout << "Welcome please use the numbers 1 through 3 to select a class\n";
	std::cout << "1.)  Veteran\n";
	veteran.displayStats();
	std::cout << "2.) Paranoid Schizophrenic\n";
	schizo.displayStats();
	std::cout << "3.) Regular Civilian\n";
	regular.displayStats();
	std::cin >> playerInput;
	std::cin.ignore();

	if (playerInput == 1)
	{
		you.sanity = veteran.sanity;
		you.durability = veteran.durability;
		you.observation = veteran.observation;
		std::cout << "you will be experiencing the story as a veteran with ptsd\n";
	}
	else if (playerInput == 2)
	{
		you.sanity = schizo.sanity;
		you.durability = schizo.durability;
		you.observation = schizo.observation;
		std::cout << "you will be experiencing the story as paranoid schizophrenic\n";
	}
	else
	{
		you.sanity = regular.sanity;
		you.durability = regular.durability;
		you.observation = regular.observation;
		std::cout << "you will be experiencing the story as a regular person\n";
	}
	std::cout << "Press enter to continue\n";
	std::cin.get();
	
	clearScreen();
	write("Knock, ");
	pause(1000);
	write("Knock, ");
	pause(1000);
	write("Knock.... ");
	pause(3000);
	std::cout << "\n";
	write("BANGBANGBANGBANGBANGBANGBANG");

	std::cout << "\n\n\nYou wake up to the sound of banging on your door without knowing if it will stop you decide you need to check what it is\n";
	std::cout << "Do you think you should grab something to defend yourself with in case things go sour?\n";
	std::cout << "1.)  yes\n2.) no\n";
	std::cin >> playerInput;
	std::cin.ignore();
	if (you.sanity == 0)
	{
		write("(Of course you need to find a weapon it's probably them coming to get you)");
		std::cout << "\n\nYou quickly run to the kitchen and find the most wicked knife you have before approaching the door\n";
		you.hasWeapon = true;
	}
	else if (playerInput == 1)
	{
		if (you.sanityCheck(5) == true)
		{
			std::cout << "Don't be paranoid I'm sure it's just someone who needs directions or maybe help with a phone charger or something\n";
			std::cout << "You sluggishly walk to the door groggy and tired eager to just go back to sleep\n";
		}
		else
		{
			std::cout << "Better safe than sorry, you promptly find a knife from the kitchen and approach the door somewhat cautiously\n";
			you.hasWeapon = true;
		}
	}
	else if (playerInput == 2)
	{
		std::cout << "'uggghhh, Better see who this is I'm sure it's just some punk kids ding dong ditching' \n";
	}

	pause(3000);
	std::cout << "As you reach the door you peer out through the peephole\n";
	pause(1000);
	clearScreen();
    std::cout << arrowArt;
	pause(2000/(you.sanity + 1));
	clearScreen();
	write("Thumpthumpthump....");
	std::cout << "\nYour heart is beating a little faster.\n";
	pause(1000);
	std::cout << "You take a second look through the peephole after a second and see nothing\n";
	std::cout << "Did you really see what you thought you did?\n";
	std::cout << "1.) yes\n2.) no\n";
	std::cin >> playerInput;
	std::cin.ignore();
	if ((playerInput == 1) || (you.sanityCheck(4) == false))
	{
		write("'whwhat was that out there?????'");
		pause(500);
		std::cout << "\nstruggling to think you start to believe something terrible is out to get you\n";
		pause(1000);
		if (you.sanity == 0)
		{
			std::cout << "due to already being at 0 sanity you take a hit to your other stats\n";
			you.durability = you.durability - 2;
			you.observation = you.observation - 2;
		}
		else
		{
			std::cout << "not understanding what you saw your sanity has been reduced\n";
			you.sanity--;
		}
		you.displayStats();
		std::cout << "Press enter to continue\n";
		std::cin.get();
		
		write("'I don't know exactly what I saw but it looked vaguely human should I go out and investigate?'");
		std::cout << "\n1.) yes\n2.) no\n";
		std::cin >> playerInput;
		if (playerInput == 1);
		{
			if (you.obserCheck(5) == true)
			{
				write("'Whatever it was, it seemed emaciated and if it tries to fight I'm sure I can kill it");
			}
			std::cout << "\nyou open the door and start to walk outside calling out cautiously to find what direction it may have gone\n";
			write("'Hello, is there somebody there?'");
			pause(1500);
			std::cout << "\nAfter a couple seconds you hear a weak moan coming from the bushes beneath a tree nearby\n";
			write("'unnngghhhhh'");
			std::cout << "\n";
			write("(that doesnt sound like anything inhuman just sounds like someone with no strength left in their body)");
			std::cout << "\nYou decide to approach the bushes and see a pale emaciated man, eyes sunken with a dislocated jaw slumped against the tree\n";
			pause(500);
			std::cout << "His hunched back along with the other features makes him seem almost as a creature that came from hell (and in a way he may have been just that)\n";
			write("'Heeuullp maaee leaasse'");
			std::cout << "\nthe body croaked out, it was evident that this (man) was in incredible pain and could hardly speak correctly due to his dislocated jaw\n";
			if ((you.sanityCheck(3) == false) && (you.hasWeapon == true))
			{
				write("(this could be a trick... this creature is pretending to act weak so that I will lower my guard, maybe I should just kill it now)");
				std::cout << "\n1.) kill it\n2.) move it inside your garage for the night\n";
				std::cin >> playerInput;

				if (playerInput == 1)
				{
					std::cout << "Taking out the knife you grabbed earlier you plunge the blade into the thing's chest\n";
					std::cout << "The sound that followed was one that would haunt you for years, an animalistic gurgling sound, not quite a scream because the thing didn't have\n";
					std::cout << "enough strength left in it for the sound to be much greater than a whimper\n";
					pause(1000);
					std::cout << "you return to your bed and lie awake all night until you hear a knock at your door again in the morning\n";
				}
				else
				{
					std::cout << "Thinking this may just be a man in a terrible situation you lift him up and bring him into your garage and go back inside and stay up trying to think what to do next\n";
					std::cout << "In the morning, you hear another knock on your door\n";
				}
			}
			else
			{
				write("(should I try to help this (man) or should I just leave him out here? His appearance is so uncanny that it's frightening)");
				std::cout << "\n1.) Bring it into the garage\n2.) Leave it out beneath the tree\n";
				std::cin >> playerInput;
				if (playerInput == 1)
				{
					std::cout << "Thinking this may just be a man in a terrible situation you lift him up and bring him into your garage and go back inside and stay up trying to think what to do next\n";
					std::cout << "In the morning, you hear another knock on your door\n";
				}
				else
				{
					std::cout << "You leave the man underneath the tree and return to your bed with some peace of mind knowing what you saw before you are able to get back to sleep after some time\n";
					std::cout << "In the morning, you're woken up by another knock on your door\n";
				}
			
			}
		}
	}
	else if (playerInput == 2)
	{
		write("'n-n-no I'm just seeing things because I'm tired there wasn't anything there'");
		pause(500);
		std::cout << "\nUnfortunately denying what you saw doesn't do anything to help and you aren't likely to get back to sleep tonight\n";
		std::cout << "your sanity is reduced dramaticallly\n";
		you.sanity = you.sanity - 3;
		you.displayStats();
		std::cout << "Press enter to continue\n";
		std::cin.get();
		
		std::cout << "You spend the rest of the night wide awake in bed until you hear a knock at your door in the morning\n";
	}

}