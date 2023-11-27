#include <QApplication>

#include "calculator/calculator.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::CalculatorModel model;
  s21::CalculatorController controller(model);
  s21::Calculator view(controller);
  view.show();
  return a.exec();
}
