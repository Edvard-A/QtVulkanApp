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

void VisualObject::vecSetPosition(QVector3D newPosition)
{
    mMatrix(0, 3) = newPosition.x(); // Position in the x-axis
    mMatrix(1, 3) = newPosition.y(); // Position in the y-axis
    mMatrix(2, 3) = newPosition.z(); // Position in the z-axis
}

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
    if(this->isColliding(otherObject))
    {
        //qDebug() << "Player position is: " << otherObject->getPosition();
        //qDebug() << "Enemy position is: " << this->getPosition();

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
        if(this->getPosition() != anchor) //<- Might be better to use this
        //if(sqrt((this->getPosition().x() - anchor.x()) * (this->getPosition().x() - anchor.x())) > 0.1f &&
        //    sqrt((this->getPosition().z() - anchor.z()) * (this->getPosition().z() - anchor.z())) > 0.1f)
        {
            //qDebug("Enemy is moving!");
            if(this->getPosition().x() < anchor.x())
                this->move(speed, 0, 0);
            if(this->getPosition().x() > anchor.x())
                this->move(-speed, 0, 0);
            if(this->getPosition().z() < anchor.z())
                this->move(0, 0, speed);
            if(this->getPosition().z() > anchor.z())
                this->move(0, 0, -speed);
        }
        else
            qDebug("enemy is not moving!");

    }
}
