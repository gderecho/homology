#ifndef HOMOLOGY_MATRIX_H_
#define HOMOLOGY_MATRIX_H_

#include <ostream>
#include <vector>
#include <initializer_list>
#include <algorithm>

#include <ring.h>

namespace homology {

template<typename R>
class Matrix {
private:
    using vec2d = std::vector<std::vector<R>>;
    using ilist = std::initializer_list<std::vector<R>>;

    vec2d data_;
    size_t rowdim_;
    size_t coldim_;

public:
    Matrix(ilist);
    Matrix(vec2d);

    Matrix(const Matrix &) = default;
    Matrix(Matrix &&) = default;
    ~Matrix() = default;
    Matrix &operator=(const Matrix &) = default;
    Matrix &operator=(Matrix &&) = default;

    size_t rowdim() const {return rowdim_;}
    size_t coldim() const {return coldim_;}

    /*
     * friend Matrix operator+
     * 
     * Assumes left and right have the same dimensions.
     *
     */
    friend Matrix operator+(const Matrix &left, const Matrix &right)
    {
        size_t rowdim = left.rowdim();
        size_t coldim = left.coldim();
        vec2d sum {};
        sum.reserve(rowdim);
        for(size_t i = 0; i < rowdim; ++i) {
            std::vector<R> temp{};
            temp.reserve(coldim);

            std::transform(begin(left.data_[i]),
                    end(left.data_[i]),
                    begin(right.data_[i]),
                    back_inserter(temp),
                    [](R a, R b) {return a+b;});

            sum.emplace_back(std::move(temp));
        }
        return sum;
    }

    friend Matrix operator*(const Matrix &left, const Matrix &right)
    {
        return {{0}};
    }

    friend bool operator==(const Matrix &left, const Matrix &right)
    {
        return left.data_ == right.data_;
    }

    friend bool operator!=(const Matrix &left, const Matrix &right)
    {
        return false;
    }
};

template<typename R>
inline Matrix<R>::Matrix(ilist init_list)
    : data_{init_list}, 
      rowdim_{data_.size()},
      coldim_{rowdim_ > 0 ? data_[0].size() : 0} 
{}

template<typename R>
inline Matrix<R>::Matrix(vec2d vec)
    : data_{vec}, 
      rowdim_{data_.size()},
      coldim_{rowdim_ > 0 ? data_[0].size() : 0} 
{}


} // namespace homology
#endif // HOMOLOGY_Matrix_H_ 
