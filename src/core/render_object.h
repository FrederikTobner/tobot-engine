#pragma once

namespace Tobot::Core
{
    class RenderObject
    {
    protected:
        const char *m_Id;
        int m_PositionX;
        int m_PositionY;

    public:
        RenderObject(const char *id, int x, int y) : m_Id(id), m_PositionX(x), m_PositionY(y) {}
        virtual ~RenderObject() = 0;

        const char* getId();
    };
} // namespace Tobot::Core

