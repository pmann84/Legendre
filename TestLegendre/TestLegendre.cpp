#include "gtest/gtest.h"

#include "TestLegendreUtils.h"
#include "../Legendre/AssociatedLegendre.h"

TEST(TestLegendre, LegendreInvalidInput)
{
	unsigned int l = 1;
	unsigned int m = 1;
	double inputValue = 1.5;
	AssociatedLegendre legendre(l, m);
	EXPECT_THROW(legendre(inputValue), LegendreException::InputOutOfRange);
}

TEST(TestLegendre, LegendreUpperIndexNegativeThrows)
{
	unsigned int l = 1;
	int m = -2;
	EXPECT_THROW(AssociatedLegendre(l, m), LegendreException::InvalidIndex);
}

TEST(TestLegendre, LegendreUpperIndexGreaterThanLowerThrows)
{
	unsigned int l = 1;
	unsigned int m = 5;
	EXPECT_THROW(AssociatedLegendre(l, m), LegendreException::InvalidIndex);
}

TEST(TestLegendre, LegendreEvaluateAtM0L0)
{
	unsigned int l = 0;
	unsigned int m = 0;
	double inputValue = 0.5;
	AssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre00(inputValue));
}

TEST(TestLegendre, LegendreEvaluateAtM1L1)
{
	unsigned int l = 1;
	unsigned int m = 1;
	double inputValue = 0.5;
	AssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre11(inputValue));
}

TEST(TestLegendre, LegendreEvaluateAtM1L2)
{
	unsigned int l = 2;
	unsigned int m = 1;
	double inputValue = 0.5;
	AssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre21(inputValue));
}

TEST(TestLegendre, LegendreEvaluateAtM1L3)
{
	unsigned int l = 3;
	unsigned int m = 1;
	double inputValue = 0.5;
	AssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre31(inputValue));
}

TEST(TestLegendre, LegendreEvaluateAtM3L4)
{
	unsigned int l = 4;
	unsigned int m = 3;
	double inputValue = 0.5;
	AssociatedLegendre legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(inputValue), TestLegendreUtils::Legendre43(inputValue));
}