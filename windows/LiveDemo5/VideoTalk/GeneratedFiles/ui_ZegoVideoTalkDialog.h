/********************************************************************************
** Form generated from reading UI file 'ZegoVideoTalkDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEGOVIDEOTALKDIALOG_H
#define UI_ZEGOVIDEOTALKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ZegoMircophone.h"

QT_BEGIN_NAMESPACE

class Ui_ZegoVideoTalkDialog
{
public:
    QVBoxLayout *verticalLayout_18;
    QVBoxLayout *verticalLayout;
    QWidget *m_zoneTitle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_lbRoomName;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *m_bMin;
    QPushButton *m_bMax;
    QPushButton *m_bClose;
    QHBoxLayout *horizontalLayout;
    QWidget *m_zoneLiveView;
    QHBoxLayout *horizontalLayout_ForAVView;
    QWidget *m_zoneLiveView_Inner;
    QHBoxLayout *zoneLiveViewHorizontalLayout;
    QFrame *m_lineBetweenViewAndList;
    QWidget *m_zoneCommonAndUserList;
    QVBoxLayout *verticalLayout_15;
    QTabWidget *m_tabCommonAndUserList;
    QWidget *m_tabContact;
    QVBoxLayout *verticalLayout_16;
    QFrame *m_lineContact;
    QFrame *m_lineLongContact;
    QTableView *m_listLog;
    QWidget *m_tabMember;
    QVBoxLayout *verticalLayout_17;
    QFrame *m_lineMember;
    QFrame *m_lineLongMember;
    QListView *m_listMember;
    QFrame *m_lineMain;
    QHBoxLayout *horizontalLayout2;
    QWidget *m_zoneSettings;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_10;
    QLabel *m_lbEquipment_2;
    QSpacerItem *verticalSpacer_11;
    QFormLayout *formLayout_2;
    QLabel *m_lbMircoPhone_2;
    QComboBox *m_cbMircoPhone;
    QLabel *m_lbCamera_2;
    QComboBox *m_cbCamera;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_12;
    QLabel *m_lbOperation_2;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *m_bCamera;
    QSpacerItem *horizontalSpacer;
    MircoPhoneButton *m_bProgMircoPhone;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *m_bSound;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_14;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *m_bAux;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *m_bCapture;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_17;
    QFrame *m_lineBetweenSettingsAndEdit;
    QWidget *m_zoneInput;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_14;
    QTextEdit *m_edInput;
    QSpacerItem *verticalSpacer_17;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *m_bShowFullScreen;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *verticalSpacer_18;

    void setupUi(QDialog *ZegoVideoTalkDialog)
    {
        if (ZegoVideoTalkDialog->objectName().isEmpty())
            ZegoVideoTalkDialog->setObjectName(QStringLiteral("ZegoVideoTalkDialog"));
        ZegoVideoTalkDialog->resize(1283, 721);
        ZegoVideoTalkDialog->setStyleSheet(QStringLiteral("background-color: #ffffff;"));
        verticalLayout_18 = new QVBoxLayout(ZegoVideoTalkDialog);
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_zoneTitle = new QWidget(ZegoVideoTalkDialog);
        m_zoneTitle->setObjectName(QStringLiteral("m_zoneTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_zoneTitle->sizePolicy().hasHeightForWidth());
        m_zoneTitle->setSizePolicy(sizePolicy);
        m_zoneTitle->setMinimumSize(QSize(0, 40));
        m_zoneTitle->setMaximumSize(QSize(16777215, 40));
        m_zoneTitle->setStyleSheet(QStringLiteral("background-color: #0e88eb;"));
        horizontalLayout_3 = new QHBoxLayout(m_zoneTitle);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        m_lbRoomName = new QLabel(m_zoneTitle);
        m_lbRoomName->setObjectName(QStringLiteral("m_lbRoomName"));
        m_lbRoomName->setStyleSheet(QString::fromUtf8("padding-left: 20px;\n"
"font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 14px;\n"
"color: #ffffff;\n"
"border: none;"));

        horizontalLayout_3->addWidget(m_lbRoomName);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, -1, -1, -1);
        m_bMin = new QPushButton(m_zoneTitle);
        m_bMin->setObjectName(QStringLiteral("m_bMin"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_bMin->sizePolicy().hasHeightForWidth());
        m_bMin->setSizePolicy(sizePolicy1);
        m_bMin->setMinimumSize(QSize(30, 40));
        m_bMin->setMaximumSize(QSize(30, 40));
        m_bMin->setFocusPolicy(Qt::NoFocus);
        m_bMin->setStyleSheet(QLatin1String("QPushButton{\n"
"    border: 1px solid #0e88eb;\n"
"    background-color: #0e88eb;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border: 1px solid #0d80de;\n"
"    background-color: #0d80de;\n"
"}\n"
"\n"
"QPushButton:hover:pressed{\n"
"    border: 1px solid #0d79d1;\n"
"    background-color: #0d79d1;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/images/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_bMin->setIcon(icon);
        m_bMin->setFlat(true);

        horizontalLayout_9->addWidget(m_bMin);

        m_bMax = new QPushButton(m_zoneTitle);
        m_bMax->setObjectName(QStringLiteral("m_bMax"));
        sizePolicy1.setHeightForWidth(m_bMax->sizePolicy().hasHeightForWidth());
        m_bMax->setSizePolicy(sizePolicy1);
        m_bMax->setMinimumSize(QSize(30, 40));
        m_bMax->setMaximumSize(QSize(30, 40));
        m_bMax->setFocusPolicy(Qt::NoFocus);
        m_bMax->setStyleSheet(QLatin1String("QPushButton{\n"
"    border: 1px solid #0e88eb;\n"
"    background-color: #0e88eb;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border: 1px solid #0d80de;\n"
"    background-color: #0d80de;\n"
"}\n"
"\n"
"QPushButton:hover:pressed{\n"
"    border: 1px solid #0d79d1;\n"
"    background-color: #0d79d1;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/images/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_bMax->setIcon(icon1);
        m_bMax->setCheckable(true);
        m_bMax->setFlat(true);

        horizontalLayout_9->addWidget(m_bMax);

        m_bClose = new QPushButton(m_zoneTitle);
        m_bClose->setObjectName(QStringLiteral("m_bClose"));
        m_bClose->setEnabled(true);
        sizePolicy1.setHeightForWidth(m_bClose->sizePolicy().hasHeightForWidth());
        m_bClose->setSizePolicy(sizePolicy1);
        m_bClose->setMinimumSize(QSize(30, 40));
        m_bClose->setMaximumSize(QSize(30, 40));
        m_bClose->setFocusPolicy(Qt::NoFocus);
        m_bClose->setLayoutDirection(Qt::LeftToRight);
        m_bClose->setStyleSheet(QLatin1String("QPushButton{\n"
"    border: 1px solid #0e88eb;\n"
"    background-color: #0e88eb;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border: 1px solid #0d80de;\n"
"    background-color: #0d80de;\n"
"}\n"
"\n"
"QPushButton:hover:pressed{\n"
"    border: 1px solid #0d79d1;\n"
"    background-color: #0d79d1;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_bClose->setIcon(icon2);
        m_bClose->setFlat(true);

        horizontalLayout_9->addWidget(m_bClose);


        horizontalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout->addWidget(m_zoneTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_zoneLiveView = new QWidget(ZegoVideoTalkDialog);
        m_zoneLiveView->setObjectName(QStringLiteral("m_zoneLiveView"));
        m_zoneLiveView->setEnabled(true);
        sizePolicy.setHeightForWidth(m_zoneLiveView->sizePolicy().hasHeightForWidth());
        m_zoneLiveView->setSizePolicy(sizePolicy);
        m_zoneLiveView->setAutoFillBackground(false);
        m_zoneLiveView->setStyleSheet(QLatin1String("background-color: #ffffff;\n"
"border: none;"));
        horizontalLayout_ForAVView = new QHBoxLayout(m_zoneLiveView);
        horizontalLayout_ForAVView->setSpacing(0);
        horizontalLayout_ForAVView->setObjectName(QStringLiteral("horizontalLayout_ForAVView"));
        horizontalLayout_ForAVView->setContentsMargins(0, 0, 0, 0);
        m_zoneLiveView_Inner = new QWidget(m_zoneLiveView);
        m_zoneLiveView_Inner->setObjectName(QStringLiteral("m_zoneLiveView_Inner"));
        zoneLiveViewHorizontalLayout = new QHBoxLayout(m_zoneLiveView_Inner);
        zoneLiveViewHorizontalLayout->setSpacing(0);
        zoneLiveViewHorizontalLayout->setObjectName(QStringLiteral("zoneLiveViewHorizontalLayout"));
        zoneLiveViewHorizontalLayout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_ForAVView->addWidget(m_zoneLiveView_Inner);


        horizontalLayout->addWidget(m_zoneLiveView);

        m_lineBetweenViewAndList = new QFrame(ZegoVideoTalkDialog);
        m_lineBetweenViewAndList->setObjectName(QStringLiteral("m_lineBetweenViewAndList"));
        m_lineBetweenViewAndList->setMinimumSize(QSize(1, 0));
        m_lineBetweenViewAndList->setMaximumSize(QSize(1, 16777215));
        m_lineBetweenViewAndList->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #e6e6e6;"));
        m_lineBetweenViewAndList->setFrameShape(QFrame::VLine);
        m_lineBetweenViewAndList->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(m_lineBetweenViewAndList);

        m_zoneCommonAndUserList = new QWidget(ZegoVideoTalkDialog);
        m_zoneCommonAndUserList->setObjectName(QStringLiteral("m_zoneCommonAndUserList"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_zoneCommonAndUserList->sizePolicy().hasHeightForWidth());
        m_zoneCommonAndUserList->setSizePolicy(sizePolicy2);
        m_zoneCommonAndUserList->setMinimumSize(QSize(320, 0));
        m_zoneCommonAndUserList->setMaximumSize(QSize(320, 16777215));
        m_zoneCommonAndUserList->setStyleSheet(QStringLiteral("background-color: #ffffff;"));
        verticalLayout_15 = new QVBoxLayout(m_zoneCommonAndUserList);
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        m_tabCommonAndUserList = new QTabWidget(m_zoneCommonAndUserList);
        m_tabCommonAndUserList->setObjectName(QStringLiteral("m_tabCommonAndUserList"));
        m_tabCommonAndUserList->setStyleSheet(QString::fromUtf8("QTabWidget::pane{\n"
"	border: none;\n"
"}\n"
"\n"
"QTabWidget::tab-bar{\n"
"    left: 0px;\n"
"}\n"
"\n"
"QTabBar::tab{\n"
"    width: 160px;\n"
"    height: 40px;\n"
"    margin: 0 0 0 0;\n"
"	font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	font-size: 16px;\n"
"	color: #333333;\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QTabBar::tab:selected{\n"
"	width: 160px;\n"
"	height: 40px;\n"
"	font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	font-size: 16px;\n"
"	color: #0e88eb;\n"
"	background-color: #ffffff;\n"
"}"));
        m_tabContact = new QWidget();
        m_tabContact->setObjectName(QStringLiteral("m_tabContact"));
        verticalLayout_16 = new QVBoxLayout(m_tabContact);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        m_lineContact = new QFrame(m_tabContact);
        m_lineContact->setObjectName(QStringLiteral("m_lineContact"));
        m_lineContact->setMinimumSize(QSize(0, 2));
        m_lineContact->setMaximumSize(QSize(16777215, 2));
        m_lineContact->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0e88eb;\n"
"margin-right: 160px;"));
        m_lineContact->setFrameShape(QFrame::HLine);
        m_lineContact->setFrameShadow(QFrame::Sunken);

        verticalLayout_16->addWidget(m_lineContact);

        m_lineLongContact = new QFrame(m_tabContact);
        m_lineLongContact->setObjectName(QStringLiteral("m_lineLongContact"));
        m_lineLongContact->setMinimumSize(QSize(0, 1));
        m_lineLongContact->setMaximumSize(QSize(16777215, 1));
        m_lineLongContact->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #e6e6e6;"));
        m_lineLongContact->setFrameShape(QFrame::HLine);
        m_lineLongContact->setFrameShadow(QFrame::Sunken);

        verticalLayout_16->addWidget(m_lineLongContact);

        m_listLog = new QTableView(m_tabContact);
        m_listLog->setObjectName(QStringLiteral("m_listLog"));
        m_listLog->setStyleSheet(QString::fromUtf8("QTableView{\n"
"font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 14px;\n"
"color: #666666;\n"
"padding-top: 5px;\n"
"padding-left: 14px;\n"
"}\n"
"\n"
"QTableView::item{\n"
"    border: none;\n"
"    padding-top: 10px;\n"
"}\n"
"\n"
"QScrollBar:vertical {                 \n"
"    background:transparent;  \n"
"    width:9px;  \n"
"    margin: 0px 0px 2px 0px;  \n"
"}  \n"
"  \n"
"QScrollBar::handle:vertical {  \n"
"    background: rgb(195, 195, 195);  \n"
"    min-height: 20px;  \n"
"    border-radius: 3px;  \n"
"}  \n"
"  \n"
"QScrollBar::handle:vertical:hover{  \n"
"    background:rgba(0,0,0,30%);  \n"
"}  \n"
"  \n"
"QScrollBar::add-line:vertical {  \n"
"    height: 0px;  \n"
"    subcontrol-position: bottom;  \n"
"    subcontrol-origin: margin;  \n"
"}  \n"
"  \n"
"QScrollBar::sub-line:vertical {  \n"
"    height: 0px;  \n"
"    subcontrol-position: top;  \n"
"    subcontrol-origin: margin;  \n"
"}"));
        m_listLog->setFrameShape(QFrame::NoFrame);
        m_listLog->setShowGrid(false);

        verticalLayout_16->addWidget(m_listLog);

        m_tabCommonAndUserList->addTab(m_tabContact, QString());
        m_tabMember = new QWidget();
        m_tabMember->setObjectName(QStringLiteral("m_tabMember"));
        verticalLayout_17 = new QVBoxLayout(m_tabMember);
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        m_lineMember = new QFrame(m_tabMember);
        m_lineMember->setObjectName(QStringLiteral("m_lineMember"));
        m_lineMember->setMinimumSize(QSize(0, 2));
        m_lineMember->setMaximumSize(QSize(16777215, 2));
        m_lineMember->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0e88eb;\n"
"margin-left: 160px;"));
        m_lineMember->setFrameShape(QFrame::HLine);
        m_lineMember->setFrameShadow(QFrame::Sunken);

        verticalLayout_17->addWidget(m_lineMember);

        m_lineLongMember = new QFrame(m_tabMember);
        m_lineLongMember->setObjectName(QStringLiteral("m_lineLongMember"));
        m_lineLongMember->setMinimumSize(QSize(0, 1));
        m_lineLongMember->setMaximumSize(QSize(16777215, 1));
        m_lineLongMember->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #e6e6e6;"));
        m_lineLongMember->setFrameShape(QFrame::HLine);
        m_lineLongMember->setFrameShadow(QFrame::Sunken);

        verticalLayout_17->addWidget(m_lineLongMember);

        m_listMember = new QListView(m_tabMember);
        m_listMember->setObjectName(QStringLiteral("m_listMember"));
        m_listMember->setStyleSheet(QString::fromUtf8("QListView{\n"
"font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 14px;\n"
"color: #666666;\n"
"padding-left: 14px;\n"
"border: none;\n"
"padding-top: 5px;\n"
"}\n"
"\n"
"QListView::item{\n"
"    width: 290px;\n"
"    min-height: 8px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QScrollBar:vertical {                 \n"
"    background:transparent;  \n"
"    width:9px;  \n"
"    margin: 0px 0px 2px 0px;  \n"
"}  \n"
"  \n"
"QScrollBar::handle:vertical {  \n"
"    background: rgb(195, 195, 195);  \n"
"    min-height: 20px;  \n"
"    border-radius: 3px;  \n"
"}  \n"
"  \n"
"QScrollBar::handle:vertical:hover{  \n"
"    background:rgba(0,0,0,30%);  \n"
"}  \n"
"  \n"
"QScrollBar::add-line:vertical {  \n"
"    height: 0px;  \n"
"    subcontrol-position: bottom;  \n"
"    subcontrol-origin: margin;  \n"
"}  \n"
"  \n"
"QScrollBar::sub-line:vertical {  \n"
"    height: 0px;  \n"
"    subcontrol-position: top;  \n"
"    subcontrol-origin: margin;  \n"
"}"));
        m_listMember->setSelectionMode(QAbstractItemView::NoSelection);
        m_listMember->setSpacing(0);

        verticalLayout_17->addWidget(m_listMember);

        m_tabCommonAndUserList->addTab(m_tabMember, QString());

        verticalLayout_15->addWidget(m_tabCommonAndUserList);


        horizontalLayout->addWidget(m_zoneCommonAndUserList);


        verticalLayout->addLayout(horizontalLayout);

        m_lineMain = new QFrame(ZegoVideoTalkDialog);
        m_lineMain->setObjectName(QStringLiteral("m_lineMain"));
        m_lineMain->setMinimumSize(QSize(0, 1));
        m_lineMain->setMaximumSize(QSize(16777215, 1));
        m_lineMain->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #e6e6e6;"));
        m_lineMain->setFrameShape(QFrame::HLine);
        m_lineMain->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(m_lineMain);

        horizontalLayout2 = new QHBoxLayout();
        horizontalLayout2->setSpacing(0);
        horizontalLayout2->setObjectName(QStringLiteral("horizontalLayout2"));
        horizontalLayout2->setSizeConstraint(QLayout::SetFixedSize);
        m_zoneSettings = new QWidget(ZegoVideoTalkDialog);
        m_zoneSettings->setObjectName(QStringLiteral("m_zoneSettings"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_zoneSettings->sizePolicy().hasHeightForWidth());
        m_zoneSettings->setSizePolicy(sizePolicy3);
        m_zoneSettings->setMinimumSize(QSize(0, 138));
        m_zoneSettings->setMaximumSize(QSize(16777215, 138));
        m_zoneSettings->setStyleSheet(QStringLiteral("background-color: #ffffff;"));
        horizontalLayout_10 = new QHBoxLayout(m_zoneSettings);
        horizontalLayout_10->setSpacing(50);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_11 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, -1, -1);
        verticalSpacer_10 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_10);

        m_lbEquipment_2 = new QLabel(m_zoneSettings);
        m_lbEquipment_2->setObjectName(QStringLiteral("m_lbEquipment_2"));
        m_lbEquipment_2->setMinimumSize(QSize(18, 0));
        m_lbEquipment_2->setMaximumSize(QSize(16777215, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_lbEquipment_2->setFont(font);
        m_lbEquipment_2->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 14px;\n"
"color: #666666;"));

        verticalLayout_10->addWidget(m_lbEquipment_2);

        verticalSpacer_11 = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_11);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setHorizontalSpacing(16);
        formLayout_2->setVerticalSpacing(10);
        m_lbMircoPhone_2 = new QLabel(m_zoneSettings);
        m_lbMircoPhone_2->setObjectName(QStringLiteral("m_lbMircoPhone_2"));
        m_lbMircoPhone_2->setStyleSheet(QString::fromUtf8("QLabel:!enabled{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 14px;\n"
"    color: #cccccc;\n"
" }\n"
" \n"
"QLabel:enabled{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 14px;\n"
"    color: #666666;\n"
" }"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, m_lbMircoPhone_2);

        m_cbMircoPhone = new QComboBox(m_zoneSettings);
        m_cbMircoPhone->setObjectName(QStringLiteral("m_cbMircoPhone"));
        m_cbMircoPhone->setMinimumSize(QSize(260, 32));
        m_cbMircoPhone->setMaximumSize(QSize(260, 32));
        m_cbMircoPhone->setStyleSheet(QString::fromUtf8("  QComboBox{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QComboBox:!enabled{\n"
"    border: 1px solid #e6e6e6;\n"
"    border-radius: 2px;\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"	background-color: #fafafa;\n"
"	color: #cccccc;\n"
" }\n"
"\n"
" QComboBox:enabled:!hover{\n"
"    border: 1px solid #e6e6e6;\n"
"    border-radius: 2px;\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"	background-color: #fafafa;\n"
"	color: #666666;\n"
"}\n"
"QComboBox:enabled:hover{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
" \n"
"    border-left-width: 1px;\n"
"\n"
"    border-top-right-radius: 2px; /* same rad"
                        "ius as the QComboBox */\n"
