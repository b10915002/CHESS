#include "pawnpro.h"
#include "ui_pawnpro.h"

pawnpro::pawnpro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pawnpro)
{
    ui->setupUi(this);
    setWindowIcon(QPixmap("pawn.png"));
    ui->pushButton->setIcon(QPixmap("queen.png"));
    ui->pushButton_2->setIcon(QPixmap("knight.png"));
    ui->pushButton_3->setIcon(QPixmap("rook.png"));
    ui->pushButton_4->setIcon(QPixmap("bishop.png"));
    chesschoose = 5;
}

pawnpro::~pawnpro()
{
    delete ui;
}

void pawnpro::on_pushButton_clicked()
{
    chesschoose = 5;
    this->close();
}

void pawnpro::on_pushButton_2_clicked()
{
    chesschoose = 2;
    this->close();
}

void pawnpro::on_pushButton_3_clicked()
{
    chesschoose = 3;
    this->close();
}

void pawnpro::on_pushButton_4_clicked()
{
    chesschoose = 4;
    this->close();
}

