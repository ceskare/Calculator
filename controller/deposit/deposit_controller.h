#ifndef CPP3_SMARTCALC_V2_0_CONTROLLER_DEPOSIT_DEPOSIT_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_CONTROLLER_DEPOSIT_DEPOSIT_CONTROLLER_H_

#include "../../model/deposit/deposit_model.h"

namespace s21 {
class DepositController {
 public:
  DepositController(DepositModel model);

  void CalculateDeposit(DepositConditions conditions);

  double GetIncome() const;

  double GetTaxOutcome() const;

  double GetTotalSum() const;

 private:
  DepositModel model_;
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_CONTROLLER_DEPOSIT_DEPOSIT_CONTROLLER_H_
