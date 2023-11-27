#ifndef CPP3_SMARTCALC_V2_0_CONTROLLER_CREDIT_CREDIT_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_CONTROLLER_CREDIT_CREDIT_CONTROLLER_H_

#include "../../model/credit/credit_model.h"

namespace s21 {
class CreditController {
 public:
  CreditController(CreditModel model);

  void CalculateCredit(CreditConditions conditions);

  std::vector<double> GetPayment() const;

  double GetOverpayment() const;

  double GetTotalPayment() const;

 private:
  CreditModel model_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_CONTROLLER_CREDIT_CREDIT_CONTROLLER_H_
