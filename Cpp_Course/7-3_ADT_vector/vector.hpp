#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

/// @file

/// ADT vector
//
/// This is an ADT that implements vector values.
/// The x and y are stored as two integers.
/// The appropriate constructors and operators are provided.

class vector
{
private:
    int x;
    int y;
public:
    vector(int x, int y);
    ~vector();
    vector operator+(const vector & rhs) const;
    vector operator-(const vector & rhs) const;
    vector operator*(const int rhs) const;
    vector & operator+=(const vector & rhs);
    vector operator-() const;
    vector operator+() const;
    vector & operator-=(const vector & rhs);
    vector & operator*=(const int rhs);
    vector operator/(const int rhs) const;
    vector & operator/=(const int rhs);
    friend vector operator*(const int lhs, const vector & rhs);
    bool operator==( const vector & rhs ) const;
    friend std::ostream & operator<<(std::ostream & lhs, const vector & rhs);

};

#endif // VECTOR_HPP
