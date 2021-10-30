#include <iostream>
#include <cmath>

typedef double REAL;

const REAL C_1 = 1.44e-02; // constante (hc)/(lk) para lambda =960nm
const REAL L = 960e-09; //longitud de onda
const REAL C = C_1/L;
const REAL T_max = 2596.5; //temperatura máxima de referencia
const REAL Tp_1 = 2567; //temperaturas menores que T_max para hacer el cálculo del error
const REAL Tp_2 = 587;

REAL R(REAL T_1, REAL T_2); // declaración de la función calculada restando el 1 arriba y abajo
REAL A(REAL T_1, REAL T_2); // declaración de la función sin contar ese 1

int main(void)
{
		std::cout << std::fabs(1-A(T_max, Tp_1)/R(T_max, Tp_1)) << "\t" << std::fabs(1-A(T_max, Tp_2)/R(T_max, Tp_2)) << "\n";
    //imprime en pantalla el error relativo usando primero dos temperaturas altas y despues una alta y una baja
	return 0;
}

REAL R(REAL T_1, REAL T_2)
{
	REAL d = (std::exp(C/T_2)-1)/(std::exp(C/T_1)-1);
	return d;
}

REAL A(REAL T_1, REAL T_2)
{
	REAL d = std::exp(C/T_2)/std::exp(C/T_1);
	return d;
}