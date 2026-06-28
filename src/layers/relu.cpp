#include "nn/layers/relu.hpp"
#include "nn/core/matrix.hpp"

namespace nn {
    Matrix ReLU::forward(const Matrix& input){
        Matrix output(input);

        for (std::size_t i = 0; i < output.rows(); ++i) {
            for (std::size_t j = 0; j < output.cols(); ++j) {
                if (output(i, j) < 0.0) {
                    output(i, j) = 0.0;
                }
            }
        }
        return output;
    }
}