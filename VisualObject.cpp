#include "VisualObject.h"

VisualObject::VisualObject()
{
    mMatrix.setToIdentity();
}

void VisualObject::move(float x, float y, float z)
{
    mMatrix.translate(x, y, z);
}

void VisualObject::scale(float s)
{
    mMatrix.scale(s);
}

void VisualObject::scaleUneven(float x, float y, float z)
{
    mMatrix.scale(x, y, z);
}

void VisualObject::rotate(float t, float x, float y, float z)
{
    mMatrix.rotate(t, x, y, z);
}

QVector3D VisualObject::getPosition()
{
    float x = mMatrix(0, 3); // Position in the x-axis
    float y = mMatrix(1, 3); // Position in the y-axis
    float z = mMatrix(2, 3); // Position in the z-axis
    return QVector3D(x, y, z);
}

void VisualObject::setPosition(float x, float y, float z)
{
    mMatrix(0, 3) = x; // Position in the x-axis
    mMatrix(1, 3) = y; // Position in the y-axis
    mMatrix(2, 3) = z; // Position in the z-axis
}

void VisualObject::setXZPosition(float x, float z)
{
    mMatrix(0, 3) = x; // Position in the x-axis
    mMatrix(2, 3) = z; // Position in the z-axis
}

void VisualObject::vecSetPosition(QVector3D newPosition)
{
    mMatrix(0, 3) = newPosition.x(); // Position in the x-axis
    mMatrix(1, 3) = newPosition.y(); // Position in the y-axis
    mMatrix(2, 3) = newPosition.z(); // Position in the z-axis
}

// UNUSED
void VisualObject::moveEnemy()
{

    if(this->getPosition().x() < 1.f && !isEndReached)
    {
        //qDebug("this function was called!");
        mMatrix.translate(0.005f, 0.f, 0.f);
    } else{
        isEndReached = true;
        mMatrix.translate(0.f, 0.f, 0.f);
    }

    if(this->getPosition().x() > 0 && isEndReached)
    {
        mMatrix.translate(-0.005f, 0.f, 0.f);
    } else{
        isEndReached = false;
    }
}

bool VisualObject::isColliding(VisualObject* otherObject)
{
    if( sqrt((this->getPosition().x() - otherObject->getPosition().x()) * (this->getPosition().x() - otherObject->getPosition().x())) < 6 &&
        sqrt((this->getPosition().z() - otherObject->getPosition().z()) * (this->getPosition().z() - otherObject->getPosition().z())) < 6)
    {
        return true;
    } else
        return false;
}

