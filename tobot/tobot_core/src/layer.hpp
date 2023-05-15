#pragma once

#include "pre_compiled_header.hpp"

#include "game_entity.hpp"

namespace Tobot::Core {
    class Layer {
        public:
            std::size_t order;

            std::string id;

            std::unordered_map<std::string, GameEntity *> entities;

            Layer(std::string id, std::size_t order);
    };
} // namespace Tobot::Core
