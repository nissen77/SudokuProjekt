#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <windows.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    popup = new PopUp();

    // assigns the ui pointer to the array fields
    fields[0][0] = ui->field_0_0;
    fields[0][1] = ui->field_0_1;
    fields[0][2] = ui->field_0_2;
    fields[0][3] = ui->field_0_3;
    fields[0][4] = ui->field_0_4;
    fields[0][5] = ui->field_0_5;
    fields[0][6] = ui->field_0_6;
    fields[0][7] = ui->field_0_7;
    fields[0][8] = ui->field_0_8;

    fields[1][0] = ui->field_1_0;
    fields[1][1] = ui->field_1_1;
    fields[1][2] = ui->field_1_2;
    fields[1][3] = ui->field_1_3;
    fields[1][4] = ui->field_1_4;
    fields[1][5] = ui->field_1_5;
    fields[1][6] = ui->field_1_6;
    fields[1][7] = ui->field_1_7;
    fields[1][8] = ui->field_1_8;

    fields[2][0] = ui->field_2_0;
    fields[2][1] = ui->field_2_1;
    fields[2][2] = ui->field_2_2;
    fields[2][3] = ui->field_2_3;
    fields[2][4] = ui->field_2_4;
    fields[2][5] = ui->field_2_5;
    fields[2][6] = ui->field_2_6;
    fields[2][7] = ui->field_2_7;
    fields[2][8] = ui->field_2_8;

    fields[3][0] = ui->field_3_0;
    fields[3][1] = ui->field_3_1;
    fields[3][2] = ui->field_3_2;
    fields[3][3] = ui->field_3_3;
    fields[3][4] = ui->field_3_4;
    fields[3][5] = ui->field_3_5;
    fields[3][6] = ui->field_3_6;
    fields[3][7] = ui->field_3_7;
    fields[3][8] = ui->field_3_8;

    fields[4][0] = ui->field_4_0;
    fields[4][1] = ui->field_4_1;
    fields[4][2] = ui->field_4_2;
    fields[4][3] = ui->field_4_3;
    fields[4][4] = ui->field_4_4;
    fields[4][5] = ui->field_4_5;
    fields[4][6] = ui->field_4_6;
    fields[4][7] = ui->field_4_7;
    fields[4][8] = ui->field_4_8;

    fields[5][0] = ui->field_5_0;
    fields[5][1] = ui->field_5_1;
    fields[5][2] = ui->field_5_2;
    fields[5][3] = ui->field_5_3;
    fields[5][4] = ui->field_5_4;
    fields[5][5] = ui->field_5_5;
    fields[5][6] = ui->field_5_6;
    fields[5][7] = ui->field_5_7;
    fields[5][8] = ui->field_5_8;

    fields[6][0] = ui->field_6_0;
    fields[6][1] = ui->field_6_1;
    fields[6][2] = ui->field_6_2;
    fields[6][3] = ui->field_6_3;
    fields[6][4] = ui->field_6_4;
    fields[6][5] = ui->field_6_5;
    fields[6][6] = ui->field_6_6;
    fields[6][7] = ui->field_6_7;
    fields[6][8] = ui->field_6_8;

    fields[7][0] = ui->field_7_0;
    fields[7][1] = ui->field_7_1;
    fields[7][2] = ui->field_7_2;
    fields[7][3] = ui->field_7_3;
    fields[7][4] = ui->field_7_4;
    fields[7][5] = ui->field_7_5;
    fields[7][6] = ui->field_7_6;
    fields[7][7] = ui->field_7_7;
    fields[7][8] = ui->field_7_8;

    fields[8][0] = ui->field_8_0;
    fields[8][1] = ui->field_8_1;
    fields[8][2] = ui->field_8_2;
    fields[8][3] = ui->field_8_3;
    fields[8][4] = ui->field_8_4;
    fields[8][5] = ui->field_8_5;
    fields[8][6] = ui->field_8_6;
    fields[8][7] = ui->field_8_7;
    fields[8][8] = ui->field_8_8;

    // restricts input
    // only numbers from 1-9
    QRegExp re("[1-9]");
    QRegExpValidator *validator = new QRegExpValidator(re, this);
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            fields[i][j]->setValidator(validator);
        }
    }
    createSudoku(48);
    getValues();
}

/* ================================================================================================
* main functions
*/

// checks if the Sudoku is solved
bool MainWindow::checkSudoku(){
    getValues();
    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            if(checkField(x, y, numbers[y][x]) == 0 || numbers[y][x] == 0){
                return false;
            }
        }
    }
    return true;
}

