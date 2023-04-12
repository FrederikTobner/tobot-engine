#pragma once

#include "SDL.h"

#include "render_object.h"

namespace Tobot::Core {
    class GameEntity : public Tobot::Core::RenderObject {

        protected:
            void setTexture(SDL_Surface * texture);

            SDL_Surface * p_TextureSurface;
            SDL_Texture * p_Texture;

        private:
            SDL_Rect m_SrcRect, m_DstRect;

            void prepareRects();

        public:
            GameEntity(char const * id, int x, int y, SDL_Texture * texture);
            GameEntity(char const * id, int x, int y);

            virtual ~GameEntity() = 0;

            void initializeTexture(SDL_Renderer * renderer);

            virtual void update() override = 0;
            void render(SDL_Renderer * renderer) override;
            void dispose() override;
    };
} // namespace Tobot::Core
