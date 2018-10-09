#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();


private slots:
    void on_behaviorButton_clicked();

private:
    Ui::HomeWindow *ui;
};

#endif // HOMEWINDOW_H
