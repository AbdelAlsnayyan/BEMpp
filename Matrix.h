

namespace LinAlg{

class Matrix{

 public:
  Matrix(std::size_t rows, std::size_t cols) : m_row_size(rows), m_col_size(cols) {m_data = new double[rows*cols]();};

  std::size_t row_size(){return m_row_size;};
  std::size_t col_size(){return m_col_size;};

  double& operator() (std::size_t i1, std::size_t i2) { return m_data[i2 + m_col_size*i1];};
  //const double& operator() (std::size_t i1, std::size_t i2) const {return m_data[i2 + rows*i1];};

 protected:
  std::size_t m_row_size;
  std::size_t m_col_size;
  double *m_data;
};

}
