#include "Matrix4.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

Matrix4::Matrix4() {
    setIdentity();
}

void Matrix4::setIdentity() {
    M[0] = 1.0f; M[1] = 0.0f; M[2] = 0.0f; M[3] = 0.0f;
    M[4] = 0.0f; M[5] = 1.0f; M[6] = 0.0f; M[7] = 0.0f;
    M[8] = 0.0f; M[9] = 0.0f; M[10] = 1.0f; M[11] = 0.0f;
    M[12] = 0.0f; M[13] = 0.0f; M[14] = 0.0f; M[15] = 1.0f;
}

void Matrix4::printMatrix() const {
    std::cout << "\n------------------------\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "| ";
        for (int j = 0; j < 4; ++j) {
            std::cout << std::setw(5) << M[i * 4 + j] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "---------------------\n";
}

Vector3 Matrix4::multiplyVector(const Vector3& vec) const {
    return Vector3(
        (M[0] * vec.X) + (M[1] * vec.Y) + (M[2] * vec.Z) + (M[3] * 1.0f),
        (M[4] * vec.X) + (M[5] * vec.Y) + (M[6] * vec.Z) + (M[7] * 1.0f),
        (M[8] * vec.X) + (M[9] * vec.Y) + (M[10] * vec.Z) + (M[11] * 1.0f)
    );

}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
    Matrix4 result;
    
    // Row 0 x Columns 0-3
    result.M[0]  = M[0]*other.M[0] + M[1]*other.M[4] + M[2]*other.M[8]  + M[3]*other.M[12];
    result.M[1]  = M[0]*other.M[1] + M[1]*other.M[5] + M[2]*other.M[9]  + M[3]*other.M[13];
    result.M[2]  = M[0]*other.M[2] + M[1]*other.M[6] + M[2]*other.M[10] + M[3]*other.M[14];
    result.M[3]  = M[0]*other.M[3] + M[1]*other.M[7] + M[2]*other.M[11] + M[3]*other.M[15];

    // Row 1 x Columns 0-3
    result.M[4]  = M[4]*other.M[0] + M[5]*other.M[4] + M[6]*other.M[8]  + M[7]*other.M[12];
    result.M[5]  = M[4]*other.M[1] + M[5]*other.M[5] + M[6]*other.M[9]  + M[7]*other.M[13];
    result.M[6]  = M[4]*other.M[2] + M[5]*other.M[6] + M[6]*other.M[10] + M[7]*other.M[14];
    result.M[7]  = M[4]*other.M[3] + M[5]*other.M[7] + M[6]*other.M[11] + M[7]*other.M[15];

    // Row 2 x Columns 0-3
    result.M[8]  = M[8]*other.M[0] + M[9]*other.M[4] + M[10]*other.M[8] + M[11]*other.M[12];
    result.M[9]  = M[8]*other.M[1] + M[9]*other.M[5] + M[10]*other.M[9] + M[11]*other.M[13];
    result.M[10] = M[8]*other.M[2] + M[9]*other.M[6] + M[10]*other.M[10]+ M[11]*other.M[14];
    result.M[11] = M[8]*other.M[3] + M[9]*other.M[7] + M[10]*other.M[11]+ M[11]*other.M[15];

    // Row 3 x Columns 0-3
    result.M[12] = M[12]*other.M[0] + M[13]*other.M[4] + M[14]*other.M[8] + M[15]*other.M[12];
    result.M[13] = M[12]*other.M[1] + M[13]*other.M[5] + M[14]*other.M[9] + M[15]*other.M[13];
    result.M[14] = M[12]*other.M[2] + M[13]*other.M[6] + M[14]*other.M[10]+ M[15]*other.M[14];
    result.M[15] = M[12]*other.M[3] + M[13]*other.M[7] + M[14]*other.M[11]+ M[15]*other.M[15];

    return result;
}

Matrix4 Matrix4::makeTranslation(float x, float y, float z) {
    Matrix4 transMatrix;
    transMatrix.M[12] = x;
    transMatrix.M[13] = y;
    transMatrix.M[14] = z;
    return transMatrix;
}

Matrix4 Matrix4::makeScale(float x, float y, float z) {
    Matrix4 scaleMatrix;
    scaleMatrix.M[0] = x;
    scaleMatrix.M[5] = y;
    scaleMatrix.M[10] = z;
    return scaleMatrix;
}

Matrix4 Matrix4::makeRotationX(float radians) {
    Matrix4 rotXMatrix;
    float c = cosf(radians);
    float s = sinf(radians);

    rotXMatrix.M[5] = c;
    rotXMatrix.M[6] = s;
    rotXMatrix.M[9] = s;
    rotXMatrix.M[10] = c;

    return rotXMatrix;
}

Matrix4 Matrix4::makeRotationY(float radians) {
    Matrix4 rotYMatrix;
    float c = cosf(radians);
    float s = sinf(radians);

    rotYMatrix.M[0] = c;
    rotYMatrix.M[2] = -s;
    rotYMatrix.M[8] = s;
    rotYMatrix.M[10] = c;

    return rotYMatrix;
}

Matrix4 Matrix4::makeRotationZ(float radians) {
    Matrix4 rotZMatrix;
    float c = cosf(radians);
    float s = sinf(radians);

    rotZMatrix.M[0] = c;
    rotZMatrix.M[1] = s;
    rotZMatrix.M[4] = -s;
    rotZMatrix.M[5] = c;

    return rotZMatrix;
}