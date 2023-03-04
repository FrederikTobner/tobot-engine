#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

#include "render_object.h"

namespace Farscape::Core
{
    class View
    {
    private:
        std::unordered_map<const char *, std::unique_ptr<RenderObject>> m_RenderObjects;

    protected:
        const char *m_Id;
        
        /// TODO: Make this something like "T extends RenderObject"
        template<typename T>
        void add(T *renderObject);

    public:
        virtual void initialize() = 0;
    };
} // namespace Farscape::Core
