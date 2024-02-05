#include "stdlib.h"
#include "stdio.h"

#include "std_types.h"

u32 prefs_get_array_size(str key)
{
    u32 size = 0;

    FILE* fptr;

    fptr = fopen(key,"r");

    if(fptr ==NULL)
    {
        size = 0;
    }
    else
    {
        fscanf(fptr,"%d",&size);
        fclose(fptr);
    }

    return size;
}

void prefs_set_str_array(str key, str arr[],u32 length)
{
    FILE *fptr;

    fptr = fopen(key,"w");

    if(fptr != NULL)
    {
        fprintf(fptr,"%d\n",length);

        u32 i;
        for(i=0; i<length; i++)
        {
            fprintf(fptr,"%s\n",arr[i]);
        }
        fclose(fptr);
    }
}

void prefs_get_str_array(str key,str buffer[])
{
    u32 size = 0;

    FILE* fptr;

    fptr = fopen(key,"r");

    if(fptr !=NULL)
    {
        fscanf(fptr,"%d",&size);

        u32 i;
        for(i=0; i<size; i++)
        {
            fscanf(fptr,"%s",buffer[i]);
        }

        fclose(fptr);
    }
}

void prefs_set_int_array(str key, s32 arr[],u32 length)
{
    FILE *fptr;

    fptr = fopen(key,"w");

    if(fptr != NULL)
    {
        fprintf(fptr,"%d\n",length);

        u32 i;
        for(i=0; i<length; i++)
        {
            fprintf(fptr,"%d\n",arr[i]);
        }
        fclose(fptr);
    }
}

void prefs_get_int_array(str key,s32 buffer[])
{
    u32 size = 0;
    FILE* fptr;

    fptr = fopen(key,"r");

    if(fptr !=NULL)
    {
        fscanf(fptr,"%d",&size);

        u32 i;
        for(i=0; i<size; i++)
        {
            fscanf(fptr,"%d",buffer+i );
        }

        fclose(fptr);
    }
}

