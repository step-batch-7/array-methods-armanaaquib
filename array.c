#include <stdlib.h>
#include "array.h"

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
