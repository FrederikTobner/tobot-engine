#pragma once
#include <unordered_map>

#include <iostream>
#include <string>


#include "game_entity.h"

namespace Tobot::Core {
    class Layer {
        public:
            int order;

            const char *id;

            std::unordered_map<const char *, GameEntity *> entities;

            Layer(const char  *id, int order);
    };
} // namespace Tobot::Core
