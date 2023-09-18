namespace BEM{

 class MassMatrix{
 public:

  MassMatrix(const CG::Mesh &MeshA) : m_col_size(MeshA.num_faces()), m_row_size(MeshA.num_faces()) {};
  void Assemble(const CG::Mesh &MeshA);

 private:
 std::size_t m_col_size;
 std::size_t m_row_size;


};


}
