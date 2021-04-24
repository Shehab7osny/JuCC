#include "grammar/grammar.h"

#include <sstream>

std::string jucc::grammar::Rule::toString() {
  std::stringstream ss;
  for (auto &entity : entities) {
    ss << entity;
  }
  return ss.str();
}
