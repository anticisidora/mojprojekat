//
// Created by matfrg on 11/29/25.
//

#include "MyApp.h"

#include "GUIController.h"
#include "MainController.h"
#include "spdlog/spdlog.h"

namespace app {
void MyApp::app_setup() {
    spdlog::info("App setup done!");
    auto main_controller = register_controller<app::MainController>();
    auto gui_controller = register_controller<app::GUIController>();
    main_controller->after(engine::core::Controller::get<engine::core::EngineControllersEnd>());
    main_controller->before(gui_controller);
}
}// namespace app