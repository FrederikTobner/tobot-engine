#include "tobot_engine.hpp"
#include "tobot_tooling.hpp"

class Soldier : public Tobot::Core::GameEntity {
    public:
        Soldier() : GameEntity("soldier", 10.0f, 10.0f, "assets/Player_gold.png") {
        }

        void update() override {
            this->m_transform.translate(Tobot::Math::Vector2D<float>(1.0f, 1.0f));
            this->m_transform.rotate(1.0);
            if (this->getPosition().getX() == 500.0f) {
                this->setVisible(false);
            }
        }
};

class Weapon : public Tobot::Core::GameEntity {
    public:
        Weapon() : GameEntity("weapon", 10, 10, "assets/Weapon_Parazoinium.png") {
        }

        void update() override {
            this->m_transform.translate(Tobot::Math::Vector2D<float>(1.0f, 1.0f));
            this->m_transform.rotate(1.0);
            if (this->getPosition().getX() == 500.0f) {
                this->setVisible(false);
            }
        }
};

class Player : public Tobot::Core::GameEntity {
    public:
        Player() : GameEntity("player", 50, 50, "assets/inspirational_picture.png") {
        }

        void update() override {
        }
};

class Background : public Tobot::Core::GameEntity {
    public:
        Background() : GameEntity("background", 0, 0, "assets/main_menu_background.png", 1.6f, 1.6f) {
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
            Tobot::Core::Layer * weaponLayer = new Tobot::Core::Layer("weaponLayer", 2);
            Tobot::Core::Layer * playerLayer = new Tobot::Core::Layer("playerLayer", 3);
            this->addLayer(layer);
            this->addLayer(playerLayer);
            this->addLayer(weaponLayer);

            this->add(new Background());
            this->add("foreground", new Player());
            this->add("playerLayer", new Soldier());
            this->add("weaponLayer", new Weapon());
        }

        void onDestroy() override {
            LOG_INFO("%s", "MainMenu::onDestroy");
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
    Tobot::Tooling::Logger::enableFileOutput();
    LOG_INFO("Hello from Example %i", 123);
    return new Example();
}