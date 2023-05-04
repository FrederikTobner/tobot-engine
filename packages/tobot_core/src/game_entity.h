#pragma once

#include "SDL.h"

#include "render_object.h"

namespace Tobot::Core {
    class GameEntity : public Tobot::Core::RenderObject {

        protected:
            auto setTexture(SDL_Surface * texture) -> void;

            SDL_Surface * p_TextureSurface;
            SDL_Texture * p_Texture;

        private:
            SDL_Rect m_SrcRect, m_DstRect;

            auto prepareRects() -> void;

        public:
            GameEntity(char const * id, float x, float y, SDL_Texture * texture);
            GameEntity(char const * id, float x, float y);

            virtual ~GameEntity() = 0;

            auto initializeTexture(SDL_Renderer * renderer) -> void;

            virtual auto update() -> void override = 0;
            auto render(SDL_Renderer * renderer) -> void override;
            auto dispose() -> void override;
    };
} // namespace Tobot::Core
