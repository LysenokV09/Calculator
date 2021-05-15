#include "calculator.h"
#include "ui_calculator.h"
#include <QLabel>
#include <cmath>

double all_nam,all_nam_2,all_nam_3,all_nam_4=0, Disk, x_1, x_2;
QString NLab,NLab_2,NLab_3,NLab_4,D,X1,X2;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
  ui->label->setText(" 0 ");ui->label_2->setText(" 0 ");ui->label_3->setText(" 0 ");ui->label_4->setText(" 0 ");
    connect(ui->zerro, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->one, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->two, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->tree, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->four, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->five, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->six, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->seven, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->eith, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->nine, SIGNAL(clicked()),this,SLOT(gigits_numb()));
    connect(ui->plmin, SIGNAL(clicked()),this,SLOT(operations()));
     connect(ui->Blabel, SIGNAL(clicked()),this,SLOT(gigits_numb()));
     connect(ui->Blabel_2, SIGNAL(clicked()),this,SLOT(gigits_numb()));
     connect(ui->Blabel_3, SIGNAL(clicked()),this,SLOT(gigits_numb()));
     connect(ui->Blabel_4, SIGNAL(clicked()),this,SLOT(gigits_numb()));
            ui->Blabel->setCheckable(true);
                ui->Blabel_2->setCheckable(true);
                  ui->Blabel_3->setCheckable(true);
                    ui->Blabel_4->setCheckable(true);
                    if(ui->Blabel->isChecked()){
                   ui->label->setText("  ");
}}
Calculator::~Calculator()
{
    delete ui;
}
void Calculator::gigits_numb()
{
     QPushButton *button =(QPushButton *) sender();
   if(ui->Blabel_4->isChecked()){
     all_nam_4=(ui->label_4->text()+button->text()).toDouble();
        NLab_4=QString::number(all_nam_4,'g',15);
       ui->label_4->setText(NLab_4);
        }
   else if(ui->Blabel_3->isChecked()){
     all_nam_3=(ui->label_3->text()+button->text()).toDouble();
        NLab_3=QString::number(all_nam_3,'g',15);
       ui->label_3->setText(NLab_3);
        }
   else if(ui->Blabel_2->isChecked()){
        ui->Blabel->setCheckable(true);
     all_nam_2=(ui->label_2->text()+button->text()).toDouble();
        NLab_2=QString::number(all_nam_2,'g',15);
       ui->label_2->setText(NLab_2);
        }
   else if(ui->Blabel->isChecked()){
     all_nam=(ui->label->text()+button->text()).toDouble();
        NLab=QString::number(all_nam,'g',15);
       ui->label->setText(NLab);
        }

}
int Calculator::vvod(){
      return all_nam,  all_nam_2, all_nam_3,all_nam_4;
      }
