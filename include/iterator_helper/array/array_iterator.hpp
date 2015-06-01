/**
 * @file
 * @brief   Header and implementation of ArrayIterator.
 *
 * @author  ymoch
 * @date    2015-06-02  ymoch
 */
#ifndef ITERATOR_HELPER_ARRAY_ARRAY_ITERATOR_H_
#define ITERATOR_HELPER_ARRAY_ARRAY_ITERATOR_H_

#include "const_array_iterator.hpp"

namespace iterator_helper {

/**
 * @brief   Iterator for an array.
 */
template <typename ValueType, typename SizeType = std::size_t>
class ArrayIterator : public ConstArrayIterator<ValueType, SizeType> {
  typedef ConstArrayIterator<ValueType, SizeType> ConstType;

 public:
  /**
   * @brief         Constructor.
   *
   * @param[in]     first   First element of the array.
   * @param[in]     index   Index of the pointed element in that array.
   * @param[in]     size    Array size.
   */
  ArrayIterator(ValueType* first, const SizeType& index, const SizeType& size)
      : ConstType(first, index, size) {}

  /**
   * @brief         Copy constructor.
   *
   * @param[in]     that  Copied object
   */
  ArrayIterator(const ArrayIterator& that) : ConstType(that) {}

  /**
   * @brief         Operator =.
   *
   * @param[in]     that  Copied object.
   * @return        This object.
   */
  ArrayIterator& operator=(const ArrayIterator& that) {
    ConstType::operator=(that);
    return *this;
  }

  /**
   * @brief         Operator *.
   *
   * @return        Pointed element.
   */
  ValueType& operator*() {
    return const_cast<ValueType&>(ConstType::operator*());
  }

  /**
   * @brief         Operator ->.
   *
   * @return        Pointed element.
   */
  ValueType* operator->() {
    return const_cast<ValueType*>(ConstType::operator->());
  }
};

}  // namespace iterator_helper

#endif  // ITERATOR_HELPER_ARRAY_ARRAY_ITERATOR_H_
