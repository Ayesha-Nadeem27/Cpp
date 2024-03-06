#pragma once

#include <stdexcept>
#include <iostream>

using namespace std;

class AdminException : public runtime_error {
    public:
        explicit AdminException(const std::string& message )
            : runtime_error(message) {}
};