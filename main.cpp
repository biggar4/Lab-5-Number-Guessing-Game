/*
 Ethan Biggar
 Computer Science Fall 2025
 Due Date: 11/11
 Lab 5: Number Guessing Game
 Description: A number guessing game where the computer selects a random number from 0–100. The user has to try and correctly guess the right number. The game will show you your wins and losses after you're done.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void numberGuessingGame();
void winningMessage();
void losingMessage();
void playAgainMessage();
int getRandNum(int min, int max);
int getUserGuess();
bool checkGuess(int userGuess_, int randomNumber_);

// Main program
// Pre Condition: Program starts and random generator is seeded
// Post Condition: Runs the gam until the user chooses to quit
int main() {
    srand(static_cast<unsigned int>(time(0))); // seed random number generator

    // variables needed for the game
    int totalWins = 0;
    int totalLosses = 0;
    int min = 0;
    int max = 100;
    int maxGuesses = 20;
    int randomNumber = getRandNum(min, max);
    int userGuess = 0;
    int attempts = 0;
    bool won = false;
    
// Out puts header for the guessing game
    numberGuessingGame();

//do while loop to run the game, outputs messages, and keeps track of wins and losses. Exits program if letter is entered
    do {
        userGuess = getUserGuess();
        if(userGuess == -1){
            return 2;
        }
        attempts++;
        
        if (checkGuess(userGuess, randomNumber)){
            winningMessage();
            won = true;
            totalWins++;
            cout << "Losses: " << totalLosses << " Wins: " << totalWins << endl;
            break;
        }
        else (losingMessage());{
            totalLosses++;
        }
        
    } while (attempts < maxGuesses);
    if (!won){
        losingMessage();
        cout << "The correct number was: " << randomNumber << endl;
        
        cout << "Losses: " << totalLosses << " Wins: " << totalWins << endl;
    }
// allows user to decide if they want to play again or not without having to exit the code
    playAgainMessage();
    char userInput;
    while (true) {
        cin >> userInput;

        if (userInput == 'Y' || userInput == 'y') {
            main();
            return 0;
        }

        if (userInput == 'N' || userInput == 'n') {
            cout << "Thanks for playing!";
            return 1;
        }

        cout << "Invalid input. Please enter Y or N: ";
    }


    return 0;
}


// Pre condition: none
// Post condition: Displays welcome message and directions for game
void numberGuessingGame() {
    cout << "   Welcome to the Number Guessing Game!\n";
    cout << "   Guess a number between 0 and 100.\n";
    cout << "   You have 20 attempts. Good luck!\n";
}

// Pre condition: Min and max set range
// Post condition: Returns random number between the min and max
int getRandNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Pre condition: User puts in a valid integer
// Post condition: Returns integer value the user puts in whether it's a valid integer or not
// If letter is entered it causes program to exit gracefully
int getUserGuess() {
    int guess;
    cout << "Enter your guess: ";

    if (!(cin >> guess)) {
        cout << "Invalid input. Exiting the program.\n";
        return 3;  //
    }

    while (guess < 0 || guess > 100) {
        cout << "Invalid input please guess a number 0 - 100\n";
        cout << "Enter valid guess: ";

        if (!(cin >> guess)) {
            cout << "Invalid input. Exiting the program.\n";
            return 3;
        }
    }

    return guess;
}


// Checks whether user's guess is correct
// Pre condition: userGuess_ and randomNumber_ are valid integers
// Post condition: Returns true if guess matches randome number and false if not
bool checkGuess(int userGuess_, int randomNumber_) {
    return userGuess_ == randomNumber_;
}

// Displays random winning message
// Pre condition: none
// Post condition: randomly displays one of ten winning messages
void winningMessage() {
    int msgNum = rand() % 10 + 1;
    switch (msgNum) {
        case 1: cout << " Incredible! You nailed it!\n"; break;
        case 2: cout << " You guessed it! Well done!\n"; break;
        case 3: cout << " Winner! Great job!\n"; break;
        case 4: cout << " You’re on fire! Correct guess!\n"; break;
        case 5: cout << " Spot on! That’s the number!\n"; break;
        case 6: cout << " Victory! You got it!\n"; break;
        case 7: cout << " Boom! That’s the right number!\n"; break;
        case 8: cout << " Perfect guess!\n"; break;
        case 9: cout << " You’ve got great intuition!\n"; break;
        case 10: cout << " That’s a win! Nice work!\n"; break;
    }
}

// Displays random losing message
// Pre condition: none
// Post condition: randomly displays one of ten losing messages
void losingMessage() {
    int msgNum = rand() % 10 + 1;
    switch (msgNum) {
        case 1: cout << " Better luck next time!\n"; break;
        case 2: cout << " So close, but not quite!\n"; break;
        case 3: cout << " You’ll get it next time!\n"; break;
        case 4: cout << " The number slipped away this time!\n"; break;
        case 5: cout << " Yikes, tough round!\n"; break;
        case 6: cout << " You weren't even close!\n"; break;
        case 7: cout << " Not your lucky day!\n"; break;
        case 8: cout << " Maybe next time you’ll get it!\n"; break;
        case 9: cout << " The number wins this time!\n"; break;
        case 10: cout <<" So close! No win this round.\n"; break;
    }
}

// Asks the player if they want to play again and displays random play again message
// Pre condition: none
// Post condition: randomly displays one of ten play again messages
void playAgainMessage() {
    int msgNum = rand() % 10 + 1;

    switch (msgNum) {
        case 1: cout << "\nPlay again? (Y/N): "; break;
        case 2: cout << "\nWant to test your luck again? (Y/N): "; break;
        case 3: cout << "\nCare for another round? (Y/N): "; break;
        case 4: cout << "\nFeeling lucky? Try again? (Y/N): "; break;
        case 5: cout << "\nAnother go? (Y/N): "; break;
        case 6: cout << "\nPlay one more game? (Y/N): "; break;
        case 7: cout << "\nGive it another shot? (Y/N): "; break;
        case 8: cout << "\nWant to guess again? (Y/N): "; break;
        case 9: cout << "\nDo you want to play another game? (Y/N): "; break;
        case 10: cout << "\nGo again? (Y/N): "; break;
    }
}
