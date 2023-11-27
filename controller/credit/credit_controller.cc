#include "credit_controller.h"

namespace s21 {

CreditController::CreditController(CreditModel model) : model_(model) {}

void CreditController::CalculateCredit(CreditConditions conditions) {
  model_.CalculateCredit(conditions);
}

std::vector<double> CreditController::GetPayment() const {
  return model_.GetPayment();
}

double CreditController::GetOverpayment() const {
  return model_.GetOverpayment();
}

double CreditController::GetTotalPayment() const {
  return model_.GetTotalPayment();
}

}  // namespace s21
