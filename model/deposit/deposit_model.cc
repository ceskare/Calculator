#include "deposit_model.h"
namespace s21 {

double DepositModel::GetIncome() const { return income_; }

double DepositModel::GetTaxOutcome() const { return tax_outcome_; }

double DepositModel::GetTotalSum() const { return total_sum_; }

void DepositModel::CalculateDeposit(DepositConditions conditions) {
  double accrued_interest = conditions.deposit, tax_amount, deposit_amount,
         temp_interest = 0;
  if (conditions.capitalization == 'y') {
    for (int i = 1; i <= conditions.term; i++) {
      if (i % conditions.month_r == 0)
        accrued_interest += conditions.replenishments;
      if (i % conditions.month_w == 0)
        accrued_interest -= conditions.withdrawals;
      if (i % conditions.periodicity == 0) {
        accrued_interest += temp_interest;
        accrued_interest +=
            accrued_interest * (1 + conditions.rate / 1200) - accrued_interest;
        temp_interest = 0;
      } else
        temp_interest +=
            accrued_interest * (1 + conditions.rate / 1200) - accrued_interest;
    }
  } else
    accrued_interest = conditions.deposit +
                       ((conditions.deposit * (1 + conditions.rate / 1200) -
                         conditions.deposit) *
                        conditions.term);
  tax_amount = (accrued_interest - conditions.deposit) * conditions.tax / 100;
  deposit_amount = accrued_interest - conditions.deposit - tax_amount;
  income_ = accrued_interest;
  tax_outcome_ = tax_amount;
  total_sum_ = deposit_amount;
}
};  // namespace s21
