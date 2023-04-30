#include "layer.h"

using namespace Tobot::Core;

[[nodiscard]] Layer::Layer(std::string id, std::size_t order) : id(id), order(order) {
}
