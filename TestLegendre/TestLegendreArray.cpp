#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "TestLegendreUtils.h"
#include "../Legendre/AssociatedLegendre.h"

TEST(TestLegendreArray, LegendreInvalidInput)
{
	unsigned int l = 1;
	unsigned int m = 1;
	std::vector<double> inputs({-0.75, -0.5, 0.0, 0.25, 1.5});
	AssociatedLegendre legendre(l, m);
	EXPECT_THROW(legendre(inputs), LegendreException::InputOutOfRange);
}

TEST(TestLegendreArray, LegendreEvaluateAtM0L0)
{
	unsigned int l = 0;
	unsigned int m = 0;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre legendre(l, m);
	EXPECT_THAT(legendre(inputs), testing::ElementsAre(TestLegendreUtils::Legendre00(inputs[0]), 
													   TestLegendreUtils::Legendre00(inputs[1]), 
													   TestLegendreUtils::Legendre00(inputs[2]), 
													   TestLegendreUtils::Legendre00(inputs[3]), 
													   TestLegendreUtils::Legendre00(inputs[4])));
}

TEST(TestLegendreArray, LegendreEvaluateAtM1L1)
{
	unsigned int l = 1;
	unsigned int m = 1;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre legendre(l, m);
	EXPECT_THAT(legendre(inputs), testing::ElementsAre(TestLegendreUtils::Legendre11(inputs[0]), 
													   TestLegendreUtils::Legendre11(inputs[1]), 
													   TestLegendreUtils::Legendre11(inputs[2]), 
													   TestLegendreUtils::Legendre11(inputs[3]), 
													   TestLegendreUtils::Legendre11(inputs[4])));
}

TEST(TestLegendreArray, LegendreEvaluateAtM1L2)
{
	unsigned int l = 2;
	unsigned int m = 1;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre legendre(l, m);
	std::vector<double> results = legendre(inputs);
	EXPECT_THAT(legendre(inputs), testing::ElementsAre(TestLegendreUtils::Legendre21(inputs[0]), 
													   TestLegendreUtils::Legendre21(inputs[1]), 
													   TestLegendreUtils::Legendre21(inputs[2]), 
													   TestLegendreUtils::Legendre21(inputs[3]), 
													   TestLegendreUtils::Legendre21(inputs[4])));
}

TEST(TestLegendreArray, LegendreEvaluateAtM1L3)
{
	unsigned int l = 3;
	unsigned int m = 1;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre legendre(l, m);
	std::vector<double> results = legendre(inputs);
	for (int i = 0; i < results.size(); ++i)
	{
		EXPECT_DOUBLE_EQ(results[i], TestLegendreUtils::Legendre31(inputs[i]));
	}
}

TEST(TestLegendreArray, LegendreEvaluateAtM3L4)
{
	unsigned int l = 4;
	unsigned int m = 3;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre legendre(l, m);
	std::vector<double> results = legendre(inputs);
	for (int i = 0; i < results.size(); ++i)
	{
		EXPECT_DOUBLE_EQ(results[i], TestLegendreUtils::Legendre43(inputs[i]));
	}
}