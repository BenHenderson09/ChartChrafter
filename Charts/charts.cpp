#include "charts.h"
#include "ui_charts.h"

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

charts::charts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::charts)
{
    ui->setupUi(this);
    setFixedSize(size());
}

void charts::on_btnBarChart_pressed()
{
    QTableWidget *barTable = ui->tblBarChart;
    std::map<QString,QString> data = getTableData(barTable);

    QString title = ui->txtBarChartTitle->toPlainText();
    QString xLabel = ui->txtBarChartLabelX->toPlainText();
    QString yLabel = ui->txtBarChartLabelY->toPlainText();

    int records = int(data.size());

    if (records > 0){
        charts::barchart(data,title, xLabel, yLabel);
    }

}

void charts::on_btnPieChart_pressed()
{
    QTableWidget *pieTable = ui->tblPieChart;
    std::map<QString,QString> data = getTableData(pieTable);

    QString title = ui->txtPieChartTitle->toPlainText();

    int records = int(data.size());

    if (records > 0){
        charts::piechart(data,title);
    }
}

void charts::on_btnLineChart_pressed()
{
    QTableWidget *lineTable = ui->tblLineChart;
    std::map<QString,QString> data = getTableData(lineTable);

    QString title = ui->txtLineChartTitle->toPlainText();
    QString xLabel = ui->txtLineChartLabelX->toPlainText();
    QString yLabel = ui->txtLineChartLabelY->toPlainText();

    int records = int(data.size());

    if (records > 0){
        charts::linechart(data,title, xLabel, yLabel);
    }
}

std::map<QString,QString> charts::getTableData(QTableWidget *table){
    std::map<QString,QString> data;
    QList<QTableWidgetItem *> items = table->findItems("", Qt::MatchContains);
    int rows = items.size()/2;

    for (int i = 0; i < rows; i++){
        QString label = table->model()->data(ui->tblBarChart->model()->index(i,0)).toString();
        QString value = table->model()->data(ui->tblBarChart->model()->index(i,1)).toString();

        if (label != "" && value != ""){
             data[label] = value;
        }
    }

    return data;
}

charts::~charts()
{
    delete ui;
}
