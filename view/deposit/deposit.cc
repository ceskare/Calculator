#include "deposit.h"

#include "../calculator/calculator.h"
#include "cmath"
#include "ui_deposit.h"

namespace s21 {

Deposit::Deposit(DepositController controller, QWidget *parent)
    : controller_(controller), QWidget(parent), ui_(new Ui::Deposit) {
  ui_->setupUi(this);
  this->setWindowTitle("Deposit Calculator");
  ui_->deposit->setMaximum(9999999999999);
  connect(ui_->deposit_button, SIGNAL(clicked()), this,
          SLOT(OnPushButtonClicked()));
}

Deposit::~Deposit() { delete ui_; }

void Deposit::OnPushButtonClicked() {
  double deposit = ui_->deposit->value();
  double rate = ui_->rate->value();
  double tax = ui_->tax->value();
  double withdrawals = ui_->withdrawals->value();
  double replenishments = ui_->replenishments->value();
  int term = ui_->term->value();
  int periodicity = 1;
  char type = 'd';
  if (ui_->checkBox->isChecked()) type = 'y';
  int index_of_per = ui_->comboBox->currentIndex();
  ;
  if (index_of_per == 0)
    periodicity = 1;
  else if (index_of_per == 1)
    periodicity = 4;
  else if (index_of_per == 2)
    periodicity = 12;
  DepositConditions conditions = {
      deposit, term,        rate,           tax, periodicity,
      type,    withdrawals, replenishments, 1,   1};
  controller_.CalculateDeposit(conditions);
  //  deposit_calc(deposit, term, rate, tax, periodicity, type, withdrawals,
  //               replenishments, 1, 1, &income, &tax_outcome, &total_sum);
  ui_->income->setText(
      QString::number(round(controller_.GetIncome() * 100) / 100, 'g', 12));
  ui_->tax_outcome->setText(
      QString::number(round(controller_.GetTaxOutcome() * 100) / 100, 'g', 12));
  ui_->total_sum->setText(
      QString::number(round(controller_.GetTotalSum() * 100) / 100, 'g', 12));
}

void Deposit::on_comboBox_currentIndexChanged(int *index) {
  *index = ui_->comboBox->currentIndex();
}

}  // namespace s21
