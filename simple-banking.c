#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models/account.h"
#include "libraries/customer_actions.h"

struct account accounts[120];

int saveCSV(struct account* accounts){
  /*OVERWRITE EXISTING CSV TO SAVE CHANGES MADE TO ACCOUNTS*/
  /*open the file*/
  FILE *file_write;
  file_write = fopen("DB/AccountData.csv", "w+");

  /*write the headline into the file*/
  fprintf(file_write, "Id, Balance\n");

  /*Iterate over array and write every struct in accounts into the file as a new row*/
  for(int i = 0; i <= 100; i++) {
    printf("%d, %.2f,\n", accounts[i].id, accounts[i].balance);
    fprintf(file_write, "%d, %.2f,\n", accounts[i].id, accounts[i].balance);
  }

  fclose(file_write);
  return 0;
}

int loadCSV(struct account* accounts){
  /*READ THE FILE AND SAVE VALUES IN ACCOUNTS ARRAY!*/
  FILE *file;
  file = fopen("DB/AccountData.csv", "r");

  char buffer[1024];
  int row = 0;
  int column = 0;
  int i = 0;
  int counter = 0;

  while (fgets(buffer, 1024, file)) {

    column = 0;
    row = row + 1;

    char* value = strtok(buffer, ", ");

    while(value){

      if (column == 0) {
        accounts[i].id = atoi(value);
      }

      if (column == 1) {
        accounts[i].balance = atof(value);
      }

      value = strtok(NULL, ", ");
      column++;
      counter++;
    }
    i++;
  }
  return 0;
}

// int newAccount(void){

//   FILE *file;
//   file = fopen("DB/AccountData.csv", "a+");
//   int id;
//   double balance = 0;

//   printf("Enter account id: ");
//   scanf("%d", &id);

//   fprintf(file, "\n%d, %le,", id, balance);

//   printf("\nNew Account added to record");
//   fclose(file);
//   return id;
// }

/*HIER WEITER ARBEITEN -- DER FEHLER LIEGT HIER*/

struct account* findAccount(int id, struct account* accounts){

  struct account account;
  struct account* active_account = NULL;

  for(int i = 0; i <= 100; i++){
    if(accounts[i].id == id){
      account = accounts[i];
      active_account = &account;
    }
  }
  return active_account;
}

// int showMenu(struct account* a){

//   int running = 1;
//   int choice;

//   do {
//     printf("You're staring at a Thrustworthy Banks screen!\n");
//     printf("What can this computer do for you?\n");
//     printf("(1)   Show balance\n");
//     printf("(2)   Deposit\n");
//     printf("(3)   Withdraw\n");
//     printf("(4)   Quit\n");


//     scanf("%d", &choice);

    // switch(choice) {
    //   case 1:
    //   printf("Show balance ...\n");
    //   showBalance(a);
    //   break;

      // case 2:
      // printf("Depsit money ...\n");
      // a.balance = deposit(a.balance);
      // printf("Menu value: %.2f", a.balance);
      // break;

      // case 3:
      // printf("Withdraw amount ...\n");
      // a.balance = withdraw(a.balance);
      // break;

      // case 4:
      // printf("Goodbye. Your fortune is save with us ...\n");
      // running = 0;
      // break;
    // }

//   } while (running == 1);

//   return 0;
// }

int main(void){

  struct account* accountsptr = accounts;

  loadCSV(accounts);

  printf("Please enter your account number: ");
  int account_number;
  scanf("%d", &account_number);

  struct account* active_account = findAccount(account_number, accounts);
  printf("BALANCE 2: %.2f\n", (*active_account).balance);
  // showMenu(active_account);

  saveCSV(accounts);

  /*int id = newAccount();*/

  return 0;
}
