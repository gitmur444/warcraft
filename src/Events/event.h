/**
 * @brief Event class.
 */

#pragma once

#include <string>

class Event {
public:
    virtual ~Event() = default;
    virtual std::string ToString() const = 0;
};
