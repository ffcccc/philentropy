//  Part of the philentropy package
//
//  Copyright (C) 2015-2020 Hajk-Georg Drost
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  A copy of the GNU General Public License is available at
//  http://www.r-project.org/Licenses/
// 

#ifndef philentropy_Distances_H
#define philentropy_Distances_H philentropy_Distances_H

// http://stackoverflow.com/questions/23527719/calling-a-rcpp-function-from-another-rcpp-function-while-building-an-r-package


// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppEigen)]]

//#include <Rcpp.h>
//#include <RcppEigen.h>
#include <math.h>
#include <iostream>
#include "utils.h"
#include <Eigen/Core>
#include <Eigen/Dense>

//// [[Rcpp::export]]
//double custom_log2(const double& x ){
//        if (x == 0.0){
//          return NAN;
//        } else {
//          return log(x)/log(2.0);
//        }
//}
//
//// [[Rcpp::export]]
//double custom_log10(const double& x ){
//  if (x == 0.0){
//    return NAN;
//  } else {
//    return log(x)/log(10.0);
//  }
//}



// [[Rcpp::export]]
double euclidean(const Eigen::Map<Eigen::ArrayXd>& P,const Eigen::Map<Eigen::ArrayXd>& Q, bool testNA){
  int    P_len = P.size();
  int    Q_len = Q.size();
  double dist  = 0.0;
  double diff  = 0.0;

  if (P_len != Q_len){
    //Rcpp::
    stop("The vectors you are comparing do not have the same length!");
  }

  if (testNA){
    // for (int i = 0; i < P_len; i++){
    //   if ((Rcpp::NumericVector::is_na(P[i])) || (Rcpp::NumericVector::is_na(Q[i]))){
    //     Rcpp::stop("Your input vector stores NA values...");
    //   }
    //   diff = fabs(P[i] - Q[i]);
    //   dist += diff * diff;
    // }
  } else {
    // Eigen::VectorXd x = Rcpp::as<Eigen::VectorXd>(P);
    // Eigen::VectorXd y = Rcpp::as<Eigen::VectorXd>(Q);
    //Eigen::Map<Eigen::VectorXd> x(Rcpp::as<Eigen::Map<Eigen::VectorXd> >(P));
    //Eigen::Map<Eigen::VectorXd> y(Rcpp::as<Eigen::Map<Eigen::VectorXd> >(Q));
    //static _Tp compute(const Eigen::Array<_Tp, -1, 1>& x, const Eigen::Array<_Tp, -1, 1>& y) {
    // assert(x.size() > 0);
    // assert(x.size() == y.size());

    //return (x - y).square().sum();
    //dist = (x - y).matrix().squaredNorm();
    dist = (P - Q).norm();
  }
  return dist;
}


#endif // philentropy_Distances_H





