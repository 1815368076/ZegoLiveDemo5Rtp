/********************************************************************************
** Form generated from reading UI file 'ZegoShareDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEGOSHAREDIALOG_H
#define UI_ZEGOSHAREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ZegoShareDialog
{
public:
    QPushButton *m_copy;
    QPushButton *m_quit;
    QLabel *m_title;
    QLabel *m_link;

    void setupUi(QDialog *ZegoShareDialog)
    {
        if (ZegoShareDialog->objectName().isEmpty())
            ZegoShareDialog->setObjectName(QStringLiteral("ZegoShareDialog"));
        ZegoShareDialog->resize(700, 166);
        m_copy = new QPushButton(ZegoShareDialog);
        m_copy->setObjectName(QStringLiteral("m_copy"));
        m_copy->setGeometry(QRect(460, 120, 112, 34));
        m_quit = new QPushButton(ZegoShareDialog);
        m_quit->setObjectName(QStringLiteral("m_quit"));
        m_quit->setGeometry(QRect(580, 120, 112, 34));
        m_title = new QLabel(ZegoShareDialog);
        m_title->setObjectName(QStringLiteral("m_title"));
        m_title->setGeometry(QRect(20, 20, 371, 18));
        m_link = new QLabel(ZegoShareDialog);
        m_link->setObjectName(QStringLiteral("m_link"));
        m_link->setGeometry(QRect(30, 60, 651, 21));

        retranslateUi(ZegoShareDialog);

        QMetaObject::connectSlotsByName(ZegoShareDialog);
    } // setupUi

    void retranslateUi(QDialog *ZegoShareDialog)
    {
        ZegoShareDialog->setWindowTitle(QApplication::translate("ZegoShareDialog", "Dialog", Q_NULLPTR));
        m_copy->setText(QApplication::translate("ZegoShareDialog", "\345\244\215\345\210\266", Q_NULLPTR));
        m_quit->setText(QApplication::translate("ZegoShareDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        m_title->setText(QApplication::translate("ZegoShareDialog", "\350\257\267\345\260\206\350\257\245\351\223\276\346\216\245\345\210\206\344\272\253\347\273\231\346\202\250\347\232\204\346\234\213\345\217\213,\345\233\264\350\247\202\346\202\250\347\232\204\347\233\264\346\222\255", Q_NULLPTR));
        m_link->setText(QApplication::translate("ZegoShareDialog", "LINK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZegoShareDialog: public Ui_ZegoShareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEGOSHAREDIALOG_H
