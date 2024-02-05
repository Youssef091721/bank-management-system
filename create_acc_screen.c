#include "models.h"

void create_acc_screen()
{
    system("cls");

    UserAcc add;

    printf("\nEnter the name:");
    scanf("%s",add.name);

    printf("\nEnter the national ID:");
    scanf("%d",&add.nat_id);

    printf("\nEnter the age:");
    scanf("%d",&add.age);

    printf("\nEnter the address:");
    scanf("%s",add.address);

    printf("\nEnter the password:");
    scanf("%s",add.password);

    printf("\nEnter money:");
    scanf("%d",&add.money);

    boolean res;
    res = repo_create_acc(add.name,add.password,add.address,add.nat_id,add.age,add.money);

    if(res)
    {
        printf("Account created successfully\n");
    }
    else
    {
        printf("Failed to create account\n");
    }

    u32 input=0;
    printf("\nEnter 0 to reload screen, 1 to go back: ");
    scanf("%d",&input);

    if(input ==0)
    {
        create_acc_screen();
    }
    else
    {
        home_screen();
    }
}
