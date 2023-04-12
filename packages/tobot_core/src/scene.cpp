#include "scene.h"

using namespace Tobot::Core;

Scene::Scene(char const * id) : m_Id(id) {
    Layer * baseLayer = new Layer(this->m_BaseLayerId, 0);
    this->m_Layers[this->m_BaseLayerId] = baseLayer;
}

void Scene::add(GameEntity * gameEntity) {
    this->m_Layers.at(this->m_BaseLayerId)->entities[gameEntity->getId()] = gameEntity;
}

void Scene::add(char const * layerId, GameEntity * gameEntity) {
    this->m_Layers.at(this->m_BaseLayerId)->entities.insert(std::make_pair(gameEntity->getId(), gameEntity));
}

void Scene::addLayer(Layer * layer) {
    this->m_Layers[layer->id.c_str()] = layer;
}

void Scene::prepareTextures(SDL_Renderer * renderer) {
    for (auto layer : this->m_Layers) {
        for (auto entity : layer.second->entities) {
            entity.second->initializeTexture(renderer);
        }
    }
}

void Scene::update() {
    std::vector<Layer *> layers;
    if (this->m_Layers.size() > 0) {
        std::vector<Layer *> sortedLayers;
        for (auto & pair : this->m_Layers) {
            sortedLayers.push_back(pair.second);
        }
        std::sort(sortedLayers.begin(), sortedLayers.end(), [](Layer * a, Layer * b) { return a->order < b->order; });
        layers = sortedLayers;
    }

    for (auto layer : this->m_Layers) {
        layers.push_back(layer.second);
    }

    for (auto & layer : layers) {
        for (auto & entity : layer->entities) {
            entity.second->update();
        }
    }
}

void Scene::render(SDL_Renderer * renderer) {
    for (auto object : this->m_Layers) {
        for (auto entity : object.second->entities) {
            if (entity.second->isVisible()) {
                entity.second->render(renderer);
            }
        }
    }
}

void Scene::destroy(char const * id) {
    for (auto layer : this->m_Layers) {
        for (auto entity : layer.second->entities) {
            if (entity.first == id) {
                entity.second->dispose();
            }
        }
    }
}

void Scene::destroyAll() {
    for (auto layer : this->m_Layers) {
        for (auto entity : layer.second->entities) {
            entity.second->dispose();
        }
    }
}

Scene::~Scene() {
    for (auto layer : this->m_Layers) {
        delete layer.second;
    }
}