#ifndef __TEST_MAP_VOID_H
#define __TEST_MAP_VOID_H

#include "test_array_void.h"

Object square(Object);
Object square_root(Object);
Object to_lower(Object);

void test_map_void_for_empty_array(void);
void test_map_void_for_array_of_ints(void);
void test_map_void_for_array_of_floats(void);
void test_map_void_for_array_of_chars(void);

void test_map_void(void);

#endif
