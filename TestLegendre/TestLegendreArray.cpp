#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Legendre/AssociatedLegendre.h"

TEST(TestLegendreArray, LegendreInvalidInput)
{
	int l = 1;
	int m = 1;
	std::vector<double> inputs({-0.75, -0.5, 0.0, 0.25, 1.5});
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_THROW(legendre(inputs), LegendreException::InputOutOfRange);
}

TEST(TestLegendreArray, LegendreEvaluateAtM0L0)
{
	int l = 0;
	int m = 0;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_THAT(legendre(inputs), testing::ElementsAre(1.0,1.0,1.0,1.0,1.0));
}

TEST(TestLegendreArray, LegendreEvaluateAtM1L1)
{
	int l = 1;
	int m = 1;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_THAT(legendre(inputs), testing::ElementsAre(-0.66143782776614768, -0.8660254037844386, -1.0, -0.96824583655185426, -0.8660254037844386));
}

TEST(TestLegendreArray, LegendreEvaluateAtM1L2)
{
	int l = 2;
	int m = 1;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_THAT(legendre(inputs), testing::ElementsAre(1.4882351124738322, 1.299038105676658, 0.0, -0.72618437741389075, -1.299038105676658));
}

TEST(TestLegendreArray, LegendreEvaluateAtM1L3)
{
	int l = 3;
	int m = 1;
	std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
	AssociatedLegendre<double> legendre(l, m);
	EXPECT_THAT(legendre(inputs), testing::ElementsAre(-1.798284094239214, -0.3247595264191645, 1.5, 0.99850351894409983, -0.3247595264191645));
}