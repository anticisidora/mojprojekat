//
// Created by matfrg on 11/29/25.
//

#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H
#include <engine/core/Controller.hpp>

namespace app {

class GUIController : public engine::core::Controller {
public:
    std::string_view name() const override {
        return "app::GUIKontroler";
    }

private:
    void initialize() override;
    void poll_events() override;
    void draw() override;
};

} // app

#endif //GUICONTROLLER_H
