#pragma once

#include "pre_compiled_header.h"

#include "scene.h"

#include "concepts.h"

namespace Tobot::Core {
    /// @brief Responsible for supplying the application with scenes which are pushed onto a stack
    ///        at runtime during the user and consumed before the application handles input events.
    class SceneManager {
        public:
            /// @brief Contains possible scenes which are pushed onto the stack during runtime
            inline static std::stack<Tobot::Core::Scene *> sp_SceneStack = {};

            /// @brief Loads a new scene onto the scene stack. It calles the scenes constructor.
            /// @tparam T Type of the scene implementation
            /// @tparam ...TArgs One or more types of scenes constructor
            /// @param ...args Constructor arguments of the scene implementation
            template <typename T, typename... TArgs>
                requires BaseOf<T, Tobot::Core::Scene>
            static auto navigateTo(TArgs &&... args) -> void;
    };
} // namespace Tobot::Core
