// Copyright (C) 2013 Vrije Universiteit Brussel, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.


#ifndef cf3_lss_mkl_dss_hpp
#define cf3_lss_mkl_dss_hpp


#include "LibLSS_MKL.hpp"
#include "../../../lss/cf3/lss/linearsystem.hpp"


namespace cf3 {
namespace lss {
namespace mkl {


/**
 * @brief Interface to Intel MKL direct sparse solvers.
 * @author Pedro Maciel
 */
class lss_API dss : public
  linearsystem< double >
{
  // utility definitions
  typedef detail::sparse_matrix< double, 1 > matrix_t;


 public:
  // framework interfacing
  static std::string type_name() { return "dss"; }


  /// Construction
  dss(const std::string& name,
    const size_t& _size_i=size_t(),
    const size_t& _size_j=size_t(),
    const size_t& _size_k=1,
    const double& _value=double() );

  /// Solve
  dss& solve();


 protected:
  // linear system matrix interfacing

  const double& A(const size_t& i, const size_t& j) const { return m_A(i,j); }
        double& A(const size_t& i, const size_t& j)       { return m_A(i,j); }

  void A___initialize(const size_t& i, const size_t& j, const double& _value=double()) { m_A.initialize(i,j,_value); }
  void A___initialize(const std::vector< double >& _vector) { m_A.initialize(_vector); }
  void A___initialize(const std::string& _fname)            { m_A.initialize(_fname);  }
  void A___clear()                    { m_A.clear();    }
  void A___zerorow(const size_t& i)   { m_A.zerorow(i); }
  void A___print_level(const int& _l) { m_A.m_print = detail::print_level(_l); }

  void          A___print(std::string& _fname) const { m_A.print(_fname);   }
  std::ostream& A___print(std::ostream& o)     const { return m_A.print(o); }
  size_t        A___size(const size_t& d)      const { return m_A.size(d);  }


 protected:
  // storage
  matrix_t m_A;
  void *handle;
  int nrhs,
      opt,
      sym,
      type;

};


}  // namespace mkl
}  // namespace lss
}  // namespace cf3


#endif
