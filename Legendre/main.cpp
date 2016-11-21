#include <iostream>

#include "AssociatedLegendre.h"

int main()
{
	int l = 1;
	int m = 1;
	AssociatedLegendre legendre(l, m);
	double evalVal = 0.5;
	std::cout << "P_" << l << "^" << m << "(" << evalVal << ") = " << legendre(evalVal) << std::endl;
	return 0;
}