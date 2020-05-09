#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "test_map.h"

Object to_lower(Object obj)
{
  char character = *(Char_Ptr)obj;
  Object new_obj = (Object)malloc(sizeof(char));

  *(Char_Ptr)new_obj = tolower(character);

  return new_obj;
}

Object square_root(Object obj)
{
  float number = *(Float_Ptr)obj;
  Object new_obj = (Object)malloc(sizeof(float));

  *(Float_Ptr)new_obj = sqrt(number);

  return new_obj;
}

Object square(Object obj)
{
  int number = *(Int_Ptr)obj;
  Object new_obj = (Object)malloc(sizeof(int));

  *(Int_Ptr)new_obj = number * number;

  return new_obj;
}

void test_map_void_for_array_of_chars(void)
{
  char chars[] = {'A', 'S', 'E', 'D', 'a'};
  ArrayVoid_ptr array_void = create_array_void(create_objects_from_chars(chars, 5), 5);

  ArrayVoid_ptr actual_array_void = map_void(array_void, to_lower);

  char lowers[] = {'a', 's', 'e', 'd', 'a'};
  ArrayVoid_ptr expected_array_void = create_array_void(create_objects_from_chars(lowers, 5), 5);

  assert_array_void_equal(actual_array_void, expected_array_void, is_int_equal, "should map array of chars");
}

void test_map_void_for_array_of_floats(void)
{
  float float_array[] = {1, 25, 4, 9, 16};
  ArrayVoid_ptr array_void = create_array_void(create_objects_from_floats(float_array, 5), 5);

  ArrayVoid_ptr actual_array_void = map_void(array_void, square_root);

  float square_roots[] = {1.0, 5, 2.0, 3.0, 4.0};
  ArrayVoid_ptr expected_array_void = create_array_void(create_objects_from_floats(square_roots, 5), 5);

  assert_array_void_equal(actual_array_void, expected_array_void, is_float_equal, "should map array of floats");
}

void test_map_void_for_array_of_ints(void)
{
  int int_array[] = {1, 2, -2, 0, 3};
  ArrayVoid_ptr array_void = create_array_void(create_objects_from_ints(int_array, 5), 5);

  ArrayVoid_ptr actual_array_void = map_void(array_void, square);

  int squares[] = {1, 4, 4, 0, 9};
  ArrayVoid_ptr expected_array_void = create_array_void(create_objects_from_ints(squares, 5), 5);

  assert_array_void_equal(actual_array_void, expected_array_void, is_int_equal, "should map array of integers");
}

void test_map_void_for_empty_array(void)
{
  Object_Ptr empty_array;
  ArrayVoid_ptr array = create_array_void(empty_array, 0);

  ArrayVoid_ptr actual_array = map_void(array, square);
  ArrayVoid_ptr expected_array = create_array_void(empty_array, 0);

  assert_array_void_equal(actual_array, expected_array, is_int_equal, "should map an empty array");
}

void test_map_void(void)
{
  printf("Testing map_void...\n");

  test_map_void_for_empty_array();
  test_map_void_for_array_of_ints();
  test_map_void_for_array_of_floats();
  test_map_void_for_array_of_chars();

  printf("\n");
}
