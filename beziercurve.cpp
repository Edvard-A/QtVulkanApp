#include "beziercurve.h"

BezierCurve::BezierCurve() {}

QVector3D BezierCurve::CalculateBezier(float t, int d)
{
    QVector3D a[4];
    for(int i = 0; i < 4; i++){
        a[i] = c[i];
    }

    for(int k = d; k > 0; k--){
        for(int i = 0; i < k; i++){
            a[i] = a[i] * (1-t) + a[i + 1] * t;
        }
    }

    return a[0];
}
