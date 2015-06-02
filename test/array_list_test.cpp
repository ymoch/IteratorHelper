/**
 * @file
 * @brief   Test implementation of array lists.
 *
 * @author  ymoch
 * @date    2015-06-02  ymoch
 */
#include <algorithm>

#include "tests.h"
#include "tester.hpp"

#include "include/iterator_helper/array/array_list.hpp"
#include "include/iterator_helper/array/const_array_list.hpp"

namespace {

/**
 * @brief         Functor to add 1.
 */
template <typename T>
struct AddOne {
  void operator()(T& value) const { ++value; }
};

}  // namespace

namespace array_list_test {

extern void Test_NormalArrayListRandomAccessSucceeds() {
  int array[] = {0, 1, 2, 3, 4};
  std::size_t array_size = sizeof(array) / sizeof(array[0]);
  iterator_helper::ArrayList<int> array_list(array, array_size);

  for (std::size_t i = 0; i < array_size; ++i) {
    ASSERT(array_list[i] == array[i]);
  }
}

extern void Test_NormalArrayListIteratorAccessSucceeds() {
  int array[] = {0, 1, 2, 3, 4};
  std::size_t array_size = sizeof(array) / sizeof(array[0]);
  iterator_helper::ArrayList<int> array_list(array, array_size);

  std::size_t index = 0;
  for (auto it = array_list.begin(); it != array_list.end(); ++it, ++index) {
    ASSERT(*it == array[index]);
  }
}

extern void Test_NormalArrayListIteratorIncrementOperationSucceeds() {
  int array[] = {0, 1};
  std::size_t array_size = sizeof(array) / sizeof(array[0]);
  iterator_helper::ArrayList<int> array_list(array, array_size);

  auto it = array_list.begin();
  ASSERT(*(it++) == 0);

  it = array_list.begin();
  ASSERT(*(++it) == 1);
}

extern void Test_NormalArrayListForEachSucceeds() {
  static const int kArrayOrg[] = {0, 1, 2, 3, 4};
  static const std::size_t kArrayOrgSize =
      sizeof(kArrayOrg) / sizeof(kArrayOrg[0]);

  int array[kArrayOrgSize];
  std::size_t array_size = sizeof(array) / sizeof(array[0]);
  std::memcpy(array, kArrayOrg, sizeof(array));
  iterator_helper::ArrayList<int> array_list(array, array_size);

  std::for_each(array_list.begin(), array_list.end(), AddOne<int>());
  for (std::size_t i = 0; i < array_size; ++i) {
    ASSERT(array_list[i] == kArrayOrg[i] + 1);
    ASSERT(array_list[i] == array[i]);
  }
}

}  // namespace array_list_test
