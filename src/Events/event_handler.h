/**
 * @brief Event handler class.
 */


#pragma once

#include "event.h"
#include <iostream>
#include <string>
#include <memory>

class EventHandler {
public:
    void HandleEvent(const std::shared_ptr<Event>& event) {
        std::cout << event->ToString() << std::endl;
    }
};
