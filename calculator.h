#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void gigits_numb();
    void on_zpt_clicked();
    int vvod();
    void operations();
    void on_AC_clicked();
    void on_otvet_1_clicked();
    void on_otvet_2_clicked();
    void on_Blabel_clicked();
    void on_Blabel_2_clicked();
    void on_Blabel_3_clicked();
    void on_Blabel_4_clicked();
};
#endif // CALCULATOR_H
