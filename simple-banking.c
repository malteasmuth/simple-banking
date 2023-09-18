#include <stdio.h>
#include <stdlib.h>

int showBalance(double balance){
  printf("Your balance is: %le EUR \n", balance);
  return 0;
}

double deposit(double balance){
  
}

double withdraw(double balance){

  double withdraw_amount;

  printf("How much money do you want to deposit?");
  scanf("%le", &withdraw_amount);

  balance = balance - withdraw_amount;

  printf("Your new balance: %le", balance);

  return balance;
}


int showMenu(double balance){

  int running = 1;
  int choice;

  do {
    printf("You're staring at Thrustworthy Banks!\n");
    printf("(1)   Show balance\n");
    printf("(2)   Deposit\n");
    printf("(3)   Withdraw\n");
    printf("(4)   Quit\n");

    scanf("%d", &choice);

    switch(choice) {

      case 1:
      printf("Show balance ...\n");
      showBalance(balance);
      break;

      case 2:
      printf("Depsit money ...\n");
      break;

      case 3:
      printf("Withdraw amount ...\n");
      balance = withdraw(balance);
      break;

      case 4:
      printf("Goodbye ...\n");
      running = 0;
      break;
    }

  } while (running == 1);

  return 0;
}

int main(void){

  double balance = 100.12;

  showMenu(balance);
  return 0;
}
