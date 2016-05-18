#include "vector.hpp"

/// constructor from explicit values
//
/// This constructor initializes a vector into a x and a y.
vector::vector(int x, int y):
x (x), y (y)
{}

vector::~vector()
{}

/// adds one vector to another 
//
/// This operator+ adds a vector to another vector.
vector vector::operator+(const vector & rhs) const{
    return vector(x + rhs.x, y + rhs.y);
}

/// subtracts two vectors from eachother 
// 
/// This operator- subtracts a vector from another vector.  
vector vector::operator-(const vector & rhs) const{
    return vector(x-rhs.x, y - rhs.y);
}

/// multiply a vector by an integer 
//
/// This operator* multiplies a rational value by an integer value. 
vector vector::operator*(const int rhs) const {
    return vector(x * rhs,y * rhs);
}

/// positive number
//
/// This operator+ is called when for example +4 * (3,4)
/// the +4 doesn't have an effect on the answer you would 
/// get with 4 * (3,4), this is why nothing happens when 
/// this operator+ gets called. 
vector vector::operator+() const{
}

/// negative number
//
/// This operator- is called when for example -4 * (3,4)
/// the -4 has an effect on the answer you would otherwise get
/// with 4 * (3,4), this is why when this operator- is called the 
/// number is made negative. 
vector vector::operator-() const{
    int p = x * -1;
    int s = y * -1;
    return vector(p,s);
}

/// adds a vector to another vector 
//
/// This operator+= adds a vector value a vector variable.
vector & vector::operator+=(const vector & rhs){
    x = x + rhs.x;
    y = y + rhs.y;
    return *this;
}

/// subtracts a vector to another vector 
//
/// This operator-= subtracts a vector value a vector variable. 
vector & vector::operator-=(const vector & rhs){
    x = x - rhs.x;
    y = y - rhs.y;
    return *this;
}

/// multiplies a vector by an integer
//
/// This operator*= multiplies a vector by an integer
vector & vector::operator*=(const int rhs){
    x = x * rhs;
    y = y * rhs;
    return *this;
}

/// devides a vector with an integer 
//
/// This operator/ devides a vector with an integer 
vector vector::operator/(const int rhs) const {
    return vector(x / rhs,y / rhs);
}

/// devides a vector with an integer
//
/// This operator/= devides a vector with an integer 
vector & vector::operator/=(const int rhs){
    x = x / rhs;
    y = y / rhs;
    return *this;
}

/// multiplies an integer with a vector 
//
/// This operator* multiplies an integer with a vector 
vector operator*(const int lhs, const vector & rhs){
    return vector(lhs*rhs.x , lhs*rhs.y);
} 

bool vector::operator==( const vector & rhs ) const {
        return ( x == rhs.x ) && ( y == rhs.y );
   }



std::ostream & operator<<(std::ostream & lhs, const vector & rhs){
    return lhs
        << "["
        << rhs.x
        << "/"
        << rhs.y
        << "]";
}

