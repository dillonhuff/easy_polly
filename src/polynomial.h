#pragma once

namespace easy_polly {

  template<typename N>
  class monomial {

  public:
    monomial(const N& p_coeff,
	     const std::vector<int> p_powers,
	     const int p_num_vars) {}

  };


  template<typename N>
  class polynomial {

  public:
    polynomial(const std::vector<monomial<N> > p_monos,
	       const int p_num_vars) {}

  };
  
}
