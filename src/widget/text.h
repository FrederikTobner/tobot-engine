#pragma once

#include "core/render_object.h"

namespace Farscape::Widget
{
    class Text : public Farscape::Core::RenderObject
    {
    private:
        const char *m_Text;

    public:
        Text(const char *text, const char *id, int x, int y) : RenderObject(id, x, y), m_Text(text) {}
    };
} // namespace Farscape::Widget

