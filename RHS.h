#include <iostream>
#include "Vector.h"
#include "Mesh.h"
#include "Integration.h"

namespace BEM{
 
 class RHS : public LinAlg::Vector  {

  public:
  RHS(const CG::Mesh &MeshA) : Vector(MeshA.num_faces()) {};

  void Assemble(const CG::Mesh &MeshA);


 };

}
