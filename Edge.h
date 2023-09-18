#ifndef EDGE_H
#define EDGE_H

#include <cstddef>


namespace CG{
 
class Vertex;
class HalfEdge;
class Edge{

 public:
  Edge() { m_halfedge[0] = NULL; m_halfedge[1] = NULL;};
  ~Edge() {};

  HalfEdge *&halfedge(int i) { return m_halfedge[i]; };
  double &length(){return m_length;};
   
 private:
  HalfEdge *m_halfedge[2];
  double m_length;

};

class EdgeKey {
 public:
  EdgeKey(Vertex *v1, Vertex *v2);
  bool operator<(const EdgeKey & key) const ;
  bool operator==(const EdgeKey & key) const;

 private:
  Vertex *m_vertices[2];
};

}
#endif
