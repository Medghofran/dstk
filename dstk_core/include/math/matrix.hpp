#pragma once

#include <cstdint>
#include <cstdlib>

namespace dstk {

template<typename t_inner_type, std::uint16_t __rows, std::uint16_t __cols>
class mat {
private:
  t_inner_type *_inner_array;
  std::uint16_t _rows, _cols;

public:
  mat() {
    _inner_array = (t_inner_type*)malloc(sizeof(t_inner_type) * __rows * __cols);
    _rows = __rows;
    _cols = __cols;
  }

  ~mat() {
    // delete allocated resources
    delete _inner_array;
  }

  // basic matrix operations
  mat<t_inner_type, __cols, __rows> transpose();
  mat<t_inner_type, __rows, __cols> operator+(const mat<t_inner_type, __rows, __cols> &_other);
  mat<t_inner_type, __rows, __cols> operator-(const mat<t_inner_type, __rows, __cols> &_other);
  mat<t_inner_type, __rows, __cols> operator*(const mat<t_inner_type, __rows, __cols> &_other);
  const t_inner_type operator[](std::uint16_t _row);
};

}// namespace dstk