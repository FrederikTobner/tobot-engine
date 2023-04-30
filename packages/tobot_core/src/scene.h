#pragma once

#include "SDL.h"

#include "pre_compiled_header.h"

#include "game_entity.h"
#include "layer.h"
#include "render_object.h"

namespace Tobot::Core {

    /// @brief A hash function for strings and char pointers that can be used in unordered_map.
    struct string_hash {
            using hash_type = std::hash<std::string_view>;
            using is_transparent = void;

            std::size_t operator()(const char * str) const {
                return hash_type{}(str);
            }
            std::size_t operator()(std::string_view str) const {
                return hash_type{}(str);
            }
            std::size_t operator()(std::string const & str) const {
                return hash_type{}(str);
            }
    };

    /// @brief A scene is a collection of layers that are rendered on the screen.
    ///@details These layers can contain game entities. The scene is responsible for the lifecycle of the game entities.
    /// It is also responsible for the lifecycle of the layers.
    class Scene {
        private:
            char const * m_BaseLayerId = "baseLayer";
            std::unordered_map<std::string, Layer *, string_hash, std::equal_to<>> m_Layers;

        protected:
            char const * m_Id;

            /**
             * @brief Adds a new GameEntity to the base layer
             *
             * @param gameEntity
             */
            auto add(Tobot::Core::GameEntity * gameEntity) -> void;

            /**
             * @brief Adds a new GameEntity to a specified layer. The layer must be created before.
             *
             * @param layerId
             */
            auto add(char const * layerId, GameEntity *) -> void;

            auto addLayer(Layer * layer) -> void;

            auto destroy(char const * id) -> void;
            auto destroyAll() -> void;

        public:
            Scene(char const * id);
            virtual ~Scene() = 0;

            auto prepareTextures(SDL_Renderer * renderer) -> void;

            auto update() -> void;
            auto render(SDL_Renderer * renderer) -> void;

            virtual auto onCreate() -> void = 0;
            virtual auto onDestroy() -> void = 0;
    };
} // namespace Tobot::Core
