#include "AssociatedLegendre.h"

AssociatedLegendre::AssociatedLegendre(int l, int m) : m_l(l), m_m(m)
{
}

AssociatedLegendre::~AssociatedLegendre()
{
}

double AssociatedLegendre::operator()(double x)
{
	double pll = 1.0;
	double somx2;

	if (m_m < 0 || m_m > m_l || fabs(x) > 1.0)
	{
		// TODO: Write exception for this
		throw;
	}
	if (m_m > 0)
	{
		somx2
	}

	return 0.0;
}
