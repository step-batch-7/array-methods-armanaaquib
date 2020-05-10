#include <stdio.h>
#include "test_array.h"
#include "array.h"

int squares(int);
void test_map_for_empty_array(void);
void test_map_for_array_of_integers(void);
void test_map(void);

Bool is_even(int);
void test_filter_for_empty_array(void);
void test_filter_for_array_of_integers(void);
void test_filter(void);

int add(int, int);
void test_reduce_for_empty_array(void);
void test_reduce_for_array_of_integers(void);
void test_reduce(void);

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

Bool is_even(int number)
{
  return number % 2 == 0 ? True : False;
}

void test_filter_for_empty_array(void)
{
  int empty_int_array[] = {};
  Array_Ptr array = create_array(empty_int_array, 0);

  Array_Ptr actual_array = filter(array, is_even);
  Array_Ptr expected_array = create_array(empty_int_array, 0);

  assert_array_equal(actual_array, expected_array, "should filter an empty array");
}

void test_filter_for_array_of_integers(void)
{
  int int_array[] = {1, 2, 3, 4, 0};
  Array_Ptr array = create_array(int_array, 5);

  Array_Ptr actual_array = filter(array, is_even);

  int evens[] = {2, 4, 0};
  Array_Ptr expected_array = create_array(evens, 3);

  assert_array_equal(actual_array, expected_array, "should filter array of integers");
}

void test_filter(void)
{
  printf("Testing filter...\n");

  test_filter_for_empty_array();
  test_filter_for_array_of_integers();

  printf("\n");
}

int add(int number_1, int number_2)
{
  return number_1 + number_2;
}

void test_reduce_for_empty_array(void)
{
  int empty_int_array[] = {};
  Array_Ptr array = create_array(empty_int_array, 0);

  int result = reduce(array, 10, add);

  assert_int_equal(result, 10, "should reduce to initial value for an empty array");
}

void test_reduce_for_array_of_integers(void)
{
  int int_array[] = {1, 2, -3, 4, 5};
  Array_Ptr array = create_array(int_array, 5);

  int result = reduce(array, 1, add);

  assert_int_equal(result, 10, "should reduce array of integers");
}

void test_reduce(void)
{
  printf("Testing reduce...\n");

  test_reduce_for_empty_array();
  test_reduce_for_array_of_integers();

  printf("\n");
}

int main(void)
{
  test_map();
  test_filter();
  test_reduce();

  display_tests_status();

  return 0;
}
