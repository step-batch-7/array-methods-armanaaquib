#ifndef __TEST_REDUCE_VOID_H
#define __TEST_REDUCE_VOID_H

#include "test_array_void.h"

Object greater(Object, Object);
Object add(Object, Object);

void test_reduce_void_for_empty_array(void);
void test_reduce_void_for_array_of_ints(void);
void test_reduce_void_for_array_of_floats(void);

void test_reduce_void(void);

#endif
