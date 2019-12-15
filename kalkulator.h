#ifndef KALKULATOR_H
#define KALKULATOR_H

#include <QMainWindow>

namespace Ui {
class kalkulator;
}

class kalkulator : public QMainWindow
{
    Q_OBJECT

public:
    explicit kalkulator(QWidget *parent = nullptr);
    ~kalkulator();

private slots:
    void on_P0_clicked();

    void on_P1_clicked();

    void on_P2_clicked();

    void on_P3_clicked();

    void on_P4_clicked();

    void on_P5_clicked();

    void on_P6_clicked();

    void on_P7_clicked();

    void on_P8_clicked();

    void on_P9_clicked();

    void on_PComma_clicked();

    void on_EScreen_clicked();

    void on_PDivision_clicked();

    void on_PMultiply_clicked();

    void on_PaddMem_clicked();

    void on_PReleaseMem_clicked();

    void on_PMinus_clicked();

    void on_PClear_clicked();

    void on_PPlus_clicked();

    void on_Release_clicked();

private:
    Ui::kalkulator *ui;

    enum Operation
    {
        Plus,
        Minus,
        Multiply,
        Divide,
        NoOperation,
    };

    double Left;
    double Right;
    bool isLeft;
    bool isRight;
    int Opt;
    double Memory;
    bool isComma;
    bool ScreenClear;
    void AddtoScreen(QString);
};

#endif // KALKULATOR_H
