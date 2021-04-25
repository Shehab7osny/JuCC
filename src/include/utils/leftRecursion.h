#ifndef JUCC_LEFTRECURSION_H
#define JUCC_LEFTRECURSION_H
#include "grammar/grammar.h"

namespace jucc::utils {
const char DASH[] = "'";

grammar::Productions RemoveDirectLeftRecursion(const grammar::Production &);
bool IsRecursive(const grammar::Production &);

}  // namespace jucc::utils
#endif  // JUCC_LEFTRECURSION_H