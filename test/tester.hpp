#ifndef TESTER_HPP
#define TESTER_HPP

#include <cstdlib>
#include <iostream>

#define ASSERT(condition)                                                   \
  if (!(condition)) {                                                       \
    std::cout << "[Error] " << #condition << " in " << __FUNCTION__ << " (" \
              << __FILE__ << " line " << __LINE__ << ")" << std::endl;      \
    abort();                                                                \
  }

#endif  // TESTER_HPP
