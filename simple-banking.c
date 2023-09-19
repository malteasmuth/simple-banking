#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/account.h"
#include "libraries/customer_actions.h"

struct account accounts[100];

struct account* loadCSV(){
  FILE *file;
  file = fopen("DB/AccountData.csv", "r");

  struct account * accptr = NULL;
  accptr = accounts;

  char buffer[1024];
  int row = 0;
  int column = 0;
  int i = 0;

  while (fgets(buffer, 1024, file)) {

    column = 0;
    row = row + 1;

    char* value = strtok(buffer, ", ");

    while(value){

      if (column == 0) {
        printf("Id: ");
        accounts[i].id = atoi(value);
      }

      if (column == 1) {
        printf("Balance: ");
        accounts[i].balance = atof(value);
      }

      printf("%s", value);
      value = strtok(NULL, ", ");
      column++;
    }
    i++;
    printf("\n");
  }
  printf("Id: %d, Balance: %.2f\n", accounts[2].id, accounts[2].balance);
  return 0;
}

int save(struct account a){
  FILE *file;
  file = fopen("DB/AccountData.csv", "w+");

  fprintf(file, "Id, Balance\n");
  fprintf(file, "%d, %.2f", a.id, a.balance);
  fclose(file);
  return 0;
}

struct account showMenu(struct account a){

  int running = 1;
  int choice;

  do {
    printf("You're staring at a Thrustworthy Banks screen!\n");
    printf("What can this computer do for you?\n");
    printf("(1)   Show balance\n");
    printf("(2)   Deposit\n");
    printf("(3)   Withdraw\n");
    printf("(4)   Quit\n");

    scanf("%d", &choice);

    switch(choice) {

      case 1:
      printf("Show balance ...\n");
      showBalance(a.balance);
      break;

      case 2:
      printf("Depsit money ...\n");
      a.balance = deposit(a.balance);
      break;

      case 3:
      printf("Withdraw amount ...\n");
      a.balance = withdraw(a.balance);
      break;

      case 4:
      printf("Goodbye. Your fortune is save with us ...\n");
      running = 0;
      break;

      case 5:
      loadCSV();
      break;
    }

  } while (running == 1);

  return a;
}

int main(void){
  loadCSV();
  struct account a = { a.id = 1, a.balance = 0.00 };
  a = showMenu(a);
  return 0;
}
