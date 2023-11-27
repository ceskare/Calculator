#include "tests.h"

#include <gtest/gtest.h>

#include <cmath>

//#include "../controller/credit/credit_controller.h"
//#include "../controller/deposit/deposit_controller.h"
#include "../controller/calculator/calculator_controller.h"

TEST(CalculatorTest, TestCalculations) {
  s21::CalculatorModel model;
  s21::CalculatorController controller(model);
  for (int i = 0; i < 10; ++i) {
    controller.SetExpression(kTestCalculation[i]);
    EXPECT_NEAR(controller.GetResult(), kCalculationResult[i], kAccuracy);
  }
}

TEST(CalculatorTest, TestFunction) {
  s21::CalculatorModel model;
  s21::CalculatorController controller(model);
  for (int i = 0; i < 10; ++i) {
    controller.SetExpression(kTestFunction[i]);
    EXPECT_NEAR(controller.GetResult(), kFunctionResult[i], kAccuracy);
  }
}

TEST(CalculatorTest, TestCalcError) {
  s21::CalculatorModel model;
  s21::CalculatorController controller(model);
  for (int i = 0; i < 10; ++i) {
    controller.SetExpression(kTestCalcError[i]);
    double result = controller.GetResult();
    EXPECT_EQ(std::isnan(result), true);
  }
}

TEST(CalculatorTest, TestError) {
  s21::CalculatorModel model;
  s21::CalculatorController controller(model);
  for (int i = 0; i < 10; ++i) {
    controller.SetExpression(kTestError[i]);
    EXPECT_THROW(controller.GetResult(), std::exception);
  }
}

// START_TEST(credit) {
//   double a = 1, b = 1, c = 1, d = 1;
//   credit_calc(1, 1, 1, 'a', &a, &b, &c, &d);
//   int status = ERROR;
//   if (a && b && c && d) status = OK;
//   ck_assert_int_eq(status, OK);
//   credit_calc(1, 1, 1, 'd', &a, &b, &c, &d);
//   status = ERROR;
//   if (a && b && c && d) status = OK;
//   ck_assert_int_eq(status, OK);
// }
//
// START_TEST(deposit) {
//   double a = 1, b = 1, c = 1;
//   int status = ERROR;
//   deposit_calc(1, 1, 1, 1, 1, 'n', 1, 1, 1, 1, &a, &b, &c);
//   if (a && b && c) status = OK;
//
//   ck_assert_int_eq(status, OK);
//   status = ERROR;
//   if (a && b && c) status = OK;
//   deposit_calc(1, 1, 1, 1, 1, 'y', 1, 1, 1, 1, &a, &b, &c);
//   ck_assert_int_eq(status, OK);
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}