#include <stdio.h>
#include <stdlib.h>
#include "../models/account.h"

// int save(void){
//   /*open the file*/
//   FILE *file_write;
//   file_write = fopen("DB/AccountDataUpdate.csv", "w+");
//   /*write the headline into the file*/
//   fprintf(file_write, "Id, Balance\n");

//   /*write every struct in accounts into the file*/

//   /*DEBUGGING*/printf("Menu value: %.2f", a.balance);

//   printf("%d, %.2f, \n", accounts[3].id,accounts[3].balance);


//   for(int i = 1; i <= 100; i++) {
//     fprintf(file_write, "%d, %.2f,\n", accounts[i].id, accounts[i].balance);
//   }

//   fclose(file_write);
//   return 0;
// }

// struct account loadCSV(){
//   FILE *file;
//   file = fopen("DB/AccountData.csv", "r");

//   char buffer[1024];
//   int row = 0;
//   int column = 0;
//   int i = 0;

//   while (fgets(buffer, 1024, file)) {

//     column = 0;
//     row = row + 1;

//     char* value = strtok(buffer, ", ");

//     while(value){

//       if (column == 0) {
//         /*printf("Id: ");*/
//         accounts[i].id = atoi(value);
//       }update csv in c programming

//       if (column == 1) {
//         /*printf("Balance: ");*/
//         accounts[i].balance = atof(value);
//       }

//       /*printf("%s", value);*/
//       value = strtok(NULL, ", ");
//       column++;
//     }
//     i++;
//     /*printf("\n");*/
//   }
//   return 0;
// }

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

struct account* findAccount(int id){

  struct account account;

  for(int i = 0; i <= 100; i++){
    if(accounts[i].id == id){
      account = accounts[i];
    }
  }
  printf("%d", account.id);
  return account;
}
