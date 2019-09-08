#ifndef HOMOLOGY_Z_H_
#define HOMOLOGY_Z_H_

#include <ostream>

namespace homology {



template<int N>
requires N > 0
class Z {
private:
    int value_;

    static constexpr int modulo(int);
public:

    constexpr Z() noexcept {}
    constexpr Z(int) noexcept;

    Z(const Z &) = default;
    Z(Z &&) = default;
    ~Z() = default;
    Z &operator=(const Z &) = default;
    Z &operator=(Z &&) = default;


    friend constexpr Z operator+(Z z) 
    {
        return z;
    }

    friend constexpr Z operator-(Z z) 
    {
        return Z{-z.value_};
    }

    friend constexpr Z operator+(Z left, Z right)
    {
        return Z{left.value_ + right.value_};
    }
    
    friend constexpr Z operator-(Z left, Z right)
    {
        return Z{left.value_ - right.value_};
    }

    friend constexpr Z operator*(Z left, Z right)
    {
        return Z{left.value_ * right.value_};
    }

    friend constexpr bool operator==(Z left, Z right)
    {
        return left.value_ == right.value_;
    }

    friend constexpr std::ostream &operator<<(std::ostream &o, Z i)
    {
        o << i.value_;
        return o;
    }

};

template<int N>
inline constexpr Z<N>::Z(int i) noexcept
   : value_{modulo(i)} {}



template<int N>
constexpr int Z<N>::modulo(int i)
{
    return (i % N + N) % N;
}



} // namespace homology
#endif // HOMOLOGY_Z_H_ 
