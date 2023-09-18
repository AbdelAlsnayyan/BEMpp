#ifndef FACE_H
#define FACE_H
#include "Vector3D.h"
#include "HalfEdge.h"


namespace CG{

class HalfEdge;
class Face{

  public:

   std::size_t &id(){return m_id;}

   HalfEdge *&halfedge() { return m_halfedge; };
   Vector3D &norm() { return m_norm; };
   Vector3D position(double u, double v);
   double &area(){return m_area;};
   double compute_area();
   void normal();
   void printVertexPositions();

  private:
   std::size_t m_id;
   HalfEdge *m_halfedge;
   Vector3D m_norm;
   double m_area;

};

}
#endif
