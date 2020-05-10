#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "test_filter_void.h"

Bool is_vowel(Object obj)
{
  char c = tolower(*(Char_Ptr)obj);

  return c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u';
}

Bool is_even(Object obj)
{
  int number = *(Int_Ptr)obj;

  return number % 2 == 0 ? True : False;
}

void test_filter_void_for_array_of_chars(void)
{
  char chars[] = {'A', 's', 'E', 'D', 'u'};
  ArrayVoid_ptr array_void = create_array_void(create_objects_from_chars(chars, 5), 5);

  ArrayVoid_ptr actual_array_void = filter_void(array_void, is_vowel);

  char vowels[] = {'A', 'E', 'u'};
  ArrayVoid_ptr expected_array_void = create_array_void(create_objects_from_chars(vowels, 5), 3);

  assert_array_void_equal(actual_array_void, expected_array_void, is_int_equal, "should filter array of chars");
}

void test_filter_void_for_array_of_ints(void)
{
  int int_array[] = {1, 2, 4, 0, 3};
  ArrayVoid_ptr array_void = create_array_void(create_objects_from_ints(int_array, 5), 5);

  ArrayVoid_ptr actual_array_void = filter_void(array_void, is_even);

  int evens[] = {2, 4, 0};
  ArrayVoid_ptr expected_array_void = create_array_void(create_objects_from_ints(evens, 5), 3);

  assert_array_void_equal(actual_array_void, expected_array_void, is_int_equal, "should filter array of integers");
}

void test_filter_void_for_empty_array(void)
{
  Object_Ptr empty_array;
  ArrayVoid_ptr array = create_array_void(empty_array, 0);

  ArrayVoid_ptr actual_array = filter_void(array, is_even);
  ArrayVoid_ptr expected_array = create_array_void(empty_array, 0);

  assert_array_void_equal(actual_array, expected_array, is_int_equal, "should filter an empty array");
}

void test_filter_void(void)
{
  printf("Testing filter_void...\n");

  test_filter_void_for_empty_array();
  test_filter_void_for_array_of_ints();
  test_filter_void_for_array_of_chars();

  printf("\n");
}
