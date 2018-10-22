#include "behaviorprogramming.h"
#include "ui_behaviorprogramming.h"



BehaviorProgramming::BehaviorProgramming(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BehaviorProgramming)
{
    ui->setupUi(this);
    ui->textFrame->setHidden(true);
    ui->thresholdEdit_2->setDisabled(true);
    ui->thresholdEdit_3->setDisabled(true);
}

BehaviorProgramming::~BehaviorProgramming()
{
    delete ui;
}

void BehaviorProgramming::on_actionNew_triggered()
{
    currentFile.clear();
    ui->triggerNameEdit->setText("");
    ui->inTypeMenu->setCurrentIndex(0);
    ui->inPortMenu->setCurrentIndex(0);
    ui->showNameMenu->setCurrentIndex(0);
    ui->triggerList->clear();
}


void BehaviorProgramming::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as") + ".bmo";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    //QTextStream out(&file);
}

void BehaviorProgramming::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
}

void BehaviorProgramming::on_inTypeMenu_activated(const QString &arg1)
{
    if(arg1 == "Analog" || arg1 == "Digital")
    {
        ui->textFrame->setHidden(true);
        ui->textFrame->setDisabled(true);
        ui->analogFrame->setEnabled(true);
        ui->analogFrame->setHidden(false);
    }
    else
    {
        ui->analogFrame->setHidden(true);
        ui->analogFrame->setDisabled(true);
        ui->textFrame->setEnabled(true);
        ui->textFrame->setHidden(false);
    }
}

void BehaviorProgramming::on_logicCombo_activated(const QString &arg1)
{
    if(arg1 == "< X <")
    {
        ui->thresholdEdit->setDisabled(true);
        ui->thresholdEdit_2->setEnabled(true);
        ui->thresholdEdit_3->setEnabled(true);
    }
    else
    {
        ui->thresholdEdit->setEnabled(true);
        ui->thresholdEdit_2->setDisabled(true);
        ui->thresholdEdit_3->setDisabled(true);
    }
}

void BehaviorProgramming::on_addTrigger_clicked()
{
    QString trigger;
    if(ui->inTypeMenu->currentText() == "Text")
    {
        trigger = ui->triggerNameEdit->text() +"," + ui->inTypeMenu->currentText() +
                "," + ui->inPortMenu->currentText() +"," + ui->commandText->text() + "," + ui->showNameMenu->currentText();
    }
    else
    {
        if(ui->logicCombo->currentText() == "< X <")
        {
            trigger = ui->triggerNameEdit->text() +"," + ui->inTypeMenu->currentText() +
                    "," + ui->inPortMenu->currentText() +"," + ui->logicCombo->currentText()
                    + "," + ui->thresholdEdit_2->text() + "," + ui->thresholdEdit_3->text() +"," + ui->showNameMenu->currentText();
        }
        else
        {
            trigger = ui->triggerNameEdit->text() +"," + ui->inTypeMenu->currentText() +
                    "," + ui->inPortMenu->currentText() +"," + ui->logicCombo->currentText()
                    + "," +  ui->thresholdEdit->text() +"," + ui->showNameMenu->currentText();
        }
    }
    ui->triggerList->addItem(trigger);
}
