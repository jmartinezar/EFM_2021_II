#include <iostream>
#include <cmath>

typedef double REAL;

const REAL C = 1.5e04; // constante (hc)/(lk) para lambda =960nm

REAL R(REAL T_1, REAL T_2); // declaración de la función calculada restando el 1 arriba y abajo
REAL A(REAL T_1, REAL T_2); // declaración de la función sin contar ese 1

int main(void)
{
		std::cout << std::fabs(1-A(2596.5, 2567)/R(2596.5, 2567)) << "\t" << std::fabs(1-A(2596.5, 587)/R(2596.5, 587)) << "\n";
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