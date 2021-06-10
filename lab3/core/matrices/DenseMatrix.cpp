#include "DenseMatrix.h"

#include <utility>

DenseMatrix::DenseMatrix(std::vector<std::vector<double>> matrix) : matrix(std::move(matrix)) {}

double DenseMatrix::get(size_t y, size_t x) const {
    return matrix[y][x];
}

void DenseMatrix::set(size_t y, size_t x, double value) {
    matrix[y][x] = value;
}

size_t DenseMatrix::size() const {
    return matrix.size();
}

void DenseMatrix::swap_rows(size_t row1, size_t row2) {
    std::swap(matrix[row1], matrix[row2]);
}

DenseMatrix DenseMatrix::identityMatrix(size_t size) {
    std::vector<std::vector<double>> matrix(size, std::vector<double>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        matrix[i][i] = 1;
    }
    return DenseMatrix(matrix);
}

Vector DenseMatrix::multiply(Vector v) {
    std::vector<double> ans(v.size(), 0);
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v.size(); ++j) {
            ans[i] += this->get(i, j) * v.get(j);
        }
    }
    return Vector(ans);
}

