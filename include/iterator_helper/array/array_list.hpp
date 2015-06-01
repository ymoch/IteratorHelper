/**
 * @file
 * @brief   Header and implementation of ArrayList.
 *
 * @author  ymoch
 * @date    2015-06-02  ymoch
 */
#ifndef ITERATOR_HELPER_ARRAY_ARRAY_LIST_H_
#define ITERATOR_HELPER_ARRAY_ARRAY_LIST_H_

#include "const_array_list.hpp"
#include "array_iterator.hpp"

namespace iterator_helper {

/**
 * @brief   Array list that can change its own elements.
 */
template <typename ValueType, typename SizeType = std::size_t>
class ArrayList : public ConstArrayList<ValueType, SizeType> {
  typedef ConstArrayList<ValueType, SizeType> ConstType;

 public:
  /**
   * @brief         Iterator that cannot change properties of this object.
   */
  typedef typename ConstType::ConstIterator ConstIterator;

  /**
   * @brief         Iterator that can change properties of this object.
   */
  typedef ArrayIterator<ValueType, SizeType> Iterator;

  /**
   * @brief         Constructor.
   *
   * @param[in]     first   First element of the array.
   * @param[in]     size    Number of elements in this array.
   */
  ArrayList(ValueType* first, const SizeType& size) : ConstType(first, size) {}

  /**
   * @brief         Copy constructor.
   *
   * @param[in]     that  Copied object
   */
  ArrayList(const ArrayList& that) : ConstType(that) {}

  /**
   * @brief         Operator =.
   *
   * @param[in]     that  Copied object.
   * @return        This object.
   */
  ArrayList& operator=(const ArrayList& that) {
    ConstType::operator=(that);
    return *this;
  }

  /**
   * @brief         Get the pointer to the body.
   *
   * @return        Pointer to the body.
   */
  ValueType* data() { return const_cast<ValueType*>(ConstType::data()); }

  /**
   * @brief         Operator [].
   *
   * @param[in]     index   Index of the element.
   * @return        Pointed element.
   */
  ValueType& operator[](const SizeType& index) {
    return const_cast<ValueType&>(ConstType::operator[](index));
  }

  /**
   * @brief         Get the const iterator to the beginning of this sequence.
   *
   * @return        Const iterator to the beginning of this sequence.
   */
  Iterator begin() { return Iterator(this->data(), 0, ConstType::size()); }

  /**
   * @brief         Get the const iterator to the element past the end of the
   *                sequence.
   *
   * @return        Const iterator to the element past the end of the sequence.
   */
  Iterator end() {
    return Iterator(this->data(), ConstType::size(), ConstType::size());
  }
};

}  // namespace iterator_helper

#endif  // ITERATOR_HELPER_ARRAY_ARRAY_LIST_H_
