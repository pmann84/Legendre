#include "AssociatedLegendre.h"

AssociatedLegendre::AssociatedLegendre(int l, int m) : m_l(l), m_m(m)
{
}

AssociatedLegendre::~AssociatedLegendre()
{
}

int AssociatedLegendre::l() const
{
	return m_l;
}

int AssociatedLegendre::m() const
{
	return m_m;
}

double AssociatedLegendre::operator()(double x) const
{
	double pmm = 1.0;
	double pmp1m;

	if (m_m < 0 || m_m > m_l || fabs(x) > 1.0)
	{
		// TODO: Write exception for this
		throw;
	}
	if (m_m > 0)
	{
		// P_m^m(x) = (-1) ^ m(2m - 1)!!(1 - x ^ 2) ^ m / 2
		double sqrtomx2 = sqrt(1.0 - x*x);
		double oddInt = 1.0;
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
			double pmp2m = 0.0;
			for (int i = m_m+2; i <= m_l; ++i)
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