"    border-bottom-right-radius: 2px;\n"
"\n"
" }\n"
"\n"
" QComboBox::down-arrow{\n"
"\n"
"     border-image: url(:/Resources/images/down_arrow.png);\n"
" }\n"
"\n"
" \n"
"  QComboBox QAbstractItemView{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #0e88eb;\n"
"	 background-color: #ffffff;\n"
"	 border-radius: 2px;\n"
"	 \n"
"  }\n"
"\n"
" QComboBox QAbstractItemView::item{\n"
"     \n"
"     height: 32px;\n"
"	 font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 padding-left: 10px;\n"
"	 padding-right: 10px;\n"
" }\n"
"\n"
" QComboBox QAbstractItemView::item:hover{\n"
"     \n"
"     height: 32px;\n"
"	 font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #ffffff;\n"
"	 background-color: #0e88eb;\n"
"	 padding-left: 10px;\n"
"	 padding-right: 10px;\n"
" }\n"
""));
        m_cbMircoPhone->setFrame(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, m_cbMircoPhone);

        m_lbCamera_2 = new QLabel(m_zoneSettings);
        m_lbCamera_2->setObjectName(QStringLiteral("m_lbCamera_2"));
        m_lbCamera_2->setStyleSheet(QString::fromUtf8("QLabel:!enabled{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 14px;\n"
"    color: #cccccc;\n"
" }\n"
" \n"
"QLabel:enabled{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 14px;\n"
"    color: #666666;\n"
" }"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, m_lbCamera_2);

        m_cbCamera = new QComboBox(m_zoneSettings);
        m_cbCamera->setObjectName(QStringLiteral("m_cbCamera"));
        m_cbCamera->setMinimumSize(QSize(260, 32));
        m_cbCamera->setMaximumSize(QSize(260, 32));
        m_cbCamera->setStyleSheet(QString::fromUtf8("  QComboBox{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QComboBox:!enabled{\n"
"    border: 1px solid #e6e6e6;\n"
"    border-radius: 2px;\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"	background-color: #fafafa;\n"
"	color: #cccccc;\n"
" }\n"
"\n"
" QComboBox:enabled:!hover{\n"
"    border: 1px solid #e6e6e6;\n"
"    border-radius: 2px;\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"	background-color: #fafafa;\n"
"	color: #666666;\n"
"}\n"
"QComboBox:enabled:hover{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
" \n"
"    border-left-width: 1px;\n"
"\n"
"    border-top-right-radius: 2px; /* same rad"
                        "ius as the QComboBox */\n"
"    border-bottom-right-radius: 2px;\n"
"\n"
" }\n"
"\n"
" QComboBox::down-arrow{\n"
"\n"
"     border-image: url(:/Resources/images/down_arrow.png);\n"
" }\n"
"\n"
" \n"
"  QComboBox QAbstractItemView{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #0e88eb;\n"
"	 background-color: #ffffff;\n"
"	 border-radius: 2px;\n"
"	 \n"
"  }\n"
"\n"
" QComboBox QAbstractItemView::item{\n"
"     \n"
"     height: 32px;\n"
"	 font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 padding-left: 10px;\n"
"	 padding-right: 10px;\n"
" }\n"
"\n"
" QComboBox QAbstractItemView::item:hover{\n"
"     \n"
"     height: 32px;\n"
"	 font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #ffffff;\n"
"	 background-color: #0e88eb;\n"
"	 padding-left: 10px;\n"
"	 padding-right: 10px;\n"
" }\n"
""));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, m_cbCamera);


        verticalLayout_10->addLayout(formLayout_2);


        horizontalLayout_11->addLayout(verticalLayout_10);

        horizontalSpacer_12 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_12);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 0, -1, -1);
        verticalSpacer_12 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_11->addItem(verticalSpacer_12);

        m_lbOperation_2 = new QLabel(m_zoneSettings);
        m_lbOperation_2->setObjectName(QStringLiteral("m_lbOperation_2"));
        m_lbOperation_2->setMinimumSize(QSize(0, 18));
        m_lbOperation_2->setMaximumSize(QSize(16777215, 18));
        m_lbOperation_2->setFont(font);
        m_lbOperation_2->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 14px;\n"
