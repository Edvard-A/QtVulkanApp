#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include "VisualObject.h"

class BoundingSphere : public VisualObject
{
public:
    BoundingSphere();
    BoundingSphere(float r);
};

#endif // BOUNDINGSPHERE_H
