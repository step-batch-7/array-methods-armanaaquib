#include <stdio.h>
#include <stdlib.h>
#include "test_array.h"

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

void assert_array_equal(Array_Ptr array_1, Array_Ptr array_2, Message message)
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
    are_equals = are_equals && (array_1->array[i] == array_2->array[i]);
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

void assert_int_equal(int number_1, int number_2, Message message)
{
  if(number_1 == number_2)
  {
    NO_OF_PASSING_TEST++;
    pass_message(message);
    return;
  }

  NO_OF_FAILING_TEST++;
  fail_message(message);
}
