#ifndef JUCC_GRAMMAR_GRAMMAR_H
#define JUCC_GRAMMAR_GRAMMAR_H

#include <fstream>
#include <string>
#include <utility>
#include <vector>

namespace jucc {
namespace grammar {
const char EPSILON[] = "EPSILON";

class Rule {
  /**
   * An entity is a single terminal or non terminal in the right hand side
   * of a production.
   * Example:
   * For production: E : F + E => { "F", "+", "E" } is a rule.
   */
  std::vector<std::string> entities_;

 public:
  Rule() = default;
  explicit Rule(std::vector<std::string> entities) : entities_(std::move(entities)) {}
  [[nodiscard]] const std::vector<std::string> &GetEntities() const { return entities_; }
  void SetEntities(const std::vector<std::string> &entities) { Rule::entities_ = entities; }
};

class Production {
  /**
   * class Parser returns a list of Productions.
   * Example:
   * For productions: E : F + E
   *                  E : EPSILON
   * parent = "E"
   * rules = { Rule1, Rule2 }
   */
  std::string parent_;
  std::vector<Rule> rules_;

 public:
  Production() = default;
  [[nodiscard]] const std::string &GetParent() const { return parent_; }
  [[nodiscard]] const std::vector<Rule> &GetRules() const { return rules_; }
  void SetParent(const std::string &parent) { Production::parent_ = parent; }
  void SetRules(const std::vector<Rule> &rules) { Production::rules_ = rules; }
};

using Productions = std::vector<Production>;

class Parser {
  std::ifstream file_;
  std::vector<std::string> terminals_;      // Terminals defined in grammar file
  std::vector<std::string> non_terminals_;  // Non terminals defined in grammar file
  std::string start_symbol_;                // Start symbol for the grammar
  Productions grammar_;                     // Production rules
  std::string error_;                       // parser error message

  /**
   * Splits input string via spaces.
   */
  static std::vector<std::string> FastTokenize(const std::string &s);

 public:
  /**
   * Constructor
   * @param filepath : opens std::ifstream file_
   */
  explicit Parser(const char *filepath);

  /**
   * Destructor
   * closes std::ifstream file_
   */
  ~Parser();

  /**
   * Parses the input file and populates private variables.
   * Returns true if successful.
   * On error returns false and sets error_.
   */
  bool Parse();

  /**
   * Getters for each private variable.
   */
  std::vector<std::string> GetTerminals() { return terminals_; }
  std::vector<std::string> GetNonTerminals() { return non_terminals_; }
  std::string GetStartSymbol() { return start_symbol_; }
  Productions GetProductions() { return grammar_; }
  std::string GetError() { return error_; }
};

}  // namespace grammar
}  // namespace jucc

#endif
