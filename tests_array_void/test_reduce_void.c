#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "test_reduce_void.h"

Object add(Object obj_1, Object obj_2)
{
  float num_1 = *(Float_Ptr)obj_1;
  float num_2 = *(Float_Ptr)obj_2;

  Object new_obj = (Object)malloc(sizeof(float));
  *(Float_Ptr)new_obj = num_1 + num_2;

  return new_obj;
}

Object greater(Object obj_1, Object obj_2)
{
  int num_1 = *(Int_Ptr)obj_1;
  int num_2 = *(Int_Ptr)obj_2;

  Object new_obj = (Object)malloc(sizeof(int));
  *(Int_Ptr)new_obj = num_1 >= num_2 ? num_1 : num_2;

  return new_obj;
}

void test_reduce_void_for_array_of_floats(void)
{
  float float_array[] = {1.2, 2.5, 4.0, 9.1, 1.6};
  ArrayVoid_ptr array_void = create_array_void(create_objects_from_floats(float_array, 5), 5);

  Object init = (Object)calloc(1, sizeof(float));
  Object result = reduce_void(array_void, init, add);

  Object expected_result = (Object)malloc(sizeof(float));
  *(Float_Ptr)expected_result = 18.4;

  assert_object_equal(result, expected_result, is_float_equal, "should reduce array of floats");
}

void test_reduce_void_for_array_of_ints(void)
{
  int int_array[] = {1, 2, -2, 0, 3};
  ArrayVoid_ptr array_void = create_array_void(create_objects_from_ints(int_array, 5), 5);

  Object init = (Object)malloc(sizeof(int));
  *(Int_Ptr)init = INT_MIN;
  Object result = reduce_void(array_void, init, greater);

  Object expected_result = (Object)malloc(sizeof(int));
  *(Int_Ptr)expected_result = 3;
  
  assert_object_equal(result, expected_result, is_int_equal, "should reduce array of integers");
}

void test_reduce_void_for_empty_array(void)
{
  Object_Ptr empty_array;
  ArrayVoid_ptr array = create_array_void(empty_array, 0);

  Object init = (Object)malloc(sizeof(int));
  *(Int_Ptr)init = 10;
  Object result = reduce_void(array, init, add);

  assert_object_equal(result, init, is_int_equal, "should reduce an empty array");
}

void test_reduce_void(void)
{
  printf("Testing reduce_void...\n");

  test_reduce_void_for_empty_array();
  test_reduce_void_for_array_of_ints();
  test_reduce_void_for_array_of_floats();

  printf("\n");
}