"color: #666666;"));

        verticalLayout_11->addWidget(m_lbOperation_2);

        verticalSpacer_13 = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_11->addItem(verticalSpacer_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, -1, -1, -1);
        m_bCamera = new QPushButton(m_zoneSettings);
        m_bCamera->setObjectName(QStringLiteral("m_bCamera"));
        sizePolicy1.setHeightForWidth(m_bCamera->sizePolicy().hasHeightForWidth());
        m_bCamera->setSizePolicy(sizePolicy1);
        m_bCamera->setMinimumSize(QSize(32, 32));
        m_bCamera->setMaximumSize(QSize(32, 32));
        m_bCamera->setCursor(QCursor(Qt::PointingHandCursor));
        m_bCamera->setStyleSheet(QLatin1String("QPushButton:!enabled{\n"
"    border-image: url(:/Resources/images/camera_disabled.png);\n"
"}\n"
"\n"
"QPushButton:enabled:!checked{\n"
"    border-image: url(:/Resources/images/camera_off.png);\n"
"}\n"
"\n"
"QPushButton:enabled:checked{\n"
"    border-image: url(:/Resources/images/camera_on.png);\n"
"}"));
        m_bCamera->setCheckable(true);
        m_bCamera->setChecked(true);

        horizontalLayout_12->addWidget(m_bCamera);

        horizontalSpacer = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        m_bProgMircoPhone = new MircoPhoneButton(m_zoneSettings);
        m_bProgMircoPhone->setObjectName(QStringLiteral("m_bProgMircoPhone"));
        sizePolicy1.setHeightForWidth(m_bProgMircoPhone->sizePolicy().hasHeightForWidth());
        m_bProgMircoPhone->setSizePolicy(sizePolicy1);
        m_bProgMircoPhone->setMinimumSize(QSize(32, 32));
        m_bProgMircoPhone->setMaximumSize(QSize(32, 32));
        m_bProgMircoPhone->setCursor(QCursor(Qt::PointingHandCursor));
        m_bProgMircoPhone->setStyleSheet(QLatin1String("QPushButton:!enabled{\n"
"    border-image: url(:/Resources/images/mircophone_disabled.png);\n"
"}\n"
"\n"
"QPushButton:enabled:!checked{\n"
"    border-image: url(:/Resources/images/mircophone_off.png);\n"
"}\n"
"\n"
"QPushButton:enabled:checked{\n"
"    border-image: url(:/Resources/images/mircophone_on.png);\n"
"}"));
        m_bProgMircoPhone->setCheckable(true);
        m_bProgMircoPhone->setChecked(true);

        horizontalLayout_12->addWidget(m_bProgMircoPhone);

        horizontalSpacer_13 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_13);

        m_bSound = new QPushButton(m_zoneSettings);
        m_bSound->setObjectName(QStringLiteral("m_bSound"));
        sizePolicy1.setHeightForWidth(m_bSound->sizePolicy().hasHeightForWidth());
        m_bSound->setSizePolicy(sizePolicy1);
        m_bSound->setMinimumSize(QSize(32, 32));
        m_bSound->setMaximumSize(QSize(32, 32));
        m_bSound->setCursor(QCursor(Qt::PointingHandCursor));
        m_bSound->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"    border-image: url(:/Resources/images/sound_off.png);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"    border-image: url(:/Resources/images/sound_on.png);\n"
