#include "tobot.h"

class Player : public Tobot::Core::GameEntity {
    public:
        Player() : GameEntity("player", 50, 50) {
            this->setTexture(Tobot::Core::AssetManager::loadTexture("../assets/inspirational_picture.png"));
        }

        void update() override {
            this->m_Position += Tobot::Math::Vector2D<int>(1, 1);
        }
};

class BlankScene : public Tobot::Core::Scene {
    public:
        BlankScene() : Scene("BlankScene") {
        }

        void onCreate() override {
            LOG_INFO("BlankScene::onCreate");
        }

        void onDestroy() override {
            LOG_INFO("BlankScene::onDestroy");
        }
};

class IntroductionScene : public Tobot::Core::Scene {
    public:
        IntroductionScene() : Scene("MainMenu") {
            // Initialize variables
        }

        void onCreate() override {
            // Layers, Widgets, RenderObjects
            LOG_INFO("MainMenu::onCreate");
            this->add(new Player());
        }

        void onDestroy() override {
            LOG_INFO("MainMenu::onDestroy");
            this->destroy("player");
        }
};

class Example : public Tobot::Core::TobotApplication {
    public:
        Example() : TobotApplication("Example") {
            this->m_DisplaySize = Tobot::Math::Dimension<int>(1200, 800);
            this->setInitialScene(new IntroductionScene());

            Tobot::Core::SceneManager::load<BlankScene>();
        }

        ~Example() {
            LOG_INFO("Godbye from Example %i", 321);
        }
};

Tobot::Core::TobotApplication * Tobot::Core::CreateApplication() {
    Tobot::Utilities::Logger::EnableFileOutput();
    LOG_INFO("Hello from Example %i", 123);
    return new Example();
}