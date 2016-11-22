#include "gtest/gtest.h"

#include "../Legendre/AssociatedLegendre.h"

TEST(TestLegendre, LegendreInvalidInput)
{
	int l = 1;
	int m = 1;
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_THROW(legendre(1.5), LegendreException::InputOutOfRange);
}

TEST(TestLegendre, LegendreUpperIndexNegativeThrows)
{
	int l = 1;
	int m = -2;
	EXPECT_THROW(AssociatedLegendre<double>(l, m), LegendreException::InvalidIndex);
}

TEST(TestLegendre, LegendreUpperIndexGreaterThanLowerThrows)
{
	int l = 1;
	int m = 5;
	EXPECT_THROW(AssociatedLegendre<double>(l, m), LegendreException::InvalidIndex);
}

TEST(TestLegendre, LegendreEvaluateAtM0L0)
{
	int l = 0;
	int m = 0;
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(0.5), 1.0);
}

TEST(TestLegendre, LegendreEvaluateAtM1L1)
{
	int l = 1;
	int m = 1;
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(0.5), -0.8660254037844386);
}

TEST(TestLegendre, LegendreEvaluateAtM1L2)
{
	int l = 2;
	int m = 1;
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(0.5), -1.299038105676658);
}

TEST(TestLegendre, LegendreEvaluateAtM1L3)
{
	int l = 3;
	int m = 1;
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_DOUBLE_EQ(legendre(0.5), -0.3247595264191645);
}