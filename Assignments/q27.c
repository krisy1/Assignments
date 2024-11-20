#include <stdio.h>
#include <string.h>
#define MAX_TRIES 3
void displayWord(char word[], char guessed[]) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}
int main() {
    char word[] = "hangman";
    int length = strlen(word);
    char guessed[length];
    int tries = 0;
    int correctGuesses = 0;
    char guess;
    memset(guessed, 0, sizeof(guessed));
    printf("Welcome to Hangman Game!\n");
    printf("Guess the word: \n");
    while (tries < MAX_TRIES) {
        displayWord(word, guessed);
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        int found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = 1;
                correctGuesses++;
                found = 1;
            }
        }
        if (found) {
            printf("Good guess!\n");
        } else {
            tries++;
            printf("Wrong guess! You have %d tries left.\n", MAX_TRIES - tries);
        }
        if (correctGuesses == length) {
            printf("Congratulations! You've guessed the word: %s\n", word);
            return 0;
        }
    }
    printf("Sorry, you've been hanged! The word was: %s\n", word);
    return 0;
}