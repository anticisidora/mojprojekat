//
// Created by matfrg on 11/29/25.
//

#include "GUIController.h"

#include <engine/graphics/GraphicsController.hpp>
#include <engine/platform/Input.hpp>
#include <engine/platform/PlatformController.hpp>
#include <imgui.h>


namespace engine::graphics {
class GraphicsController;
}
namespace engine::platform {
class PlatformController;
}
namespace app {
void GUIController::initialize() {
    set_enable(false);
}
void GUIController::poll_events() {
    const auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    if (platform->key(engine::platform::KeyId::KEY_L).state() == engine::platform::Key::State::JustPressed) {
        set_enable(!is_enabled());
    }
}
void GUIController::draw() {
    auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
    engine::graphics::Camera *camera = graphics->camera();
    graphics->begin_gui();
    ImGui::Begin("Informacije o trenutnom stanju kamere");
    ImGui::Text("Pozicija kamere: (%f, %f, %f)", camera->Position.x, camera->Position.y, camera->Position.z);
    ImGui::End();
    graphics->end_gui();
}

} // app