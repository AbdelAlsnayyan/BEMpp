#include <iostream>
#include "Mesh.h"
#include "Matrix.h"
#include "Integration.h"

namespace BEM{

 class MassMatrix : public LinAlg::Matrix{
 public:

  MassMatrix(const CG::Mesh &MeshA) : Matrix(MeshA.num_faces(),MeshA.num_faces()) {};
  //MassMatrix_P1(const CG::Mesh &MeshA) : Matrix(MeshA.num_verticies(),MeshA.num_verticies()) {};
  void Assemble(const CG::Mesh &MeshA);

  //Matrix MM(m_col_size,m_row_size);

 //private:
 //std::size_t m_col_size;
 //std::size_t m_row_size;


};


}
