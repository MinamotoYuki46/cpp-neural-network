#include "nn/core/matrix.hpp"

#include <algorithm>
#include <stdexcept>
#include <utility>

namespace nn {
    Matrix::Matrix(std::size_t rows, std::size_t cols)
        :   rows_(rows),
            cols_(cols),
            data_(new double[rows * cols]{}) {}

    Matrix::~Matrix() {
        delete[] data_;
    }

    Matrix::Matrix(const Matrix& other)
        :   rows_(other.rows_),
            cols_(other.cols_),
            data_(other.size() == 0 ? nullptr : new double[other.size()]){
                std::copy(other.data_, other.data_ + other.size(), data_);
            };

    Matrix& Matrix::operator=(const Matrix& other) {
        if (this == &other) return *this;

        Matrix temp(other);

        std::swap(rows_, temp.rows_);
        std::swap(cols_, temp.cols_);
        std::swap(data_, temp.data_);

        return *this;
    }

    Matrix::Matrix(Matrix&& other) noexcept
        :   rows_(std::exchange(other.rows_, 0)),
            cols_(std::exchange(other.cols_, 0)),
            data_(std::exchange(other.data_, nullptr)) {}

    Matrix& Matrix::operator=(Matrix&& other) noexcept {
        if (this == &other) return *this;

        delete[] data_;

        rows_ = std::exchange(other.rows_, 0);
        cols_ = std::exchange(other.cols_, 0);
        data_ = std::exchange(other.data_, nullptr);

        return *this;
    }


    std::size_t Matrix::rows() const noexcept { return rows_;}
    std::size_t Matrix::cols() const noexcept { return cols_;}
    std::size_t Matrix::size() const noexcept { return rows_ * cols_;}

    double& Matrix::operator()(std::size_t row, std::size_t col){
        if (row >= rows_ || col >= cols_) throw std::out_of_range("Matrix index out of range");

        return data_[row * cols_ + col];
    }

    const double& Matrix::operator()(std::size_t row, std::size_t col) const {
        if (row >= rows_ || col >= cols_) throw std::out_of_range("Matrix index out of range");

        return data_[row * cols_ + col];
    }

    void Matrix::fill(double value) {
        std::fill(data_, data_ + size(), value);
    }
}
