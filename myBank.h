
void init();
int is_space();
int open(double amount);
int balance(int account_num);
int deposit(int account_num, double sum);
int withdraw(int account_num, double sum);
int close(int account_num);
void interest(double num);
void print_accounts();
void close_all();
void empty_stdin(void); // helper function to empty stdin after wrong input for getting input again.