#ifndef JUCC_GRAMMAR_H
#define JUCC_GRAMMAR_H
#include <string>
#include <utility>
#include <vector>

namespace jucc {
namespace grammar {
const char EPSILON[] = "epsilon";
typedef std::vector<std::string> Entity;

class Rule {
  std::vector<std::string> entities;

 public:
  Rule() = default;
  explicit Rule(std::vector<std::string> entities) : entities(std::move(entities)) {}
  [[nodiscard]] const std::vector<std::string> &getEntities() const { return entities; }
  void setEntities(const std::vector<std::string> &entities) { Rule::entities = entities; }
  [[nodiscard]] std::string toString() const;
  [[nodiscard]] bool HasPrefix(const Entity &) const;
};

typedef std::vector<grammar::Rule> Rules;
class Production {
  std::string parent;
  std::vector<Rule> rules;

 public:
  Production() = default;
  Production(std::string parent, std::vector<Rule> rules) : parent(std::move(parent)), rules(std::move(rules)) {}
  [[nodiscard]] const std::string &getParent() const { return parent; }
  [[nodiscard]] const std::vector<Rule> &getRules() const { return rules; }
  void setParent(const std::string &parent) { Production::parent = parent; }
  void setRules(const std::vector<Rule> &rules) { Production::rules = rules; }
};

typedef std::vector<Production> Productions;

}  // namespace grammar
}  // namespace jucc
#endif  // JUCC_GRAMMAR_H
