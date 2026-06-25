#pragma once

#include <cstddef>
#include <iosfwd>

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

        /**
         * @brief Access the element at the specified row and column
         * @param row The row index
         * @param col The column index
         * @return A reference to the element at the specified row and column
         */
        double& operator()(std::size_t row, std::size_t cols);

        /**
         * @brief Access the element at the specified row and column (const version)
         * @param row The row index
         * @param col The column index
         * @return A const reference to the element at the specified row and column
         */
        const double& operator()(std::size_t row, std::size_t col) const;

        // Phase 2
        // Creating arithmetic operators overloading

        /**
         * @brief Element-wise addition of two matrices
         * @param rhs The matrix to add
         * @return A new matrix with the result of the addition
         */
        Matrix operator+(const Matrix& rhs) const;

        /**
         * @brief Element-wise subtraction of two matrices
         * @param rhs The matrix to subtract
         * @return A new matrix with the result of the subtraction
         */
        Matrix operator-(const Matrix& rhs) const;

        /**
         * @brief Element-wise multiplication of two matrices
         * @param rhs The matrix to multiply
         * @return A new matrix with the result of the multiplication
         */
        Matrix operator*(const Matrix& rhs) const;

        /**
         * @brief Scalar multiplication of a matrix
         * @param scalar The scalar to multiply
         * @return A new matrix with the result of the multiplication
         */
        Matrix operator*(double scalar) const;

        /**
         * @brief Element-wise addition of two matrices
         * @param rhs The matrix to add
         * @return A reference to this matrix after the addition
         */
        Matrix& operator+=(const Matrix& rhs);

        /**
         * @brief Element-wise subtraction of two matrices
         * @param rhs The matrix to subtract
         * @return A reference to this matrix after the subtraction
         */
        Matrix& operator-=(const Matrix& rhs);

        /**
         * @brief Scalar multiplication of a matrix
         * @param scalar The scalar to multiply
         * @return A reference to this matrix after the multiplication
         */
        Matrix& operator*=(double scalar);

        /**
         * @brief Friend function to output a matrix to an ostream
         * @param os The output stream
         * @param matrix The matrix to output
         * @return The output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

        /**
         * @brief Fill the matrix with a given value
         * @param value The value to fill the matrix with
         */
        void fill(double value);
    };
}
