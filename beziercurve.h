#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QVector3D>

class BezierCurve
{
public:
    BezierCurve();
    QVector3D CalculateBezier(float t, int d);

private:
    QVector3D c[4];
};

#endif // BEZIERCURVE_H
