#ifndef SCENE_HPP
#define SCENE_HPP

#include "renderer.hpp"
#include "camera.hpp"

class Scene
{
private:
    Renderer &sceneRenderer;
    Camera &sceneCamera;
public:
    Scene(Camera &camera, Renderer &render);
    void enableScene();
    Camera *getCamera();
};

#endif