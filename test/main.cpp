/**
 * @file
 * @brief   Test execution.
 *
 * @author  ymoch
 * @date    2015-06-02  ymoch
 */
#include "tests.h"

/**
 * @brief         Main
 *
 * @return        Return code.
 */
int main() {
  array_list_test::Test_NormalArrayListRandomAccessSucceeds();
  array_list_test::Test_NormalArrayListIteratorAccessSucceeds();
  array_list_test::Test_NormalArrayListIteratorIncrementOperationSucceeds();
  array_list_test::Test_NormalArrayListForEachSucceeds();

  return 0;
}
