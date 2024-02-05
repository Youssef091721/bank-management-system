#include "home_screen.h"
#include "std_types.h"
#include <string.h>

#define CORRECT_PASS "adnan"

void register_screen()
{
    system("cls");

    printf(" _  _  _  _______  _                  \n");
    printf("| || || |(_______)| |                 \n");
    printf("| || || | _____   | |                 \n");
    printf("| ||_|| ||  ___)  | |                 \n");
    printf("| |___| || |_____ | |_____            \n");
    printf(" \\______||_______)|_______)          \n");
    printf("                                      \n");
    printf("  ______   _____   ______   _______   \n");
    printf(" / _____) / ___ \\ |  ___ \\ (_______)\n");
    printf("| /      | |   | || | _ | | _____     \n");
    printf("| |      | |   | || || || ||  ___)    \n");
    printf("| \\_____ | |___| || || || || |_____  \n");
    printf(" \\______) \\_____/ |_||_||_||_______)\n");
    printf("                                      \n");

    str adminPass;

    printf("Enter password: ");
    scanf("%s",adminPass);

    if(strcmp(CORRECT_PASS,adminPass) == 0)
    {
        home_screen();
    }
    else
    {
        printf("Wrong password\n");

        u32 input=0;
        printf("Enter 0 to try again, 1 exit: ");
        scanf("%d",&input);

        if(input ==0)
        {
            register_screen();
        }
        else
        {
            exit(0);
        }

    }


}
