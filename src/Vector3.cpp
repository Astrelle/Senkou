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

bool Vector3::operator==(const Vector3& other) const{
    return std::abs(X - other.X) < SenkouMath::EpsilonThreshold &&
           std::abs(Y - other.Y) < SenkouMath::EpsilonThreshold &&
           std::abs(Z - other.Z) < SenkouMath::EpsilonThreshold;
}

bool Vector3::operator!=(const Vector3& other) const{
    return !(*this == other);
}

// Length of the vector!
float Vector3::getMagnitude() const{
    return sqrt((X*X) + (Y*Y) + (Z*Z));
}

// Performance-effective option of magnitude function for checks that don't need exact distance.

float Vector3::getMagnitudeSquare() const{
    return (X*X) + (Y*Y) + (Z*Z);
}

float Vector3::getDistance(const Vector3& a, const Vector3& b){
    return (a - b).getMagnitude();
}

float Vector3::getDistanceSquare(const Vector3& a, const Vector3& b){
    return (a - b).getMagnitudeSquare();
}

float Vector3::getDotProduct(const Vector3& other) const{
    return (X*other.X) + (Y*other.Y) + (Z*other.Z);
}

Vector3 Vector3::getCrossProduct(const Vector3& other) const{
    return Vector3(
        (Y * other.Z) - (Z * other.Y),
        (Z * other.X) - (X * other.Z),
        (X * other.Y) - (Y * other.X)
    );
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

Vector3 Vector3::lerp(const Vector3& a, const Vector3& b, float t){
    t = SenkouMath::clamp(t, 0.0, 1.0);
    //std::cout << t << std::endl;
    return a + (b - a) * t;
}

void Vector3::printVector() const{
    std::cout << X << " " << Y << " " << Z << std::endl;
}