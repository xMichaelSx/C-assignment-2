#include <stdio.h>
#include "myBank.h"

double account[50][2];

void init(){
    for(int i=0; i<50;i++){
        account[i][0] = 0;
        account[i][1] = 0;
    }
}

int is_space(){
    int free_index = -1;
    for (int i = 0; i<50; i++){
        if (account[i][0] == 0){
            free_index = i;
            break;
        }
    }
    return free_index;
}

int open(double amount){
    int check_space = is_space();
    if (check_space != -1)
    {
        account[check_space][0] = 1;
        account[check_space][1] = amount;

        printf("New account number is: %d\n\n", (900 + check_space+1));
        return 1;
    }
    else
    {
        return 0;
    }

}

int balance(int account_num){

    if (account_num < 901 || account_num > 950)
        return 0;

    if (account[account_num-901][0] != 0){
        printf("The balance of account number %d is: %0.2lf\n\n", account_num, account[account_num-901][1]);
        return 1;
    }
    else return 0;
}

int deposit(int account_num, double sum){

    if (account_num < 901 || account_num > 950)
        return 0;

    if (sum <= 0) return 2; // cant deposite a negative number

    if (account[account_num-901][0] != 0){
        account[account_num-901][1] += sum;
        printf("The balance of account number %d is: %0.2lf\n\n", account_num, account[account_num-901][1]);
        return 1;
    }
    else return 0;

}

int withdraw(int account_num, double sum){

    if (account_num < 901 || account_num > 950)
        return 0;

    if (sum <= 0) return 2; // cant withraw a negative number

    if (account[account_num-901][1] - sum < 0){
        return 3;
    }

    if (account[account_num-901][1] - sum == 0){
        return 4;
    }

    if (account[account_num-901][0] != 0){
        account[account_num-901][1] -= sum;
        printf("The new balance is: %0.2lf\n\n", account[account_num-901][1]);
        return 1;
    }
    else return 0;
}

int close(int account_num){
    
    if (account_num < 901 || account_num > 950)
        return 0;

    else if(account[account_num-901][0] == 0)
    {
        return 2;
    }

    else
    {
        account[account_num-901][0] = 0;
        account[account_num-901][1] = 0;
        printf("Closed account number %d\n", account_num);
        return 1;
    }
}

void interest(double num){

    if (num <= 0){
        printf("Invalid interest rate\n");
    }
    else
    {
        num = (num/100)+1;
        for (int i=0; i<50; i++){
            if (account[i][0] == 1){
                account[i][1] *= num;
            }
        }
    }
}

void print_accounts(){
    for (int i=0; i<50; i++){
            if (account[i][0] == 1){
                printf("The balance of account number %d is: %0.2lf\n", i+901, account[i][1]);
            }
        }
    printf("\n");
}

void close_all(){
    for(int i=0; i<50; i++){
        if (account[i][0] == 1){
            account[i][0] = 0;
            account[i][1] = 0;
        }
    }
}

// helper function to empty stdin after wrong input for getting input again.
void empty_stdin(void){
    int c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
}