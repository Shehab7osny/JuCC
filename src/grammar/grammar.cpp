#include "grammar/grammar.h"

#include <sstream>

std::string jucc::grammar::Rule::toString() const {
  std::stringstream ss;
  for (auto &entity : entities) {
    ss << entity;
  }
  return ss.str();
}

bool jucc::grammar::Rule::HasPrefix(const grammar::Entity &prefix) const {
  // not considering epsilon, handled by parent scope
  if (prefix.size() > entities.size()) {
    return false;
  }
  for (int i = 0; i < static_cast<int>(prefix.size()); i++) {
    if (entities[i] != prefix[i]) {
      return false;
    }
  }
  return true;
}
