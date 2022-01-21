#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_released();

    void on_pushButton_3_released();

    void on_pushButton_4_released();

    void on_pushButton_6_released();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
