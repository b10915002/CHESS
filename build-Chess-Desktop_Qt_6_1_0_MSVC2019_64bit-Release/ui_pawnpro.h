/********************************************************************************
** Form generated from reading UI file 'pawnpro.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAWNPRO_H
#define UI_PAWNPRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pawnpro
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;

    void setupUi(QDialog *pawnpro)
    {
        if (pawnpro->objectName().isEmpty())
            pawnpro->setObjectName(QString::fromUtf8("pawnpro"));
        pawnpro->resize(363, 131);
        pushButton = new QPushButton(pawnpro);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 40, 80, 80));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setIconSize(QSize(32, 32));
        pushButton_2 = new QPushButton(pawnpro);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 40, 80, 80));
        pushButton_2->setIconSize(QSize(32, 32));
        pushButton_3 = new QPushButton(pawnpro);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 40, 80, 80));
        pushButton_3->setIconSize(QSize(32, 32));
        pushButton_4 = new QPushButton(pawnpro);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 40, 80, 80));
        pushButton_4->setIconSize(QSize(32, 32));
        label = new QLabel(pawnpro);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 361, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Copperplate Gothic Bold")});
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(pawnpro);

        QMetaObject::connectSlotsByName(pawnpro);
    } // setupUi

    void retranslateUi(QDialog *pawnpro)
    {
        pawnpro->setWindowTitle(QCoreApplication::translate("pawnpro", "Promotion", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label->setText(QCoreApplication::translate("pawnpro", "Choose one chess to promotion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pawnpro: public Ui_pawnpro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAWNPRO_H
