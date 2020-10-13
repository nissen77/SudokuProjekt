#include "popup.h"
#include "ui_popup.h"

PopUp::PopUp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PopUp)
{
    ui->setupUi(this);
}

PopUp::~PopUp()
{
    delete ui;
}

void PopUp::setPopUpText(const QString text){
    ui->lineEdit->setText(text);
    ui->lineEdit->setReadOnly(1);
}

void PopUp::on_pushButton_clicked()
{
    close();
}
