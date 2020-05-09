#include <stdlib.h>
#include "array.h"

Array_Ptr create_array(Int_Array int_array, unsigned length)
{
  Array_Ptr array = (Array_Ptr)malloc(sizeof(Array));

  array->array = (Int_Array)malloc(sizeof(int) * length);
  array->length = length;

  for(unsigned i = 0; i < length; i++)
  {
    array->array[i] = int_array[i];
  }

  return array;
}

Array_Ptr map(Array_Ptr src, Mapper mapper)
{
  Array_Ptr dest = (Array_Ptr)malloc(sizeof(Array));

  dest->array = (Int_Array)malloc(sizeof(int) * src->length);
  dest->length = src->length;

  for(unsigned i = 0; i < src->length; i++)
  {
    dest->array[i] = (*mapper)(src->array[i]);
  }

  return dest;
}
