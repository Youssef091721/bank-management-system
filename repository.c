#include <stdio.h>
#include <string.h>

#include "std_types.h"
#include "models.h"
#include "models.h"


#define ID_FILE         "acc_nat_ids.txt"
#define NAME_FILE       "acc_names.txt"
#define PASS_FILE       "acc_pass.txt"
#define ADDRESS_FILE    "acc_address.txt"
#define MONEY_FILE      "acc_money.txt"
#define AGE_FILE        "acc_age.txt"


u32 repo_get_acc_numbers()
{
    return prefs_get_array_size(NAME_FILE);
}

boolean repo_create_acc(str name, str password, str address,s32 nat_id,s32 age, s32 money)
{
    u32 si = prefs_get_array_size(NAME_FILE) + 1;

    s32 nat_ids[si];
    str names[si];
    str passwords[si];
    str addresses[si];
    s32 moneys[si];
    u32 ages[si];

    prefs_get_int_array(ID_FILE,nat_ids);
    prefs_get_str_array(NAME_FILE,names);
    prefs_get_str_array(PASS_FILE,passwords);
    prefs_get_str_array(ADDRESS_FILE,addresses);
    prefs_get_int_array(MONEY_FILE,moneys);
    prefs_get_int_array(AGE_FILE,ages);

    strcpy(names[si - 1],name);
    strcpy(passwords[si - 1],password);
    strcpy(addresses[si - 1],address);
    moneys[si-1] = money;
    nat_ids[si-1] = nat_id;
    ages[si-1] = age;


    //check that national id is unique
    u32 i =0;
    boolean flag = true;
    for(; i<si-1; i++)
    {
        if(nat_ids[i] == nat_id)
        {
            flag = false;
            break;
        }
    }

    if(flag && nat_id>= 0 && money>= 0 && age>0)
    {
        prefs_set_str_array(NAME_FILE,names,si);
        prefs_set_str_array(PASS_FILE,passwords,si);
        prefs_set_str_array(ADDRESS_FILE,addresses,si);
        prefs_set_int_array(ID_FILE,nat_ids,si);
        prefs_set_int_array(MONEY_FILE,moneys,si);
        prefs_set_int_array(AGE_FILE,ages,si);

        return true;
    }
    else
    {
        return false;
    }
}

boolean repo_update_info(u32 nat_id, str new_name, str new_password, str new_address,s32 newAge)
{
    u32 si = prefs_get_array_size(ID_FILE);

    u32 nat_ids[si];
    str names[si];
    str passwords[si];
    str addresses[si];
    u32 ages[si];


    prefs_get_int_array(ID_FILE, nat_ids);
    prefs_get_str_array(NAME_FILE, names);
    prefs_get_str_array(PASS_FILE, passwords);
    prefs_get_str_array(ADDRESS_FILE, addresses);
    prefs_get_int_array(AGE_FILE, ages);


    u32 index = -1;
    u32 i=0;
    for (; i < si; i++)
    {
        if (nat_ids[i] == nat_id)
        {
            index = i;
            break;
        }
    }

    if (index != -1 && newAge > 0)
    {

        strcpy(names[index], new_name);
        strcpy(passwords[index], new_password);
        strcpy(addresses[index], new_address);
        ages[index] = newAge;

        prefs_set_str_array(NAME_FILE, names, si);
        prefs_set_str_array(PASS_FILE, passwords, si);
        prefs_set_str_array(ADDRESS_FILE, addresses, si);
        prefs_set_int_array(ID_FILE, nat_ids, si);
        prefs_set_int_array(AGE_FILE, ages, si);

        return true;
    }
    else
    {
        return false;
    }
}

boolean repo_desposite(u32 id,s32 money)
{
    s32 index_of_user=-1;
    u32 si = prefs_get_array_size(NAME_FILE);

    u32 ids[si];
    s32 moneys[si];

    prefs_get_int_array(ID_FILE,ids);
    prefs_get_int_array(MONEY_FILE,moneys);

    u32 i;
    for(i=0; i<si; i++)
    {
        if(id==ids[i])
        {

            index_of_user=i;
            break;
        }
        else {}
    }

    if(index_of_user !=-1 && money > 0)
    {

        moneys[index_of_user]=moneys[index_of_user]+money;
        prefs_set_int_array(MONEY_FILE,moneys,si);

        return true;
    }
    else
    {
        return false;
    }

}

