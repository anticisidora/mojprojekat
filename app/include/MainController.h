//
// Created by matfrg on 11/29/25.
//

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "glm/vec3.hpp"


#include <engine/core/Controller.hpp>
#include <engine/resources/Shader.hpp>

namespace app {

class MainController : public engine::core::Controller {
    void initialize() override;
    bool loop() override;
    void set_lighting(engine::resources::Shader *shader);
    void draw_sun();
    void draw_mercury();
    void draw_venus();
    void draw_earth();
    void draw_mars();
    void draw_jupiter();
    void draw_saturn();
    void draw_uranus();
    void draw_neptune();
    void draw_meteorite();
    void draw_skybox();
    void update_camera();
    void update() override;
    void begin_draw() override;
    void draw() override;
    void end_draw() override;

    bool visible_meteorite = false;
    bool visible_jupiter = true;
    bool move_meteorite = false;

    glm::vec3 meteorite_pos = glm::vec3(12.0f, 6.0f, -20.0f);
    glm::vec3 jupiter_pos = glm::vec3(3.5f, 0.0f, -20.0f);
    float meteorite_speed = 3.0f;

    float meteor_radius = 0.25f;
    float jupiter_radius = 1.8f;


public:
    std::string_view name() const override {
        return "app::MainController";
    }
};


}// namespace app

#endif//MAINCONTROLLER_H
