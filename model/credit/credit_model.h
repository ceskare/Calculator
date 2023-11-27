#ifndef CPP3_SMARTCALC_V2_0_MODEL_CREDIT_MODEL_H_
#define CPP3_SMARTCALC_V2_0_MODEL_CREDIT_MODEL_H_

#include <vector>

namespace s21 {
struct CreditConditions {
  double total_credit;
  int term;
  double rate;
  char type;
};

class CreditModel {
 public:
  CreditModel() = default;

  ~CreditModel() = default;

  void CalculateCredit(CreditConditions conditions);

  std::vector<double> GetPayment() const;

  double GetOverpayment() const;

  double GetTotalPayment() const;

 private:
  std::vector<double> payment_;
  double overpayment_;
  double total_payment_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_MODEL_CREDIT_MODEL_H_
