#include "rollingball.h"
#include <fstream>
#include "HeightMap.h"

rollingBall::rollingBall()
{
    textureType = orange;
    Vertex v1{1.0f, 0.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f};
    Vertex v2{0.5f, 1.0f, 0.0f,    1.0f, 0.0f, 0.7f,    0.5f, 0.0f};
    Vertex v3{0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f};

    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
}

rollingBall::rollingBall(const std::string &fileName)
{
    std::ifstream inn(fileName);
    if (!inn.is_open())
        return;
    // read input from math part of compulsory
    int n;
    Vertex v;
    inn >> n;
    for (auto i=0; i<n; i++)
    {
        inn >> v;
        mVertices.push_back(v);
        //qDebug() << v.x << v.y << v.z;
    }
    inn.close();
}

void rollingBall::move(float deltaTime)
{

}
