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

void charts::barchart(std::map<QString,QString> data, QString title, QString xLabel, QString yLabel){
    QVector<QBarSet*> set;
    QBarSeries *series = new QBarSeries();

    for (auto const& x : data)
    {
        // Appends all bar labels and values to the set
        set.append(new QBarSet(x.first));
        *set[set.size()-1] << x.second.toDouble();

        // Add the bar to the series
        series->append(set[set.size()-1]);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->setAnimationOptions(QChart::AllAnimations);

    QFont titleFont;
    titleFont.setPixelSize(35);
    chart->setTitleFont(titleFont);

    QFont labelFont;
    labelFont.setPixelSize(18);

    QStringList categories;
    categories << "";

    QBarCategoryAxis *barAxis = new QBarCategoryAxis();
    barAxis->append(categories);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText(yLabel);

    chart->createDefaultAxes();
    chart->setAxisX(barAxis,series);

    chart->axisY()->setTitleText(yLabel);
    chart->axisY()->setTitleFont(labelFont);

    chart->axisX()->setTitleText(xLabel);
    chart->axisX()->setTitleFont(labelFont);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setFont(labelFont);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chartWindow.setCentralWidget(chartView);
    chartWindow.resize(1500, 800);
    chartWindow.show();
}
