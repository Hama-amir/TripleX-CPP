#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
// Introducing what is going on to the user by printing a welcome message to the Terminal
    std::cout << std::endl;
    std::cout << "\nYou're breaking into a level " << Difficulty;
    std::cout << " secure server system . . .\n\nYou need to enter the correct codes to continue . . . \n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    // Declaring 3 Number codes
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
    
    // Print CodeSum and CodeProduct to the terminal
    std::cout << " + There are 3 numbers in the code";
    std::cout << "\n + The codes add up to: " << CodeSum;
    std::cout << "\n + The codes multiply to give: " << CodeProduct << std::endl;

    //store player code
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if player code is correct
    if(GuessProduct==CodeProduct && GuessSum==CodeSum)
    {
        std::cout << "\n*** Great! You extreacted a file! You still have another code to break for more files ***";
        return true;
    }
    else
        {
            std::cout << "\n*** An alarm went off!!! Be careful agent, you still have another chance.. QUICK... ***";
        return false;
        }

}

int main()
{
   srand(time(NULL)); // create new random sequence based on time of day

   int LevelDifficulty = 1;
   const int MaxDifficulty = 4;
   
   while (LevelDifficulty <= MaxDifficulty) // loop game until all levels completed
   {
        bool bLevelComplete = PlayGame(LevelDifficulty); 
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the Buffer
        
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
        
   }
   std::cout << "YOU DID IT! You broke into the system!\nGet the info you need and get out\nYOU WIN - MISSION COMPLETE";
   return 0;
}