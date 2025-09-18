#include "formatter.hpp"
#include <sstream>

namespace formatter {
    std::string format(const std::string& text) {
        std::ostringstream oss;
        oss << text;
        return oss.str();
    }
}
