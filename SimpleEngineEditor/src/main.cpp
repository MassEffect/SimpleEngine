#include <iostream>
#include "SimpleEngineCore/Application.hpp"
#include <memory>
#include <imgui/imgui.h>

class SimpleEngineEditor : public SimpleEngine::Application
{
    virtual void on_update() override
    {
       // std::cout << "Update frame:" << ++frame << std::endl;
    };

    virtual void on_ui_draw() override
    {
        ImGui::Begin("Editor");
        ImGui::SliderFloat3("camera_position", camera_position, -10.f, 10.f);
        ImGui::SliderFloat3("camera_rotation", camera_rotation, 0.f, 360.f);
        ImGui::Checkbox("perspective_camera", &perspective_camera);
        ImGui::End();
    };

    int frame = 0;
};

int main()
{
   auto pSimpleEngineEditor = std::make_unique<SimpleEngineEditor>();

   int returnCode = pSimpleEngineEditor -> start(1024, 768, "My first SimpleEngineEditor");

   std::cin.get();
   return returnCode;
}
