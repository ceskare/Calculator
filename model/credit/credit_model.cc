#include "credit_model.h"

#include <cmath>

namespace s21 {

std::vector<double> CreditModel::GetPayment() const { return payment_; }

double CreditModel::GetOverpayment() const { return overpayment_; }

double CreditModel::GetTotalPayment() const { return total_payment_; }

void CreditModel::CalculateCredit(CreditConditions conditions) {
  payment_.clear();
  if (conditions.type == 'a') {
    payment_.push_back((conditions.total_credit * conditions.rate / 1200) /
                       (1 - pow(1 + conditions.rate / 1200, -conditions.term)));
    total_payment_ = conditions.term * (payment_.back());
    overpayment_ = (total_payment_)-conditions.total_credit;
  } else {
    double first_pay = 0;
    double d = 30.4166545;  // Количество дней в платежном периоде
    double OD = conditions.total_credit;  // Остаток долга на начало расчета
                                          // равен сумме кредита
    double DP = 0;  // Дифференцированный платеж
    overpayment_ = 0;

    for (int m = 1; m <= conditions.term; m++) {
      // Рассчитываем дифференцированный платеж по формуле
      overpayment_ += (OD * (conditions.rate / 100) * d) / 365;
      DP = (conditions.total_credit / conditions.term) +
           (OD * (conditions.rate / 100) * d) / 365;

      // Уменьшаем остаток долга на сумму погашения основного долга
      OD -= conditions.total_credit / conditions.term;
      if (!first_pay) first_pay = DP;
    }
    payment_.push_back(first_pay);
    total_payment_ = (overpayment_) + conditions.total_credit;
    payment_.push_back(DP);
  }
}
};  // namespace s21
