#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(Object_Ptr objects, unsigned length)
{
  ArrayVoid_ptr array_void = (ArrayVoid_ptr)malloc(sizeof(ArrayVoid));

  array_void->array = (Object_Ptr)malloc(sizeof(Object) * length);
  array_void->length = length;

  for(unsigned i = 0; i < length; i++)
  {
    array_void->array[i] = objects[i];
  }

  return array_void;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr dest = (ArrayVoid_ptr)malloc(sizeof(ArrayVoid));

  dest->array = (Object_Ptr)malloc(sizeof(Object) * src->length);
  dest->length = src->length;

  for(unsigned i = 0; i < src->length; i++)
  {
    dest->array[i] = (*mapper)(src->array[i]);
  }

  return dest;
}
