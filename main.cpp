#include <iostream>
#include "Mesh.h"
#include "MassMatrix.h"

int main(){

std::cout << "--> Read mesh..." << std::endl;
CG::Mesh *oldMesh = new CG::Mesh();
oldMesh->read_obj(1);

std::cout << "--> Compute normals..." << std::endl;
oldMesh->normals();

std::cout << "--> Compute areas..." << std::endl;
oldMesh->area();

std::cout << "--> Compute two ring neighborhood..." << std::endl;
oldMesh->create_2ring_neighborhood();

//BEM::GaussLegendreRule<9> Int_Order;
//std::cout << Int_Order.xi_int[1] << std::endl;
BEM::MassMatrix MM(*oldMesh);


return 0;

};
