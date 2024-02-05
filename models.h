#ifndef MODELS_H_INCLUDED
#define MODELS_H_INCLUDED

#include "std_types.h"

typedef struct UserAcc{
    u32 index;
    u32 nat_id;
    str name;
    str password;
    str address;
    s32 money;
    u32 age;
}UserAcc;

#endif // MODELS_H_INCLUDED
