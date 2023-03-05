#pragma once

#include "math/vector2d.h"

namespace Tobot::Core
{
    class RenderObject
    {
    protected:
        const char *m_Id;
        Tobot::Math::Vector2D<int> m_Position;

    public:
        RenderObject(const char *id, int x, int y) : m_Id(id), m_Position(x, y) {}
        virtual ~RenderObject() = 0;

        const char *getId();
        Tobot::Math::Vector2D<int> getPosition();
    };
} // namespace Tobot::Core
