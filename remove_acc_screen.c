#include "std_types.h"

void remove_acc_screen()
{
    system("cls");

    u32 id;
    printf("Enter national id: ");
    scanf("%d",&id);

    boolean res=  repo_remove_acc(id);

    if(res == true)
    {
        printf("Account removed successfully\n");
    }
    else
    {
        printf("Wrong id\n");
    }

    u32 input=0;
    printf("\nEnter 0 to reload screen, 1 to go back: ");
    scanf("%d",&input);

    if(input ==0)
    {
        remove_acc_screen();
    }
    else
    {
        home_screen();
    }
}
