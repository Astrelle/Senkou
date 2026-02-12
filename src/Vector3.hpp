#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Vector3 {
    float X, Y, Z;

    Vector3(float x, float y, float z);


    // handle operators and operator overloading
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar) const;
    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    // find magnitude and offer performance-effective magnitude square function for quick checks.
    float getMagnitude() const;
    float getMagnitudeSquare() const;

    static float getDistance(const Vector3& a, const Vector3& b);
    static float getDistanceSquare(const Vector3& a, const Vector3& b);

    float getDotProduct(const Vector3& other) const;

    Vector3 getCrossProduct(const Vector3& other) const;

    static Vector3 lerp(const Vector3& a, const Vector3& b, float t);

    // create directional vector
    Vector3 normalize() const;

    void printVector() const;
};

#endif