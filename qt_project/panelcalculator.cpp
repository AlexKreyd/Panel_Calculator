#include "panelcalculator.h"
#include "./ui_panelcalculator.h"
#include "QString"
#include "ui_panelcalculator.h"
#include "cmath"

PanelCalculator::PanelCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PanelCalculator)
{
    ui->setupUi(this);
}

PanelCalculator::~PanelCalculator()
{
    delete ui;
}

float PanelCalculator:: energy_sum()
{
    float sum = 0;
    float hours = 0; // количество часов, на которое умножается мощность прибора
    if (ui->checkBox->isChecked()){
        hours = ui->textEdit_17->toPlainText().toFloat();
        sum += ui->textEdit->toPlainText().toFloat() * hours;;
    }
    if (ui->checkBox_2->isChecked()){
        hours = ui->textEdit_18->toPlainText().toFloat();
        sum += ui->textEdit_2->toPlainText().toFloat() * hours;
    }
    if (ui->checkBox_3->isChecked()){
        hours = ui->textEdit_16->toPlainText().toFloat();
        sum += ui->textEdit_3->toPlainText().toFloat() * hours;
    }
    if (ui->checkBox_4->isChecked()){
        hours = ui->textEdit_15->toPlainText().toFloat();
        sum += ui->textEdit_4->toPlainText().toFloat() * hours;
    }
    if (ui->checkBox_5->isChecked()){
        hours = ui->textEdit_12->toPlainText().toFloat();
        sum += ui->textEdit_5->toPlainText().toFloat() * hours;
    }
    if (ui->checkBox_6->isChecked()){
        hours = ui->textEdit_10->toPlainText().toFloat();
        sum += ui->textEdit_6->toPlainText().toFloat() * hours;
    }
    if (ui->checkBox_8->isChecked()){
        hours = ui->textEdit_13->toPlainText().toFloat();
        sum += ui->textEdit_7->toPlainText().toFloat() * hours;
    }
    if (ui->checkBox_7->isChecked()){
        hours = ui->textEdit_14->toPlainText().toFloat();
        sum += ui->textEdit_8->toPlainText().toFloat() * hours;
    }
    if (ui->checkBox_9->isChecked()){
        hours = ui->textEdit_11->toPlainText().toFloat();
        sum += ui->textEdit_9->toPlainText().toFloat() * hours;
    }

    return sum;
}

