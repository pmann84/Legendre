#include "TestLegendreUtils.h"

double TestLegendreUtils::NormalisationFactor(unsigned int l, unsigned int m)
{
	return sqrt(((2.0*l + 1.0) / 2.0)*(std::tgamma(l - m + 1) / std::tgamma(l + m + 1)));
}

// L = 0, M = 0
double TestLegendreUtils::Legendre00(double x, bool norm)
{
	double result = 1.0;
	if (norm)
	{
		return NormalisationFactor(0, 0)*result;
	}
	return result;
}

// L = 1, M = 0
double TestLegendreUtils::Legendre10(double x, bool norm)
{
	double result = x;
	if (norm)
	{
		return NormalisationFactor(0, 0)*result;
	}
	return result;
}

// L = 1, M = 1
double TestLegendreUtils::Legendre11(double x, bool norm)
{
	double result = -sqrt(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(1, 1)*result;
	}
	return result;
}

// L = 2, M = 0
double TestLegendreUtils::Legendre20(double x, bool norm)
{
	double result = 0.5*(3.0*x*x - 1.0);
	if (norm)
	{
		return NormalisationFactor(2, 0)*result;
	}
	return result;
}

// L = 2, M = 1
double TestLegendreUtils::Legendre21(double x, bool norm)
{
	double result = -3.0*x*sqrt(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(2, 1)*result;
	}
	return result;
}

// L = 2, M = 2
double TestLegendreUtils::Legendre22(double x, bool norm)
{
	double result = 3.0*(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(2, 2)*result;
	}
	return result;
}

// L = 3, M = 0
double TestLegendreUtils::Legendre30(double x, bool norm)
{
	double result = 0.5*x*(5.0*x*x - 3.0);
	if (norm)
	{
		return NormalisationFactor(3, 0)*result;
	}
	return result;
}

// L = 3, M = 1
double TestLegendreUtils::Legendre31(double x, bool norm)
{
	double result = -1.5*(5.0*x*x - 1.0)*sqrt(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(3, 1)*result;
	}
	return result;
}

// L = 3, M = 2
double TestLegendreUtils::Legendre32(double x, bool norm)
{
	double result = 15.0*x*(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(3, 2)*result;
	}
	return result;
}

// L = 3, M = 3
double TestLegendreUtils::Legendre33(double x, bool norm)
{
	double result = -15.0*sqrt(1.0 - x*x)*sqrt(1.0 - x*x)*sqrt(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(3, 3)*result;
	}
	return result;
}

// L = 4, M = 0
double TestLegendreUtils::Legendre40(double x, bool norm)
{
	double result = (1.0 / 8.0)*(35.0*x*x*x*x - 30.0*x*x + 3.0);
	if (norm)
	{
		return NormalisationFactor(4, 0)*result;
	}
	return result;
}

// L = 4,  M = 1
double TestLegendreUtils::Legendre41(double x, bool norm)
{
	double result = (-5.0 / 2.0)*(7.0*x*x*x - 3.0*x)*sqrt(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(4, 1)*result;
	}
	return result;
}

// L = 4, M = 2
double TestLegendreUtils::Legendre42(double x, bool norm)
{
	double result = (15.0 / 2.0)*(7.0*x*x - 1.0)*(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(4, 2)*result;
	}
	return result;
}

// L = 4, M = 3
double TestLegendreUtils::Legendre43(double x, bool norm)
{
	double result = -105.0*x*sqrt(1.0 - x*x)*sqrt(1.0 - x*x)*sqrt(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(4, 3)*result;
	}
	return result;
}

// L = 4, M = 4
double TestLegendreUtils::Legendre44(double x, bool norm)
{
	double result = 105.0*(1.0 - x*x)*(1.0 - x*x);
	if (norm)
	{
		return NormalisationFactor(4, 4)*result;
	}
	return result;
}

// L = 5, M = 0
double TestLegendreUtils::Legendre50(double x, bool norm)
{
	double result = (1.0 / 8.0)*x*(63.0*x*x*x*x - 70.0*x*x + 15.0);
	if (norm)
	{
		return NormalisationFactor(5, 0)*result;
	}
	return result;
}