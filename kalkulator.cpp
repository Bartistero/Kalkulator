#include "kalkulator.h"
#include "ui_kalkulator.h"

kalkulator::kalkulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kalkulator)
{
    ui->setupUi(this);
    Left=0;
    Right=0;
    isComma=false;
    Opt=Operation::NoOperation;
    Memory=0;
    isLeft=false;
    isRight=false;
    ScreenClear=false;
}

kalkulator::~kalkulator()
{
    delete ui;
}

void kalkulator::on_P0_clicked()
{
    AddtoScreen("0");
}

void kalkulator::on_P1_clicked()
{
    AddtoScreen("1");
}

void kalkulator::on_P2_clicked()
{
    AddtoScreen("2");
}

void kalkulator::on_P3_clicked()
{
    AddtoScreen("3");

}

void kalkulator::on_P4_clicked()
{
    AddtoScreen("4");
}

void kalkulator::on_P5_clicked()
{
    AddtoScreen("5");
}

void kalkulator::on_P6_clicked()
{
    AddtoScreen("6");

}

void kalkulator::on_P7_clicked()
{
    AddtoScreen("7");
}

void kalkulator::on_P8_clicked()
{
    AddtoScreen("8");
}

void kalkulator::on_P9_clicked()
{
    AddtoScreen("9");
}

void kalkulator::on_PComma_clicked()
{

}

void kalkulator::on_EScreen_clicked()
{

}

void kalkulator::on_PDivision_clicked()
{
    if(!isLeft)
    {
        Left=ui->EScreen->text().toDouble();
        isLeft=true;
        ScreenClear=true;
    }
    Opt = Divide;
}

void kalkulator::on_PMultiply_clicked()
{
    if(!isLeft)
    {
        Left=ui->EScreen->text().toDouble();
        isLeft=true;
        ScreenClear=true;
    }
    Opt = Multiply;
}

void kalkulator::on_PaddMem_clicked()
{
    Memory= ui->EScreen->text().toDouble();
    ScreenClear=true;
}

void kalkulator::on_PReleaseMem_clicked()
{

}

void kalkulator::on_PMinus_clicked()
{
    if(!isLeft)
    {
        Left=ui->EScreen->text().toDouble();
        isLeft=true;
        ScreenClear=true;
    }
    Opt=Minus;
}

void kalkulator::on_PClear_clicked()
{
    Left=0;
    Right=0;
    isComma=false;
    Opt=Operation::NoOperation;
    //ui->EScreen->clear();
    ui->EScreen->setText("0");
    isLeft=false;
    isRight=false;
    ScreenClear=false;
}

void kalkulator::AddtoScreen(QString Text)
{
    QString oldtext = ui->EScreen->text(); //Pobiera tekst z wyswietlacza

    if(oldtext.length() > ui->EScreen->maxLength()) return;
    if(oldtext == "0")
        oldtext.clear();
    if(ScreenClear)
    {
        oldtext.clear();
        ScreenClear=false;
    }

    oldtext.append(Text);
    ui->EScreen->setText(oldtext);
}

void kalkulator::on_PPlus_clicked()
{
    if(!isLeft)
    {
        Left = ui->EScreen->text().toDouble();
        isLeft=true;
        ScreenClear=true;
    }
    Opt=Plus;
}

void kalkulator::on_Release_clicked()
{
    double tmp;
    if(!isLeft)
        return;
    Right=ui->EScreen->text().toDouble();
    switch(Opt)
    {
    case Plus:
        tmp=Left + Right;

        break;

    case Minus:
        tmp=Left-Right;
        break;

    case Multiply:
        tmp=Left*Right;
        break;

    case Divide:
        tmp=Left/Right;
        break;

    }
    ScreenClear=true;;
    Left=tmp;
    ui->EScreen->setText(QString::number(tmp));
}
