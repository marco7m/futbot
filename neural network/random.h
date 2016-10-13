#include <random>

std::random_device rd;
std::mt19937 gen{rd()};
std::uniform_real_distribution<> dis{-1, 1};

namespace randomize{
    double unit_rand(){
        return dis(gen);
    }
}


