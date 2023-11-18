#include "s21_matrix_oop.h"

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::out_of_range("Error: out of range");
  }
  rows_ = rows;
  cols_ = cols;
  MemoryAllocation();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  MemoryAllocation();
  Copy(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.cols_ = 0;
  other.rows_ = 0;
}
double& S21Matrix ::operator()(int rows, int cols) {
  if (rows >= rows_ || cols >= cols_ || rows < 0 || cols < 0) {
    throw std::out_of_range(
        "Trying to access out of range element in S21Matrix.");
  }
  return matrix_[rows][cols];
}

double S21Matrix ::operator()(int rows, int cols) const {
  if (rows >= rows_ || cols >= cols_ || rows < 0 || cols < 0) {
    throw std::out_of_range(
        "Trying to access out of range element in S21Matrix.");
  }
  return matrix_[rows][cols];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  MemoryClean();
  rows_ = other.rows_;
  cols_ = other.cols_;
  MemoryAllocation();
  Copy(other);
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    MemoryClean();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

void S21Matrix ::Copy(const S21Matrix& other) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::MemoryAllocation() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::MemoryClean() {
  if (matrix_ != nullptr) {
    for (int freematrix_ = 0; freematrix_ < rows_; freematrix_++) {
      delete[] matrix_[freematrix_];
    }
    delete[] matrix_;
  }
  matrix_ = nullptr;
  cols_ = 0;
  rows_ = 0;
}

bool S21Matrix::CheckMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_ || rows_ <= 0 || cols_ <= 0)
    throw std::invalid_argument("invalid argument");
  return true;
}
void S21Matrix::SetSize(int rows, int cols) {
  S21Matrix buff(*this);
  MemoryClean();
  rows_ = rows;
  cols_ = cols;
  MemoryAllocation();
  Copy(buff);
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if ((fabs(matrix_[i][j] - other.matrix_[i][j])) >= eps) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->CheckMatrix(other)) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (this->CheckMatrix(other)) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (rows_ <= 0 || cols_ <= 0) throw std::invalid_argument("invalid argument");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) throw std::invalid_argument("invalid argument");
  S21Matrix mulresult(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int s = 0; s < cols_; s++) {
        mulresult.matrix_[i][j] += matrix_[i][s] * other.matrix_[s][j];
      }
    }
  }
  *this = mulresult;
}

S21Matrix S21Matrix ::Transpose() {
  S21Matrix result(this->cols_, this->rows_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

S21Matrix S21Matrix ::CalcComplements() {
  if (rows_ != cols_) throw std::out_of_range("Error: out of range");
  S21Matrix result(this->rows_, this->cols_);
  if (rows_ == 1 && cols_ == 1) {
    result.matrix_[0][0] = 1;
    return result;
  }
  S21Matrix minor(this->rows_ - 1, this->cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      double num = 0.0;
      int n_cols = 0, n_rows = 0;
      minor.rows_ = rows_ - 1;
      minor.cols_ = cols_ - 1;
      Minor(i, j, n_rows, n_cols, minor);
      num = minor.Determinant();
      result.matrix_[i][j] = pow((-1), (i + j)) * num;
    }
  }
  return result;
}

void S21Matrix::Minor(int i, int j, int& n_rows, int& n_cols,
                      S21Matrix& minor) {
  for (int minrows_ = 0; minrows_ < rows_; minrows_++) {
    if (minrows_ == i) n_rows = 1;
    n_cols = 0;
    for (int min_cols = 0; min_cols < cols_; min_cols++) {
      if (min_cols == j) n_cols = 1;
      if (minrows_ != i && min_cols != j) {
        minor.matrix_[minrows_ - n_rows][min_cols - n_cols] =
            matrix_[minrows_][min_cols];
      }
    }
  }
}

double S21Matrix::Determinant() {
  if (rows_ != cols_ || rows_ <= 0)
    throw std::out_of_range("Error: out of range");
  S21Matrix temp = *this;
  double result = 1.0;
  DetCalc(temp, &result);
  for (int i = 0; i < rows_; i++) {
    result *= temp.matrix_[i][i];
  }
  return result;
}

void S21Matrix ::DetCalc(S21Matrix& temp, double* result) {
  for (int i = 0; i < rows_; i++) {
    if (temp.matrix_[i][i] == 0.0) {
      for (int j = i + 1; j < cols_; j++) {
        if (temp.matrix_[j][i] != 0.0) {
          double* temp_o = temp.matrix_[i];
          temp.matrix_[i] = temp.matrix_[j];
          temp.matrix_[j] = temp_o;
          *result *= -1.0;
          break;
        }
      }
    }
    if (temp.matrix_[i][i] != 0.0) {
      for (int j = i + 1; j < rows_; j++) {
        double coef = temp.matrix_[j][i] / temp.matrix_[i][i];
        for (int z = i; z < cols_; z++) {
          temp.matrix_[j][z] -= coef * (double)temp.matrix_[i][z];
        }
      }
    }
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0.0) throw std::out_of_range("Error: out of range");
  S21Matrix minor(rows_, cols_);
  minor = CalcComplements();
  double dop_mat = (1.0 / det);
  S21Matrix trans(cols_, rows_);
  trans = minor.Transpose();
  trans *= dop_mat;
  return trans;
}