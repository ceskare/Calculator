#include "calculator_model.h"

#include <cmath>
#include <cstring>
#include <iostream>

namespace s21 {

void CalculatorModel::SetExpression(std::string expression) {
  while (!operations_.empty()) {
    operations_.pop();
  }
  while (!numbers_.empty()) {
    numbers_.pop();
  }
  expression_ = expression;
}

void CalculatorModel::SetXValue(double x) { x_ = x; }

void CalculatorModel::Calculate() {
  if (operations_.empty() || numbers_.empty()) {
    throw(std::out_of_range("Incorrect expression"));
  }
  char sign = operations_.top().sign;
  operations_.pop();
  double num1 = numbers_.top().number, num2 = 0;
  numbers_.pop();
  if (strchr("+-*/^m", sign)) {
    if (numbers_.empty()) {
      throw(std::out_of_range("Incorrect expression"));
    }
    num2 = numbers_.top().number;
    numbers_.pop();
  }
  if (sign == '+') {
    numbers_.push({num1 + num2, '0'});
  } else if (sign == '-') {
    numbers_.push({num2 - num1, '0'});
  } else if (sign == '*') {
    numbers_.push({num1 * num2, '0'});
  } else if (sign == '/') {
    numbers_.push({num2 / num1, '0'});
  } else if (strchr("sctaglon", sign)) {
    if (sign == 's') {
      numbers_.push({sin(num1), '0'});
    } else if (sign == 'c') {
      numbers_.push({cos(num1), '0'});
    } else if (sign == 't') {
      numbers_.push({tan(num1), '0'});
    } else if (sign == 'a') {
      numbers_.push({asin(num1), '0'});
    } else if (sign == 'g') {
      numbers_.push({acos(num1), '0'});
    } else if (sign == 'n') {
      numbers_.push({atan(num1), '0'});
    } else if (sign == 'l') {
      numbers_.push({log(num1), '0'});
    } else if (sign == 'o') {
      numbers_.push({log10(num1), '0'});
    }
  } else if (sign == 'm') {
    numbers_.push({fmod(num2, num1), '0'});
  } else if (sign == 'q') {
    numbers_.push({sqrt(num1), '0'});
  } else if (sign == '^') {
    numbers_.push({pow(num2, num1), '0'});
  } else {
    numbers_.push({num1, '0'});
  }
}

int CalculatorModel::ReadFunction(std::string expression) {
  int index = 0;
  if (!expression.compare(0, 2, "ln")) {  // Change 2 to 3 and ln to ln(
    operations_.push({0, 'l'});
    index = 2;
  } else if (!expression.compare(0, 3, "log")) {
    operations_.push({0, 'o'});
    index = 3;
  } else if (!expression.compare(0, 3, "mod")) {
    operations_.push({0, 'm'});
    index = 3;
  } else if (!expression.compare(0, 3, "sin")) {
    operations_.push({0, 's'});
    index = 3;
  } else if (!expression.compare(0, 3, "cos")) {
    operations_.push({0, 'c'});
    index = 3;
  } else if (!expression.compare(0, 3, "tan")) {
    operations_.push({0, 't'});
    index = 3;
  } else if (!expression.compare(0, 4, "asin")) {
    operations_.push({0, 'a'});
    index = 4;
  } else if (!expression.compare(0, 4, "acos")) {
    operations_.push({0, 'g'});
    index = 4;
  } else if (!expression.compare(0, 4, "atan")) {
    operations_.push({0, 'n'});
    index = 4;
  } else if (!expression.compare(0, 4, "sqrt")) {
    operations_.push({0, 'q'});
    index = 4;
  } else
    throw std::out_of_range("Incorrect expression");
  return index;
}

int CalculatorModel::GetRank(char type) {
  int rank = -1;
  if (type == '(')
    rank = 0;
  else if (strchr("+-", type))
    rank = 1;
  else if (strchr("*/m", type))
    rank = 2;
  else if (strchr("^", type))
    rank = 3;
  else if (strchr("sctalogqn", type))
    rank = 4;
  return rank;
}

double CalculatorModel::Parse() {
  int bracket = 0;
  setlocale(LC_ALL, "C");
  std::size_t offset = 0;
  for (std::size_t i = 0; i <= expression_.size(); ++i) {
    if (std::isdigit(expression_[i]) ||
        (i == 0 && strchr("+-", expression_[i])) ||
        (i != 0 && expression_[i - 1] == '(' && strchr("+-", expression_[i]))) {
      double number = std::stod(expression_.substr(i), &offset);
      i += offset - 1;
      numbers_.push({number, 0});
    } else if (std::strchr("+-/*^", expression_[i])) {
      if (!operations_.empty() && operations_.top().sign &&
          GetRank(expression_[i]) <= GetRank(operations_.top().sign) &&
          GetRank(expression_[i]) != 3) {
        Calculate();
        --i;
      } else {
        operations_.push({0, expression_[i]});
      }
    } else if (strchr("()", expression_[i])) {
      if (expression_[i] == '(') {
        ++bracket;
        operations_.push({0, expression_[i]});
      } else if (expression_[i] == ')') {
        --bracket;
        while (!operations_.empty() && operations_.top().sign != '(') {
          Calculate();
        }
        if (!operations_.empty() && operations_.top().sign == '(') {
          operations_.pop();
        }
      }
    } else if (expression_[i] == 'x') {
      numbers_.push({x_, '0'});
    } else if (strchr("sctalm", expression_[i])) {
      i += ReadFunction(expression_.substr(i)) - 1;
    } else {
      throw std::out_of_range("Incorrect expression!");
    }
  }
  if (bracket != 0) {
    throw std::out_of_range("Incorrect expression!");
  }
  if (numbers_.empty()) {
    throw std::out_of_range("Incorrect expression!");
  }
  double result = numbers_.top().number;
  numbers_.pop();
  if (!numbers_.empty()) {
    throw std::out_of_range("Incorrect expression!");
  }
  return result;
}

}  // namespace s21
