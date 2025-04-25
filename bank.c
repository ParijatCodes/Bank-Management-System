#include<stdio.h>
#include<string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

const char* ACCOUNT_FILE = "account.dat";

typedef struct{
    char name[50];
    int acc_no;
    float balance;
}account;

int main(){
    
    while (1)
    {
       int choice;
        printf("\n*** BANK MANAGEMENT SYSTEM ***");
        printf("\n 1. Create Account");
        printf("\n 2. Deposit Money");
        printf("\n 3. Withdraw Money ");
        printf("\n 4. Check Balance ");
        printf("\n 5. EXIT");
        printf(" \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            deposit_money();
            break;
        case 3:
            withdraw_money();
            break;
        case 4:
            check_balance();
            break;
        case 5:
            printf("\nClosing The Online Banking,\n Thanks For Your Visit \n");
            return 0;
            
        default:
        printf("Invalid Choice! \n");
        
            break;
        }
        
    }
    
     return 0;
}

void create_account(){
    account acc;

    FILE *file= fopen(ACCOUNT_FILE, "ab+");
    if (file==NULL){
        printf("\nUnable to open file! \n");
        return ;
    }

    char c;
    do
    {
        c = getchar();
    } while (c!= '\n' && c != EOF);
    

    printf("Enter Your Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    int ind= strcspn(acc.name, "\n");
    acc.name[ind]= '\0';
    printf("Enter Your Account Number: ");
    scanf("%d", &acc.acc_no);
    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);
    printf("\nAccount Created Succesfully \n");
    
    
}
void deposit_money(){
    FILE *file= fopen(ACCOUNT_FILE, "rb+");
    if (file== NULL)
    {
        printf("Unable to open account file !! \n");
        return;
    }
    int acc_no;
    float money;
    account acc_to_read;
    printf("Enter Your Account NO: \n");
    scanf("%d", &acc_no);
    printf("Enter Amount To Deposit: \n");
    scanf("%f", &money);

    while (fread(&acc_to_read, sizeof(acc_to_read), 1, file))
    {
        if (acc_to_read.acc_no == acc_no)
        {
            acc_to_read.balance += money;
            fseek(file, -(long)sizeof(acc_to_read), SEEK_CUR);
            fwrite(&acc_to_read, sizeof(acc_to_read),1 ,file);
            fclose(file);
            printf("Successfully Deposited Rs. %2f . New Balance is Rs.%.2f \n", money, acc_to_read.balance);
            return;
            
        }
        
    }

    fclose(file);
    printf("Money could not be deposited as the Account No %d was not found in records. \n", acc_no);
    
}   
void withdraw_money(){
    FILE *file= fopen(ACCOUNT_FILE, "rb+");
    if (file== NULL)
    {
        printf("\nUnable to open the account file !!! \n");
        return;
    }
    
    int acc_no;
    float money;
    account acc_to_read;
    printf("Enter Your Account No: \n");
    scanf("%d", &acc_no);
    printf("Enter the amount you want to withdraw: \n");
    scanf("%f", &money);

    while (fread(&acc_to_read, sizeof(acc_to_read), 1, file))
    {
        if (acc_to_read.acc_no== acc_no)
        {
            if (acc_to_read.balance >= money)
            {
                acc_to_read.balance -= money;
                if (fseek(file, -((long)sizeof(acc_to_read)), SEEK_CUR) == 0) {
                    fwrite(&acc_to_read, sizeof(acc_to_read), 1, file);
                } else {
                    printf("Error: Unable to update account information.\n");
                }
                printf("Successfully Withdrawn Rs.%.2f. Remaining balance is Rs.%.2f \n", money, acc_to_read.balance);
                
            }else{
                printf("Insufficient Balance ! \n");
                
            }
            fclose(file);
            return;
        }
        
    }
    
    fclose(file);
    printf("Money could not be withdrawn as the Account No %d was not found in records. \n", acc_no);

}
void check_balance(){
    
    FILE *file= fopen(ACCOUNT_FILE, "rb");
    if (file== NULL)
    {
        printf("Unable to open file !! \n");
        return ;
    }
    
    int acc_no;
    account acc_read;
    printf("Enter Your Account Number: \n");
    scanf("%d", &acc_no);
    
    while (fread(&acc_read, sizeof(acc_read),1, file))
    {
        if (acc_read.acc_no == acc_no)
        {
            printf("Your Account Balance is Rs.%.2f \n", acc_read.balance);
            fclose(file);
            return;
        }
        
    }
    fclose(file);
   printf("\nAccount No: %d was not found. \n", acc_no);
    
}