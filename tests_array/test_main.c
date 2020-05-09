#include <stdio.h>
#include "test_array.h"

int squares(int);
void test_map_for_empty_array();
void test_map_for_array_of_integers();
void test_map(void);

int square(int number)
{
  return number * number;
}

void test_map_for_array_of_integers(void)
{
  int int_array[] = {1, 2, -2, 0, 3};
  Array_Ptr array = create_array(int_array, 5);

  Array_Ptr actual_array = map(array, square);

  int squares[] = {1, 4, 4, 0, 9};
  Array_Ptr expected_array = create_array(squares, 5);

  assert_array_equal(actual_array, expected_array, "should map array of integers");
}

void test_map_for_empty_array(void)
{
  int empty_int_array[] = {};
  Array_Ptr array = create_array(empty_int_array, 0);

  Array_Ptr actual_array = map(array, square);
  Array_Ptr expected_array = create_array(empty_int_array, 0);

  assert_array_equal(actual_array, expected_array, "should map an empty array");
}

void test_map(void)
{
  printf("Testing map...\n");

  test_map_for_empty_array();
  test_map_for_array_of_integers();

  printf("\n");
}

int main(void)
{
  test_map();

  display_tests_status();

  return 0;
}
