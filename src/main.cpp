#include "Vector3.hpp"
#include "MathUtils.hpp"
#include <iostream>

int main(){

    Vector3 vector(2, 3, 6);
    Vector3 normalizedVector = vector.normalize();

    std::cout << "Magnitude of (2, 3, 6): " << vector.getMagnitude() << " and squared value: " << vector.getMagnitudeSquare() << std::endl;  
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

    Vector3 playerView = Vector3(0, 0, 1).normalize();
    Vector3 behindPlayer = Vector3(0, 0, -1).normalize();
    Vector3 infrontPlayer = Vector3(0, 0, 3).normalize();
    Vector3 abovePlayer = Vector3(0, 2, 0).normalize();


    std::cout << "Proceeding with Dot Product tests! Positive is visible, 0 is perpendicular, negative is not visible!" << std::endl;

    if(playerView.getDotProduct(behindPlayer) <= SenkouMath::EpsilonThreshold){
        std::cout << "Succesfully not visible!" << std::endl;
    }

    if(playerView.getDotProduct(infrontPlayer) >= 0){
        std::cout << "Succesfully visible!" << std::endl;
    }

    if(std::abs(playerView.getDotProduct(abovePlayer)) < SenkouMath::EpsilonThreshold){
        std::cout << "Succesfully perpendicular!" << std::endl;
    }

    std::cout << "Testing finding the cross product!" << std::endl;

    Vector3 viewCrossProduct = Vector3(1,0,0).getCrossProduct(Vector3(0,1,0));
    viewCrossProduct.printVector();

}