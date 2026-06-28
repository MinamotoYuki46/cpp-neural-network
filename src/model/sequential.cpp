#include "nn/model/sequential.hpp"
#include "nn/core/matrix.hpp"

#include <utility>

namespace nn {
    void Sequential::add(std::unique_ptr<Layer> layer){
        layers_.push_back(std::move(layer));
    }

    Matrix Sequential::forward(const Matrix& input){
        Matrix output = input;

        for(auto& layer: layers_){
            output = layer -> forward(output);
        }
        
        return output;
    }

    std::size_t Sequential::size() const noexcept {
        return layers_.size();
    }
}