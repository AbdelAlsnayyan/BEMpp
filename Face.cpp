#include "Face.h"
#include <iostream>

namespace CG{

void Face::normal(){
    Vector3D normal;

    HalfEdge *h = halfedge();

    do
    {
      Vector3D pi = h->vertex()->position();
      Vector3D pj = h->he_next()->vertex()->position();

      normal = normal +  pi.cross(pj);

      h = h->he_next();
    }
    while( h != halfedge() );

    norm() = normal.unit(); 
}

void Face::printVertexPositions(){

    HalfEdge* h = halfedge(); 
    do {
        Vertex* v = h->vertex();   
        h = h->he_next();                 
    } while (h != halfedge());    
}

double Face::compute_area(){

 double area = 0.0;

 HalfEdge* h = halfedge(); 

 HalfEdge *ht  = h->twin(); 
 HalfEdge *hn  = h->he_next();

 HalfEdge *hnt = hn->twin();

 Vector3D V1 = h->vertex()->position();
 Vector3D V2 = ht->vertex()->position();

 Vector3D V3 = hn->vertex()->position();
 Vector3D V4 = hnt->vertex()->position();

 Vector3D VV1 = V4-V3;
 Vector3D VV2 = V2-V1; 

 area = VV1.cross(VV2).norm2();

 return area/2.0;

}

Vector3D Face::position(double u, double v){
 double w = 1 - u - v;

 HalfEdge *h   = halfedge();
 HalfEdge *hn  = h->he_next();
 HalfEdge *hnn = hn->he_next();

 Vector3D V1   = h->vertex()->position();
 Vector3D V2   = hn->vertex()->position();
 Vector3D V3   = hnn->vertex()->position();

 Vector3D pos = V1*u + V2*v  + V3*w; 

 return pos;

}

}
