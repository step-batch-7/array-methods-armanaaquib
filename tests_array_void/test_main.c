#include "test_array_void.h"
#include "test_map_void.h"
#include "test_reduce_void.h"

int main(void)
{
  test_map_void();
  test_reduce_void();

  display_tests_status();

  return 0;
}
