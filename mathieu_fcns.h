#ifndef MATHIEU_FCNS_H
#define MATHIEU_FCNS_H

#include "../config.h"

namespace xsf {
namespace mathieu {

  int mathieu_ce(int m, double q, double v, double *ce, double *ced);
  int mathieu_se(int m, double q, double v, double *se, double *sed);
  int mathieu_modmc1(int m, double q, double v, double *modmc1, double *modmc1d);
  int mathieu_modms1(int m, double q, double v, double *modms1, double *modms1d);
  int mathieu_modmc2(int m, double q, double v, double *modmc2, double *modmc2d);
  int mathieu_modms2(int m, double q, double v, double *modms2, double *modms2d);      

} // namespace mathieu
} // namespace xsf

#endif

