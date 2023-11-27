#include "calculator.h"

#include "../credit/credit.h"
#include "../deposit/deposit.h"
#include "../graph/graph.h"
#include "ui_calculator.h"

namespace s21 {

Calculator::Calculator(CalculatorController controller, QWidget *parent)
    : controller_(controller), QMainWindow(parent), ui_(new Ui::Calculator) {
  ui_->setupUi(this);
  connect(ui_->b0, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b1, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b2, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b3, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b4, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b5, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b6, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b7, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b8, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->b9, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->Exp, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->ButtonX, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->Right_bracket, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->Left_bracket, SIGNAL(clicked()), this, SLOT(DigitClicked()));
  connect(ui_->Mod, SIGNAL(clicked()), this, SLOT(OperatorClicked()));
  connect(ui_->Plus, SIGNAL(clicked()), this, SLOT(OperatorClicked()));
  connect(ui_->Minus, SIGNAL(clicked()), this, SLOT(OperatorClicked()));
  connect(ui_->Multiply, SIGNAL(clicked()), this, SLOT(OperatorClicked()));
  connect(ui_->Division, SIGNAL(clicked()), this, SLOT(OperatorClicked()));
  connect(ui_->Dot, SIGNAL(clicked()), this, SLOT(OperatorClicked()));
  connect(ui_->Sin, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Cos, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Tan, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Asin, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Acos, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Atan, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Log, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Ln, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Sqrt, SIGNAL(clicked()), this, SLOT(FunctionClicked()));
  connect(ui_->Power, SIGNAL(clicked()), this, SLOT(PowerClicked()));
  connect(ui_->Equal, SIGNAL(clicked()), this, SLOT(EqualClicked()));
  connect(ui_->AC, SIGNAL(clicked()), this, SLOT(ACClicked()));
  connect(ui_->Graph, SIGNAL(clicked()), this, SLOT(GraphClicked()));
  connect(ui_->Credit, SIGNAL(clicked()), this, SLOT(CreditClicked()));
  connect(ui_->Deposit, SIGNAL(clicked()), this, SLOT(DepositClicked()));
}

Calculator::~Calculator() { delete ui_; }

void Calculator::OperatorClicked() {
  QPushButton *button = (QPushButton *)(sender());
  QString string = ui_->label->text();
  int code_point = string[string.size() - 1].unicode();
  if (std::isdigit(code_point) || code_point == '(' || code_point == ')') {
    string.append(button->text());
    ui_->label->setText(string);
  }
}

void Calculator::DigitClicked() {
  QPushButton *button = (QPushButton *)(sender());
  QString string = ui_->label->text();
  string.append(button->text());
  ui_->label->setText(string);
}

void Calculator::FunctionClicked() {
  QPushButton *button = (QPushButton *)(sender());

  QString string = ui_->label->text();
  string.append(button->text() + "(");
  ui_->label->setText(string);
}

void Calculator::EqualClicked() {
  QString input = ui_->label->text();
  std::string expression = input.toStdString();
  controller_.SetExpression(expression);
  try {
    controller_.SetXValue(ui_->XSpinBox->value());
    double result = controller_.GetResult();
    if (std::isnan(result)) {
      ui_->label->setText("ERROR");
    } else
      ui_->label->setText(QString::number(result, 'g', 12));
  } catch (std::exception &e) {
    ui_->label->setText("ERROR");
  }
}

void Calculator::PowerClicked() {
  if (!ui_->label->text().endsWith('^'))
    ui_->label->setText(ui_->label->text() + "^");
}

void Calculator::ACClicked() {
  ui_->label->clear();
  ui_->label->setText("");
}

void Calculator::GraphClicked() {
  Graph *new_window = new Graph(controller_);
  new_window->setExpression(ui_->label->text());
  new_window->setAttribute(Qt::WA_DeleteOnClose);
  new_window->show();
}

void Calculator::CreditClicked() {
  CreditModel model;
  CreditController credit_controller(model);
  Credit *new_window = new Credit(credit_controller);
  new_window->setAttribute(Qt::WA_DeleteOnClose);
  new_window->show();
}

void Calculator::DepositClicked() {
  DepositModel model;
  DepositController deposit_controller(model);
  Deposit *new_window = new Deposit(deposit_controller);
  new_window->setAttribute(Qt::WA_DeleteOnClose);
  new_window->show();
}
}  // namespace s21
