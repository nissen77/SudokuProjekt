#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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

    QRegExp re("[1-9]");
    QRegExpValidator *validator = new QRegExpValidator(re, this);
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            fields[i][j]->setValidator(validator);
        }
    }
    fields[0][0]->setText("1");
    fields[0][0]->setReadOnly(1);

    int solved[9][9] = 	{{8, 6, 3,  9, 2, 5,  7, 4, 1} ,
                         {4, 1, 2,  7, 8, 6,  3, 5, 9} ,
                         {7, 5, 9,  4, 1, 3,  2, 8, 6 },

                         {9, 7, 1,  2, 6, 4,  8, 3, 5 },
                         {3, 4, 6,  8, 5, 7,  9, 1, 2 },
                         {2, 8, 5,  3, 9, 1,  4, 6, 7 },

                         {1, 9, 8,  6, 3, 2,  5, 7, 4 },
                         {5, 2, 4,  1, 7, 8,  6, 9, 3 },
                         {6, 3, 7,  5, 4, 9,  1, 2, 8}};

    int solved2[9][9] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
                          { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
                          { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
                          { 2, 6, 3, 4, 1, 5, 9, 8, 7 },
                          { 9, 7, 4, 8, 6, 3, 1, 2, 5 },
                          { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
                          { 1, 3, 8, 9, 4, 7, 2, 5, 6 },
                          { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
                          { 7, 4, 5, 2, 8, 6, 3, 1, 9 } };

    int unsolved[9][9]= {{4,0,3,0,2,0,6,0,0},
                       {9,0,0,3,0,5,0,0,1},
                       {0,0,1,8,0,6,4,0,0},
                       {0,0,8,1,0,2,9,0,0},
                       {7,0,0,0,0,0,0,0,8},
                       {0,0,6,7,0,8,2,0,0},
                       {0,0,2,6,0,9,5,0,0},
                       {8,0,0,2,0,3,0,0,9},
                       {0,0,5,0,1,0,3,0,0}};


    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            fields[i][j] ->setText(QString::number(unsolved[i][j]));
        }
    }

    getValues();
}

bool MainWindow::pruefeFeld(int x, int y, int n){
    for(int i = 0; i < 9; i++){
        if(zahlen[y][i] == n &&  x != i){
            return false;
        }
        if(zahlen[i][x]== n && y != i){
            return false;
        }
    }

    int px = x%3;
    int py = y%3;
    int xq = (x/3)*3;
    int yq = (y/3)*3;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(n == zahlen[yq+i][xq+j] && i!=py && j != px){
                return false;
            }
        }
    }
    return true;

}

bool MainWindow::pruefSudoku(){
    getValues();
    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            if(pruefeFeld(x, y, zahlen[y][x]) == 0){
                return false;
            }
        }
    }
    return true;
}



void MainWindow::solveSudoku(){
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            if(zahlen[y][x] == 0){
                for(int n = 1; n < 10 ;n++) {
                    if(pruefeFeld(x, y, n) && !fertig){
                        zahlen[y][x] = n;
                        solveSudoku();
                        zahlen[y][x] = 0;
                    }
                }
                return;
            }
        }
    }

    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            fields[y][x] ->setText(QString::number(zahlen[y][x]));
        }
    }
    fertig = true;
}


void MainWindow::getValues(){
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            zahlen[i][j] = fields[i][j]->text().toInt();
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_closebtn_clicked()
{
    solveSudoku();
    printf("testsudoku %d\n",pruefSudoku());
    //close();
}
