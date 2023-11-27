#ifndef CPP3_SMARTCALC_V2_0_MODEL_CALCULATOR_CALCULATOR_MODEL_H_
#define CPP3_SMARTCALC_V2_0_MODEL_CALCULATOR_CALCULATOR_MODEL_H_

#include <stack>
#include <string>

namespace s21 {

class CalculatorModel {
 public:
  CalculatorModel() = default;
  ~CalculatorModel() = default;

  void SetExpression(std::string expression);
  void SetXValue(double x);
  double Parse();

 private:
  struct Lexeme {
    double number;
    char sign;
  };

  std::string expression_;
  double x_;
  std::stack<Lexeme> numbers_;
  std::stack<Lexeme> operations_;

  void Calculate();
  int GetRank(char type);
  int ReadFunction(std::string expression);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_MODEL_CALCULATOR_CALCULATOR_MODEL_H_