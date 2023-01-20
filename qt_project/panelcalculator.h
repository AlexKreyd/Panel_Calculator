#ifndef PANELCALCULATOR_H
#define PANELCALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PanelCalculator; }
QT_END_NAMESPACE

class PanelCalculator : public QMainWindow
{
    Q_OBJECT

public:
    PanelCalculator(QWidget *parent = nullptr);
    ~PanelCalculator();

private slots:
    void on_pushButton_clicked();
    float energy_sum();
    int panels_calc(float sum);
    float energy_per_number(int number);
    float random_weather();
    int morning_hours_number();
    int day_hours_number();
    int evening_hours_number();

private:
    Ui::PanelCalculator *ui;
};
#endif // PANELCALCULATOR_H
