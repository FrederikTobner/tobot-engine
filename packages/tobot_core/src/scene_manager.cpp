#include "scene_manager.h"

using namespace Tobot::Core;

template <typename T, typename... TArgs>
    requires BaseOf<T, Tobot::Core::Scene>
auto SceneManager::navigateTo(TArgs &&... args) -> void {
    T * scene(new T(std::forward<TArgs>(args)...));
    SceneManager::sp_SceneStack.push(scene);
}