void Calculator::on_zpt_clicked()
{
    if(ui->Blabel_4->isChecked()){
   if(!(ui->label_4->text().contains("."))){
      ui->label_4->setText(ui->label_4->text() + ".");}
    }
    else if(ui->Blabel_3->isChecked()){
   if(!(ui->label_3->text().contains("."))){
      ui->label_3->setText(ui->label_3->text() + ".");}
    }
    else if(ui->Blabel_2->isChecked()){
    if(!(ui->label_2->text().contains("."))){
       ui->label_2->setText(ui->label_2->text() + ".");}
     }
     else if(ui->Blabel->isChecked()){
    if(!(ui->label->text().contains("."))){
       ui->label->setText(ui->label->text() + ".");}
     }
}
void Calculator::operations()
{
    QPushButton *button =(QPushButton *) sender();
    if(button->text()=="+/-"){
        if(ui->Blabel_2->isChecked()){
      all_nam_2=(ui->label_2->text()).toDouble();

        all_nam_2=all_nam_2*(-1);
        NLab_2=QString::number(all_nam_2,'g',15);
        ui->label_2->setText(NLab_2);}
        else if(ui->Blabel->isChecked()){
      all_nam=(ui->label->text()).toDouble();
        all_nam=all_nam*(-1);
        NLab=QString::number(all_nam,'g',15);
        ui->label->setText(NLab);}
    }
}
void Calculator::on_AC_clicked()
{ ui->Blabel->setCheckable(true);
    ui->Blabel_2->setCheckable(true);
      ui->Blabel_3->setCheckable(true);
        ui->Blabel_4->setCheckable(true);
         all_nam=0,all_nam_2=0,all_nam_3=0,all_nam_4=0;
         ui->label->setText(" 0 ");ui->label_2->setText(" 0 ");ui->label_3->setText(" 0 ");ui->label_4->setText(" 0 ");
            ui->koren->setText("");ui->koren_2->setText("");
             ui->K_1->setText(""); ui->K_2->setText("");
                ui->Diskkrim->setText("");ui->D_1->setText("");
                 ui->rezult->setText("");
}
void Calculator::on_otvet_1_clicked()
{
    ui->Blabel_4->setCheckable(false);ui->Blabel_3->setCheckable(false);ui->Blabel_2->setCheckable(false);ui->Blabel->setCheckable(false);
            vvod();
             ui->rezult->setText("             Результат  ");
         if(all_nam_4!=0){  all_nam_3=all_nam_3-all_nam_4;}
        if(all_nam==0){

            all_nam_3=all_nam_3*(-1);
            x_1=all_nam_3/all_nam_2;
            ui->koren->setText("1 корень=");
                            X1=QString::number(x_1,'g',15);
                             ui->K_1->setText(X1);

        }
        else if(all_nam_2==0){

             x_1=sqrt(all_nam_3/all_nam);
             x_2=x_1*(-10);
             ui->koren->setText("1 корень= ");
                             X1=QString::number(x_1,'g',15);
                              ui->K_1->setText(X1);
                              ui->koren_2->setText("2 корень= ");
                                              X2=QString::number(x_2,'g',15);
                                               ui->K_2->setText(X2);
         }
         else if(all_nam!=0){
         Disk=(pow(all_nam_2,2))-((4*all_nam)*all_nam_3);
            D=QString::number(Disk,'g',15);

            ui->Diskkrim->setText("Дискриминант= ");
         ui->D_1->setText(D);
         if(Disk>=0){
                if(Disk>0){
                    x_1=((all_nam_2*(-1))-(sqrt(Disk)))/(2*all_nam);
                    x_2=((all_nam_2*(-1))+(sqrt(Disk)))/(2*all_nam);
                    ui->koren->setText("1 корень= ");
                                    X1=QString::number(x_1,'g',9);
                                     ui->K_1->setText(X1);
                                     ui->koren_2->setText("2 корень= ");
                                                     X2=QString::number(x_2,'g',9);
                                                      ui->K_2->setText(X2);
                }
                else{
                    x_1=(-1*all_nam_2)/(2*all_nam);
                    ui->koren->setText("1 корень=");
                    X1=QString::number(x_1,'g',9);
                     ui->K_1->setText(X1);
                }
            }
            else{
                    Disk=Disk*(-1);
                    x_1=(all_nam_2/(2*all_nam))*(-1);
                    x_2=(sqrt(Disk))/2;
                    ui->koren->setText("1 корень= ");
                                    X1=QString::number(x_1,'g',4);
                                    X2=QString::number(x_2,'g',4);
                                    ui->K_1->setText(X1);
                                    ui->K_1->setText(ui->K_1->text() + "+");
                                     ui->K_1->setText(ui->K_1->text() + X2);
                                      ui->K_1->setText(ui->K_1->text() + "i");
                                      ui->koren_2->setText("2 корень= ");
                                                      ui->K_2->setText(X1);
                                                      ui->K_2->setText(ui->K_2->text() + "-");
                                                       ui->K_2->setText(ui->K_2->text() + X2);
                                                        ui->K_2->setText(ui->K_2->text() + "i");
                }
         }
}

void Calculator::on_Blabel_clicked()
{
      ui->ukaz->setText(" Введите число! Затем перейдите к следующей ячейке");

}

void Calculator::on_Blabel_2_clicked()
{
    ui->ukaz->setText(" Введите число! Затем перейдите к следующей ячейке");
}

void Calculator::on_Blabel_3_clicked()
{
    ui->ukaz->setText(" Введите число! Затем перейдите к следующей ячейке");
}

void Calculator::on_Blabel_4_clicked()
{
    ui->ukaz->setText(" Введите число! Затем перейдите к следующей ячейке");
}
