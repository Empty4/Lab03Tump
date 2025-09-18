#include "formatter_ex.hpp"
#include "formatter.hpp"

namespace formatter_ex {
    std::string format(const std::string& text) {
        return "[" + formatter::format(text) + "]";
    }
}
