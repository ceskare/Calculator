#ifndef CPP3_SMARTCALC_V2_0_VIEW_CALCULATOR_CALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_VIEW_CALCULATOR_CALCULATOR_H_

#include <QMainWindow>

#include "../../controller/calculator/calculator_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

namespace s21 {

class Calculator : public QMainWindow {
  Q_OBJECT

 public:
  Calculator(CalculatorController controller, QWidget *parent = nullptr);
  ~Calculator();

 private:
  Ui::Calculator *ui_;
  CalculatorController controller_;

 private slots:
  void DigitClicked();
  void OperatorClicked();
  void FunctionClicked();
  void EqualClicked();
  void PowerClicked();
  void ACClicked();
  void GraphClicked();
  void CreditClicked();
  void DepositClicked();
};

}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_VIEW_CALCULATOR_CALCULATOR_H_
