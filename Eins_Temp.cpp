#include <iostream>
#include <cmath>
#include <cstdlib>

const double R = 8.3446;//constante de los gases ideales
const double C = 18.4758;//capacidad calorifica molar (CCM)

double f(double x);//esta función es la CCM menos la expresión de Einstein haciendo un cambio de variable de 1/x=T_E/T
template <class fptr>
double Newton(double x, fptr fun, double eps);//método de Newton para calcular raíces

  int main(void)
{
  std::cout << Newton(0.2, f, 0.000001) << "\n";//donde la función se hace cero es donde la expresión de Einstein y la CCM son iguales
  return 0;
}

double f(double x)
{
  return C - 3*R*(1.0/x)*(1.0/x)*(std::pow(M_E, 1.0/x)/((std::pow(M_E, 1.0/x)-1.0)*(std::pow(M_E, 1.0/x)-1.0)));
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