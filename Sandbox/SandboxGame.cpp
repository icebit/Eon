#include "SandboxGame.h"
#include <Math/Math.h>

SandboxGame::SandboxGame(Config *config)
    : Game(config), camera(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 1.0f),
                           Vec3(0.0f, 1.0f, 0.0f)) {}

void SandboxGame::Init() {
  float verts[] = {
      -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  -0.5f, -0.5f, 1.0f, 0.0f,
      0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
      -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
      -0.5f, 0.5f,  0.5f,  0.0f, 1.0f, -0.5f, -0.5f, 0.5f,  0.0f, 0.0f,

      -0.5f, 0.5f,  0.5f,  1.0f, 0.0f, -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f,
      -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, -0.5f, 0.5f,  0.5f,  1.0f, 0.0f,

      0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
      0.5f,  -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  -0.5f, -0.5f, 0.0f, 1.0f,
      0.5f,  -0.5f, 0.5f,  0.0f, 0.0f, 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

      -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  -0.5f, -0.5f, 1.0f, 1.0f,
      0.5f,  -0.5f, 0.5f,  1.0f, 0.0f, 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

      -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
      -0.5f, 0.5f,  0.5f,  0.0f, 0.0f, -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f};

  Mesh *mesh = new Mesh(verts, 36, true);

  Texture textureTiles("Concrete.jpg");
  Material *material1 = new Material(Shader(LoadText("Vertex.glsl").c_str(),
                                            LoadText("Fragment.glsl").c_str()));
  material1->AddTexture(textureTiles, "texture1");

  // Add entity
  Entity *entity1 = new Entity();
  RenderComponent *rComponent1 = new RenderComponent(mesh, material1);
  TransformComponent *tComponent1 = new TransformComponent(
      Vec3(0.0f, 0.0f, 0.0f), Vec3(0.8f, 0.8f, 0.8f), Vec3(0.0f, 0.0f, 0.0f));
  entity1->AddComponent(tComponent1);
  entity1->AddComponent(rComponent1);
  world.AddEntity(entity1);

  world.AddEntity(&fpsCamera);

  renderer.SetCamera(fpsCamera.GetCamera());

  renderer.SetBackgroundColor(Vec4(0.1f, 0.1f, 0.1f, 1.0f));
}

void SandboxGame::Tick(float delta) {
  pitch += input.GetMouseDeltaY() * -0.002f;
  yaw += input.GetMouseDeltaX() * 0.002f;

  fpsCamera.pos =
      fpsCamera.pos + Vec3(input.GetX() * 0.05f, 0.0f, input.GetY() * 0.05f);

  fpsCamera.pitch = pitch;
  fpsCamera.yaw = yaw;

  std::cout << "FPS: " << 1000 / delta << std::endl;
}
