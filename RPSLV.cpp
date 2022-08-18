// /////////////////////////////
// RPSLV.cpp
// /////////////////////////////

#include "RPSLV.h"

int main(void)
{
    std::cout << "\n\nWelcome to Rock-Paper-Scissors-Lizard-Spock. \n";

    int p1{-10};

    do
    {
        p1 = storeChoice();

        if(p1 == -10){continue;}

        int cpu = generateChoice();

        int result = compareChoices(p1, cpu);

        printResult(p1, cpu, result);


    } while (p1 != -10);

    std::cout << "\nQuitting... " << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    std::cout << "\nThank you for playing. Goodbye! \n" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
    
}