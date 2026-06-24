#pragma once

#include <cstddef>

namespace nn {

    /***
     * @brief Simple 2D matrix with row-major storage
     *
     * Phase 1 intentionally uses raw pointer ownership to paractice
     * destructor, copy constructor, copy assignment, move constructor,
     * and move assignment
     */

    class Matrix {
    private:
        std::size_t rows_ {};
        std::size_t cols_ {};
        double * data_ {};

    public:
        Matrix() = default;

        /**
         * @brief Construct a rows x cols zero-initialized matrix
         */
        Matrix(std::size_t rows, std::size_t cols);

        /**
         * @brief Destroy owned matrix memory         *
         */
        ~Matrix();

        /**
         * @brief Deep-copy constructor
         */
        Matrix(const Matrix& other);

        /**
         * @brief Deep-copy assignment using copy-and-swap
         */
        Matrix& operator=(const Matrix& other);

        /**
         * @brief Move constructor.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Move assignment
         *
         */
        Matrix& operator=(Matrix&& other) noexcept;

        [[nodiscard]] std::size_t rows() const noexcept;
        [[nodiscard]] std::size_t cols() const noexcept;
        [[nodiscard]] std::size_t size() const noexcept;

        double& operator()(std::size_t row, std::size_t cols);
        const double& operator()(std::size_t row, std::size_t col) const;

        void fill(double value);
    };
}
