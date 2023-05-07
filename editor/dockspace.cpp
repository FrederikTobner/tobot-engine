/// @file dockspace.cpp
/// @brief Contains definitions regarding the dockspace of the editor

#include "dockspace.hpp"

using namespace Tobot::Editor;

Dockspace::Dockspace(bool & show_tobot_about, ImGuiIO & io, ImVec2 & scenePosition, ImVec2 & sceneWindowSize)
    : show_tobot_about(show_tobot_about), io(io), scenePosition(scenePosition), sceneWindowSize(sceneWindowSize) {
    this->viewport = ImGui::GetMainViewport();
}

auto Tobot::Editor::Dockspace::render() -> void {

    ImGui::SetNextWindowPos(ImVec2(viewport->Pos.x, viewport->Pos.y + 30));
    ImGui::SetNextWindowSize(ImVec2(viewport->Size.x, viewport->Size.y - 30));
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking |
                                    ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                                    ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                                    ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::Begin("Master DockSpace", NULL, window_flags);
    ImGuiID dockMain = ImGui::GetID("MyDockspace");

    ImGui::DockSpace(dockMain);
    ImGui::End();
    ImGui::PopStyleVar(3);

    // The Inspector Window
    static float position[] = {1.0f, 2.0f};
    static float rotation = 0.0f;
    static float scale[] = {3.0f, 4.0f};
    ImGui::Begin("Inspector");
    ImGui::Text("Transform");
    ImGui::InputFloat2("Position", position);
    ImGui::InputFloat("Rotation", &rotation);
    ImGui::InputFloat2("Scale", scale);
    ImGui::End();

    // The scene hierarchy
    ImGui::Begin("Hierarchy");
    if (ImGui::TreeNode("Root")) {
        if (ImGui::TreeNode("Child 1")) {
            ImGui::Text("Hello from Child 1");
            ImGui::TreePop();
        }
        ImGui::TreePop();
    }
    ImGui::End();

    // The resources window
    ImGui::Begin("Resources");
    ImGui::Text("Here we will display resources");
    ImGui::BulletText("Folders");
    ImGui::BulletText("Assets");
    ImGui::BulletText("Scripts");
    ImGui::BulletText("Etc");
    ImGui::End();

    // Our Scene Window
    ImGui::Begin("Scene Window");
    // Get the position and size of the window so we can render our scene without the toolbar
    scenePosition = ImVec2(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y + 20);
    sceneWindowSize = ImVec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y - 20);
    ImGui::End();

    // Creating the about window for tobot
    if (show_tobot_about) {
        ImGui::Begin("TobotAbout", &show_tobot_about,
                     ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking);
        ImGui::Text("Rendering implemented using SDL2 and ImGui\n\nAuthors:\n");
        ImGui::BulletText("Jonas Habel");
        ImGui::BulletText("Julian Otto");
        ImGui::BulletText("Frederik Tobner");
        ImGui::End();
    }
}