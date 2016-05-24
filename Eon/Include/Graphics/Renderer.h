#ifndef EON_RENDERER_RENDERER_H
#define EON_RENDERER_RENDERER_H

#include <SDL.h>
#include <vector>

#include "Common.h"
#include "Graphics/Color.h"
#include "Graphics/Mesh.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"

namespace eon {
namespace graphics {
class Renderer {
public:
  Renderer(const char *name, int width, int height);
  ~Renderer();

  void Render();

  void AddMesh(Mesh *mesh);
  void RemoveMesh(Mesh *mesh);

  void SetBackgroundColor(Color color);
  Color GetBackgroundColor();

  void SetShader(Shader shader);

  void SetTexture(Texture texture);

private:
  SDL_Window *window;
  Color bgColor;

  std::vector<Mesh *> meshes;

  GLuint currentShader;

  GLuint currentTexture;
};
}
}

#endif