void VisualObject::chase(VisualObject* otherObject, float speed, QVector3D anchor)
{
    //qDebug() << "is enemy chasing?: " << bIsChasing;
    if(this->isColliding(otherObject))
    {
        //qDebug() << "Player position is: " << otherObject->getPosition();
        //qDebug() << "Enemy position is: " << this->getPosition();
        bIsChasing = true;
        if(this->getPosition().x() < otherObject->getPosition().x())
            this->move(speed, 0, 0);
        if(this->getPosition().x() > otherObject->getPosition().x())
            this->move(-speed, 0, 0);
        if(this->getPosition().z() < otherObject->getPosition().z())
            this->move(0, 0, speed);
        if(this->getPosition().z() > otherObject->getPosition().z())
            this->move(0, 0, -speed);

        //if(this->getPosition() != otherObject->getPosition())
        //    this->move(speed, 0, speed);

        //this->move(otherObject->getPosition().x(), 0, otherObject->getPosition().z());
        //this->move(sqrt(otherObject->getPosition().x() * otherObject->getPosition().x()) * speed,
        //           0,
        //           sqrt(otherObject->getPosition().z() * otherObject->getPosition().z()) * speed);
        //qDebug() << "player X position is: " << sqrt(otherObject->getPosition().x() * otherObject->getPosition().x());//sqrt(otherObject->getPosition().x() * otherObject->getPosition().x());
    }
    else
    {
        //qDebug() << returnToThis;
        //if(this->getPosition() != anchor) //<- Might be better to use this
        if( sqrt((this->getPosition().x() - returnToThis.x()) * (this->getPosition().x() - returnToThis.x())) > 0.002f &&
            sqrt((this->getPosition().z() - returnToThis.z()) * (this->getPosition().z() - returnToThis.z())) > 0.002f)
        //if( (this->getPosition().x() - returnToThis.x()).length() &&
        //    (this->getPosition().z() - returnToThis.z()).length())
        {
            //qDebug("Enemy is moving!");

            if(this->getPosition().x() < returnToThis.x())
            {
                this->move(speed, 0, 0);
                qDebug("moving in positive X direction");
            }
            if(this->getPosition().x() > returnToThis.x())
            {
                this->move(speed * (-1), 0, 0);
                qDebug("moving in negative X direction");
            }
            if(this->getPosition().z() < returnToThis.z())
            {
                this->move(0, 0, speed);
                qDebug("moving in positive Z direction");
            }
            if(this->getPosition().z() > returnToThis.z())
            {
                this->move(0, 0, speed * (-1));
                qDebug("moving in negative Z direction");
            }
        }
        else
        {
            bIsChasing = false;
            //mT = 0;
            //setXZPosition(-2.5, 2.0);
            //qDebug("enemy is not moving!");
        }
    }
    if(!bIsChasing)
    {
        //qDebug() << "mT is: " << mT;
        //qDebug() << "is going forward?: " << mbIsForward;
        if (mbIsForward)
            mT += bezierSpeed;
        else
            mT -= bezierSpeed;

        if (mT >= 1.0f){
            mT = 1.0f;
            mbIsForward = false;
        }

        else if (mT <= 0.0f)
        {
            mT = 0.0f;
            mbIsForward = true;
        }

        QVector3D pos = calclulateDeCastiljau(mP0, mP1, mP2, mP3, mT);
        //qDebug() << "position is: " << pos;
        setXZPosition(pos.x(), pos.z());
        returnToThis.setX(pos.x());
        returnToThis.setZ(pos.z());
        //qDebug() << "Anchor is: " << returnToThis;
        //qDebug() << "mT is: " << mT;
        //if(this->getPosition().x() < 5.f && this->getPosition().z() < (-5) && !isEndReached) // x < end.x() && z < end.z()
        //{
        //    qDebug("this function was called!");
        //    mMatrix.translate(5.f / 100, 0.f, 11.f / 100); // translate(end.x() / speed?, 0, end.z() / speed?)
        //} else{
        //    isEndReached = true;
        //}

        //if(this->getPosition().x() > 0 && this->getPosition().z() > -16 && isEndReached)
        //{
        //    mMatrix.translate(-5.f / 100, 0.f, -11.f / 100);
        //} else{
        //    isEndReached = false;
        //}
    }
}

QVector3D VisualObject::calclulateDeCastiljau(QVector3D p0, QVector3D p1, QVector3D p2, QVector3D p3, float t)
{
    // QVector2D b10, b11, b12;
    // b10 =

    // return QVector3D(1, 1, 1);
    QVector3D a = (1-t)* p0 + t * p1;
    QVector3D b = (1-t)* p1 + t * p2;
    QVector3D c = (1-t)* p2 + t * p3;

    QVector3D Q1 = (1-t)* a + t * b;
    QVector3D Q2 = (1-t)* b + t * c;

    QVector3D R = (1-t) * Q1 + t * Q2;


    return R;
}

// UNUSED
void VisualObject::gooner() //(QVector3D p0, QVector3D p1, QVector3D p2, QVector3D p3)
{

    //qDebug() << "mT is: " << mT;
    //qDebug() << "is going forward?: " << mbIsForward;
    if (mbIsForward)
        mT += bezierSpeed;
    else
        mT -= bezierSpeed;

    if (mT >= 1.0f){
        mT = 1.0f;
        mbIsForward = false;
    }

    else if (mT <= 0.0f)
    {
        mT = 0.0f;
        mbIsForward = true;
    }

    QVector3D pos = calclulateDeCastiljau(mP0, mP1, mP2, mP3, mT);
    qDebug() << "position is: " << pos;
    setXZPosition(pos.x(), pos.z());

}
