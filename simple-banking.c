#include <stdio.h>
#include <stdlib.h>

struct account{
    int id;
    double balance;
};

int save(struct account a){
  FILE *file;
  file = fopen("AccountData.csv", "w+");

  fprintf(file, "Id, Balance\n");
  fprintf(file, "%d, %.2f", a.id, a.balance);
  fclose(file);
  return 0;
}

int showBalance(double balance){
  printf("Your balance is: %.2f EUR \n", balance);
  return 0;
}

double deposit(double balance){
  double deposit_amount;

  printf("Please enter the amount you want to deposit.\n");
  printf("Amount: ");
  scanf("%le", &deposit_amount);

  balance = balance + deposit_amount;

  printf("Your new balance: %.2f EUR\n", balance);

  return balance;
}

double withdraw(double balance){

  double withdraw_amount;

  printf("How much money do you want to withdraw?\n");
  printf("Amount: ");
  scanf("%le", &withdraw_amount);

  balance = balance - withdraw_amount;

  printf("Your new balance: %.2f EUR\n", balance);

  return balance;
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
      printf("Goodbye ...\n");
      running = 0;
      break;
    }

  } while (running == 1);

  return a;
}

int main(void){

  struct account a = { a.id = 1, a.balance = 0.00 };

  a = showMenu(a);
  save(a);

  return 0;
}
