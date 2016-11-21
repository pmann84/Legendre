#ifndef __ASSOCIATED_LEGENDRE_H__
#define __ASSOCIATED_LEGENDRE_H__

#include <math.h>
// Uses the recurrence relation:
// (l - m) P_l^m (x) = x (2l - 1) P_l-1^m (x) - (l + m - 1) P_l-2^m (x)
// to calculate the value at x, for starting values it uses the following
// relations:
// P_m^m (x) = (-1)^m (2m - 1)!! (1 - x^2)^m/2
// P_m+1^m (x) = x (2m + 1) P_m^m (x)
// constraints here are that -1 <= x <= 1
// and 0 <= m <= l

class AssociatedLegendre
{
public:
	AssociatedLegendre(int l, int m);
	~AssociatedLegendre();

	double operator()(double x);

private:
	int m_l;
	int m_m;
};

#endif // __ASSOCIATED_LEGENDRE_H__
