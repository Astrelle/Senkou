#include "Vector3.hpp"
#include "MathUtils.hpp"
#include "Matrix4.hpp"
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

    // Vector3 playerMovement = Vector3::lerp(player, target, -.1);


    //I'm going to be honest I'm too lazy to write these tests I'm uploading this file to Gemini and asking it to write tests for new functionality.
    // --- New Tests: Equality and Lerp ---
    std::cout << "\n--- Testing Equality and Lerp ---" << std::endl;

    // Test 1: Epsilon Equality
    // We create a vector that is technically different by a tiny amount
    Vector3 vA(1.0f, 1.0f, 1.0f);
    Vector3 vB(1.00000001f, 1.0f, 1.0f); 

    if (vA == vB) {
        std::cout << "Success: vA and vB are equal within Epsilon!" << std::endl;
    } else {
        std::cout << "Failure: Equality check is too strict." << std::endl;
    }

    // Test 2: Standard Lerp (50% mark)
    Vector3 start(0, 0, 0);
    Vector3 end(10, 10, 10);
    Vector3 mid = Vector3::lerp(start, end, 0.5f);

    std::cout << "Lerp 50% (Expected 5 5 5): ";
    mid.printVector();

    // Test 3: Clamped Lerp (Overshoot)
    // t = 2.0 should be clamped to 1.0 (returning the 'end' vector)
    Vector3 overshoot = Vector3::lerp(start, end, 2.0f);
    
    if (overshoot == end) {
        std::cout << "Success: Lerp correctly clamped 2.0 to 1.0!" << std::endl;
    } else {
        std::cout << "Failure: Lerp overshoot was not clamped." << std::endl;
    }

    // --- Testing Distance Functions ---
    std::cout << "\n--- Testing Distance ---" << std::endl;

    // A 3-4-5 triangle scenario:
    // Point A at (0, 0, 0)
    // Point B at (3, 4, 0)
    // The distance should be exactly 5.0
    Vector3 pointA(0, 0, 0);
    Vector3 pointB(3, 4, 0);

    float dist = Vector3::getDistance(pointA, pointB);
    float distSq = Vector3::getDistanceSquare(pointA, pointB);

    std::cout << "Distance between (0,0,0) and (3,4,0): " << dist << std::endl;
    std::cout << "Distance Square: " << distSq << std::endl;

    // Verification logic using your Epsilon
    if (std::abs(dist - 5.0f) < SenkouMath::EpsilonThreshold) {
        std::cout << "Success: Distance is correctly calculated as 5!" << std::endl;
    }

    if (std::abs(distSq - 25.0f) < SenkouMath::EpsilonThreshold) {
        std::cout << "Success: Distance Square is correctly calculated as 25!" << std::endl;
    }

    // --- testing Matrix4 baseline ---
    Matrix4 matrix;
    matrix.printMatrix();

    // --- test Matrix-Vector Multiplication ---
    Vector3 point(1.0f, 2.0f, 3.0f);

    Vector3 identityResult = matrix.multiplyVector(point);
    std::cout << "Identity Test (Expected 1 2 3): ";
    identityResult.printVector();

    if (identityResult == point) {
        std::cout << "Success: Identity matrix left vector unchanged." << std::endl;
    } else{
        std::cout << "Failure: Identity amtrix alterted vector coordinates." << std::endl;
    }

    Matrix4 translationMatrix;

    translationMatrix.M[3] = 5.0f; //X +5
    translationMatrix.M[7] = -3.0f; //Y -3
    translationMatrix.M[11] = 10.0f; //Z +10

    std::cout << "\nTranslation Matrix:";
    translationMatrix.printMatrix();

    Vector3 translatedResult = translationMatrix.multiplyVector(point); //(1+5[6], 2-3[-1], 3+10[13]) 6, -1, 13 expected
    translatedResult.printVector();

}