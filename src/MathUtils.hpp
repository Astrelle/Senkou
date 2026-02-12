#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

namespace SenkouMath {
    
    //Epsilon float safeguard for comparisons

    constexpr float EpsilonThreshold = 0.000001f;

    // Pi, I'll probably need it.

    constexpr float Pi = 3.1415926f;

    // Implementation of std::clamp for safeguard

    static float clamp(float value, float min, float max){
        if (value < min) 
            return min;
        if (value > max)
            return max;
        return value;
    }
}
#endif