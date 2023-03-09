#pragma once

#include "math/vector2d.h"

#include "SDL.h"

namespace Tobot::Core
{
    class RenderObject
    {
    protected:
        const char *m_Id;
        Tobot::Math::Vector2D<int> m_Position;

    public:
        RenderObject(const char *id, int x, int y);
        virtual ~RenderObject() = 0;

        virtual void update() = 0;
        virtual void render(SDL_Renderer *renderer) = 0;

        const char *getId();
        Tobot::Math::Vector2D<int> getPosition();
    };
} // namespace Tobot::Core
