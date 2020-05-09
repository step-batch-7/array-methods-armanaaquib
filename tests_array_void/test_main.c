#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "test_array_void.h"
#include "array_void.h"

Object_Ptr create_objects_from_ints(Int_Ptr, unsigned);
Object_Ptr create_objects_from_floats(Float_Ptr, unsigned);

Object square(Object);
void test_map_void_for_empty_array(void);
void test_map_void_for_array_of_ints(void);
Object square_root(Object);
void test_map_void_for_array_of_floats(void);
void test_map_void(void);

Object_Ptr create_objects_from_ints(Int_Ptr array, unsigned length)
{
  Object_Ptr objects = (Object_Ptr)malloc(sizeof(Object) * length);
  
  for(unsigned i = 0; i < length; i++)
  {
    Object obj = (Object)malloc(sizeof(int));
    *(Int_Ptr)obj = array[i];
    objects[i] = obj;
  }

  return objects;
}

Object_Ptr create_objects_from_floats(Float_Ptr array, unsigned length)
{
  Object_Ptr objects = (Object_Ptr)malloc(sizeof(Object) * length);
  
  for(unsigned i = 0; i < length; i++)
  {
    Object obj = (Object)malloc(sizeof(float));
    *(Float_Ptr)obj = array[i];
    objects[i] = obj;
  }

  return objects;
}

Object square_root(Object obj)
{
  float number = *(Float_Ptr)obj;
  Object new_obj = (Object)malloc(sizeof(float));

  *(Float_Ptr)new_obj = sqrt(number);

  return new_obj;
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

Object square(Object obj)
{
  int number = *(Int_Ptr)obj;
  Object new_obj = (Object)malloc(sizeof(int));

  *(Int_Ptr)new_obj = number * number;

  return new_obj;
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

  printf("\n");
}

int main(void)
{
  test_map_void();

  display_tests_status();

  return 0;
}
