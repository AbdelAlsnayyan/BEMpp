#ifndef VERTEX_H
#define VERTEX_H

#include "Vector3D.h"
#include <vector>
#include "HalfEdge.h"
#include <iostream>
#include <set>


namespace CG{

class HalfEdge;
class Vertex{
 public:
  std::size_t & id() { return m_id; };
  std::size_t &valence() {return m_valence;};
  std::size_t one_ring();
  void        two_ring();
  Vector3D & position() { return m_position; };

  HalfEdge *& halfedge() { return m_halfedge; };

 private:
  std::size_t   m_id;
  std::size_t   m_valence;
  Vector3D m_position;
  HalfEdge *m_halfedge;
  std::vector<Vertex*> m_one_ring;
  std::vector<Vertex*> m_two_ring;

};

}

#endif
