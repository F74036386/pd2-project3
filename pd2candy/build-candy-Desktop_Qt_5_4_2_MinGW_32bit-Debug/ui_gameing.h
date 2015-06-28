/********************************************************************************
** Form generated from reading UI file 'gameing.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEING_H
#define UI_GAMEING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameing
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLCDNumber *lcdNumber_3;
    QLabel *label_8;

    void setupUi(QWidget *gameing)
    {
        if (gameing->objectName().isEmpty())
            gameing->setObjectName(QStringLiteral("gameing"));
        gameing->resize(839, 641);
        pushButton = new QPushButton(gameing);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 20, 90, 50));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(26);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(gameing);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 90, 81, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        lcdNumber = new QLCDNumber(gameing);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(680, 130, 91, 41));
        label_2 = new QLabel(gameing);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(670, 210, 111, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(20);
        label_2->setFont(font2);
        lcdNumber_2 = new QLCDNumber(gameing);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(690, 250, 71, 41));
        label_3 = new QLabel(gameing);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(680, 440, 121, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        label_4 = new QLabel(gameing);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(670, 470, 121, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Agency FB"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        label_4->setFont(font4);
        label_5 = new QLabel(gameing);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(660, 500, 141, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("Agency FB"));
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        label_5->setFont(font5);
        label_6 = new QLabel(gameing);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(680, 391, 111, 20));
        label_7 = new QLabel(gameing);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(700, 330, 91, 20));
        label_7->setFont(font2);
        lcdNumber_3 = new QLCDNumber(gameing);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(690, 360, 71, 21));
        label_8 = new QLabel(gameing);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(680, 410, 151, 31));
        label_8->setFont(font5);

        retranslateUi(gameing);

        QMetaObject::connectSlotsByName(gameing);
    } // setupUi

    void retranslateUi(QWidget *gameing)
    {
        gameing->setWindowTitle(QApplication::translate("gameing", "Form", 0));
        pushButton->setText(QApplication::translate("gameing", "restart", 0));
        label->setText(QApplication::translate("gameing", "score", 0));
        label_2->setText(QApplication::translate("gameing", "steps remine", 0));
        label_3->setText(QApplication::translate("gameing", "1 star :  1000  score", 0));
        label_4->setText(QApplication::translate("gameing", "2 star :  2000  score", 0));
        label_5->setText(QApplication::translate("gameing", "3 star :  3000  score", 0));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("gameing", "stars", 0));
        label_8->setText(QApplication::translate("gameing", " pass:1000 score", 0));
    } // retranslateUi

};

namespace Ui {
    class gameing: public Ui_gameing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEING_H
