#include "Vector3.hpp"
#include <iostream>

int main(){

    Vector3 vector = {2, 3, 6};
    Vector3 normalizedVector = vector.normalize();

    std::cout << "Magnitude of (2, 3, 6): " << vector.getMagnitude() << std::endl;  
    normalizedVector.printVector();
    std::cout << "Magnitude of normalized vector! If 1 then success: " << normalizedVector.getMagnitude() << std::endl;

    Vector3 player(1, 1, 1);
    Vector3 target(2, 3, 6);
    Vector3 finalPos = player + target;

    finalPos.printVector();

    Vector3 toOriginalVector = finalPos - vector;
    float distance = toOriginalVector.getMagnitude();
    Vector3 dir = toOriginalVector.normalize();

    dir.printVector();

}