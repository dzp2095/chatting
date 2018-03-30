/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelTips;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditUserName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditAddress;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditPort;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnLogin;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(392, 237);
        verticalLayout_2 = new QVBoxLayout(login);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        labelTips = new QLabel(login);
        labelTips->setObjectName(QStringLiteral("labelTips"));
        labelTips->setStyleSheet(QStringLiteral("color:rgb(255, 0, 0)"));

        verticalLayout->addWidget(labelTips);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(90, 0));

        horizontalLayout->addWidget(label);

        lineEditUserName = new QLineEdit(login);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setMaxLength(16);
        lineEditUserName->setFrame(true);

        horizontalLayout->addWidget(lineEditUserName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditAddress = new QLineEdit(login);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        lineEditAddress->setMaxLength(15);

        horizontalLayout_2->addWidget(lineEditAddress);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(90, 0));

        horizontalLayout_3->addWidget(label_3);

        lineEditPort = new QLineEdit(login);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));
        lineEditPort->setMaxLength(5);

        horizontalLayout_3->addWidget(lineEditPort);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnLogin = new QPushButton(login);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));

        horizontalLayout_4->addWidget(btnLogin);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", 0));
        labelTips->setText(QApplication::translate("login", "\347\231\273\351\231\206\344\270\255\342\200\246\342\200\246", 0));
        label->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", 0));
        lineEditUserName->setText(QApplication::translate("login", "test001", 0));
        lineEditUserName->setPlaceholderText(QApplication::translate("login", "\351\225\277\345\272\246\344\270\2726~16", 0));
        label_2->setText(QApplication::translate("login", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        lineEditAddress->setText(QApplication::translate("login", "127.0.0.1", 0));
        lineEditAddress->setPlaceholderText(QApplication::translate("login", "000.000.000.000", 0));
        label_3->setText(QApplication::translate("login", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        lineEditPort->setText(QApplication::translate("login", "8000", 0));
        btnLogin->setText(QApplication::translate("login", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
