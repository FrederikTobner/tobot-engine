#include "tobot.h"

class Player : public Tobot::Core::GameEntity
{
public:
    Player() : GameEntity("player", 50, 50)
    {
        this->setTexture(Tobot::Core::AssetManager::loadTexture("../../assets/inspirational_picture.png"));
    }

    void update() override
    {
        this->m_Position += Tobot::Math::Vector2D<int>(1, 1);
    }
};

class IntroductionScene : public Tobot::Core::Scene
{
public:
    IntroductionScene() : Scene("MainMenu")
    {
        // Initialize variables
    }

    void onCreate() override
    {
        // Layers, Widgets, RenderObjects
        LOG_INFO("MainMenu::onCreate");
        this->add(new Player());
    }
};

class Example : public Tobot::Core::TobotApplication
{
public:
    Example() : TobotApplication("Example")
    {
        this->m_DisplayWidth = 1200;
        this->m_DisplayHeight = 800;
        this->setInitialScene(new IntroductionScene());
    }

    ~Example()
    {
        LOG_INFO("Godbye from Example %i", 321);
    }
};

Tobot::Core::TobotApplication *Tobot::Core::CreateApplication()
{
    Tobot::Utilities::Logger::EnableFileOutput();
    LOG_INFO("Hello from Example %i", 123);
    return new Example();
}