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
    model = glm::translate(model, glm::vec3(-10.0f, 0.0f, -20.0f));
    model = glm::scale(model, glm::vec3(0.3f));
    shader->set_mat4("model", model);
    sun->draw(shader);
}
void MainController::draw_mercury() {

    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *mercury = resources->model("mercury");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-5.50f, 0.0f, -20.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(-1.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.5f));
    shader->set_mat4("model", model);
    mercury->draw(shader);
}
void MainController::draw_venus() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *venus = resources->model("venus");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-3.70f, 0.0f, -20.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(-1.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.8f));
    shader->set_mat4("model", model);
    venus->draw(shader);
}
void MainController::draw_earth() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *earth = resources->model("earth");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-1.55f, 0.0f, -20.0f));
    model = glm::rotate(model, glm::radians(270.0f), glm::vec3(-1.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.95f));
    shader->set_mat4("model", model);
    earth->draw(shader);
}
void MainController::draw_mars() {

    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *mars = resources->model("mars");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.5f, 0.0f, -20.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(-1.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.7f));
    shader->set_mat4("model", model);
    mars->draw(shader);
}
void MainController::draw_jupiter() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *jupiter = resources->model("jupiter");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(3.5f, 0.0f, -20.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(-1.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.8f));
    shader->set_mat4("model", model);
    jupiter->draw(shader);
}
void MainController::draw_saturn() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *saturn = resources->model("saturn");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(7.3f, 0.0f, -20.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(-1.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.2f));
    shader->set_mat4("model", model);
    saturn->draw(shader);
}
void MainController::draw_uranus() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *uranus = resources->model("uranus");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(10.50f, 0.0f, -20.0f));
    model = glm::scale(model, glm::vec3(2.0f));
    shader->set_mat4("model", model);
    uranus->draw(shader);
}

void MainController::draw_neptune() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *neptune = resources->model("neptune");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(13.0f, 0.0f, -20.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(-1.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.7f));
    shader->set_mat4("model", model);
    neptune->draw(shader);
}
void MainController::draw_meteorite() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *meteorite = resources->model("meteorite");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, meteorite_pos);
    model = glm::scale(model, glm::vec3(0.25f));
    shader->set_mat4("model", model);
    meteorite->draw(shader);
}

void MainController::draw_skybox() {
    auto resources = engine::core::Controller::get<engine::resources::ResourcesController>();
    auto skybox = resources->skybox("blue");
    auto shader = resources->shader("skybox");
    auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
    graphics->draw_skybox(shader, skybox);
}

void MainController::update_camera() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    auto camera = engine::core::Controller::get<engine::graphics::GraphicsController>()->camera();
    float dt = platform->dt();
    if (platform->key(engine::platform::KEY_W)
                .state() == engine::platform::Key::State::Pressed) {
        camera->move_camera(engine::graphics::Camera::Movement::FORWARD, dt);
    }
    if (platform->key(engine::platform::KEY_S)
                .state() == engine::platform::Key::State::Pressed) {
        camera->move_camera(engine::graphics::Camera::Movement::BACKWARD, dt);
    }
    if (platform->key(engine::platform::KEY_A)
                .state() == engine::platform::Key::State::Pressed) {
        camera->move_camera(engine::graphics::Camera::Movement::LEFT, dt);
    }
    if (platform->key(engine::platform::KEY_D)
                .state() == engine::platform::Key::State::Pressed) {
        camera->move_camera(engine::graphics::Camera::Movement::RIGHT, dt);
    }

    if (platform->key(engine::platform::KeyId::KEY_M).state() == engine::platform::Key::State::JustPressed) {
        visible_meteorite = true;
        move_meteorite = true;

        meteorite_pos = glm::vec3(12.0f, 6.0f, -20.0f);
    }

    if (platform->key(engine::platform::KeyId::KEY_R).state() == engine::platform::Key::State::JustPressed) {
        visible_jupiter = true;
        visible_meteorite = false;
        move_meteorite = false;

        meteorite_pos = glm::vec3(12.0f, 6.0f, -20.0f);
    }
}
void MainController::update() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    float dt = platform->dt();
    if (move_meteorite) {

        glm::vec3 direction = jupiter_pos - meteorite_pos;
        float distance = glm::length(direction);


        direction = glm::normalize(direction);


        meteorite_pos += direction * meteorite_speed * dt;

        float collision_distance = meteor_radius + jupiter_radius;

        if (distance <= collision_distance) {
            visible_meteorite = false;
            visible_jupiter = false;
            move_meteorite = false;
        }
    }


    update_camera();
}

void MainController::begin_draw() {
    engine::graphics::OpenGL::clear_buffers();
}
void MainController::draw() {
    draw_sun();
    draw_mercury();
    draw_venus();
    draw_earth();
    draw_mars();
    if (visible_jupiter) {
        draw_jupiter();
    }
    draw_saturn();
    draw_uranus();
    draw_neptune();
    if (visible_meteorite) {
        draw_meteorite();
    }
    draw_skybox();
}
void MainController::end_draw() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    platform->swap_buffers();
}


}// namespace app