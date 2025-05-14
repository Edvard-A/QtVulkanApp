#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "VisualObject.h"
#include <string>

class HeightMap : public VisualObject
{
public:
    HeightMap();

    void makeTerrain(std::string heightMapImage);

    void makeTerrain(unsigned char* textureData, int width, int height);

    float calculateBarycentric(QVector2D P, QVector3D A, QVector3D B, QVector3D C);

private:
	int mWidth{ 0 };
	int mHeight{ 0 };
	int mChannels{ 0 };
};

#endif // HEIGHTMAP_H