float PanelCalculator::random_weather(){
    float weather_coef = 0;
    int r = rand()%100+1;
    if(ui->comboBox->currentText() == "Краснодар"){
        if(ui->comboBox_2->currentText() == "Январь"){
            if(r >= 1 & r <= 3) weather_coef = 1;
            else if(r > 3 & r <= 39) weather_coef = 0.5;
            else if(r > 39 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Февраль"){
            if(r >= 1 & r <= 4) weather_coef = 1;
            else if(r > 4 & r <= 43) weather_coef = 0.5;
            else if(r > 43 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Март"){
            if(r >= 1 & r <= 6) weather_coef = 1;
            else if(r > 6 & r <= 57) weather_coef = 0.5;
            else if(r > 57 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Апрель"){
            if(r >= 1 & r <= 19) weather_coef = 1;
            else if(r > 19 & r <= 61) weather_coef = 0.5;
            else if(r > 61 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Май"){
            if(r >= 1 & r <= 12) weather_coef = 1;
            else if(r > 12 & r <= 61) weather_coef = 0.5;
            else if(r > 61 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Июнь"){
            if(r >= 1 & r <= 25) weather_coef = 1;
            else if(r > 25 & r <= 65) weather_coef = 0.5;
            else if(r > 65 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Июль"){
            if(r >= 1 & r <= 23) weather_coef = 1;
            else if(r > 23 & r <= 81) weather_coef = 0.5;
            else if(r > 81 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Август"){
            if(r >= 1 & r <= 41) weather_coef = 1;
            else if(r > 41 & r <= 86) weather_coef = 0.5;
            else if(r > 86 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Сентябрь"){
            if(r >= 1 & r <= 33) weather_coef = 1;
            else if(r > 33 & r <= 78) weather_coef = 0.5;
            else if(r > 78 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Октябрь"){
            if(r >= 1 & r <= 34) weather_coef = 1;
            else if(r > 34 & r <= 75) weather_coef = 0.5;
            else if(r > 75 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Ноябрь"){
            if(r >= 1 & r <= 26) weather_coef = 1;
            else if(r > 26 & r <= 70) weather_coef = 0.5;
            else if(r > 70 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Декабрь"){
            if(r >= 1 & r <= 6) weather_coef = 1;
            else if(r > 6 & r <= 50) weather_coef = 0.5;
            else if(r > 50 & r <= 100) weather_coef = 0.2;
        }
    }

    if(ui->comboBox->currentText() == "Москва"){
        if(ui->comboBox_2->currentText() == "Январь"){
            if(r > 3 & r <= 20) weather_coef = 0.5;
            else if(r > 20 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Февраль"){
            if(r == 1) weather_coef = 1;
            else if(r > 1 & r <= 18) weather_coef = 0.5;
            else if(r > 18 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Март"){
            if(r == 1) weather_coef = 1;
            else if(r > 1 & r <= 31) weather_coef = 0.5;
            else if(r > 31 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Апрель"){
            if(r >= 1 & r <= 19) weather_coef = 1;
            else if(r > 19 & r <= 61) weather_coef = 0.5;
            else if(r > 61 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Май"){
            if(r >= 1 & r <= 13) weather_coef = 1;
            else if(r > 13 & r <= 72) weather_coef = 0.5;
            else if(r > 72 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Июнь"){
            if(r >= 1 & r <= 10) weather_coef = 1;
            else if(r > 10 & r <= 75) weather_coef = 0.5;
            else if(r > 75 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Июль"){
            if(r >= 1 & r <= 2) weather_coef = 1;
            else if(r > 2 & r <= 76) weather_coef = 0.5;
            else if(r > 76 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Август"){
            if(r >= 1 & r <= 17) weather_coef = 1;
            else if(r > 17 & r <= 76) weather_coef = 0.5;
            else if(r > 76 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Сентябрь"){
            if(r >= 1 & r <= 14) weather_coef = 1;
            else if(r > 14 & r <= 70) weather_coef = 0.5;
            else if(r > 70 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Октябрь"){
            if(r >= 1 & r <= 5) weather_coef = 1;
            else if(r > 5 & r <= 61) weather_coef = 0.5;
            else if(r > 61 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Ноябрь"){
            if(r >= 1 & r <= 8) weather_coef = 1;
            else if(r > 8 & r <= 43) weather_coef = 0.5;
            else if(r > 43 & r <= 100) weather_coef = 0.2;
        }
        if(ui->comboBox_2->currentText() == "Декабрь"){
            if(r >= 1 & r <= 2) weather_coef = 1;
            else if(r > 2 & r <= 33) weather_coef = 0.5;
            else if(r > 33 & r <= 100) weather_coef = 0.2;
        }
    }
    return weather_coef;

}

int PanelCalculator::morning_hours_number(){
    int hours_number = 0;
    if(ui->comboBox->currentText() == "Краснодар"){
        if(ui->comboBox_2->currentText() == "Январь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Февраль") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Март") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Апрель") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Май") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Июнь") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Июль") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Август") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Сентябрь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Октябрь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Ноябрь") hours_number = 2;
        if(ui->comboBox_2->currentText() == "Декабрь") hours_number = 2;
    }

    if(ui->comboBox->currentText() == "Москва"){
        if(ui->comboBox_2->currentText() == "Январь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Февраль") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Март") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Апрель") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Май") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Июнь") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Июль") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Август") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Сентябрь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Октябрь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Ноябрь") hours_number = 1;
        if(ui->comboBox_2->currentText() == "Декабрь") hours_number = 1;
    }

    return hours_number;
}

int PanelCalculator::day_hours_number(){
    int hours_number = 0;
    if(ui->comboBox->currentText() == "Краснодар"){
        if(ui->comboBox_2->currentText() == "Январь") hours_number = 5;
        if(ui->comboBox_2->currentText() == "Февраль") hours_number = 5;
        if(ui->comboBox_2->currentText() == "Март") hours_number = 6;
        if(ui->comboBox_2->currentText() == "Апрель") hours_number = 7;
        if(ui->comboBox_2->currentText() == "Май") hours_number = 8;
        if(ui->comboBox_2->currentText() == "Июнь") hours_number = 8;
        if(ui->comboBox_2->currentText() == "Июль") hours_number = 8;
        if(ui->comboBox_2->currentText() == "Август") hours_number =7;
        if(ui->comboBox_2->currentText() == "Сентябрь") hours_number = 6;
        if(ui->comboBox_2->currentText() == "Октябрь") hours_number = 5;
        if(ui->comboBox_2->currentText() == "Ноябрь") hours_number = 5;
        if(ui->comboBox_2->currentText() == "Декабрь") hours_number = 5;
    }

    if(ui->comboBox->currentText() == "Москва"){
        if(ui->comboBox_2->currentText() == "Январь") hours_number = 5;
        if(ui->comboBox_2->currentText() == "Февраль") hours_number = 5;
        if(ui->comboBox_2->currentText() == "Март") hours_number = 6;
        if(ui->comboBox_2->currentText() == "Апрель") hours_number = 8;
        if(ui->comboBox_2->currentText() == "Май") hours_number = 8;
        if(ui->comboBox_2->currentText() == "Июнь") hours_number = 9;
        if(ui->comboBox_2->currentText() == "Июль") hours_number = 8;
        if(ui->comboBox_2->currentText() == "Август") hours_number = 6;
        if(ui->comboBox_2->currentText() == "Сентябрь") hours_number = 6;
        if(ui->comboBox_2->currentText() == "Октябрь") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Ноябрь") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Декабрь") hours_number = 4;
    }

    return hours_number;
}

int PanelCalculator::evening_hours_number(){
    int hours_number = 0;
    if(ui->comboBox->currentText() == "Краснодар"){
        if(ui->comboBox_2->currentText() == "Январь") hours_number = 2;
        if(ui->comboBox_2->currentText() == "Февраль") hours_number = 2;
        if(ui->comboBox_2->currentText() == "Март") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Апрель") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Май") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Июнь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Июль") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Август") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Сентябрь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Октябрь") hours_number = 2;
        if(ui->comboBox_2->currentText() == "Ноябрь") hours_number = 2;
        if(ui->comboBox_2->currentText() == "Декабрь") hours_number = 2;
    }

    if(ui->comboBox->currentText() == "Москва"){
        if(ui->comboBox_2->currentText() == "Январь") hours_number = 2;
        if(ui->comboBox_2->currentText() == "Февраль") hours_number = 2;
        if(ui->comboBox_2->currentText() == "Март") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Апрель") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Май") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Июнь") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Июль") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Август") hours_number = 4;
        if(ui->comboBox_2->currentText() == "Сентябрь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Октябрь") hours_number = 3;
        if(ui->comboBox_2->currentText() == "Ноябрь") hours_number = 2;
        if(ui->comboBox_2->currentText() == "Декабрь") hours_number = 2;
    }
    return hours_number;
}

float PanelCalculator::energy_per_number(int number){
    float energy_per_panel = 0.275;
    float sum_energy = 0;
    srand(time(0));
    int m_hours = morning_hours_number();
    int d_hours = day_hours_number();
    int e_hours = evening_hours_number();
    for(int i = 0; i<10000; ++i){
        float morning_energy = m_hours * 0.4 *random_weather()* energy_per_panel * number;
        float day_energy = d_hours * 1 * random_weather() * energy_per_panel * number;
        float evening_energy =e_hours * 0.4 * random_weather() * energy_per_panel * number;
        sum_energy += morning_energy + day_energy + evening_energy;
    }
    sum_energy /= 10000;
    return sum_energy;
}

int PanelCalculator::panels_calc(float sum){
    if(sum == 0) return 0;
    float max_energy_per_day = morning_hours_number()*0.275*0.4 + day_hours_number()*0.275*1 + evening_hours_number()*0.275*0.4;
    int start_number = (int) sum /  max_energy_per_day + 1;
    int panel_number = start_number;
    float energy = 0;
    while(energy < sum){
        energy = floor(energy_per_number(panel_number) * 100) / 100;
        if(energy > sum){
            ui->label_17->setText(QString::number(energy));
            break;
        }
        panel_number++;
    }


    return panel_number;
}

void PanelCalculator::on_pushButton_clicked()
{
    float sum = energy_sum();
    int number = panels_calc(sum);
    ui->label_12->setText(QString::number(sum));
    ui->label_15->setText(QString::number(number));


}

