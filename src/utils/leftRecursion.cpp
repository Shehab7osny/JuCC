#include "utils/leftRecursion.h"
namespace grammar = jucc::grammar;

grammar::Productions jucc::utils::RemoveDirectLeftRecursion(const grammar::Production &prod) {
  if (!IsRecursive(prod)) {
    return grammar::Productions{prod};
  }
  std::string parent = prod.getParent();
  std::string parent_dash = prod.getParent() + std::string(DASH);

  grammar::Productions prods(2);
  prods[0].setParent(parent_dash);
  prods[1].setParent(parent);

  auto parent_rules = prods[0].getRules();
  auto parent_dash_rules = prods[1].getRules();

  for (const auto &rule : prod.getRules()) {
    auto entries = rule.getEntities();
    if (entries[0] == parent) {
      auto new_entries = std::vector<std::string>(entries.begin() + 1, entries.end());
      new_entries.push_back(parent_dash);
      parent_dash_rules.push_back(grammar::Rule(new_entries));
    } else {
      entries.push_back(parent_dash);
      parent_rules.push_back(grammar::Rule(entries));
    }
  }
  parent_dash_rules.push_back(grammar::Rule({std::string(grammar::EPSILON)}));
  prods[0].setRules(parent_dash_rules);
  prods[1].setRules(parent_rules);
  return prods;
}

bool jucc::utils::IsRecursive(const grammar::Production &prod) {
  for (const auto &rule : prod.getRules()) {
    if (prod.getParent() == rule.getEntities()[0]) {
      return true;
    }
  }
  return false;
}
