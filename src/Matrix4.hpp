#ifndef MATRIX4_HPP
#define MATRIX4_HPP

#include "Vector3.hpp"

struct Matrix4 {
    /* 4x4 matrix layout:
    [0] [1] [2] [3]
    [4] x x x
    [8] x x x 
    [12] x x x
    */

    float M[16];

    Matrix4();

    void setIdentity();

    void printMatrix() const;

    Vector3 multiplyVector(const Vector3& vec) const;

    Matrix4 operator*(const Matrix4& other) const;

    static Matrix4 makeTranslation(float x, float y, float z);

    static Matrix4 makeScale(float x, float y, float z);

    static Matrix4 makeRotationX(float radians);
    static Matrix4 makeRotationY(float radians);
    static Matrix4 makeRotationZ(float radians);
};

#endif