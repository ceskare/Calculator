#include "graph.h"

#include "../calculator/calculator.h"
#include "ui_graph.h"

namespace s21 {

Graph::Graph(CalculatorController controller, QWidget *parent)
    : controller_(controller), QWidget(parent), ui_(new Ui::Graph) {
  ui_->setupUi(this);
  this->setWindowTitle("Graph of function");
  ui_->xMax->setMaximum(1000000);
  ui_->xMax->setMinimum(0.5);
  ui_->xMin->setMaximum(-0.5);
  ui_->xMin->setMinimum(-1000000);
  ui_->xMax->setValue(10);
  ui_->xMin->setValue(-10.0);
  ui_->yMax->setMaximum(1000000);
  ui_->yMax->setMinimum(0.5);
  ui_->yMin->setMaximum(-0.5);
  ui_->yMin->setMinimum(-1000000);
  ui_->yMax->setValue(10);
  ui_->yMin->setValue(-10.0);
}

Graph::~Graph() { delete ui_; }

void Graph::setExpression(QString expression) {
  ui_->result->setText(expression);
}

void Graph::on_buttonGraph_clicked() {
  double x_min, x_max, y_min, y_max;
  x_min = ui_->xMin->value();
  x_max = ui_->xMax->value();
  y_min = ui_->yMin->value();
  y_max = ui_->yMax->value();
  double h = (x_max - x_min) / 1000000;
  QVector<double> x_vector, y_vector;
  QString result = ui_->result->text();
  std::string expression = result.toStdString();

  ui_->widget->xAxis->setRange(x_min, x_max);
  ui_->widget->yAxis->setRange(y_min, y_max);
  controller_.SetExpression(expression);
  for (double x = x_min; x <= x_max; x += h) {
    ////    int res = Parser(str, &y, x);
    try {
      controller_.SetXValue(x);
      double y = controller_.GetResult();
      y_vector.push_back(y);
      x_vector.push_back(x);
    } catch (std::exception &e) {
      break;
    }
  }
  ui_->widget->addGraph();
  ui_->widget->graph()->addData(x_vector, y_vector);
  ui_->widget->graph()->setLineStyle(QCPGraph::lsNone);
  QCPScatterStyle my_scatter;
  my_scatter.setShape(QCPScatterStyle::ssDisc);
  my_scatter.setSize(2);
  ui_->widget->graph()->setScatterStyle(my_scatter);
  ui_->widget->replot();
}

}  // namespace s21
