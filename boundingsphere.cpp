#include "boundingsphere.h"

#include "Vertex.h"

BoundingSphere::BoundingSphere() {}

BoundingSphere::BoundingSphere(float r)
{
    Vertex top{     0.0f,  r, 0.0f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f};
    Vertex bottom{  0.0f, -r, 0.0f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f};
    Vertex right{   r, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f};
    Vertex left{   -r, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f};

    Vertex far{     0.0f, 0.0f,  r,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f};
    Vertex near{    0.0f, 0.0f, -r,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f};

    mVertices.push_back(top);      //  0
    mVertices.push_back(right);    //  1
    mVertices.push_back(bottom);   //  2
    mVertices.push_back(left);     //  3
    mVertices.push_back(far);      //  4
    mVertices.push_back(near);     //  5

    // front of circle
    mIndices.push_back(0);
    mIndices.push_back(1);
    mIndices.push_back(4);

    mIndices.push_back(1);
    mIndices.push_back(2);
    mIndices.push_back(4);

    mIndices.push_back(2);
    mIndices.push_back(3);
    mIndices.push_back(4);

    mIndices.push_back(3);
    mIndices.push_back(0);
    mIndices.push_back(4);

    // back of circle
    mIndices.push_back(0);
    mIndices.push_back(1);
    mIndices.push_back(5);

    mIndices.push_back(1);
    mIndices.push_back(2);
    mIndices.push_back(5);

    mIndices.push_back(2);
    mIndices.push_back(3);
    mIndices.push_back(5);

    mIndices.push_back(3);
    mIndices.push_back(0);
    mIndices.push_back(5);

}
