#ifndef __TEST_ARRAY_VOID_H
#define __TEST_ARRAY_VOID_H

#include "array_void.h"

typedef char *Message;
typedef int *Int_Ptr;
typedef float *Float_Ptr;
typedef char *Char_Ptr;

void fail_message(Message message);
void pass_message(Message message);

typedef Bool (*Are_Equal)(Object, Object);

Bool is_int_equal(Object, Object);
Bool is_float_equal(Object, Object);

void assert_array_void_equal(ArrayVoid_ptr, ArrayVoid_ptr, Are_Equal, Message);

void display_tests_status();

#endif
