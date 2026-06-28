#pragma once

#include "nn/core/matrix.hpp"
#include "nn/layers/layers.hpp"

namespace nn {
    class ReLU : public Layer {
        public:
            Matrix forward(const Matrix& input) override;
    };
}