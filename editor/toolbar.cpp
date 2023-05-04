#include "toolbar.h"

#include "imgui.h"

auto Tobot::Editor::toolBarMain() -> void {
    ImGuiViewport * viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(viewport->Pos.x, viewport->Pos.y + 20));
    ImGui::SetNextWindowSize(ImVec2(viewport->Size.x, 50));
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
    ImGui::SetCursorPosX(viewport->Size.x / 2 - 85);
    ImGui::Button("Play", ImVec2(50, 37));
    ImGui::SameLine();
    ImGui::SetCursorPosX(viewport->Size.x / 2 - 25);
    ImGui::Button("Pause", ImVec2(50, 37));
    ImGui::SameLine();
    ImGui::SetCursorPosX(viewport->Size.x / 2 + 35);
    ImGui::Button("Stop", ImVec2(50, 37));

    ImGui::End();
}