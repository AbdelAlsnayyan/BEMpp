#include <vector>
#include <map>
#include <iterator>
#include "HalfEdge.h"

namespace CG{

class Mesh{

 public:

  int read_obj(std::size_t a);

  Vertex *create_vertex(std::size_t id);
  Vertex *id_vertex(std::size_t id);

  Face *create_face(Vertex *v[],std::size_t id);
  Face *id_face(std::size_t id);

  Edge *create_edge(Vertex *v1, Vertex *v2);

  void create_1ring_neighborhood();
  void create_2ring_neighborhood();
  void printVertexPositions(Face *&f);
  void area();
  void normals();
  
  std::size_t num_faces() const {return m_num_faces;};
  std::size_t num_vertices() const {return m_num_vertices;};

 protected:		
  std::vector<Edge*> m_edges;
  std::vector<Face*> m_faces;
  std::vector<Vertex*> m_vertices;

  std::map<std::size_t, Vertex*> m_map_vertex;
  std::map<std::size_t, Face*> m_map_face;
  std::map<EdgeKey, Edge*> m_map_edge;
  std::size_t m_num_vertices;
  std::size_t m_num_faces;


};

}
