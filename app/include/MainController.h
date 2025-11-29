//
// Created by matfrg on 11/29/25.
//

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include <engine/core/Controller.hpp>

namespace app {

class MainController : public engine::core::Controller {
    void initialize() override;
    bool loop() override;
    void draw_sun();
    void begin_draw() override;
    void draw() override;
    void end_draw() override;

public:
    std::string_view name() const override {
        return "app::MainController";
    }
};


}// namespace app

#endif//MAINCONTROLLER_H
