#include <GL/gl.h>
#include "../include/scene.hpp"

Scene::Scene(Camera &camera, Renderer &render)
    :
    sceneCamera(camera),
    sceneRenderer(render) {}

void Scene::enableScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    sceneCamera.demonstrate();
    sceneRenderer.start();
    glPopMatrix();
}
Camera *Scene::getCamera()
{
    return &sceneCamera;
}