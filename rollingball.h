#ifndef ROLLINGBALL_H
#define ROLLINGBALL_H

#include <string>
#include "VisualObject.h"

class rollingBall : public VisualObject
{
public:
    rollingBall();
    rollingBall(const std::string &fileName);
    void move(float deltaTime);
    void setSurface(VisualObject* surface) { triangle_surface = surface; }

protected:
    VisualObject* triangle_surface;
private:
    QVector3D mOldNormal = {0.0f, 0.0f, 1.0f};
    int mOldIndex = 0;
};

#endif // ROLLINGBALL_H
