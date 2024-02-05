#include <stdio.h>
#include <string.h>

#include "std_types.h"
#include "models.h"
#include "repository.h"

void transaction_screen()
{
    system("cls");

    u32 id;
    u32 choice=0;
    s32 money=0;

    printf("Enter national id: ");
    scanf("%d",&id);

    if(repo_check_acc(id))
    {
        printf("1) For deposit\n");
        printf("2) For Withdraw\n");
        printf("3) For change from Dollar To Eg\n");
        printf("4) For change from Eg To Dollar\n");

        printf("Your input: ");
        scanf("%d",&choice);

        if(choice==1)
        {

            printf("Enter the money: ");
            scanf("%d",&money);

            boolean res;
            res = repo_desposite(id,money);

            if(res)
            {
                printf("Money added successfully\n");
            }
            else
            {
                printf("Failed to add money\n");
            }
        }
        else if(choice==2)
        {

            printf("Enter the money: ");
            scanf("%d",&money);

            boolean res;
            res = repo_withdraw(id,money);

            if(res)
            {
                printf("Money withdraw successfully\n");
            }
            else
            {
                printf("Failed to withdraw money\n");
            }
        }
        else if(choice==3)
        {


        }
        else if(choice==4)
        {

        }
        else
        {
            printf("Wrong input\n");
        }
    }
    else
    {
        printf("No account is found with this id\n");
    }

    u32 input=0;
    printf("\nEnter 0 to reload screen, 1 to go back: ");
    scanf("%d",&input);

    if(input ==0)
    {
        transaction_screen();
    }
    else
    {
        home_screen();
    }
}
