#include <stdio.h>
#include "myBank.h"

int main()
{
init();
char input;
int flag = 1;

printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");

while (flag){

    scanf(" %c", &input);

    int out = 0;
    int account_num = 0;
    double num = 0;
    switch(input)
    {
        case 'O':
            printf("Please enter amount for deposit:\n");
            double amount = 0;
            while (scanf("%lf", &amount) != 1)
            {
                empty_stdin();
                printf("wrong deposit input, please try again\n");
            }
            out = open(amount);
            if (out == 0){
                printf("too many accounts, try again later :)\n\n");
            }
            out = 0;
            printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
            break;

        case 'B':
            printf("Please enter account number: \n");
            while (scanf("%d",&account_num) != 1)
            {
                empty_stdin();
                printf("wrong account number, please try again\n");
            }
            out = balance(account_num);
            if (out == 0){
                printf("Wrong account number, try again \n\n");
            }
            out = 0;
            account_num = 0;
            printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
            break;

        case 'D':
            printf("Please enter account number: \n");
            while (scanf("%d",&account_num) != 1)
            {
                empty_stdin();
                printf("wrong account number, please try again\n");
            }

            printf("Please enter amount for deposit: ");
            while (scanf("%lf",&num) != 1)
            {
                empty_stdin();
                printf("wrong amount number, please try again\n");
            }
            out = deposit(account_num,num);
            if (out == 0){
                printf("This account is closed, try a different account or create one \n\n");
            }
            else if(out == 2){
                printf("can only deposit a positive amount of money other than 0");
            }
            out = 0;
            account_num = 0;
            num = 0;
            printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
            break;

        case 'W':
            printf("Please enter account number: \n");
            while (scanf("%d",&account_num) != 1)
            {
                empty_stdin();
                printf("wrong account number, please try again\n");
            }

            printf("Please enter amount to withdraw: \n");
            while (scanf("%lf",&num) != 1)
            {
                empty_stdin();
                printf("wrong amount number, please try again\n");
            }
            out = withdraw(account_num,num);
            if (out == 0){
                printf("This account is closed, try a different account or create one \n\n");
            }
            else if(out == 2){
                printf("Cannot withdraw a negative amount\n\n");
            }
            else if(out == 3){
                printf("Cannot withdraw, not enough money\n\n");
            }
            else if(out == 4){
                printf("can only withdraw a positive amount of money other than 0\n\n");
            }

            out = 0;
            account_num = 0;
            num = 0;
            printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
            break;

        case 'C':
            printf("Please enter account number: \n");
            while (scanf("%d",&account_num) != 1)
            {
                empty_stdin();
                printf("wrong account number, please try again\n");
            }
            out = close(account_num);
            if (out == 0){
                printf("wrong account number\n\n");
            }
            else if(out == 2){
                printf("This account is already closed!\n");
            }
            out = 0;
            account_num = 0;
            printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
            break;
        
        case 'I':
            printf("Please enter interest rate: \n");
            while (scanf("%lf",&num) != 1)
            {
                empty_stdin();
                printf("Failed to read the interest rate, please try again\n");
            }
            interest(num);
            num = 0;
            printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
            break;
        
        case 'P':
            print_accounts();
            printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
            break;

        case 'E':
            close_all();
            flag = 0;
            break;

        default:
            printf("Not a valid command, please try again\n");
            printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
    }
    
}
return 0;
} 