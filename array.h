#ifndef __ARRAY_H
#define __ARRAY_H
typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef int *Int_Array;

typedef struct
{
  Int_Array array;
  int length;
} Array;

typedef Array *Array_Ptr;

Array_Ptr create_array(Int_Array, unsigned);

Array_Ptr map(Array_Ptr src, Mapper mapper);
Array_Ptr filter(Array_Ptr src, Predicate predicate);
int reduce(Array *src, int init, Reducer reducer);

#endif
