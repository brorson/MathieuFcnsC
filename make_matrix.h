#ifndef MAKE_MATRIX_H
#define MAKE_MATRIX_H

namespace xsf {
namespace mathieu {

  int make_matrix_ee(int N, double q, double* A);
  int make_matrix_eo(int N, double q, double *A);
  int make_matrix_oe(int N, double q, double *A);
  int make_matrix_oo(int N, double q, double *A);    

} // namespace mathieu
} // namespace xsf
 
#endif
