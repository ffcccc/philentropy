

#ifndef philentropy_CUSTOM_UTILS_H
#define philentropy_CUSTOM_UTILS_H philentropy_CUSTOM_UTILS_H

//#include <algorithm>
#include <math.h>




// [[Rcpp::export]]
double custom_log2(const double& x) {
    if (x == 0.0) {
        return NAN;
    }
    else {
        return log(x) / log(2.0);
    }
}

// [[Rcpp::export]]
double custom_log10(const double& x) {
    if (x == 0.0) {
        return NAN;
    }
    else {
        return log(x) / log(10.0);
    }
}


#endif
