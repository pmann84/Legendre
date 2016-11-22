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
// TODO: Calculate Legendre coefficients (? maybe)
// TODO: Update comments to use latex syntax

template<class T> class AssociatedLegendre
{
public:
	AssociatedLegendre(int l, int m);
	~AssociatedLegendre();

	int l() const;
	int m() const;

	T operator()(T x) const;
	std::vector<T> operator()(std::vector<T> x) const;

private:
	int m_l;
	int m_m;

	double calculatePolynomialValue(T x) const;
	double calculateNormalisationValue() const;
	double factorial(T n) const;
};

template <class T>
AssociatedLegendre<T>::AssociatedLegendre(int l, int m) : m_l(l), m_m(m)
{
	if (m_m < 0)
	{
		throw LegendreException::InvalidIndex("Upper Index (m) cannot be negative!");
	}
	if (m_m > m_l)
	{
		throw LegendreException::InvalidIndex("Upper Index (m) must be less than Lower Index (l)");
	}
}

template <class T>
AssociatedLegendre<T>::~AssociatedLegendre()
{
}

template <class T>
int AssociatedLegendre<T>::l() const
{
	return m_l;
}

template <class T>
int AssociatedLegendre<T>::m() const
{
	return m_m;
}

template <class T>
T AssociatedLegendre<T>::operator()(T x) const
{
	return calculatePolynomialValue(x);
}

template <class T>
std::vector<T> AssociatedLegendre<T>::operator()(std::vector<T> x) const
{
	std::vector<T> result;
	for (auto it : x)
	{
		result.push_back(calculatePolynomialValue(it));
	}
	return result;
}

template <class T>
double AssociatedLegendre<T>::calculatePolynomialValue(T x) const
{
	T pmm = 1.0;
	T pmp1m;

	// Check Inputs
	if (fabs(x) > 1.0)
	{
		throw LegendreException::InputOutOfRange();
	}

	if (m_m > 0)
	{
		// P_m^m(x) = (-1) ^ m(2m - 1)!!(1 - x ^ 2) ^ m / 2
		T sqrtomx2 = sqrt(1.0 - x*x);
		T oddInt = 1.0;
		for (int i = 1; i <= m_m; ++i)
		{
			pmm *= -1.0*oddInt*sqrtomx2;
			oddInt += 2.0;
		}
	}
	if (m_l == m_m)
	{
		return pmm;
	}
	else
	{
		// P_m + 1 ^ m(x) = x(2m + 1) P_m^m(x)
		pmp1m = x*(2.0*m_m + 1.0) * pmm;
		if (m_l == m_m + 1)
		{
			return pmp1m;
		}
		else
		{
			T pmp2m = 0.0;
			for (int i = m_m + 2; i <= m_l; ++i)
			{
				// (l - m) P_l^m (x) = x (2l - 1) P_l-1^m (x) - (l + m - 1) P_l-2^m (x)
				pmp2m = x*(2.0*m_l - 1.0)*pmp1m - (m_l + m_m - 1.0)*pmm;
				pmp2m /= (m_l - m_m);
				// Rotate variables for next iteration
				pmm = pmp1m;
				pmp1m = pmp2m;
			}
			return pmp2m;
		}
	}
}

template <class T>
double AssociatedLegendre<T>::calculateNormalisationValue() const
{
	return sqrt(((2.0*m_l + 1.0) / 2.0)*(factorial(m_l - m_m) / factorial(m_l + m_m)));
}

template <class T>
double AssociatedLegendre<T>::factorial(T n) const
{
	return std::tgamma(n + 1.0);
}

#endif // __ASSOCIATED_LEGENDRE_H__
