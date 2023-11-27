#ifndef CPP3_SMARTCALC_V2_0_MODEL_DEPOSIT_MODEL_H_
#define CPP3_SMARTCALC_V2_0_MODEL_DEPOSIT_MODEL_H_

namespace s21 {
struct DepositConditions {
  double deposit;
  int term;
  double rate, tax;
  int periodicity;
  char capitalization;
  double withdrawals, replenishments;
  int month_r, month_w;
};

class DepositModel {
 public:
  DepositModel() = default;
  ~DepositModel() = default;
  void CalculateDeposit(DepositConditions conditions);

  double GetIncome() const;

  double GetTaxOutcome() const;

  double GetTotalSum() const;

 private:
  double income_;
  double tax_outcome_;
  double total_sum_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_MODEL_DEPOSIT_MODEL_H_
