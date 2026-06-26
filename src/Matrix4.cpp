#include "Matrix4.hpp"
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