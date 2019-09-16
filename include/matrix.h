#ifndef HOMOLOGY_MATRIX_H_
#define HOMOLOGY_MATRIX_H_

#include <ostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iterator>

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

    template<typename ptype>
    class iterator_base_; 

public:
    Matrix(ilist);
    Matrix(vec2d);

    Matrix(const Matrix &) = default;
    Matrix(Matrix &&) = default;
    ~Matrix() = default;
    Matrix &operator=(const Matrix &) = default;
    Matrix &operator=(Matrix &&) = default;

    size_t constexpr rowdim() const {return rowdim_;}
    size_t constexpr coldim() const {return coldim_;}

    typedef iterator_base_<Matrix*> iterator;
    typedef iterator_base_<const Matrix*> const_iterator;

    iterator begin() {return this;}
    iterator end() {return iterator(this,rowdim(),0);}
    const_iterator begin() const {return this;}
    const_iterator end() const {return const_iterator(this,rowdim(),0);}

private:
    template<typename ptype>
    class iterator_base_ {
    private:
        ptype p_;
        size_t x_;
        size_t y_;

    public:
        // traits
        using diference_type = size_t;
        using value_type = R;
        using pointer = const R*;
        using reference =  const R&;
        using iterator_category = std::random_access_iterator_tag;

        // functionality
        iterator_base_(ptype p);
        iterator_base_(ptype p, size_t x, size_t y);

        iterator_base_ &operator++();
        iterator_base_ &operator--();
        iterator_base_ operator++(int) = delete;
        iterator_base_ operator--(int) = delete;

        bool operator==(iterator_base_ other) const;
        bool operator!=(iterator_base_ other) const;

        reference operator*() const {return p_->data_[x_][y_];}
        pointer operator->() const {return &(p_->data_[x_][y_]);}
    };


public:

    /*
     * friend Matrix operator+
     * 
     * Assumes left and right have the same dimensions.
     *
     */
    friend Matrix operator+(const Matrix &left, const Matrix &right)
    {
        vec2d sum {};
        sum.reserve(left.rowdim());
        for(size_t i = 0; i < left.rowdim(); ++i) {
            std::vector<R> temp{};
            temp.reserve(left.coldim());

            std::transform(std::begin(left.data_[i]),
                    std::end(left.data_[i]),
                    std::begin(right.data_[i]),
                    std::back_inserter(temp),
                    [](R a, R b) {return a+b;});

            sum.emplace_back(std::move(temp));
        }
        return Matrix(std::move(sum));
    }

    friend R multiply_row_by_column(
            const Matrix &left, 
            const Matrix &right,
            size_t i,
            size_t j)
    {
        R total = 0;
        for(size_t h = 0; h < left.coldim(); ++h) {
            total = total + left.data_[i][h] * right.data_[h][j];
        }
        return total;
    }

    friend Matrix operator*(const Matrix &left, const Matrix &right)
    {
        vec2d data;
        data.reserve(left.rowdim());
        for(size_t i = 0; i < left.rowdim(); ++i) {
            std::vector<R> temp {};
            data.emplace_back(std::move(temp));
            data[i].reserve(right.coldim());
            for(size_t j = 0; j < right.coldim(); ++j) {
                R value = multiply_row_by_column(left,right,i,j);
                data[i].push_back(value);
            }
        }
        return Matrix{std::move(data)};
    }

    friend bool operator==(const Matrix &left, const Matrix &right)
    {
        return left.data_ == right.data_;
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

template<typename R>
inline typename Matrix<R>::const_iterator begin(const Matrix<R> &m)
{
    return m.begin();
}

template<typename R>
inline typename Matrix<R>::const_iterator end(const Matrix<R> &m)
{
    return m.end();
}

template<typename R>
inline typename 
Matrix<R>::iterator begin(Matrix<R> &m)
{
    return m.begin();
}

template<typename R>
inline typename 
Matrix<R>::iterator end(Matrix<R> &m)
{
    return m.end();
}

template<typename R> 
inline bool operator!=(const Matrix<R> &left, 
        const Matrix<R> &right)
{
    return !(left == right);
}

template<typename R>
template<typename ptype>
inline Matrix<R>::iterator_base_<ptype>::iterator_base_(ptype p)
    : p_{p}, x_{0}, y_{0}  {}

template<typename R>
template<typename ptype>
inline Matrix<R>::iterator_base_<ptype>
    ::iterator_base_(ptype p, size_t x, size_t y)
    : p_{p}, x_{x}, y_{y}  {}

template<typename R>
template<typename ptype>
inline typename Matrix<R>::template iterator_base_<ptype> & 
    Matrix<R>::iterator_base_<ptype>::operator--()
{
    if(y_ != 0) {
        --y_;
        return *this;
    }
    y_ = p_->coldim() - 1;
    --x_;
    return *this;
}

template<typename R>
template<typename ptype>
inline typename Matrix<R>::template iterator_base_<ptype> & 
    Matrix<R>::iterator_base_<ptype>::operator++() 
{
    if(y_ + 1 < p_->coldim()) {
        ++y_;
        return *this;
    }
    y_ = 0;
    ++x_;
    return *this;
}

template<typename R>
template<typename ptype>
inline bool Matrix<R>
    ::iterator_base_<ptype>
    ::operator==(iterator_base_ other) const
{
    return x_ == other.x_ && y_ == other.y_;
}

template<typename R>
template<typename ptype>
inline bool Matrix<R>
    ::iterator_base_<ptype>
    ::operator!=(iterator_base_ other) const
{
    return !(*this == other);
}



} // namespace homology
#endif // HOMOLOGY_Matrix_H_ 
