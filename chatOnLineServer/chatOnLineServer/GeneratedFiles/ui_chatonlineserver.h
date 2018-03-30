/********************************************************************************
** Form generated from reading UI file 'chatonlineserver.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATONLINESERVER_H
#define UI_CHATONLINESERVER_H

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

class Ui_chatOnLineServerClass
{
public:
    QAction *actionStart;
    QAction *actionSetPort;
    QAction *actionClose;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPort;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelClientNum;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chatOnLineServerClass)
    {
        if (chatOnLineServerClass->objectName().isEmpty())
            chatOnLineServerClass->setObjectName(QStringLiteral("chatOnLineServerClass"));
        chatOnLineServerClass->resize(837, 795);
        actionStart = new QAction(chatOnLineServerClass);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStart->setCheckable(false);
        actionSetPort = new QAction(chatOnLineServerClass);
        actionSetPort->setObjectName(QStringLiteral("actionSetPort"));
        actionClose = new QAction(chatOnLineServerClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(chatOnLineServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelPort = new QLabel(centralWidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        labelPort->setFont(font);

        horizontalLayout->addWidget(labelPort);


        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        labelClientNum = new QLabel(centralWidget);
        labelClientNum->setObjectName(QStringLiteral("labelClientNum"));

        horizontalLayout_2->addWidget(labelClientNum);


        verticalLayout->addLayout(horizontalLayout_2);

        chatOnLineServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(chatOnLineServerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 837, 30));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        chatOnLineServerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chatOnLineServerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        chatOnLineServerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(chatOnLineServerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        chatOnLineServerClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionStart);
        menu->addSeparator();
        menu->addAction(actionSetPort);
        menu->addSeparator();
        menu->addAction(actionClose);

        retranslateUi(chatOnLineServerClass);

        QMetaObject::connectSlotsByName(chatOnLineServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *chatOnLineServerClass)
    {
        chatOnLineServerClass->setWindowTitle(QApplication::translate("chatOnLineServerClass", "chatOnLineServer", 0));
        actionStart->setText(QApplication::translate("chatOnLineServerClass", "\345\220\257\345\212\250\346\234\215\345\212\241\345\231\250", 0));
        actionSetPort->setText(QApplication::translate("chatOnLineServerClass", "\346\224\271\345\217\230\347\253\257\345\217\243", 0));
        actionClose->setText(QApplication::translate("chatOnLineServerClass", "\345\205\263\351\227\255\346\234\215\345\212\241\345\231\250", 0));
        labelPort->setText(QApplication::translate("chatOnLineServerClass", "\345\275\223\345\211\215\347\253\257\345\217\243", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("chatOnLineServerClass", "\347\231\273\345\275\225\346\227\266\351\227\264", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("chatOnLineServerClass", "\347\224\250\346\210\267\347\274\226\345\217\267", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("chatOnLineServerClass", "\347\253\257\345\217\243", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("chatOnLineServerClass", "\345\234\260\345\235\200", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("chatOnLineServerClass", "\347\224\250\346\210\267\345\220\215", 0));
        labelClientNum->setText(QApplication::translate("chatOnLineServerClass", "\345\234\250\347\272\277\344\272\272\346\225\260:0", 0));
        menu->setTitle(QApplication::translate("chatOnLineServerClass", "\346\234\215\345\212\241\345\231\250", 0));
    } // retranslateUi

};

namespace Ui {
    class chatOnLineServerClass: public Ui_chatOnLineServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATONLINESERVER_H
