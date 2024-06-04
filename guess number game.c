#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame();
int getRandomNumber(int lower, int upper);
void printInstructions();
void playAgain();

int main() {
    srand(time(0)); // Seed for random number generation
    printInstructions();
    playGame();
    return 0;
}

void printInstructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I will pick a random number between 1 and 100.\n");
    printf("Your job is to guess it. After each guess,\n I'll tell you if your guess was too high or too low.\n");
    printf("Let's get started!\n");
}

void playGame() {
    int number = getRandomNumber(1, 100);
    int guess;
    int attempts = 0;

    while (1) {
        printf("\n Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < number) {
            printf("\n Too low! Try again.\n");
        } else if (guess > number) {
            printf("\nToo high! Try again.\n");
        } else {
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
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        playGame();
    } else {
        printf("Thanks for playing! Goodbye.\n");
        exit(0);
    }
}

