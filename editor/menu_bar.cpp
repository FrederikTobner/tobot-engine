/// @file menu_bar.cpp
/// @brief Contains definitions regarding the menu bar for the editor

#include "menu_bar.h"

#include "imgui.h"

auto Tobot::Editor::menuBarMain(bool & done, bool & show_tobot_help) -> void {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("New Project")) {
                // Create a new project
            }
            if (ImGui::MenuItem("Save")) {
                // Save the project
            }
            if (ImGui::MenuItem("Exit")) {
                done = true;
            }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Assets")) {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Window")) {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help")) {
            if (ImGui::MenuItem("About Tobot")) {
                show_tobot_help = true;
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}