#include "Vector3.hpp"
#include <iostream>
#include <cmath>

const float EpsilonThreshold = 0.000001f;

Vector3::Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(X - other.X, Y - other.Y, Z - other.Z);
}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(X + other.X, Y + other.Y, Z + other.Z);
}

Vector3 Vector3::operator*(float scalar) const{
    return Vector3(X*scalar, Y*scalar, Z*scalar);
}

Vector3 Vector3::operator/(float scalar) const{
    return Vector3(X/scalar, Y/scalar, Z/scalar);
}

// Length of the vector!
float Vector3::getMagnitude(){
    return sqrt((X*X) + (Y*Y) + (Z*Z));
}

// Returns a vector with a length of 1, a direction vector!
Vector3 Vector3::normalize(){
    float distance = getMagnitude();

    if (distance > EpsilonThreshold) {
        return (*this) / distance;
    }
    else{
        return Vector3(0, 0, 0);
    }

}

void Vector3::printVector(){
    std::cout << X << " " << Y << " " << Z << std::endl;
}