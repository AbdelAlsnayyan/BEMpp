

namespace LinAlg{

class Matrix{

 public:
  Matrix(std::size_t rows, std::size_t cols) : m_row_size(rows), m_col_size(cols), data(0) {};
  Matrix(std::size_t rows, std::size_t cols) : m_row_size(rows), m_col_size(cols), {m_data = new T[rows*cols]();};

  std::size_t row_size(){return m_row_size;};
  std::size_t col_size(){return m_col_size;};

  double& Matrix::operator() (std::size_t i1, std::size_t i2) { return data[i2 + rows*i1];};
  const double& Matrix::operator() (std::size_t i1, std::size_t i2) const {return data[i2 + rows*i1];};

 private:
  std::size_t m_row_size;
  std::size_t m_col_size;
  double *m_data;
};

}
