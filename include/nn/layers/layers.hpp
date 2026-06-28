#pragma once

#include <nn/core/matrix.hpp>

namespace nn {
    /**
     * @brief Base abstract layer
     */


class Layer {
    public:
        virtual Matrix forward(const Matrix& input) = 0;
        virtual ~Layer() = default;
};

    
};