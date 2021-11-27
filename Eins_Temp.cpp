#include <iostream>
#include <cmath>
#include <cstdlib>

const double R = 8.31446;//constante de los gases ideales
const double C = 18.42377;//capacidad calorifica molar (CCM)

double Eins(double x);//esta función es la CCM menos la expresión de Einstein haciendo un cambio de variable de 1/x=T_E/T

double g(double x);//esta es la función que se encuentra al interior de la integral

double Debye(double x);//esta es la función según el modelo de Debye

template <class fptr>
double Newton(double x, fptr fun, double eps);//método de Newton para calcular raíces

template <class fptr>
double Integration(double a, double b, fptr fun, double N);//integración mediante el método de Simpson

  int main(void)
{
  std::cout << Newton(0.2, Eins, 0.000001) << "\n";//donde la función se hace cero es donde la expresión de Einstein y la CCM son iguales
  std::cout << Newton(0.2, Debye, 0.000001) << "\n";//donde la función se hace cero es donde la expresión de Debye y la CCM son iguales
  return 0;
}

double Eins(double x)
{
  return C - 3*R*(1.0/x)*(1.0/x)*(std::pow(M_E, 1.0/x)/((std::pow(M_E, 1.0/x)-1.0)*(std::pow(M_E, 1.0/x)-1.0)));
}

double g(double x)
{
  return x*x*x*x*std::pow(M_E, x)/((std::pow(M_E, x)-1)*(std::pow(M_E, x)-1));
}

double Debye(double x)
{
  return C - 9*R*Integration(0.0001, 1.0/x, g, 100)*std::pow(x, 3);
}

template <class fptr>
double Newton(double x0, fptr fun, double eps)
{
  double h = 0.001;
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

template <class fptr>
double Integration(double a, double b, fptr fun, double N)
{
  double h = (b - a)/N;
  double xi = 0;
  double result1 = 0;
  double result2 = 0;
  for(int ii=0; ii<N/2 - 1; ++ii)
  {
    xi = a +2*h*ii;
    result1+=fun(xi);
  }
  for(int ii=0; ii<N/2; ++ii)
  {
    xi = a + (2*ii - 1)*h;
    result2 += fun(xi);
  }
  return h*(fun(a) + 2*result1 + 4*result2 +fun(b))/3;
}