#ifndef PAWNPRO_H
#define PAWNPRO_H

#include <QDialog>

namespace Ui {
class pawnpro;
}

class pawnpro : public QDialog
{
    Q_OBJECT

public:
    explicit pawnpro(QWidget *parent = nullptr);
    ~pawnpro();
    int chesschoose;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::pawnpro *ui;
};

#endif // PAWNPRO_H
