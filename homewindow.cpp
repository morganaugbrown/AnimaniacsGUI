#include "homewindow.h"
#include "ui_homewindow.h"
#include "behaviorprogramming.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::on_behaviorButton_clicked()
{
    ui->ProductName->setText("Comic Sans");
    QFont newFont("Comic Sans", 8, QFont::Bold);
    ui->ProductName->setFont(newFont);
    BehaviorProgramming *newWindow = new BehaviorProgramming();
    newWindow->show();
}
