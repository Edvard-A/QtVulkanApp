#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QVulkanWindow>
#include <vector>
#include "Vertex.h"
#include "Utilities.h"

class VisualObject
{
public:
    VisualObject();

    void move(float x, float y = 0.0f, float z = 0.0f);
    void scale(float s);
    void scaleUneven(float x, float y, float z);
    void rotate(float t, float x, float y, float z);

    void moveEnemy();

    bool isColliding(VisualObject* otherObject);
    void chase(VisualObject* otherObject, float speed, QVector3D anchor);

    // bezier curve functions
    //QVector3D CalculateBezier(float t, int d);
    QVector3D calclulateDeCastiljau(QVector3D p0, QVector3D p1, QVector3D p2, QVector3D p3, float t);
    //void gooner(QVector3D p0, QVector3D p1, QVector3D p2, QVector3D p3);
    void gooner();

	//Setters and Getters
    inline std::vector<Vertex> getVertices() { return mVertices; }
    inline VkBuffer& getVBuffer() { return mVertexBuffer.mBuffer; }
    inline VkDeviceMemory& getVBufferMemory() { return mVertexBuffer.mBufferMemory; }
	inline VkDeviceMemory& getIBufferMemory() { return mIndexBuffer.mBufferMemory; }
    inline void setVBuffer(VkBuffer bufferIn) { mVertexBuffer.mBuffer = bufferIn; }
    inline void setVBufferMemory(VkDeviceMemory bufferMemoryIn) { mVertexBuffer.mBufferMemory = bufferMemoryIn; }
    inline VkBuffer& getIBuffer() { return mIndexBuffer.mBuffer; }
    inline void setIBuffer(VkBuffer bufferIn) { mIndexBuffer.mBuffer = bufferIn; }
    inline void setIBufferMemory(VkDeviceMemory bufferMemoryIn) { mIndexBuffer.mBufferMemory = bufferMemoryIn; }
    inline void setName(std::string name) { mName = name; }
    inline std::string getName() const { return mName; }
    inline int getDrawType() const { return drawType; }
    inline QMatrix4x4 getMatrix() const {return mMatrix;}
	inline std::vector<Vertex> getVertices() const { return mVertices; }
	inline std::vector<uint32_t> getIndices() const { return mIndices; }
    inline int getTextureType() { return textureType; }
    inline void setTextureType(int tex) { textureType = tex; }

    QVector3D getPosition();
    void setPosition(float x, float y, float z);
    void setXZPosition(float x, float z);
    void vecSetPosition(QVector3D newPosition);

protected:
    std::vector<Vertex> mVertices;
    std::vector<uint32_t> mIndices;
    QMatrix4x4 mMatrix;
    std::string mName;

	BufferHandle mVertexBuffer;
	BufferHandle mIndexBuffer;
    //VkPrimitiveTopology mTopology{ VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST }; //not used

    int drawType{ 0 }; // 0 = fill, 1 = line


    int textureType{0};
    enum textureType
    {
        dog      = 0,
        orange   = 1,
        mark     = 2,
        pink     = 3,
        height   = 4
    };

    bool isEndReached = false;
    bool bIsChasing = false;

    // bezier curve variables
    bool mbIsForward = true;
    float mT{0};
    float bezierSpeed{0.005f};

    QVector3D mP0 = QVector3D(  -2.5f, 0.f, -2.f   );
    QVector3D mP1 = QVector3D(   1.f,  0.f, -0.5f  );
    QVector3D mP2 = QVector3D(  -1.5f, 0.f,  1.f   );
    QVector3D mP3 = QVector3D(   1.5f, 0.f,  2.5f  );

    QVector3D returnToThis = QVector3D(0, 0, 0);
};

#endif // VISUALOBJECT_H

