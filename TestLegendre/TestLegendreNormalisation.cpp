#include "gtest/gtest.h"

#include "TestLegendreUtils.h"
#include "../Legendre/AssociatedLegendre.h"

TEST(TestLegendreNormalisation, NormalisedLegendreEvaluateAtM1L2)
{
	unsigned int l = 2;
	unsigned int m = 1;
	double inputValue = 0.5;
	NormalisedAssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre21(inputValue, true));
}

TEST(TestLegendreNormalisation, NormalisedLegendreEvaluateAtM3L3)
{
	unsigned int l = 3;
	unsigned int m = 3;
	double inputValue = 0.5;
	NormalisedAssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre33(inputValue, true));
}

TEST(TestLegendreNormalisation, NormalisedLegendreEvaluateAtM2L4)
{
	unsigned int l = 4;
	unsigned int m = 2;
	double inputValue = 0.5;
	NormalisedAssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre42(inputValue, true));
}

TEST(TestLegendreNormalisation, NormalisedLegendreEvaluateAtM1L3)
{
	unsigned int l = 3;
	unsigned int m = 1;
	double inputValue = 0.0;
	NormalisedAssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre31(inputValue, true));
}