#pragma once

#include <vector>

namespace easy_polly {

  template<typename N>
  class monomial {

  public:
    monomial(const N& p_coeff,
	     const std::vector<int> p_powers,
	     const int p_num_vars) {}

  };

  template<typename N>
  bool lexicographic_order(const monomial<N>& x,
			   const monomial<N>& y) {
    assert(false);
  }


  template<typename N>
  class polynomial {

  public:
    polynomial(const std::vector<monomial<N> > p_monos,
	       const int p_num_vars) {}

  };

  template<typename N>
  struct division_result {
    std::vector<polynomial<N> > as;
    polynomial<N> remainder;
  };

  template<typename N, typename MonomialOrder>
  division_result<N> divide(const polynomial<N>& f,
			    const std::vector<polynomial<N> >& gs,
			    MonomialOrder m) {
    return division_result<N>{{}, {{}, 2}};
  }

  template<typename N, typename Comparator>
  bool poly_eq(Comparator eq,
	       const polynomial<N>& f,
	       const polynomial<N>& g) {
    assert(false);
  }
  
}
