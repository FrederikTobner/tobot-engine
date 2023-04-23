#include "scene_manager.h"

using namespace Tobot::Core;

template <typename T, typename... TArgs>
    requires BaseOf<T, Tobot::Core::Scene>
void SceneManager::navigateTo(TArgs &&... args) {
    T * scene(new T(std::forward<TArgs>(args)...));
    SceneManager::sp_SceneStack.push(scene);
}