#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlineedit.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "popup.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLineEdit *fields[9][9];
    // serves as storage for the UI values
    int numbers [9][9];
    // indicates if the sudoku got solved by solveSudoku
    bool finished = false;
    // functions for solving the sudoku
    bool checkField(int x, int y, int n);
    bool checkSudoku();
    void solveSudoku();
    void solveSudokuVisual();
    void getValues();
    void createSudoku(int difficulty);
    void clearNumbers();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    // event handler for UI elementes
    void on_solve_clicked();
    void on_check_clicked();
    void on_leicht_clicked();
    void on_normal_clicked();
    void on_schwer_clicked();
    void on_sehrschwer_clicked();
    void on_solvevisual_clicked();

private:
    Ui::MainWindow *ui;
    PopUp *popup;
};
#endif // MAINWINDOW_H
