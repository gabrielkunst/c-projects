#include <stdio.h>

float saveData(float balance) {
  FILE *file = fopen("data.txt", "w");
  if (file != NULL) {
    fprintf(file, "%f", balance);
    fclose(file);
  }
}

float getData(float balance) {
  FILE *file = fopen("data.txt", "r");
  if (file != NULL) {
    fscanf(file, "%f", &balance);
    fclose(file);
  }
  return balance;
}

int main() {
  int option;
  float value;
  float balance = getData(balance);
  printf("******************************************\n");
  printf("*************** Lester Bank **************\n");
  printf("******************************************\n");
  while(1) {
    while(1){
      printf("\nOptions:\n[1] Widthdrawal\n[2] Deposit\n[3] Balance\nChoose a number: ");
      scanf("%d", &option);
      if (option < 1 || option > 3) {
        printf("Type a valid number!\n");
      } else {
        break;
      }
    }
    switch (option) {
    case 1:
      printf("Widthdrawal value: $");
      scanf("%f", &value);
      if (balance >= value) {
        balance -= value;
        printf("Widthdrawal made successfully!");
      } else {
        printf("You don't have enough money to widthdrawal this value.");
      }
      break;
    case 2:
      printf("Deposit value: $");
      scanf("%f", &value);
      balance += value;
      printf("Deposit made successfully!");
      break;
    case 3:
      printf("Your current balance is $%.2f.", balance);
      break;
    }
    while(1){
      printf("\nDo you need anything else? [1 for YES / 2 for NO]:");
      scanf("%d", &option);
      if (option == 1 || option == 2) {
        break;
      } else {
        printf("Type a valid number!");
      }
    }
    if (option == 2) {
      saveData(balance);
      break;
    }
  }
  return 0;
}