boolean repo_withdraw(u32 id,s32 money)
{
    s32 index_of_user=-1;
    u32 si = prefs_get_array_size(NAME_FILE);

    u32 ids[si];
    s32 moneys[si];
    prefs_get_int_array(ID_FILE,ids);
    prefs_get_int_array(MONEY_FILE,moneys);

    s32 i;
    for(i=0; i<si; i++)
    {
        if(id==ids[i])
        {
            index_of_user=i;
            break;
        }
        else {}
    }


    if(index_of_user !=-1 && money <= moneys[index_of_user])
    {
        moneys[index_of_user]=moneys[index_of_user]-money;
        prefs_set_int_array(MONEY_FILE,moneys,si);
        return true;
    }
    else
    {
        return false;
    }
}

boolean repo_check_acc(u32 nat_id)
{
    s32 index_of_user=-1;
    s32 i;
    u32 si = prefs_get_array_size(NAME_FILE);

    u32 ids[si];
    prefs_get_int_array(ID_FILE,ids);


    for(i=0; i<si; i++)
    {
        if(nat_id == ids[i])
        {
            index_of_user=i;
            break;
        }
        else {}
    }

    return index_of_user != -1;
}

boolean repo_remove_acc(u32 nat_id)
{
    u32 si = prefs_get_array_size(NAME_FILE);

    u32 nat_ids[si];
    str names[si];
    str passwords[si];
    str addresses[si];
    s32 moneys[si];
    u32 ages[si];

    prefs_get_int_array(ID_FILE,nat_ids);
    prefs_get_str_array(NAME_FILE,names);
    prefs_get_str_array(PASS_FILE,passwords);
    prefs_get_str_array(ADDRESS_FILE,addresses);
    prefs_get_int_array(MONEY_FILE,moneys);
    prefs_get_int_array(AGE_FILE,ages);

    //get index
    u32 i;
    s32 index_of_user =-1;
    for(i=0; i<si; i++)
    {
        if(nat_id == nat_ids[i])
        {
            index_of_user=i;
            break;
        }
        else {}
    }

    if(index_of_user!= -1)
    {
        nat_ids[index_of_user] = nat_ids[si-1];
        strcpy(names[index_of_user],names[si-1]);
        strcpy(passwords[index_of_user],passwords[si-1]);
        strcpy(addresses[index_of_user],addresses[si-1]);
        moneys[index_of_user] = moneys[si-1];
        ages[index_of_user] = ages[si-1];

        prefs_set_str_array(NAME_FILE,names,si-1);
        prefs_set_str_array(PASS_FILE,passwords,si-1);
        prefs_set_str_array(ADDRESS_FILE,addresses,si-1);
        prefs_set_int_array(ID_FILE,nat_ids,si-1);
        prefs_set_int_array(MONEY_FILE,moneys,si-1);
        prefs_set_int_array(AGE_FILE,ages,si-1);

        return true;
    }
    else
    {
        return false;
    }


}

void repo_get_acc_list(UserAcc buffer[])
{
    u32 si = prefs_get_array_size(NAME_FILE);

    u32 nat_ids[si];
    str names[si];
    str passwords[si];
    str addresses[si];
    s32 moneys[si];
    u32 ages[si];

    prefs_get_int_array(ID_FILE,nat_ids);
    prefs_get_str_array(NAME_FILE,names);
    prefs_get_str_array(PASS_FILE,passwords);
    prefs_get_str_array(ADDRESS_FILE,addresses);
    prefs_get_int_array(MONEY_FILE,moneys);
    prefs_get_int_array(AGE_FILE,ages);

    u32 i =0;
    for(; i<si; i++)
    {
        buffer[i].index = i;
        buffer[i].nat_id = nat_ids[i];
        strcpy(buffer[i].name,names[i]);
        strcpy(buffer[i].password,passwords[i]);
        strcpy(buffer[i].address,addresses[i]);
        buffer[i].money= moneys[i];
        buffer[i].age= ages[i];
    }
}

