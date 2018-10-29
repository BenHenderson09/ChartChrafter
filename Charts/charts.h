#ifndef CHARTS_H
#define CHARTS_H

#include <QMainWindow>
#include <QTableWidget>
#include "barchart.h"

namespace Ui {
class charts;
}

class charts : public QMainWindow
{
    Q_OBJECT

public:
    explicit charts(QWidget *parent = nullptr);
    ~charts();

private slots:
    void on_btnBarChart_pressed();
    void on_btnPieChart_pressed();

    void on_btnLineChart_pressed();

public:
    QMainWindow chartWindow;
    std::map<QString,QString> getTableData(QTableWidget *table);

    void barchart(std::map<QString,QString> data, QString title, QString xLabel, QString yLabel);
    void linechart(std::map<QString,QString> data, QString title, QString xLabel, QString yLabel);
    void piechart(std::map<QString,QString> data, QString title);

private:
    Ui::charts *ui;
};

#endif // CHARTS_H
