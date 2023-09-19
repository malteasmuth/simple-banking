#include <stdio.h>
#include <stdlib.h>

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
