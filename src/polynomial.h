#pragma once

#include <vector>

namespace easy_polly {

  template<typename N>
  class monomial {
    N c;
    std::vector<int> powers;
    int nvars;

  public:
    monomial(const N& p_coeff,
	     const std::vector<int> p_powers,
	     const int p_num_vars) :
      c(p_coeff),
      powers(p_powers),
      nvars(p_num_vars) {}

    N coeff() const { return c; }
    int num_vars() const { return nvars; }
    int power(const int i) const { return powers[i]; }

    template<typename Comparator>
    bool equals(Comparator eq, const monomial<N>& g) const {
      assert(g.num_vars() == num_vars());

      if (!eq(g.coeff(), coeff())) { return false; }

      for (int i = 0; i < g.num_vars(); i++) {
	if (g.power(i) != power(i)) {
	  return false;
	}
      }

      return true;
    }
    

  };

  template<typename N>
  bool lexicographic_order(const monomial<N>& x,
			   const monomial<N>& y) {
    assert(x.num_vars() == y.num_vars());

    for (int i = 0; i < x.num_vars(); i++) {
      if (x.power(i) < y.power(i)) {
	return true;
      } if (x.power(i) > y.power(i)) {
	return false;
      }
    }

    // x == y
    return false;
  }


  template<typename N>
  class polynomial {

    std::vector<monomial<N> > monos;
    int num_vars;

  public:
    polynomial(const std::vector<monomial<N> > p_monos,
	       const int p_num_vars) {
      monos = p_monos;
      std::sort(begin(monos), end(monos), lexicographic_order<N>);
      num_vars = p_num_vars;
    }

    int num_monos() const { return monos.size(); }

    const monomial<N>& monomial(const int i) const { return monos[i]; }

    template<typename Comparator>
    bool equals(Comparator eq, const polynomial<N>& g) const {
      if (g.num_monos() != num_monos()) { return false; }

      for (unsigned i = 0; i < g.num_monos(); i++) {
	if ( !g.monomial(i).equals(eq, monomial(i)) ) {
	  return false;
	}
      }

      return true;
    }

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
    return f.equals(eq, g);
  }
  
}
