#include "Vertex.h"

namespace CG{

std::size_t Vertex::one_ring(){

    HalfEdge *h = halfedge();
    int i = 0;
    do
    {
     h = h->twin();
     h = h->he_next();
     h = h->he_next();
     m_one_ring.emplace_back(h->twin()->vertex());
     
     i++;
    }
    while( h != halfedge() );
    return i;
  
}

void Vertex::two_ring(){

    std::set<Vertex*> two_ring_set;
    for (auto v1 : m_one_ring)
     for (auto v2 : v1->m_one_ring)
      two_ring_set.insert(v2);

    for (auto e : two_ring_set)
     m_two_ring.emplace_back(e);

}

}
