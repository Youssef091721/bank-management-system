#include "std_types.h"


void check_acc_screen()
{
    system("cls");
    u32 id;
    boolean res;

    printf("Enter ID to check about: ");
    scanf("%d",&id);

    res = repo_check_acc(id);

    if(res == true)
    {
        printf("Email is already found\n");
    }
    else
    {
        printf("Email doesn\'t exist\n");
    }

    u32 input=0;
    printf("\nEnter 0 to reload screen, 1 to go back: ");
    scanf("%d",&input);

    if(input ==0)
    {
        check_acc_screen();
    }
    else
    {
        home_screen();
    }

}