"}"));
        m_bSound->setCheckable(true);
        m_bSound->setChecked(true);

        horizontalLayout_12->addWidget(m_bSound);

        horizontalSpacer_14 = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_14);


        verticalLayout_11->addLayout(horizontalLayout_12);

        verticalSpacer_14 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_11->addItem(verticalSpacer_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_13->setContentsMargins(-1, 0, 0, -1);
        m_bAux = new QPushButton(m_zoneSettings);
        m_bAux->setObjectName(QStringLiteral("m_bAux"));
        m_bAux->setMinimumSize(QSize(100, 32));
        m_bAux->setMaximumSize(QSize(100, 32));
        m_bAux->setCursor(QCursor(Qt::PointingHandCursor));
        m_bAux->setStyleSheet(QString::fromUtf8("QPushButton:!enabled{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     background-color: #ffffff;\n"
"     color: #e6e6e6;   \n"
"}\n"
"QPushButton:enabled:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #ffffff;\n"
"     color: #0e88eb;   \n"
"}\n"
"\n"
"QPushButton:enabled:hover{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;   \n"
"}\n"
"\n"
"QPushButton:enabled:hover:pressed{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #0d8"
                        "0de;\n"
"     color: #ffffff;   \n"
"}"));

        horizontalLayout_13->addWidget(m_bAux, 0, Qt::AlignTop);

        horizontalSpacer_15 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_15);

        m_bCapture = new QPushButton(m_zoneSettings);
        m_bCapture->setObjectName(QStringLiteral("m_bCapture"));
        m_bCapture->setMinimumSize(QSize(100, 32));
        m_bCapture->setMaximumSize(QSize(250, 32));
        m_bCapture->setCursor(QCursor(Qt::PointingHandCursor));
        m_bCapture->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:!enabled{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     background-color: #ffffff;\n"
"     color: #e6e6e6;   \n"
"}\n"
"QPushButton:enabled:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #ffffff;\n"
"     color: #0e88eb;   \n"
"}\n"
"\n"
"QPushButton:enabled:hover{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;   \n"
"}\n"
"\n"
"QPushButton:enabled:hover:pressed{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     bo"
                        "rder: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #0d80de;\n"
"     color: #ffffff;   \n"
"}"));

        horizontalLayout_13->addWidget(m_bCapture, 0, Qt::AlignTop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_11->addLayout(horizontalLayout_13);


        horizontalLayout_11->addLayout(verticalLayout_11);

        horizontalSpacer_17 = new QSpacerItem(250, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_17);


        horizontalLayout_10->addLayout(horizontalLayout_11);


        horizontalLayout2->addWidget(m_zoneSettings);

        m_lineBetweenSettingsAndEdit = new QFrame(ZegoVideoTalkDialog);
        m_lineBetweenSettingsAndEdit->setObjectName(QStringLiteral("m_lineBetweenSettingsAndEdit"));
        m_lineBetweenSettingsAndEdit->setMinimumSize(QSize(1, 0));
        m_lineBetweenSettingsAndEdit->setMaximumSize(QSize(1, 16777215));
        m_lineBetweenSettingsAndEdit->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #e6e6e6;"));
        m_lineBetweenSettingsAndEdit->setFrameShape(QFrame::VLine);
        m_lineBetweenSettingsAndEdit->setFrameShadow(QFrame::Sunken);

        horizontalLayout2->addWidget(m_lineBetweenSettingsAndEdit);

        m_zoneInput = new QWidget(ZegoVideoTalkDialog);
        m_zoneInput->setObjectName(QStringLiteral("m_zoneInput"));
        sizePolicy2.setHeightForWidth(m_zoneInput->sizePolicy().hasHeightForWidth());
        m_zoneInput->setSizePolicy(sizePolicy2);
        m_zoneInput->setMinimumSize(QSize(320, 138));
        m_zoneInput->setMaximumSize(QSize(320, 138));
        m_zoneInput->setStyleSheet(QStringLiteral("background-color: #ffffff;"));
        verticalLayout_13 = new QVBoxLayout(m_zoneInput);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        m_edInput = new QTextEdit(m_zoneInput);
        m_edInput->setObjectName(QStringLiteral("m_edInput"));
        m_edInput->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 14px;\n"
"    padding-left: 10px;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QScrollBar:vertical{\n"
"    border:0px solid grey;\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical{\n"
"     background-color: #dbdbdb;\n"
"     border-radius: 5px;\n"
"     min-height: 20px;\n"
"     \n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover{\n"
"     background-color: #d0d0d0;\n"
"}"));
        m_edInput->setFrameShape(QFrame::NoFrame);

        verticalLayout_14->addWidget(m_edInput);

        verticalSpacer_17 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_14->addItem(verticalSpacer_17);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_18);

        m_bShowFullScreen = new QPushButton(m_zoneInput);
        m_bShowFullScreen->setObjectName(QStringLiteral("m_bShowFullScreen"));
        sizePolicy3.setHeightForWidth(m_bShowFullScreen->sizePolicy().hasHeightForWidth());
        m_bShowFullScreen->setSizePolicy(sizePolicy3);
        m_bShowFullScreen->setMinimumSize(QSize(100, 32));
        m_bShowFullScreen->setMaximumSize(QSize(200, 32));
        m_bShowFullScreen->setCursor(QCursor(Qt::PointingHandCursor));
        m_bShowFullScreen->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:!hover{\n"
"border: none;\n"
"border-radius: 2px;\n"
"font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 14px;\n"
"background-color: #0e88eb;\n"
"color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border: none;\n"
"border-radius: 2px;\n"
"font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 14px;\n"
"background-color: #0f8ff7;\n"
"color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover:pressed{\n"
"border: none;\n"
"border-radius: 2px;\n"
"font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 14px;\n"
"background-color: #0d80de;\n"
"color: #ffffff;\n"
"}"));

        horizontalLayout_14->addWidget(m_bShowFullScreen);

        horizontalSpacer_20 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_20);


        verticalLayout_14->addLayout(horizontalLayout_14);

        verticalSpacer_18 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_14->addItem(verticalSpacer_18);


        verticalLayout_13->addLayout(verticalLayout_14);


        horizontalLayout2->addWidget(m_zoneInput);

        horizontalLayout2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout2);

        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(3, 1);

        verticalLayout_18->addLayout(verticalLayout);


        retranslateUi(ZegoVideoTalkDialog);

        m_tabCommonAndUserList->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ZegoVideoTalkDialog);
    } // setupUi

    void retranslateUi(QDialog *ZegoVideoTalkDialog)
    {
        ZegoVideoTalkDialog->setWindowTitle(QApplication::translate("ZegoVideoTalkDialog", "ZegoVideoTalkDialog", Q_NULLPTR));
        m_lbRoomName->setText(QApplication::translate("ZegoVideoTalkDialog", "Mode", Q_NULLPTR));
        m_bMin->setText(QString());
        m_bMax->setText(QString());
        m_bClose->setText(QString());
        m_tabCommonAndUserList->setTabText(m_tabCommonAndUserList->indexOf(m_tabContact), QApplication::translate("ZegoVideoTalkDialog", "\346\227\245\345\277\227", Q_NULLPTR));
        m_tabCommonAndUserList->setTabText(m_tabCommonAndUserList->indexOf(m_tabMember), QApplication::translate("ZegoVideoTalkDialog", "\346\210\220\345\221\230(0)", Q_NULLPTR));
        m_lbEquipment_2->setText(QApplication::translate("ZegoVideoTalkDialog", "Equipment", Q_NULLPTR));
        m_lbMircoPhone_2->setText(QApplication::translate("ZegoVideoTalkDialog", "\351\272\246\345\205\213\351\243\216", Q_NULLPTR));
        m_lbCamera_2->setText(QApplication::translate("ZegoVideoTalkDialog", "\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        m_lbOperation_2->setText(QApplication::translate("ZegoVideoTalkDialog", "Operation", Q_NULLPTR));
        m_bCamera->setText(QString());
        m_bProgMircoPhone->setText(QString());
        m_bSound->setText(QString());
        m_bAux->setText(QApplication::translate("ZegoVideoTalkDialog", "\345\274\200\345\220\257\346\267\267\351\237\263", Q_NULLPTR));
        m_bCapture->setText(QApplication::translate("ZegoVideoTalkDialog", "\345\243\260\345\215\241\351\207\207\351\233\206", Q_NULLPTR));
        m_bShowFullScreen->setText(QApplication::translate("ZegoVideoTalkDialog", "\345\205\250\345\261\217\346\230\276\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZegoVideoTalkDialog: public Ui_ZegoVideoTalkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEGOVIDEOTALKDIALOG_H
