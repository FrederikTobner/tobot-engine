#include "view.h"

using namespace Farscape::Core;

template<typename T>
void View::add(T *renderObject) {
    if (this->m_RenderObjects.find(renderObject->getId()) != this->m_RenderObjects.end()) {
        this->m_RenderObjects[renderObject->getId()] = std::make_unique<RenderObject>(renderObject);
    }
}