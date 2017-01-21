#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "polynomial.h"

namespace easy_polly {

  TEST_CASE("Polynomial division") {
    monomial<double> m1{1.0, {2, 1}, 2};
    monomial<double> m2{1.0, {0, 1}, 2};

    polynomial<double> f{{m1, m2}, 2};
    
  }
  
}
