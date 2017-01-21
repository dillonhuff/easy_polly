#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "polynomial.h"

namespace easy_polly {

  // Add within_eps call
  bool double_eq(const double l, const double r) {
    return l == r;
  }

  TEST_CASE("Polynomial division") {
    monomial<double> m1{1.0, {2, 1}, 2};
    monomial<double> m2{1.0, {0, 1}, 2};

    polynomial<double> f{{m1, m2}, 2};

    polynomial<double> g1{{{1.0, {1, 1}, 2}, {1.0, {1, 0}, 2}}, 2};
    polynomial<double> g2{{{1.0, {2, 0}, 2}, {1.0, {0, 0}, 2}}, 2};

    polynomial<double> a1{{{1.0, {1, 0}, 2}}, 2};
    polynomial<double> a2{{{-1.0, {0, 0}, 2}}, 2};
    polynomial<double> r{{{-1.0, {0, 1}, 2}, {-1.0, {0, 0}, 2}}, 2};

    std::vector<polynomial<double> > as{a1, a2};
    division_result<double> expected_result{as, r};    

    SECTION("Remainder is correct") {

      std::vector<polynomial<double> > g{g1, g2};
      division_result<double> res = divide(f, g, lexicographic_order<double>);

      REQUIRE(poly_eq(double_eq, res.remainder, expected_result.remainder));
    }

    SECTION("Remainder changes for ") {
      std::vector<polynomial<double> > g{g2, g1};
      division_result<double> res = divide(f, g, lexicographic_order<double>);

      REQUIRE(!poly_eq(double_eq, res.remainder, expected_result.remainder));
    }

  }
  
}
