#ifndef BARCHART_H
#define BARCHART_H
#include <QMainWindow>

class barchart : public QMainWindow
{

public:
    QMainWindow chartWindow;
    void generate(std::map<QString, QString> data, QString title);
};

#endif // BARCHART_H
