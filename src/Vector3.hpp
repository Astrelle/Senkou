#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Vector3 {
    float X, Y, Z;

    Vector3(float x, float y, float z);

    Vector3 operator-(const Vector3& other) const;
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar) const;

    float getMagnitude();

    Vector3 normalize();

    void printVector();
};

#endif