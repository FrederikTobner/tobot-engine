#include "tobot_engine.h"
#include "tobot_tooling.h"

class Player : public Tobot::Core::GameEntity {
    public:
        Player() : GameEntity("player", 50, 50) {
            this->setTexture(Tobot::Core::AssetManager::loadTexture("assets/inspirational_picture.png"));
        }

        void update() override {
        }
};

class Background :  public Tobot::Core::GameEntity {
    public:
        Background() : GameEntity("background", 0, 0) {
            this->setTexture(Tobot::Core::AssetManager::loadTexture("assets/main_menu_background.png"));
        }

        void update() override {
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
            Tobot::Core::Layer * layer = new Tobot::Core::Layer("foreground", 1);
            this->addLayer(layer);

            this->add(new Background());
            this->add("foreground", new Player());
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
        }

        ~Example() {
            LOG_INFO("Godbye from Example %i", 321);
        }
};

Tobot::Core::TobotApplication * Tobot::Core::CreateApplication() {
    Tobot::Tooling::Logging::Logger::EnableFileOutput();
    LOG_INFO("Hello from Example %i", 123);
    return new Example();
}