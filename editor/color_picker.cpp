#include "color_picker.hpp"

#include "imgui.h"

using namespace Tobot::Editor;

ColorPicker::ColorPicker(bool & show_color_picker) : show_color_picker(show_color_picker) {
}

auto ColorPicker::render() -> void {
    if (show_color_picker) {
        static ImVec4 color = {0.0f, 0.0f, 0.0f, 1.0f};
        ImGui::Begin("Color Picker", &show_color_picker);
        ImGui::ColorPicker4("Color Picker", (float *)&color,
                            ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel);
        ImGui::SliderFloat("R", &color.x, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp);
        ImGui::SliderFloat("G", &color.y, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp);
        ImGui::SliderFloat("B", &color.z, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp);
        ImGui::SliderFloat("A", &color.w, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp);
        ImGui::End();
    }
}