#include "nn/core/matrix.hpp"
#include "nn/layers/linear.hpp"
#include "nn/layers/relu.hpp"
#include "nn/model/sequential.hpp"

#include <iostream>
#include <memory>

int main() {
    nn::Matrix input(1, 4);

    input(0, 0) = 5.0;
    input(0, 1) = 2.0;
    input(0, 2) = 3.0;
    input(0, 3) = 1.0;

    nn::Sequential model;

    model.add(std::make_unique<nn::Linear>(4, 8));
    model.add(std::make_unique<nn::ReLU>());
    model.add(std::make_unique<nn::Linear>(8, 3));

    auto output = model.forward(input);

    std::cout << output;
}