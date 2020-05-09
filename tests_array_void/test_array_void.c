#include <stdio.h>
#include <stdlib.h>
#include "test_array_void.h"

unsigned NO_OF_PASSING_TEST = 0;
unsigned NO_OF_FAILING_TEST = 0;

void display_tests_status()
{
  printf("Passing %u, ", NO_OF_PASSING_TEST);
  printf("Failing %u\n", NO_OF_FAILING_TEST);
}

void fail_message(Message message)
{
  printf("X %s\n", message);
}

void pass_message(Message message)
{
  printf("- %s\n", message);
}

Bool is_int_equal(Object obj_1, Object obj_2)
{
  return *(Int_Ptr)obj_1 == *(Int_Ptr)obj_2;
}

Bool is_float_equal(Object obj_1, Object obj_2)
{
  return *(Float_Ptr)obj_1 == *(Float_Ptr)obj_2;
}

void assert_array_void_equal(ArrayVoid_ptr array_1, ArrayVoid_ptr array_2, Are_Equal is_data_equal, Message message)
{
  Bool are_equals = True;
  
  are_equals = are_equals && (array_1->length == array_2->length);

  if(!are_equals)
  {
    NO_OF_FAILING_TEST++;
    fail_message(message);
    return;
  }

  for(unsigned i = 0; i < array_1->length; i++)
  {
    are_equals = are_equals && (*is_data_equal)(array_1->array[i], array_2->array[i]);
  }

  if(are_equals)
  {
    NO_OF_PASSING_TEST++;
    pass_message(message);
    return;
  }

  NO_OF_FAILING_TEST++;
  fail_message(message);
}
