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

void charts::linechart(std::map<QString,QString> data, QString title, QString xLabel, QString yLabel){
       QLineSeries *series = new QLineSeries();

       for (auto const& x : data){
            series->append(x.first.toDouble(), x.second.toDouble());
       }

       QFont titleFont;
       titleFont.setPixelSize(35);

       QFont labelFont;
       labelFont.setPixelSize(18);

       QChart *chart = new QChart();
       chart->legend()->hide();
       chart->addSeries(series);
       chart->createDefaultAxes();

       chart->axisY()->setTitleText(yLabel);
       chart->axisY()->setTitleFont(labelFont);

       chart->axisX()->setTitleText(xLabel);
       chart->axisX()->setTitleFont(labelFont);

       chart->setAnimationOptions(QChart::AllAnimations);
       chart->setTitleFont(titleFont);
       chart->setTitle(title);

       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       QMainWindow window;
       chartWindow.setCentralWidget(chartView);
       chartWindow.resize(1500, 800);
       chartWindow.show();
}
