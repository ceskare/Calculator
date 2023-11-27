#ifndef CPP3_SMARTCALC_V2_0_VIEW_GRAPH_GRAPH_H_
#define CPP3_SMARTCALC_V2_0_VIEW_GRAPH_GRAPH_H_

#include <QVector>
#include <QWidget>

#include "../calculator/calculator.h"

namespace Ui {
class Graph;
}

namespace s21 {

class Graph : public QWidget {
  Q_OBJECT

 public:
  Graph(CalculatorController controller, QWidget *parent = nullptr);
  ~Graph();
  void setExpression(QString expression);

 private:
  CalculatorController controller_;
  Ui::Graph *ui_;

 private slots:
  void on_buttonGraph_clicked();
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_VIEW_GRAPH_GRAPH_H_
