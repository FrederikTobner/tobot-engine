#pragma once

#include "SDL.h"

#include <iostream>
#include <unordered_map>
#include <vector>

#include "game_entity.h"
#include "render_object.h"

namespace Tobot::Core {
class Scene {
  private:
    std::unordered_map<const char *, GameEntity *> m_GameEntities;

  protected:
    const char * m_Id;

    void add(Tobot::Core::GameEntity * gameEntity);

  public:
    Scene(const char * id);

    void prepareTextures(SDL_Renderer * renderer);

    void update();
    void render(SDL_Renderer * renderer);

    virtual void onCreate() = 0;
};
} // namespace Tobot::Core
