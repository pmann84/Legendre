#ifndef __TEST_LEGENDRE_UTILS_H__
#define __TEST_LEGENDRE_UTILS_H__

#include <math.h>
#include <cmath>

// Test functions that return explicit values of legendre polynomials from their
// explicit forms
namespace TestLegendreUtils
{
	double NormalisationFactor(unsigned int l, unsigned int m);

	double Legendre00(double x, bool norm = false);
	double Legendre10(double x, bool norm = false);
	double Legendre11(double x, bool norm = false);
	double Legendre20(double x, bool norm = false);
	double Legendre21(double x, bool norm = false);
	double Legendre22(double x, bool norm = false);
	double Legendre30(double x, bool norm = false);
	double Legendre31(double x, bool norm = false);
	double Legendre32(double x, bool norm = false);
	double Legendre33(double x, bool norm = false);
	double Legendre40(double x, bool norm = false);
	double Legendre41(double x, bool norm = false);
	double Legendre42(double x, bool norm = false);
	double Legendre43(double x, bool norm = false);
	double Legendre44(double x, bool norm = false);
	double Legendre50(double x, bool norm = false);
}

#endif // __TEST_LEGENDRE_UTILS_H__