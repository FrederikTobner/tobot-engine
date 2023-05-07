/// @file dockspace.cpp
/// @brief Contains definitions regarding the dockspace of the editor

#include "dockspace.hpp"

using namespace Tobot::Editor;

Dockspace::Dockspace(bool & show_demo_window, bool & show_tobot_about, bool & show_another_window, ImGuiIO & io,
                     ImVec2 & scenePosition, ImVec2 & sceneWindowSize)
    : show_demo_window(show_demo_window), show_tobot_about(show_tobot_about), show_another_window(show_another_window),
      io(io), scenePosition(scenePosition), sceneWindowSize(sceneWindowSize) {
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
    // Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its
    // code to learn more about Dear ImGui!).
    if (show_demo_window) {
        ImGui::ShowDemoWindow(&show_demo_window);
    }

    // The hello world window - example code from imgui (just for testing the layout)
    static float f = 0.0f;
    static int counter = 0;
    // Create a window called "Hello, world!" and append into it.
    ImGui::Begin("Hello, world!");

    ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
    ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
    ImGui::Checkbox("Another Window", &show_another_window);

    ImGui::SliderFloat("float", &f, 0.0f, 1.0f); // Edit 1 float using a slider from 0.0f to 1.0f

    ImGui::SliderFloat("float", &f, 0.0f,
                       1.0f); // Edit 1 float using a slider from 0.0f to 1.0f

    if (ImGui::Button("Button")) { // Buttons return true when clicked (most widgets return true when
                                   // edited/activated)
        counter++;
    }
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    ImGui::End();

    // Our Scene Window
    ImGui::Begin("Scene Window");
    // Get the position and size of the window so we can render our scene without the toolbar
    scenePosition = ImVec2(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y + 20);
    sceneWindowSize = ImVec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y - 20);
    ImGui::End();

    // Show another simple window.
    if (show_another_window) {
        ImGui::Begin("Another Window",
                     &show_another_window); // Pass a pointer to our bool variable (the window will have a
                                            // closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me")) {
            show_another_window = false;
        }
        ImGui::End();
    }
    // Creating the about window for tobot
    if (show_tobot_about) {
        ImGui::Begin("TobotAbout", &show_tobot_about);
        ImGui::Text("Rendering implemented using SDL2 and ImGui\n\nAuthors:\n");
        ImGui::BulletText("Jonas Habel");
        ImGui::BulletText("Julian Otto");
        ImGui::BulletText("Frederik Tobner");
        ImGui::End();
    }
}