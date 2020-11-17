#ifndef POPUP_H
#define POPUP_H

#include <QMainWindow>

namespace Ui {
class PopUp;
}

class PopUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit PopUp(QWidget *parent = nullptr);
    ~PopUp();
    // Funktion zum Text setzten
    void setPopUpText(const QString text);

private slots:
    // event handler für UI elemente
    void on_pushButton_clicked();

private:
    Ui::PopUp *ui;
};

#endif // POPUP_H
