#include "math/matrix.hpp"
#include <cstring>

namespace dstk {

//template<typename t_inner_type, std::uint16_t __rows, std::uint16_t __cols>
//mat<t_inner_type, __rows, __cols>::mat() {
//  _inner_array = malloc(sizeof(t_inner_type) * __rows * __cols);
//  _rows = __rows;
//  _cols = __cols;
//}
//
//template<typename t_inner_type, std::uint16_t __rows, std::uint16_t __cols>
//mat<t_inner_type, __rows, __cols>::~mat() {
//  // delete allocated resources
//  delete _inner_array;
//}

template<typename t_inner_type, std::uint16_t __rows, std::uint16_t __cols>
mat<t_inner_type, __cols, __rows> mat<t_inner_type, __rows, __cols>::transpose() {
  mat<t_inner_type, __cols, __rows> _result;

  // copy the current array as is
  std::memcpy(_result._inner_array, _inner_array, sizeof(t_inner_type) * __rows * _cols);

  return _result;
}

template<typename t_inner_type, std::uint16_t __rows, std::uint16_t __cols>
mat<t_inner_type, __rows, __cols> mat<t_inner_type, __rows, __cols>::operator+(const mat<t_inner_type, __rows, __cols> &_other) {
  mat<t_inner_type, __rows, __cols> _result;
  for (size_t i = 0; i < __rows * __cols; i++) {
    _result._inner_array[i] = _inner_array[i] + _other._inner_array[i];
  }
  return _result;
}

template<typename t_inner_type, std::uint16_t __rows, std::uint16_t __cols>
mat<t_inner_type, __rows, __cols> mat<t_inner_type, __rows, __cols>::operator-(const mat<t_inner_type, __rows, __cols> &_other) {
  mat<t_inner_type, __rows, __cols> _result;
  for (size_t i = 0; i < __rows * __cols; i++) {
    _result._inner_array[i] = _inner_array[i] - _other._inner_array[i];
  }
  return _result;
}

template<typename t_inner_type, std::uint16_t __rows, std::uint16_t __cols>
mat<t_inner_type, __rows, __cols> mat<t_inner_type, __rows, __cols>::operator*(const mat<t_inner_type, __rows, __cols> &_other) {
  mat<t_inner_type, __rows, __cols> _result;
  for (size_t i = 0; i < __rows * __cols; i++) {
    _result._inner_array[i] = _inner_array[i] * _other._inner_array[i];
  }
  return _result;
}

template<typename t_inner_type, std::uint16_t __rows, std::uint16_t __cols>
const t_inner_type dstk::mat<t_inner_type, __rows, __cols>::operator[](std::uint16_t _row) {
  return t_inner_type();
}

}// namespace dstk
