#include "models.h"

void acc_list_screen()
{
    system("cls");


    u32 si = repo_get_acc_numbers();
    UserAcc accArray[si];
    repo_get_acc_list(accArray);

    u32 i =0;
    for(; i<si; i++)
    {
        printf("%d) Name: %s,\tAddress: %s,\tAge: %d,\n   nat id: %d,\tMoney: %d\n",
               i+1, accArray[i].name,accArray[i].address,
               accArray[i].age,accArray[i].nat_id,accArray[i].money);
    }

    u32 input=0;
    printf("\n\nEnter 1 to go back: ");
    scanf("%d",&input);

    if(input ==1){
        home_screen();
    }else{
        acc_list_screen();
    }
}
