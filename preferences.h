#ifndef PREFERENCES_H_INCLUDED
#define PREFERENCES_H_INCLUDED

#include "std_types.h"

u32 prefs_get_array_size(str key);
void prefs_set_str_array(str key, str arr[],u32 length);
void prefs_set_int_array(str key, s32 arr[],u32 length);
void prefs_get_str_array(str key,str buffer[]);
void prefs_get_int_array(str key,s32 buffer[]);


#endif // PREFERENCES_H_INCLUDED
