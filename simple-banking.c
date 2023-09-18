#include <stdio.h>


int showMenu(){

  int running = 1;
  int choice;

  do {
    printf("Welcome to thrustworthy banks!\n");
    printf("(1)   Show balance\n");
    printf("(2)   Deposit\n");
    printf("(3)   Withdraw\n");
    printf("(4)   Quit\n");

    scanf("%d", &choice);

  } while (running == 1);

  return 0;
}

int main(void){

  double balance = 0;
  int account_number = 123456;

  showMenu();
  return 0;
}
