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

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object temp_objects[src->length];
  unsigned count = 0;

  for(unsigned i = 0; i < src->length; i++)
  {
    Object obj = src->array[i];

    if((*predicate)(obj))
    {
      temp_objects[count++] = obj;
    }
  }

  return create_array_void(temp_objects, count);
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  Object result = init;

  for(unsigned i = 0; i < src->length; i++)
  {
    result = (*reducer)(result, src->array[i]);
  }

  return result;
}
