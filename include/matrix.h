#ifndef HOMOLOGY_Matrix_H_
#define HOMOLOGY_Matrix_H_

#include <ostream>
#include <vector>
#include <initializer_list>

namespace homology {

template<typename R>
class Matrix {
private:
    using vec2d = std::vector<std::vector<R>>;
    using ilist = std::initializer_list<std::vector<R>>;

    vec2d data_;

public:
    constexpr Matrix(ilist init_list) noexcept;

    Matrix(const Matrix &) = default;
    Matrix(Matrix &&) = default;
    ~Matrix() = default;
    Matrix &operator=(const Matrix &) = default;
    Matrix &operator=(Matrix &&) = default;

};

template<typename R>
inline constexpr Matrix<R>::Matrix(ilist init_list) noexcept
    : data_(init_list) {}


} // namespace homology
#endif // HOMOLOGY_Matrix_H_ 
