#ifndef MATHIEU_COEFFS_H
#define MATHIEU_COEFFS_H

#include "../config.h"

namespace xsf {
namespace mathieu {

  int mathieu_coeffs_ee(int N, double q, int m, double *AA);
  int mathieu_coeffs_eo(int N, double q, int m, double *AA);
  int mathieu_coeffs_oe(int N, double q, int m, double *AA);
  int mathieu_coeffs_oo(int N, double q, int m, double *AA);    

} // namespace mathieu
} // namespace xsf

#endif
