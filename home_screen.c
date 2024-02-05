#include "repository.h"

void home_screen()
{
    system("cls");

    printf("==========Welcome==========\n\n");
    printf("----Please choose one of the options below----\n");
    printf("< 1 > Create new account \n");
    printf("< 2 > update information\n");
    printf("< 3 > transaction\n");
    printf("< 4 > check account\n");
    printf("< 5 > Removing account\n");
    printf("< 6 > Show list\n");
    printf("< 7 > Exit\n");

    u32 input=0;
    printf("Your input: ");
    scanf("%d",&input);

    switch(input){
        case 1: create_acc_screen(); break;
        case 2: update_info_screen(); break;
        case 3: transaction_screen(); break;
        case 4: check_acc_screen(); break;
        case 5: remove_acc_screen(); break;
        case 6: acc_list_screen(); break;
        case 7: exit(0);  break;
        default : home_screen();
    }
}
