#include "nn/core/matrix.hpp"
#include "nn/layers/linear.hpp"
#include <cstddef>

namespace nn {
    Linear::Linear(std::size_t in_features, std::size_t out_features)
        :   weights_(in_features, out_features), 
            bias_(1, out_features) {
                weights_.fill(0.1);
                bias_.fill(0.0);
            }

    Matrix Linear::forward(const Matrix& input){
        Matrix output = input * weights_;

        for (std::size_t i = 0; i < output.rows(); ++i) {
            for (std::size_t j = 0; j < output.cols(); ++j) {
                output(i, j) += bias_(0, j);
            }
        }

        return output;
    }
}