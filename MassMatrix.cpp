#include "MassMatrix.h"
#define int_order 5

namespace BEM{


 void MassMatrix::Assemble(const CG::Mesh &MeshA){
  GaussLegendreRule<int_order> Int_Order;
  std::size_t order_size = Int_Order.weight_int.size();
  double area = 0.0;
  for (std::size_t i = 0; i < m_col_size; i++)
   for (std::size_t j = 0; j < order_size; j++) 
    (*this)(i,i) = (*this)(i,i) + MeshA.face(i)->get_area()*Int_Order.weight_int[j];
  
 }


}
