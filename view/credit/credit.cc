#include "credit.h"

#include <cmath>

#include "../../controller/credit/credit_controller.h"
#include "ui_credit.h"

namespace s21 {

Credit::Credit(CreditController controller, QWidget *parent)
    : controller_(controller), QWidget(parent), ui_(new Ui::Credit) {
  ui_->setupUi(this);
  this->setWindowTitle("Credit Calculator");
  ui_->creditAmount->setMaximum(9999999999999);
  ui_->annuity->setChecked(true);
  connect(ui_->calculate_button, SIGNAL(clicked()), this,
          SLOT(OnButtonCalculateClicked()));
}

Credit::~Credit() { delete ui_; }

void Credit::OnButtonCalculateClicked() {
  double total_credit = ui_->creditAmount->value();
  double rate = ui_->interestRate->value();
  int term = ui_->monthTerm->value();
  char type = 'd';
  if (ui_->annuity->isChecked()) {
    type = 'a';
    ui_->second_payment->clear();
  }
  CreditConditions conditions = {total_credit, term, rate, type};
  controller_.CalculateCredit(conditions);
  std::vector<double> payment = controller_.GetPayment();
  ui_->payment->setText(
      QString::number(round(payment.front() * 100) / 100, 'g', 12));
  if (type == 'd') {
    ui_->second_payment->setText(
        QString::number(round(payment.back() * 100) / 100, 'g', 12));
  }
  ui_->overpayment->setText(QString::number(
      round(controller_.GetOverpayment() * 100) / 100, 'g', 12));
  ui_->total_payment->setText(QString::number(
      round(controller_.GetTotalPayment() * 100) / 100, 'g', 12));
}

}  // namespace s21
