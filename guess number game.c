#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int first_play = 1; // used for first play in new screen

void playGame();
int getRandomNumber(int lower, int upper);
void printInstructions();
void playAgain();
void setColor(int color);

int main() {
    srand(time(0)); // Seed for random number generation
    printInstructions();
    playGame();
    return 0;
}

void printInstructions() {
    setColor(10);
    printf("Welcome to the Number Guessing Game!\n");
    printf("I will pick a random number between 1 and 100.\n");
    printf("Your job is to guess it. After each guess,\n I'll tell you if your guess was too high or too low.\n");
    printf("Let's get started! Press any key to continue.");
    getch(); // Wait for user to press a key
}

void playGame() {
    int number = getRandomNumber(1, 100);
    int guess;
    int attempts = 0;

    if (first_play == 1) {
        system("cls"); // Clear screen for the first play
        first_play = 0; // Ensure this section only runs the first time
    }

    while (1) {
    	setColor(10);
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < number) {
            setColor(12);
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            setColor(12);
            printf("Too high! Try again.\n");
        } else {
            setColor(10);
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            playAgain();
            break;
        }
    }
}

int getRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

void playAgain() {
    char choice;
    setColor(14);
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &choice);
    system("cls");

    if (choice == 'y' || choice == 'Y') {
        playGame();
    } else {
        setColor(10);
        printf("Thanks for playing! Goodbye.\n");
        exit(0);
    }
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get console handle
    SetConsoleTextAttribute(hConsole, color); // Set text color
}
