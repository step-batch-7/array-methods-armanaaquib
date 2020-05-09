#ifndef __TEST_ARRAY_H
#define __TEST_ARRAY_H

#include "array.h"

typedef char *Message;

Array_Ptr create_array(Int_Array, unsigned);

void fail_message(Message message);
void pass_message(Message message);

void assert_array_equal(Array_Ptr, Array_Ptr, Message);

void display_tests_status();

#endif
