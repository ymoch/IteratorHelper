/**
 * @file
 * @brief   Header and implementation of ConstArrayIterator.
 *
 * @author  ymoch
 * @date    2015-06-02  ymoch
 */
#ifndef ITERATOR_HELPER_ARRAY_CONST_ARRAY_ITERATOR_H
#define ITERATOR_HELPER_ARRAY_CONST_ARRAY_ITERATOR_H

#include <cstddef>

namespace iterator_helper {

/**
 * @brief   Const iterator for an array.
 */
template <typename ValueType, typename SizeType = std::size_t>
class ConstArrayIterator {
 public:
  /**
   * @brief         Constructor.
   *
   * @param[in]     first   First element of the array.
   * @param[in]     index   Index of the pointed element in that array.
   * @param[in]     size    Array size.
   */
  ConstArrayIterator(const ValueType* first, const SizeType& index,
                     const SizeType& size)
      : first_(first), index_(index), size_(size) {}

  /**
   * @brief         Copy constructor.
   *
   * @param[in]     that  Copied object
   */
  ConstArrayIterator(const ConstArrayIterator& that)
      : first_(that.first_), index_(that.index_), size_(that.size_) {}

  /**
   * @brief         Operator =.
   *
   * @param[in]     that  Copied object.
   * @return        This object.
   */
  ConstArrayIterator& operator=(const ConstArrayIterator& that) {
    first_ = that.first_;
    index_ = that.index_;
    size_ = that.size_;
    return *this;
  }

  /**
   * @brief         Operator ==.
   *
   * @param[in]     that  Compared object.
   * @return        This pbject and that object point the same point or not.
   * @note          This operator checks pointers and indexes but sizes.
   */
  bool operator==(const ConstArrayIterator& that) const {
    if (first_ != that.first_) {
      return false;
    }
    if (index_ != that.index_) {
      return false;
    }
    return true;
  }

  /**
   * @brief         Operator ==.
   *
   * @param[in]     that  Compared object.
   * @return        This pbject and that object point different points or not.
   * @note          This operator checks pointers and indexes but sizes.
   */
  bool operator!=(const ConstArrayIterator& that) const {
    return !(*this == that);
  }

  /**
   * @brief         Operator *.
   *
   * @return        Pointed element.
   */
  const ValueType& operator*() const { return *(first_ + index_); }

  /**
   * @brief         Operator ->.
   *
   * @return        Pointed element.
   */
  const ValueType* operator->() const { return first_ + index_; }

  /**
   * @brief         Prefix operator ++.
   *
   * @return        Incremented iteretor.
   */
  ConstArrayIterator& operator++() {
    ++index_;
    return *this;
  }

  /**
   * @brief         Suffix operator ++.
   *
   * @return        Not incremented iterator.
   */
  ConstArrayIterator operator++(int) {
    ConstArrayIterator old(*this);
    ++index_;
    return old;
  }

 private:
  const ValueType* first_;  //!< First element.
  SizeType index_;          //!< Index that this points.
  SizeType size_;           //!< Array size.
};

}  // namespace iterator_helper

#endif  // ITERATOR_HELPER_ARRAY_CONST_ARRAY_ITERATOR_H
