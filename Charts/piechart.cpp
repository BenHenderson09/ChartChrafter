#include "charts.h"

#include <QtCharts/QChartView>                  // Widget used to display charts
#include <QtCharts/QBarSeries>                  // Used to draw bars representing data provided grouped into categories
#include <QtCharts/QBarSet>                     // Represents 1 set of bars in a bar chart
#include <QtCharts/QLegend>                     // Displays the color used to represent each QBarSet
#include <QtCharts/QBarCategoryAxis>            // Adds categories to the charts axes
#include <QtCharts/QHorizontalStackedBarSeries> // Used to create stacked bar charts
#include <QtCharts/QLineSeries>                 // Used to create a line chart
#include <QtCharts/QCategoryAxis>               // Used to change names on axis
#include <QtCharts/QPieSeries>                  // Used to make Pie Charts

#include <QDebug>
#include <QVector>

using namespace QtCharts;

void charts::piechart(std::map<QString,QString> data, QString title){
      QPieSeries *series = new QPieSeries();

      for (auto const& x : data){
        series->append(x.first, x.second.toDouble());
      }

      series->setLabelsVisible();

      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle(title);
      chart->legend()->show();
      chart->legend()->setAlignment(Qt::AlignBottom);
      chart->setAnimationOptions(QChart::AllAnimations);

      QFont titleFont;
      titleFont.setPixelSize(35);
      chart->setTitleFont(titleFont);

      QFont labelFont;
      labelFont.setPixelSize(18);
      chart->legend()->setFont(labelFont);

      for (int i = 0; i < series->slices().length(); i++){
        QPieSlice* slice = series->slices().at(i);
        slice->setLabelFont(labelFont);
      }

      QChartView *chartView = new QChartView(chart);
      chartView->setRenderHint(QPainter::Antialiasing);

      chartWindow.setCentralWidget(chartView);
      chartWindow.resize(1500, 800);
      chartWindow.show();
}
