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

    // Weist dem array fields die ui pointer zu
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

    // Regex damit in die ui felder nur zahlen von 1-9 eingetragen werden koennen
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
* Haupt Funktionen
*/

// prüft ob das sudoku gelöst wurde
bool MainWindow::checkSudoku(){
    getValues();
    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            if(checkField(x, y, zahlen[y][x]) == 0 || zahlen[y][x] == 0){
                return false;
            }
        }
    }
    return true;
}

/*
* solveSudoku nimmt keine Rücksicht auf Benutzereingaben und löscht dies beim lösen raus
*/
void MainWindow::solveSudoku(){
    //0) Durchläuft das Sudokufeld bis es die Zahl 0 gefunden hat und setzt dann mit der Hilfsfunktion checkField eine gültige Zahl ein
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            if(zahlen[y][x] == 0){
                for(int n = 1; n < 10 ;n++) {
                    if(checkField(x, y, n) && !fertig){
                        zahlen[y][x] = n;
                        solveSudoku();
                        zahlen[y][x] = 0;
                    }
                }
                return;
            }
        }
    }

    //1) Nach dem Vollständigen durchlaufen des Sudokufeldes werden die Zahlen in die UI eingesetzt.
    // Falls das Sudoku nicht gelöst werden kann, bleibt der Ausgangszustand erhalten
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            fields[y][x] ->setText(QString::number(zahlen[y][x]));
        }
    }

    fertig = true;
}

// löst das sudoku sichtbar für den Benutzer
// gleiches vorgehen wie bei solveSudoku, nur dass die Zahlen sofort in die UI eingetragen werden
void MainWindow::solveSudokuVisual(){
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            if(zahlen[y][x] == 0){
                for(int n = 1; n < 10 ;n++) {
                    if(checkField(x, y, n) && !fertig){
                        zahlen[y][x] = n;
                        Sleep(250);
                        fields[y][x]->setStyleSheet("*{color : blue; font-weight: 900; font-size:15px;}");
                        fields[y][x] ->setText(QString::number(zahlen[y][x]));
                        qApp->processEvents();
                        fields[y][x]->setStyleSheet("*{color:black; font-weight: normal; font-size:medium;}");
                        solveSudokuVisual();
                        zahlen[y][x] = 0;
                        if(!fertig){
                            fields[y][x] ->setText("");
                            qApp->processEvents();
                        }
                    }
                }
                return;
            }
        }
    }
    fertig = true;
}

// erstellt ein Sudoku mit Hilfe von solveSudoku
// int difficulty gibt an wie viele Werte aus dem Sudoku gelöscht werden
void MainWindow::createSudoku(int difficulty){
    clearZahlen();

    //0) setzt in das Array zahlen elf zufällig richtige Zahlen ein.
    int x, y, n;
    for(int i = 0; i < 11; i++){
        x = (rand()%9);
        y = (rand()%9);
        n = (rand()%9)+1;
        if(checkField(x, y, n)){
            zahlen[y][x] = n;
        }else i--;
    }

    //1) läst das Array zahlen lösen.
    solveSudoku();
    getValues();
    // löscht je nach Schwierigkeitsgrad eine feste Menge an Werten zufällig heraus
    for(int i = 0; i < difficulty; i++){
        x = (rand()%9);
        y = (rand()%9);
        if(zahlen[y][x] != 0){
            zahlen[y][x] = 0;
            fields[y][x]->setStyleSheet("*{font-weight: normal;}");
        }else i--;
    }

    //2) überträgt das neu erstellte Sudoku in die UI
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            fields[y][x] ->setText("");
            if(zahlen[y][x] != 0){
                fields[y][x] ->setText(QString::number(zahlen[y][x]));
                fields[y][x]->setStyleSheet("*{font-weight: bold;}");
                fields[y][x]->setReadOnly(1);
            }
        }
    }
}

/* ============================================================================================
 *Hilfs Funktionen
*/

// holt die zahlen aus den UI feldern und speichert sie ins array zahlen
void MainWindow::getValues(){
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            zahlen[i][j] = fields[i][j]->text().toInt();
        }
    }
}

// prüft die gültigkeit einer Zahl für das gewählte Feld
bool MainWindow::checkField(int x, int y, int n){
    // prüft ob die Übergebene Zahl in der Ausgewählten x-Achse oder y-Achse schon vorhanden ist
    for(int i = 0; i < 9; i++){
        if(zahlen[y][i] == n &&  x != i){
            return false;
        }
        if(zahlen[i][x]== n && y != i){
            return false;
        }
    }

    // bestimmt die Position im 3x3 Block
    int xPosInBlock = x%3;
    int yPosInBlock = y%3;
    // bestimmt in welchen 3x3 Block sich der Wert befindet
    int xPosBlock = (x/3)*3;
    int yPosBlock = (y/3)*3;

    // prüft ob in dem bestimmten 3x3 Block die Zahl bereits vorhanden ist
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(n == zahlen[yPosBlock+i][xPosBlock+j] && i!=yPosInBlock && j != xPosInBlock){
                return false;
            }
        }
    }
    return true;

}

//setzt alle Werte des Array zahlen auf 0 und die UI Felder auf schreibbar
void MainWindow::clearZahlen(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            zahlen[i][j] = 0;
            fields[i][j]->setReadOnly(0);
        }
    }
}

/* =================================================================================================
* Buttons
*/

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_solve_clicked()
{
    fertig = false;
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
    fertig = false;
    createSudoku(48);
}

void MainWindow::on_normal_clicked()
{
    fertig = false;
    createSudoku(52);
}

void MainWindow::on_schwer_clicked()
{
    fertig = false;
    createSudoku(56);
}

void MainWindow::on_sehrschwer_clicked()
{
    fertig = false;
    createSudoku(60);
}

void MainWindow::on_solvevisual_clicked()
{
    fertig = false;
    solveSudokuVisual();
}
