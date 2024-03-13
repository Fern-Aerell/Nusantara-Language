#pragma once

#include <gmp.h>
#include <mpfr.h>

namespace ncpp {

    int mpfr_cmp_with_tolerance(const mpfr_t& nilai1, const mpfr_t& nilai2, const double& tolerance);

}