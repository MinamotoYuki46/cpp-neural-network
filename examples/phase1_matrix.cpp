#include "nn/core/matrix.hpp"

#include <iostream>

int main(){
    nn::Matrix a(2, 3);

    a(0, 0) = 1.0;
    a(0, 1) = 2.0;
    a(0, 2) = 3.0;
    a(1, 0) = 4.0;
    a(1, 1) = 5.0;
    a(1, 2) = 6.0;

    nn::Matrix b = a;
    nn::Matrix c = std::move(b);

    for (std::size_t i = 0; i < c.rows(); ++i) {
        for (std::size_t j = 0; j < c.cols(); ++j) {
            std::cout << c(i, j) << ' ';
        }
        std::cout << '\n';
    }
}
