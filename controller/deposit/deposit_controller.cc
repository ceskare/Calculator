#include "deposit_controller.h"

namespace s21 {

DepositController::DepositController(DepositModel model) : model_(model) {}

void DepositController::CalculateDeposit(DepositConditions conditions) {
  model_.CalculateDeposit(conditions);
}

double DepositController::GetIncome() const { return model_.GetIncome(); }

double DepositController::GetTaxOutcome() const {
  return model_.GetTaxOutcome();
}

double DepositController::GetTotalSum() const { return model_.GetTotalSum(); }

// double CreditController::GetResult() { return model_.Parse(); }

}  // namespace s21
