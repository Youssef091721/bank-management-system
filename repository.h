#ifndef REPOSITORY_H_INCLUDED
#define REPOSITORY_H_INCLUDED
#include "models.h"


u32 repo_get_acc_numbers();

boolean repo_create_acc(str name, str password, str address,s32 nat_id,s32 age, s32 money);

boolean repo_update_info(u32 nat_id, str new_name, str new_password, str new_address,s32 newAge);

boolean repo_desposite(u32 id,s32 money);

boolean repo_withdraw(u32 id,s32 money);

boolean repo_check_acc(u32 nat_id);

boolean repo_remove_acc(u32 nat_id);

void repo_get_acc_list(UserAcc buffer[]);


#endif // REPOSITORY_H_INCLUDED
