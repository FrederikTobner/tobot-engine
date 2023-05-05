#include "toolbar.h"

#include "icons_material_design.h"
#include "imgui.h"

auto Tobot::Editor::toolBarMain() -> void {
    ImGuiViewport * viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(viewport->Pos.x, viewport->Pos.y + 20));
    ImGui::SetNextWindowSize(ImVec2(viewport->Size.x, 20));
    ImGui::SetNextWindowViewport(viewport->ID);

    ImGuiWindowFlags window_flags = 0 | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
                                    ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar |
                                    ImGuiWindowFlags_NoSavedSettings;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    ImGui::Begin("Toolbar", NULL, window_flags);
    ImGui::PopStyleVar();

    // These Buttons should be ImageButtons in the future and the allignment should be altered then as well.
    // Right now it is based on the fixed width of 50 pixels per button. Right now we have a space of 10 pixels
    // between the buttons.
    float position = ImGui::GetCursorPosY();
    // Adding the play button
    ImGui::SetCursorPosX(viewport->Size.x / 2 - 35);
    ImGui::Button("##", ImVec2(20, 20));
    ImGui::SameLine();
    // Adding the icon for the play button
    ImGui::SetCursorPosX(viewport->Size.x / 2 - 35);
    ImGui::SetCursorPosY(position + 5);
    ImGui::Text(ICON_MD_PLAY_ARROW);
    ImGui::SetCursorPosY(position);
    ImGui::SameLine();
    // Adding the pause button
    ImGui::SetCursorPosX(viewport->Size.x / 2 - 10);
    ImGui::Button("##", ImVec2(20, 20));
    ImGui::SameLine();
    // Adding the icon for the play button
    ImGui::SetCursorPosX(viewport->Size.x / 2 - 10);
    ImGui::SetCursorPosY(position + 5);
    ImGui::Text(ICON_MD_PAUSE);
    ImGui::SetCursorPosY(position);
    ImGui::SameLine();
    // Adding the stop button
    ImGui::SetCursorPosX(viewport->Size.x / 2 + 15);
    ImGui::Button("##", ImVec2(20, 20));
    // Adding the icon for the stop button
    ImGui::SetCursorPosX(viewport->Size.x / 2 + 15);
    ImGui::SetCursorPosY(position + 8);
    ImGui::Text(ICON_MD_STOP);

    ImGui::End();
}