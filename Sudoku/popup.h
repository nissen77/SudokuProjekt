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
    // function to display a text
    void setPopUpText(const QString text);

private slots:
    // event handler for UI element
    void on_pushButton_clicked();

private:
    Ui::PopUp *ui;
};

#endif // POPUP_H
