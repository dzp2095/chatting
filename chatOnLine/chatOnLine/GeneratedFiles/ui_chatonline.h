/********************************************************************************
** Form generated from reading UI file 'chatonline.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATONLINE_H
#define UI_CHATONLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatOnLineClass
{
public:
    QAction *actionLogin;
    QAction *actionLogOut;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelUserInfo;
    QSpacerItem *horizontalSpacer_3;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chatOnLineClass)
    {
        if (chatOnLineClass->objectName().isEmpty())
            chatOnLineClass->setObjectName(QStringLiteral("chatOnLineClass"));
        chatOnLineClass->resize(400, 1000);
        chatOnLineClass->setMinimumSize(QSize(400, 1000));
        chatOnLineClass->setMaximumSize(QSize(99999, 99999));
        chatOnLineClass->setLayoutDirection(Qt::LeftToRight);
        actionLogin = new QAction(chatOnLineClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogOut = new QAction(chatOnLineClass);
        actionLogOut->setObjectName(QStringLiteral("actionLogOut"));
        centralWidget = new QWidget(chatOnLineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelUserInfo = new QLabel(centralWidget);
        labelUserInfo->setObjectName(QStringLiteral("labelUserInfo"));

        horizontalLayout_4->addWidget(labelUserInfo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMaximumSize(QSize(9999, 9999));
        treeWidget->header()->setDefaultSectionSize(180);
        treeWidget->header()->setMinimumSectionSize(180);

        verticalLayout->addWidget(treeWidget);

        chatOnLineClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(chatOnLineClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 30));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        chatOnLineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chatOnLineClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        chatOnLineClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(chatOnLineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        chatOnLineClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionLogin);
        menu->addAction(actionLogOut);

        retranslateUi(chatOnLineClass);

        QMetaObject::connectSlotsByName(chatOnLineClass);
    } // setupUi

    void retranslateUi(QMainWindow *chatOnLineClass)
    {
        chatOnLineClass->setWindowTitle(QApplication::translate("chatOnLineClass", "chatOnLine", 0));
        actionLogin->setText(QApplication::translate("chatOnLineClass", "\351\207\215\346\226\260\347\231\273\351\231\206", 0));
        actionLogOut->setText(QApplication::translate("chatOnLineClass", "\351\200\200\345\207\272", 0));
        labelUserInfo->setText(QApplication::translate("chatOnLineClass", "\347\231\273\351\231\206\344\270\255\342\200\246\342\200\246", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("chatOnLineClass", "ID", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("chatOnLineClass", "\347\224\250\346\210\267\345\220\215", 0));
        menu->setTitle(QApplication::translate("chatOnLineClass", "\347\224\250\346\210\267", 0));
    } // retranslateUi

};

namespace Ui {
    class chatOnLineClass: public Ui_chatOnLineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATONLINE_H
