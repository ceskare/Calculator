#ifndef CPP3_SMARTCALC_V2_0_CONTROLLER_CALCULATOR_CALCULATOR_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_CONTROLLER_CALCULATOR_CALCULATOR_CONTROLLER_H_

#include "../../model/calculator/calculator_model.h"

namespace s21 {

class CalculatorController {
 public:
  CalculatorController(CalculatorModel model);
  void SetExpression(std::string expression);
  void SetXValue(double x);
  double GetResult();

 private:
  CalculatorModel model_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_CONTROLLER_CALCULATOR_CALCULATOR_CONTROLLER_H_
