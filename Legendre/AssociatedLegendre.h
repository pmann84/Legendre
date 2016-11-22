#ifndef __ASSOCIATED_LEGENDRE_H__
#define __ASSOCIATED_LEGENDRE_H__

#include <vector>
#include <math.h>

#include "LegendreExceptions.h"

// Uses the recurrence relation:
// (l - m) P_l^m (x) = x (2l - 1) P_l-1^m (x) - (l + m - 1) P_l-2^m (x)
// to calculate the value at x, for starting values it uses the following
// relations:
// P_m^m (x) = (-1)^m (2m - 1)!! (1 - x^2)^m/2
// P_m+1^m (x) = x (2m + 1) P_m^m (x)
// constraints here are that -1 <= x <= 1
// and 0 <= m <= l
// Calculating Associated Legendre Polynomial Values in the interval -1 <= x <= 1
// follows the algorithm:
// (1) Calculate P_m^m (x) with explicit formula as the starting point (since m <= l 
//     this will always work as a starting point)
// (2) If l == m then job is done and we can return the value calculated in (1)
// (3) Then calculate the next value P_m+1^m (x) (again since m <= l 
//     this will always work as our second point for the final recurrence formula)
// (4) If l == m+1 then we already have our value from (3) and can return
// (5) Final step we can calculate the rest of the polynomial values using the recurrence 
//     formula by iterating values of l from m+2 -> l

// For normalised values of Associated Legendre Polynomials the normalising factor is as 
// follows:
// PBar_l^m (x) = sqrt{ (2l + 1)/2 (l-m)!/(l+m)! } P_l^m (x)
// Although noted that normalising factor is sometimes expressed as:
// PBar_l^m (x) = sqrt{ (2l + 1)/2*pi (l-m)!/(l+m)! } P_l^m (x)

// TODO: Test more polynomial values for l and m
// TODO: Add calculation of normalised values of ass legs
// TODO: Calculate Legendre polynomials (just associated values with m = 0)
// TODO: Template with the type
// TODO: Calculate Legendre coefficients (? maybe)
// TODO: Update comments to use latex syntax?

class AssociatedLegendre
{
public:
	AssociatedLegendre(int l, int m);
	~AssociatedLegendre();

	int l() const;
	int m() const;

	double operator()(double x) const;
	std::vector<double> operator()(std::vector<double> x) const;

private:
	int m_l;
	int m_m;

	double calculatePolynomialValue(double x) const;
	double calculateNormalisationValue() const;
	double factorial(double n) const;
};

#endif // __ASSOCIATED_LEGENDRE_H__
