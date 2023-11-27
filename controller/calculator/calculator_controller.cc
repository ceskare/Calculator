#include "calculator_controller.h"

namespace s21 {

CalculatorController::CalculatorController(CalculatorModel model)
    : model_(model) {}

void CalculatorController::SetExpression(std::string expression) {
  model_.SetExpression(expression);
}

void CalculatorController::SetXValue(double x) { model_.SetXValue(x); }

double CalculatorController::GetResult() { return model_.Parse(); }

}  // namespace s21
