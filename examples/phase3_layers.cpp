#include "nn/core/matrix.hpp"
#include "nn/layers/linear.hpp"
#include "nn/layers/relu.hpp"

#include <iostream>

int main() {
    nn::Matrix input(1, 4);

    input(0,0)=5;
    input(0,1)=2;
    input(0,2)=3;
    input(0,3)=1;

    nn::Linear fc(4, 3);
    nn::ReLU relu;

    auto out = fc.forward(input);
    auto activated = relu.forward(out);

    std::cout << activated;
}