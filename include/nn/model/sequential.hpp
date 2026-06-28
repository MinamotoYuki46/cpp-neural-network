#pragma once 

#include "nn/core/matrix.hpp"
#include "nn/layers/layers.hpp"

#include <cstddef>
#include <memory>
#include <vector>

namespace nn {

    /**
     * @brief Sequential neural network model.
     *
     * Stores layers and applies them one by one:
     *
     * @f[
     * y = f_n(f_{n-1}(...f_1(x)))
     * @f]
     */

    class Sequential {
        private:
            std::vector<std::unique_ptr<Layer>> layers_;

        public:
            Sequential() = default;

            Sequential(const Sequential&) = delete;
            Sequential& operator=(const Sequential&) = delete;

            Sequential(Sequential&&) noexcept = default;
            Sequential& operator=(Sequential&&) noexcept = default;

            void add(std::unique_ptr<Layer> layer);

            [[nodiscard]] Matrix forward(const Matrix& input);
            [[nodiscard]] std::size_t size() const noexcept;
    };
}