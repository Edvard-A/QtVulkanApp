#ifndef ENEMY_H
#define ENEMY_H

#include "VisualObject.h"

class Enemy : public VisualObject
{
public:
    Enemy();
    void moveEnemy();
    QVector3D getPosition(){ return mPosition; };

private:
    QVector3D mPosition;
};

#endif // ENEMY_H
