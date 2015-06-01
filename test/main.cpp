/**
 * @file
 * @brief   Test implementation of iterator helpers.
 *
 * @author  ymoch
 * @date    2015-06-02  ymoch
 */
#include <iostream>
#include <algorithm>

#include "iterator_helper/array/array_list.hpp"
#include "iterator_helper/array/const_array_list.hpp"

namespace {

/**
 * @brief         Functor to add 1.
 */
template <typename T>
struct AddOne {
  void operator()(T& value) const { ++value; }
};

/**
 * @brief         Functor to print value.
 */
template <typename T>
struct Print {
  void operator()(const T& value) const { std::cout << value << std::endl; }
};

}  // namespace

/**
 * @brief         Main
 *
 * @return        Return code.
 */
int main() {
  int array[5] = {0, 1, 2, 3, 4};
  int array_size = sizeof(array) / sizeof(array[0]);
  iterator_helper::ArrayList<int> list(array, array_size);
  iterator_helper::ConstArrayList<int> clist(array, array_size);

  std::cout << "[index access with ArrayList]" << std::endl;
  for (std::size_t i = 0; i < list.size(); ++i) {
    std::cout << list[i] << std::endl;
  }

  std::cout << "[index access with ConstArrayList]" << std::endl;
  for (std::size_t i = 0; i < clist.size(); ++i) {
    std::cout << clist[i] << std::endl;
  }

  std::cout << "[begin-end with ArrayList]" << std::endl;
  std::for_each(list.begin(), list.end(), AddOne<int>());

  std::cout << "[cbegin-cend with ArrayList]" << std::endl;
  std::for_each(list.cbegin(), list.cend(), Print<int>());

  std::cout << "[cbegin-cend with ConstArrayList]" << std::endl;
  std::for_each(clist.cbegin(), clist.cend(), Print<int>());

  std::cout << "[Prefix operator]" << std::endl;
  std::cout << *(++clist.cbegin()) << std::endl;

  std::cout << "[Suffix operator]" << std::endl;
  std::cout << *(clist.cbegin()++) << std::endl;

  return 0;
}
