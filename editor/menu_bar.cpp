/// @file menu_bar.cpp
/// @brief Contains definitions regarding the menu bar for the editor

#include "menu_bar.hpp"

#include "imgui.h"

using namespace Tobot::Editor;

MenuBar::MenuBar(bool & done, bool & show_tobot_about, bool & show_color_picker)
    : done(done), show_tobot_about(show_tobot_about), show_color_picker(show_color_picker) {
}

auto MenuBar::render() -> void {
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
            if (ImGui::MenuItem("Color Picker")) {
                show_color_picker = true;
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help")) {
            if (ImGui::MenuItem("About Tobot")) {
                show_tobot_about = true;
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}