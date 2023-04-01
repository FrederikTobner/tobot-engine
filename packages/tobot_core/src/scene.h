#pragma once

#include "SDL.h"

#include "pre_compiled_header.h"

#include "game_entity.h"
#include "layer.h"
#include "render_object.h"


namespace Tobot::Core {
    class Scene {
        private:
            
            const char * m_BaseLayerId = "baseLayer";
            std::unordered_map<const char *, Layer *> m_Layers;


        protected:
            const char * m_Id;

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
            void add(const char * layerId, GameEntity *);

            void addLayer(Layer * layer);

            void destroy(const char * id);
            void destroyAll();

        public:
            Scene(const char * id);
            virtual ~Scene() = 0;

            void prepareTextures(SDL_Renderer * renderer);

            void update();
            void render(SDL_Renderer * renderer);

            virtual void onCreate() = 0;
            virtual void onDestroy() = 0;
    };
} // namespace Tobot::Core
