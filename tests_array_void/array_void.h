#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"

typedef void *Object;

typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef Object *Object_Ptr;

typedef struct
{
  Object_Ptr array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_Ptr;

ArrayVoid_Ptr create_array_void(Object_Ptr, unsigned);

ArrayVoid_Ptr map_void(ArrayVoid_Ptr src, MapperVoid mapper);
ArrayVoid_Ptr filter_void(ArrayVoid_Ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_Ptr src, Object init, ReducerVoid reducer);

#endif
