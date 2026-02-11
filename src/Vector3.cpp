#include "Vector3.hpp"
#include "MathUtils.hpp"
#include <iostream>
#include <cmath>

Vector3::Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}

// Operator functionality

Vector3 Vector3::operator-(const Vector3& other) const{
    return Vector3(X - other.X, Y - other.Y, Z - other.Z);
}

Vector3 Vector3::operator+(const Vector3& other) const{
    return Vector3(X + other.X, Y + other.Y, Z + other.Z);
}

Vector3 Vector3::operator*(float scalar) const{
    return Vector3(X*scalar, Y*scalar, Z*scalar);
}

Vector3 Vector3::operator/(float scalar) const{
    return Vector3(X/scalar, Y/scalar, Z/scalar);
}

// Length of the vector!
float Vector3::getMagnitude() const{
    return sqrt((X*X) + (Y*Y) + (Z*Z));
}

// Performance-effective option of magnitude function for checks that don't need exact distance.

float Vector3::getMagnitudeSquare() const{
    return (X*X) + (Y*Y) + (Z*Z);
}

float Vector3::getDotProduct(const Vector3& other) const{
    return (X*other.X) + (Y*other.Y) + (Z*other.Z);
}

// Returns a vector with a length of 1, a direction vector!
Vector3 Vector3::normalize() const{
    float distance = getMagnitude();

    if (distance > SenkouMath::EpsilonThreshold){
        return (*this) / distance;
    }
    else{
        return Vector3(0, 0, 0);
    }

}

void Vector3::printVector() const{
    std::cout << X << " " << Y << " " << Z << std::endl;
}