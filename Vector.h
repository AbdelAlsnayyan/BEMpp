
namespace LinAlg{
 
 class Vector{

  public:
   Vector(std::size_t sz) : m_arr_size(sz) {m_data = new double[sz]();}; 

   std::size_t size(){return m_arr_size;};

   double &operator[](const std::size_t index ) {return m_data[index];};

  protected:
   std::size_t m_arr_size;
   double *m_data;

 };


}
