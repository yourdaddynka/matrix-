#ifndef CPP1_S21_MATRIXPLUX_SRC_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUX_SRC_S21_MATRIX_OOP_H
#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  // Constructors
  S21Matrix() {
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  }
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;

  // Destructor
  ~S21Matrix() { MemoryClean(); }

  // Operators
  double& operator()(int row, int col);
  bool operator==(const S21Matrix& other) { return this->EqMatrix(other); }
  double operator()(int rows, int cols) const;
  S21Matrix operator+(const S21Matrix& other) { return *this += other; }
  S21Matrix operator-(const S21Matrix& other) { return *this -= other; }
  S21Matrix operator*(const S21Matrix& other) { return *this *= other; }
  S21Matrix operator*(const double num) { return *this *= num; }
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix& other);

  // Class methods
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();
  double Determinant();

  // Getters and setters
  int GetRows() { return rows_; }
  int GetCols() { return cols_; }
  void SetRows(int rows) { SetSize(rows, cols_); }
  void SetCols(int cols) { SetSize(rows_, cols); }

 private:
  const double eps = 1e-7;
  int rows_, cols_;
  double** matrix_;
  void SetSize(int rows_, int cols_);
  void MemoryAllocation();
  void CopyMatrix();
  void MemoryClean();
  void Minor(int i, int j, int& nrows_, int& n_columns, S21Matrix& minormat);
  void DetCalc(S21Matrix& temp, double* result);
  bool CheckMatrix(const S21Matrix& other);
  void Copy(const S21Matrix& other);
};

#endif  // CPP1_S21_MATRIXPLUX_SRC_S21_MATRIX_OOP_H