#pragma once

#include <cstddef>
#include <nn/core/matrix.hpp>
#include <nn/layers/layers.hpp>

namespace nn {

    class Linear : public Layer {
        private:
            Matrix weights_;
            Matrix bias_;
        
        public:
            Linear(std::size_t in_features, std::size_t out_features);
            Matrix forward(const Matrix& input) override;
    };
}