/*
* solveSudoku does not regard user input
*/
void MainWindow::solveSudoku(){
    //0) itterates over the array numbers until a 0 is found. It then uses checkFields to find a valid number
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            if(numbers[y][x] == 0){
                for(int n = 1; n < 10 ;n++) {
                    if(checkField(x, y, n) && !finished){
                        numbers[y][x] = n;
                        solveSudoku();
                        numbers[y][x] = 0;
                    }
                }
                return;
            }
        }
    }

    //1) after going throug the whole array the numbers are transfered into the UI
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            fields[y][x] ->setText(QString::number(numbers[y][x]));
        }
    }

    finished = true;
}

// solves the sudoku visual for the user
// same method as in solveSudoku, except that the numbers are directly written into the UI
void MainWindow::solveSudokuVisual(){
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            if(numbers[y][x] == 0){
                for(int n = 1; n < 10 ;n++) {
                    if(checkField(x, y, n) && !finished){
                        numbers[y][x] = n;
                        Sleep(250);
                        fields[y][x]->setStyleSheet("*{color : blue; font-weight: 900; font-size:15px;}");
                        fields[y][x] ->setText(QString::number(numbers[y][x]));
                        qApp->processEvents();
                        fields[y][x]->setStyleSheet("*{color:black; font-weight: normal; font-size:medium;}");
                        solveSudokuVisual();
                        numbers[y][x] = 0;
                        if(!finished){
                            fields[y][x] ->setText("");
                            qApp->processEvents();
                        }
                    }
                }
                return;
            }
        }
    }
    finished = true;
}

// creates a sudoku with the help of solveSudoku
// int difficulty indicates how many numbers are removed from the sudoku
void MainWindow::createSudoku(int difficulty){
    clearNumbers();

    //0) places 11 random numbers into the array numbers (the random numbers get validated)
    int x, y, n;
    for(int i = 0; i < 11; i++){
        x = (rand()%9);
        y = (rand()%9);
        n = (rand()%9)+1;
        if(checkField(x, y, n)){
            numbers[y][x] = n;
        }else i--;
    }

    //1) the sudoku gets solved and the values are written into the array numbers
    solveSudoku();
    getValues();
    // deletes depending on the difficulty a fixed number of elements from the array
    for(int i = 0; i < difficulty; i++){
        x = (rand()%9);
        y = (rand()%9);
        if(numbers[y][x] != 0){
            numbers[y][x] = 0;
            fields[y][x]->setStyleSheet("*{font-weight: normal;}");
        }else i--;
    }

    //2) transfers the newly created array into the ui
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            fields[y][x] ->setText("");
            if(numbers[y][x] != 0){
                fields[y][x] ->setText(QString::number(numbers[y][x]));
                fields[y][x]->setStyleSheet("*{font-weight: bold;}");
                fields[y][x]->setReadOnly(1);
            }
        }
    }
}

/* ============================================================================================
 *helper functions
*/

// gets the value from the UI and saves them in the array numbers
void MainWindow::getValues(){
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            numbers[i][j] = fields[i][j]->text().toInt();
        }
    }
}

// validates if a given numbers is valid for the given field
bool MainWindow::checkField(int x, int y, int n){
    // checks if the given numbers is contained in the x-axis or y-axis
    for(int i = 0; i < 9; i++){
        if(numbers[y][i] == n &&  x != i){
            return false;
        }
        if(numbers[i][x]== n && y != i){
            return false;
        }
    }

    // determines the position in the 3x3 block
    int xPosInBlock = x%3;
    int yPosInBlock = y%3;
    // determines in wich 3x3 block the value is contained
    int xPosBlock = (x/3)*3;
    int yPosBlock = (y/3)*3;

    // checks if the given number exists in the 3x3 block
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(n == numbers[yPosBlock+i][xPosBlock+j] && i!=yPosInBlock && j != xPosInBlock){
                return false;
            }
        }
    }
    return true;

}

// sets the value of the array number to 0 and makes the UI fields writable again
void MainWindow::clearNumbers(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbers[i][j] = 0;
            fields[i][j]->setReadOnly(0);
        }
    }
}

/* =================================================================================================
* buttons
*/

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_solve_clicked()
{
    finished = false;
    solveSudoku();
}

void MainWindow::on_check_clicked()
{
    if(checkSudoku()){
        popup->setPopUpText("Gelöst");
    }else{
        popup->setPopUpText("Nicht Gelöst");
    }
    popup->show();
}


void MainWindow::on_leicht_clicked()
{
    finished = false;
    createSudoku(48);
}

void MainWindow::on_normal_clicked()
{
    finished = false;
    createSudoku(52);
}

void MainWindow::on_schwer_clicked()
{
    finished = false;
    createSudoku(56);
}

void MainWindow::on_sehrschwer_clicked()
{
    finished = false;
    createSudoku(60);
}

void MainWindow::on_solvevisual_clicked()
{
    finished = false;
    solveSudokuVisual();
}
