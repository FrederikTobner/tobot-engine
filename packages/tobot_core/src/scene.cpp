#include "scene.hpp"

using namespace Tobot::Core;

[[nodiscard]] Scene::Scene(char const * id) : m_Id(id) {
    Layer * baseLayer = new Layer(this->m_BaseLayerId, 0);
    this->m_Layers[this->m_BaseLayerId] = baseLayer;
}

auto Scene::add(GameEntity * gameEntity) -> void {
    this->m_Layers.at(this->m_BaseLayerId)->entities[gameEntity->getId()] = gameEntity;
}

auto Scene::add(char const * layerId, GameEntity * gameEntity) -> void {
    if (!this->m_Layers.contains(layerId)) {
        throw std::runtime_error("Layer not found");
    }
    this->m_Layers.at(layerId)->entities.insert(std::make_pair(gameEntity->getId(), gameEntity));
}

auto Scene::addLayer(Layer * layer) -> void {
    this->m_Layers[layer->id.c_str()] = layer;
}

auto Scene::prepareTextures(SDL_Renderer * renderer) -> void {
    for (auto [layerId, layer] : this->m_Layers) {
        for (auto [enitityId, entity] : layer->entities) {
            entity->initializeTexture(renderer);
        }
    }
}

auto Scene::update() -> void {
    // We should sort the layers by their order using a binary search tree instead of the unordered_map
    // Another option is to use a std::vector and use the order as the index.
    // Looking up layers by the name could be slow by iterating through the vector, because that is not a priority.
    // Or we are generous regarding memory usage and add both options. Because only a single scene is active at a time,
    // and there shouldn't be too many layers in a scene we could afford that.
    // (e.g 10 layers per scene => (8Byte + KeyLenght(~8) + NullCharacter (1 byte)) * 10 = 170 bytes +
    // sizeof(unordered_map) = 170 + 32 = 202 Bytes
    // - rougly))
    std::vector<Layer *> layers;
    if (this->m_Layers.size() > 0) {
        for (auto & [layerId, layer] : this->m_Layers) {
            layers.push_back(layer);
        }
        std::sort(layers.begin(), layers.end(), [](Layer * a, Layer * b) { return a->order < b->order; });
    }

    for (auto & layer : layers) {
        for (auto & entity : layer->entities) {
            entity.second->update();
        }
    }
}

auto Scene::render(SDL_Renderer * renderer) -> void {
    // We should sort the layers by their order using a binary search tree instead of the unordered_map
    // Another option is to use a std::vector and use the order as the index.
    // Looking up layers by the name could be slow by iterating through the vector, because that is not a priority.
    // Or we are generous regarding memory usage and add both options. Because only a single scene is active at a time,
    // and there shouldn't be too many layers in a scene we could afford that.
    // (e.g 10 layers per scene => (8Byte + KeyLenght(~8) + NullCharacter (1 byte)) * 10 = 170 bytes +
    // sizeof(unordered_map) = 170 + 32 = 202 Bytes
    // - rougly))
    std::vector<Layer *> layers;
    if (this->m_Layers.size() > 0) {
        for (auto & [layerId, layer] : this->m_Layers) {
            layers.push_back(layer);
        }
        std::sort(layers.begin(), layers.end(), [](Layer * a, Layer * b) { return a->order < b->order; });
    }
    for (auto & layer : layers) {
        for (auto [enitityId, entity] : layer->entities) {
            if (entity->isVisible()) {
                entity->render(renderer);
            }
        }
    }
}

auto Scene::destroy(char const * id) -> void {
    for (auto [layerId, layer] : this->m_Layers) {
        for (auto [enitityId, entity] : layer->entities) {
            if (enitityId == id) {
                entity->dispose();
            }
        }
    }
}

auto Scene::destroyAll() -> void {
    for (auto [layerId, layer] : this->m_Layers) {
        for (auto [enitityId, entity] : layer->entities) {
            entity->dispose();
        }
    }
}

Scene::~Scene() {
    for (auto [layerId, layer] : this->m_Layers) {
        delete layer;
    }
}