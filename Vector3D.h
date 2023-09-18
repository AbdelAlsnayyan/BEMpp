#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cassert>
#include <cmath>
#include <ostream>

namespace CG{

class Vector3D {

 public:

  //Vector3D(double x, double y, double z) { m_v[0] = x; m_v[1] = y; m_v[2] = z; };
  Vector3D(double x_in, double y_in, double z_in) : x(x_in), y(y_in), z(z_in) {};
  Vector3D() { x = y = z = 0; };

// returns x, y, z
  inline double& operator[] ( const int& index ) {
    return ( &x )[ index ];
  }

// addition
  inline Vector3D operator+( const Vector3D& v ) const {
    return Vector3D( x + v.x, y + v.y, z + v.z );
  }

  // subtraction
  inline Vector3D operator-( const Vector3D& v ) const {
    return Vector3D( x - v.x, y - v.y, z - v.z );
  }

 // dot product (a.k.a. inner or scalar product)
 inline double dot( const Vector3D& u, const Vector3D& v ) {
   return u.x*v.x + u.y*v.y + u.z*v.z ;
 }

// cross product
 inline Vector3D cross(const Vector3D& v ) {
   return Vector3D( this->y*v.z - this->z*v.y,
                   this->z*v.x - this->x*v.z,
                   this->x*v.y - this->y*v.x );
 }

 // cross product
 inline Vector3D cross( const Vector3D& u, const Vector3D& v ) {
   return Vector3D( u.y*v.z - u.z*v.y,
                   u.z*v.x - u.x*v.z,
                   u.x*v.y - u.y*v.x );
 }

// 2 norm
  inline double norm2( void ) const {
    return sqrt( x*x + y*y + z*z );
  }

   // unit vector.
inline Vector3D unit( void ) const {
    double rNorm = 1. / sqrt( x*x + y*y + z*z );
    return Vector3D( rNorm*x, rNorm*y, rNorm*z );
  }

  // right scalar multiplication
  inline Vector3D operator*( const double& c ) const {
    return Vector3D( x * c, y * c, z * c );
  }


 private:
  double x;
  double y;
  double z;

};

}
#endif
