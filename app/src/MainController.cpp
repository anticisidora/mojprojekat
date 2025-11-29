//
// Created by matfrg on 11/29/25.
//

#include "MainController.h"

#include "spdlog/spdlog.h"

#include <engine/graphics/GraphicsController.hpp>
#include <engine/graphics/OpenGL.hpp>
#include <engine/platform/PlatformController.hpp>
#include <engine/resources/ResourcesController.hpp>


namespace app {

void MainController::initialize() {
    spdlog::info("MainController initialized!!!");
    engine::graphics::OpenGL::enable_depth_testing();
}
bool MainController::loop() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    if (platform->key(engine::platform::KeyId::KEY_ESCAPE).is_down()) {
        return false;
    }
    return true;
}
void MainController::draw_sun() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *sun = resources->model("sun");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -20.0f));
    model = glm::scale(model, glm::vec3(0.5f));
    shader->set_mat4("model", model);
    sun->draw(shader);
}
void MainController::begin_draw() {
    engine::graphics::OpenGL::clear_buffers();
}
void MainController::draw() {
    draw_sun();
}
void MainController::end_draw() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    platform->swap_buffers();
}


}// namespace app