#include <iostream>
#include <cmath>
#include <cstdlib>

const double R = 8.3446;
const double C = 18.4758;

double f(double x);
template <class fptr>
double Newton(double x, fptr fun, double eps);

  int main(void)
{
  std::cout << Newton(0.2, f, 0.000001) << "\n";
  return 0;
}

double f(double x)
{
  return C - 3*R*(1.0/x)*(1.0/x)*(std::pow(M_E, 1.0/x)/((std::pow(M_E, 1.0/x)-1)*(std::pow(M_E, 1.0/x)-1)));
}

template <class fptr>
double Newton(double x0, fptr fun, double eps)
{
  double h = 0.000001;
  double xr = x0;
  //int iter = 1;
  while(std::fabs(fun(xr)) > eps) {
    double fderiv =  (fun(xr+h/2) - fun(xr-h/2))/h;
    xr = xr - fun(xr)/fderiv;
    //iter++;
  }
  //niter = iter;
  return xr;
}