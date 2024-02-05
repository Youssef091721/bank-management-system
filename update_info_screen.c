#include "repository.h"

void update_info_screen()
{
    system("cls");

    u32 nat_id;
    str name;
    str password;
    str address;
    s32 money;
    u32 age;

    printf("Enter nat_id: ");
    scanf("%d",&nat_id);

    printf("Enter new name: ");
    scanf("%s",name);

    printf("Enter new password: ");
    scanf("%s",password);

    printf("Enter new age: ");
    scanf("%d",&age);

    printf("Enter new address: ");
    scanf("%s",address);

    boolean res;
    res = repo_update_info(nat_id,name,password,address,age);

    if(res)
    {
        printf("Account updated successfully\n");
    }
    else
    {
        printf("Failed to update the account\n");
    }

    u32 input=0;
    printf("\nEnter 0 to reload screen, 1 to go back: ");
    scanf("%d",&input);

    if(input ==0)
    {
        update_info_screen();
    }
    else
    {
        home_screen();
    }
}
