#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlineedit.h>
#include <iostream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLineEdit *fields[9][9];
    int zahlen [9][9];
    bool pruefeFeld(int x, int y, int n);
    bool pruefSudoku();
    void solveSudoku();
    void getValues();
    void createSudoku();
    bool fertig = false;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_closebtn_clicked();

    void on_solve_clicked();

    void on_check_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
