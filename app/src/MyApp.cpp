//
// Created by matfrg on 11/29/25.
//

#include "MyApp.h"

#include "MainController.h"
#include "spdlog/spdlog.h"

namespace app {
void MyApp::app_setup() {
    spdlog::info("App setup done!");
    auto main_controller = register_controller<app::MainController>();
    main_controller->after(engine::core::Controller::get<engine::core::EngineControllersEnd>());
}
}// namespace app