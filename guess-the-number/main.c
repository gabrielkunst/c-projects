#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
  srand(time(0));
  int random = (rand() % 20) + 1;
  int attempts = 10;
  printf("Guess the number! Remember that you have 10 attempts!\n");
  while (1) {
    if (attempts > 0) {
      int guess;
      printf("\nNow you have %d attempts left!\n", attempts);
      printf("What's your guess? (0 - 20): ");
      scanf("%d", &guess);
      if (guess == random) {
        printf("You won! The random number is %d!\n", random);
        break;
      } else {
        if (guess > random) {
          printf("Too high!\n");
          attempts--;
        } else {
          printf("Too low!\n");
          attempts--;
        }
      }
    } else {
      printf("\nYou lost!");
      break;
    }
  }
  return 0;
}