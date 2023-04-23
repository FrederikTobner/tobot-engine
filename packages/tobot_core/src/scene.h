#pragma once

#include "SDL.h"

#include "pre_compiled_header.h"

#include "game_entity.h"
#include "layer.h"
#include "render_object.h"

namespace Tobot::Core {

    /// @brief A hash function for strings that can be used in unordered_map.
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
    ///It is also responsible for the lifecycle of the layers.
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
            void add(Tobot::Core::GameEntity * gameEntity);

            /**
             * @brief Adds a new GameEntity to a specified layer. The layer must be created before.
             *
             * @param layerId
             */
            void add(char const * layerId, GameEntity *);

            void addLayer(Layer * layer);

            void destroy(char const * id);
            void destroyAll();

        public:
            Scene(char const * id);
            virtual ~Scene() = 0;

            void prepareTextures(SDL_Renderer * renderer);

            void update();
            void render(SDL_Renderer * renderer);

            virtual void onCreate() = 0;
            virtual void onDestroy() = 0;
    };
} // namespace Tobot::Core
