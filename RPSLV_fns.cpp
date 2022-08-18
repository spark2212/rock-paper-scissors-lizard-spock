// ///////////////////
// RPSLV_fns.cpp
// ///////////////////

#include "RPSLV.h"

int storeChoice()
{
    int p1{7};

    std::cout << "Enter ROCK, PAPER, SCISSORS, LIZARD or SPOCK to play, \nRANDOM to choose a random move, \nREVIEW to review the rules, \nRESET to reset the scores, \nor enter QUIT to quit." << std::endl;

    std::string p1s;

    std::cin >> p1s;

    do
    {
        for(int i = 0; i < p1s.size(); i++)
        {
            p1s[i] = toupper(p1s[i]);
        }

        if(getchar() != '\n')
        {
            std::cin >> p1s;

            while(getchar() != '\n');
        }
        
        if(p1s == "ROCK")
            p1 = 0;   
        else if(p1s == "PAPER")
            p1 = 1;
        else if(p1s == "SCISSORS")
            p1 = 2;
        else if(p1s == "LIZARD")
            p1 = 3;
        else if(p1s == "SPOCK")
            p1 = 4;
        else if(p1s == "QUIT")
            p1 = -10;
        else if(p1s == "REVIEW")
            printRules();
        else if(p1s == "RANDOM")
        { 
            srand(std::time(nullptr));
            p1 = rand() % 5;

            std::cout << "Generating..." << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(1300));      
        }
        else if(p1s == "RESET")
        {
            p1 = 8;
        }
        else
        {
            std::cout << "\nError: Invalid Input. " << std::endl;
        
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }
        
        if(p1 == 7)
        {
            std::cout << "Enter ROCK, PAPER, SCISSORS, LIZARD or SPOCK to play, \nRANDOM to choose a random move, \nREVIEW to review the rules, \nRESET to reset the scores, \nor enter QUIT to quit." << std::endl;  
            
            std::cin >> p1s;
        }
       
    }while(p1 == 7);

    return p1;
}

int generateChoice()
{
    srand(std::time(nullptr));

    int cpu = rand() % 5;

    return cpu;
}


int compareChoices(int a, int b)
{
    if(a == 8)
    {
        return 8;
    }
    
    if(a == b)
    {
        return 0;
    }
    else if(a == 0 && (b == 2 || b == 3))
    {
        return 1;
    }
    else if(a == 1 && (b == 0 || b == 4))
    {
        return 1;
    }
    else if(a == 2 && (b == 1 || b == 3))
    {
        return 1;
    }
    else if(a == 3 && (b == 1 || b == 4))
    {
        return 1;
    }
    else if(a == 4 && (b == 0 || b == 2))
    {
        return 1;
    }
    else
    {
        return -1;
    }
    
}

void printStandings(int wins, int losses, int draws, int total)
{
    std::cout << "Wins: " << wins;
    std::cout << "      Losses: " << losses;
    std::cout << "      Draws: " << draws << std::endl;
    std::cout << "Total games played: " << total << "\n\n";

    return;
}

void printResult(int a, int b, int result)
{   
    static int wins, losses, draws, total;

    if(result == 8)
    {
       wins = losses = draws = total = 0;

       std::cout << "\nGame reset. \n " << std::endl;

       std::this_thread::sleep_for(std::chrono::milliseconds(1500));

       printStandings(wins, losses, draws, total);

       return; 
    }
    
    std::string nameA = convertName(a);

    std::string nameB = convertName(b);

    std::string rule[5][5] =
    {{"DRAW", "PAPER covers ROCK.", "ROCK crushes SCISSORS.", "ROCK crushes LIZARD.", "SPOCK vaporizes ROCK."}, 
    {"PAPER covers ROCK.", "DRAW", "SCISSORS cuts PAPER.", "LIZARD eats PAPER.", "PAPER disproves SPOCK."}, 
    {"ROCK crushes SCISSORS.", "SCISSORS cuts PAPER.", "DRAW", "SCISSORS decapitates LIZARD.", "SPOCK smashes SCISSORS."},
    {"ROCK crushes LIZARD.", "LIZARD eats PAPER.", "SCISSORS decapitates LIZARD.", "DRAW", "LIZARD poisons SPOCK."},
    {"SPOCK vaporizes ROCK.", "PAPER disproves SPOCK.", "SPOCK smashes SCISSORS.", "LIZARD poisons SPOCK.", "DRAW"}};
    
    std::cout << "\nYour pick: " << nameA << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "CPU's pick: " << nameB << "\n" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    if(result > 0)
    {
        std::cout << rule[a][b] << "\n" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout << "YOU WIN! \n" << std::endl;
        wins++;
    }
    else if(result < 0)
    {
        std::cout << rule[a][b] << "\n" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout << "YOU LOSE! \n" << std::endl;
        losses++;
    }
    else if(result == 0)
    {
        std::cout << "DRAW! TRY AGAIN. \n" << std::endl;
        draws++;
    }

    total++;

    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    printStandings(wins, losses, draws, total);

    return;
}

void printRules()
{
    using std::string;
    
    std::cout << "\n\nSCISSORS cuts PAPER. \nPAPER covers ROCK. \nROCK crushes LIZARD. \nLIZARD poisons SPOCK. \nSPOCK smashes SCISSORS. \nSCISSORS decapitates LIZARD. \nLIZARD eats PAPER. \nPAPER disproves SPOCK. \nSPOCK vaporizes ROCK. \nROCK crushes SCISSORS. \n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1300));

    return;
}

std::string convertName(int a)
{
        std::string name[5] = {"ROCK", "PAPER", "SCISSORS", "LIZARD", "SPOCK"};

        return name[a];
}