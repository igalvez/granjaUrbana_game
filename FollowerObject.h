#include "GameObject.h"
#include "Sprite.h"
#include <queue>

#ifndef FOLLOWEROBJECT_H
#define FOLLOWEROBJECT_H

#define VEL 2.0f

class FollowerObject : public GameObject{
  private:
    Sprite *sprite;
    float speedX, speedY;
    std::queue<float> coordinateXQueue;
    std::queue<float> coordinateYQueue;
    float x1, y1, z;
  public:
    FollowerObject(Sprite *sprite, float x, float y, float w, float h);
    int update(int dt);
    void render(float cameraX, float cameraY);
    void renderQueueLines(float cameraX, float cameraY);
    void enqueuedCommand(float x, float y);
}; 

#endif
