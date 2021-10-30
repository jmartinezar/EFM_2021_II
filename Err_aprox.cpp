#include <iostream>
#include <cmath>

typedef double REAL;

const REAL C = 1.5e04;

REAL R(REAL T_1, REAL T_2);
REAL A(REAL T_1, REAL T_2);

int main(void)
{
		std::cout << std::fabs(1-A(2596.5, 2567)/R(2596.5, 2567)) << "\t" << std::fabs(1-A(2596.5, 587)/R(2596.5, 587)) << "\n";
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