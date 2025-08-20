#ifndef BESSELJYD_H
#define BESSELJYD_H

#include "../config.h"
//#include "../bessel.h"

namespace xsf {
namespace mathieu {

  double besselj(int k, double z);
  double bessely(int k, double z);
    
  double besseljd(int k, double z);
  double besselyd(int k, double z);

} // namespace xsf
} // namespace mathieu

#endif
