/**
 * @file
 * @brief   Header and implementation of ConstArrayList.
 *
 * @author  ymoch
 * @date    2015-06-02  ymoch
 */
#ifndef ITERATOR_HELPER_ARRAY_CONST_ARRAY_LIST_H
#define ITERATOR_HELPER_ARRAY_CONST_ARRAY_LIST_H

#include "const_array_iterator.hpp"

namespace iterator_helper {

/**
 * @brief   Array list that cannot change its own elements.
 */
template <typename ValueType, typename SizeType = std::size_t>
class ConstArrayList {
 public:
  /**
   * @brief         Iterator that cannot change properties of this object.
   */
  typedef ConstArrayIterator<ValueType, SizeType> ConstIterator;

  /**
   * @brief         Constructor.
   *
   * @param[in]     first   First element of the array.
   * @param[in]     size    Number of elements in this array.
   */
  ConstArrayList(const ValueType* first, const SizeType& size)
      : first_(first), size_(size) {}

  /**
   * @brief         Copy constructor.
   *
   * @param[in]     that  Copied object
   */
  ConstArrayList(const ConstArrayList& that)
      : first_(that.first_), size_(that.size_) {}

  /**
   * @brief         Operator =.
   *
   * @param[in]     that  Copied object.
   * @return        This object.
   */
  ConstArrayList& operator=(const ConstArrayList& that) {
    first_ = that.first_;
    size_ = that.size_;
    return *this;
  }

  /**
   * @brief         Get the pointer to the body.
   *
   * @return        Pointer to the body.
   */
  const ValueType* data() const { return first_; }

  /**
   * @brief         Get the size of this array.
   *
   * @return        Size of this array.
   */
  const SizeType& size() const { return size_; }

  /**
   * @brief         Operator [].
   *
   * @param[in]     index   Index of the element.
   * @return        Pointed element.
   */
  template <typename T>
  const ValueType& operator[](const T& index) const {
    return first_[index];
  }

  /**
   * @brief         Get the const iterator to the beginning of this sequence.
   *
   * @return        Const iterator to the beginning of this sequence.
   */
  ConstIterator cbegin() const { return ConstIterator(first_, 0, size_); }

  /**
   * @brief         Get the const iterator to the element past the end of the
   *                sequence.
   *
   * @return        Const iterator to the element past the end of the sequence.
   */
  ConstIterator cend() const { return ConstIterator(first_, size_, size_); }

 private:
  const ValueType* first_;  //!< First element.
  SizeType size_;           //!< Array size.
};

}  // namespace iterator_helper

#endif  // ITERATOR_HELPER_ARRAY_CONST_ARRAY_LIST_H
