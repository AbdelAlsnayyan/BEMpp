#ifndef HALFEDGE_H
#define HALFEDGE_H

#include "Face.h"
#include "Vertex.h"
#include "Edge.h"


namespace CG{

class Face;
class HalfEdge{

 public: 
  Edge     *& edge()    { return m_edge; };

  Vertex   *& vertex()  { return m_vertex; };
  Vertex   *& target()  { return m_vertex; };
  Vertex   *& source()  { return m_prev->vertex(); };

  HalfEdge *& he_prev() { return m_prev; };
  HalfEdge *& he_next() { return m_next; };
  HalfEdge *& twin()    { return m_twin; };

  Face     *& face()    { return m_face; };


 private:
  Face *m_face;
  Vertex *m_vertex; // target vertex
  HalfEdge *m_prev;
  HalfEdge *m_next;
  HalfEdge *m_twin;
  Edge *m_edge;

};

}

#endif
