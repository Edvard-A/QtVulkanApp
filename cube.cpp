#include "cube.h"
#include "Vertex.h"

Cube::Cube() : VisualObject()
{
    textureType = mark;
    Vertex v1{0.f, 0.f, 0.f,    0.f, 0.f, 0.f,     0.f, 1.f};
    Vertex v2{1.f, 0.f, 0.f,    0.f, 0.f, 0.f,     1.f, 1.f};
    Vertex v3{0.f, 1.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v4{0.f, 1.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v5{1.f, 1.f, 0.f,    0.f, 0.f, 0.f,     1.f, 0.f};
    Vertex v6{1.f, 0.f, 0.f,    0.f, 0.f, 0.f,     1.f, 1.f};

    Vertex v7{0.f, 0.f, 0.f,    0.f, 0.f, 0.f,     0.f, 1.f};
    Vertex v8{0.f, 0.f, -1.f,    0.f, 0.f, 0.f,     1.f, 1.f};
    Vertex v9{0.f, 1.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v10{0.f, 0.f, -1.f,    0.f, 0.f, 0.f,     0.f, 1.f};
    Vertex v11{0.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v12{0.f, 1.f, 0.f,    0.f, 0.f, 0.f,     1.f, 0.f};

    Vertex v13{0.f, 0.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v14{1.f, 0.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v15{0.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v16{0.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v17{1.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v18{1.f, 0.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v19{1.f, 0.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v20{1.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v21{1.f, 0.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v22{1.f, 0.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v23{1.f, 1.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v24{1.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v25{0.f, 0.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v26{1.f, 0.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v27{0.f, 0.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v28{0.f, 0.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v29{1.f, 0.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v30{1.f, 0.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v31{0.f, 1.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v32{1.f, 1.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v33{0.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    Vertex v34{0.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v35{1.f, 1.f, -1.f,    0.f, 0.f, 0.f,     0.f, 0.f};
    Vertex v36{1.f, 1.f, 0.f,    0.f, 0.f, 0.f,     0.f, 0.f};

    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
    mVertices.push_back(v4);
    mVertices.push_back(v5);
    mVertices.push_back(v6);
    mVertices.push_back(v7);
    mVertices.push_back(v8);
    mVertices.push_back(v9);
    mVertices.push_back(v10);
    mVertices.push_back(v11);
    mVertices.push_back(v12);
    mVertices.push_back(v13);
    mVertices.push_back(v14);
    mVertices.push_back(v15);
    mVertices.push_back(v16);
    mVertices.push_back(v17);
    mVertices.push_back(v18);
    mVertices.push_back(v19);
    mVertices.push_back(v20);
    mVertices.push_back(v21);
    mVertices.push_back(v22);
    mVertices.push_back(v23);
    mVertices.push_back(v24);
    mVertices.push_back(v25);
    mVertices.push_back(v26);
    mVertices.push_back(v27);
    mVertices.push_back(v28);
    mVertices.push_back(v29);
    mVertices.push_back(v30);
    mVertices.push_back(v31);
    mVertices.push_back(v32);
    mVertices.push_back(v33);
    mVertices.push_back(v34);
    mVertices.push_back(v35);
    mVertices.push_back(v36);
}
