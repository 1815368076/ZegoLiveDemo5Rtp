/********************************************************************************
** Form generated from reading UI file 'ZegoMainDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEGOMAINDIALOG_H
#define UI_ZEGOMAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ZegoProgressIndicator.h>

QT_BEGIN_NAMESPACE

class Ui_ZegoMainDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QWidget *m_zoneTitle;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_lbTitle;
    QFrame *m_lineVer;
    QLabel *m_lbTitleVersion;
    QPushButton *m_bJumpToNet;
    QPushButton *m_bMin;
    QPushButton *m_bClose;
    QHBoxLayout *horizontalLayout_4;
    QWidget *m_zoneCreateRoom;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *m_lbCreateRoom;
    QSpacerItem *verticalSpacer;
    QLabel *m_lbName;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *m_edRoomName;
    QSpacerItem *verticalSpacer_3;
    QLabel *m_lbMode;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout;
    QPushButton *m_bMixMode;
    QPushButton *m_bSingleMode;
    QPushButton *m_bMultiMode;
    QSpacerItem *verticalSpacer_5;
    QFrame *m_lineBeforeCreate;
    QPushButton *m_bCreateRoom;
    QVBoxLayout *verticalLayout;
    QWidget *m_zoneRoomList;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *m_TitleList;
    ZegoProgressIndicator *m_progIndicator;
    QPushButton *m_bRefreshRoomList;
    QTableView *m_roomList;
    QFrame *m_lineSpread;
    QWidget *m_zoneSettings;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *m_tabSettings;
    QWidget *m_tabVideoConfig;
    QVBoxLayout *verticalLayout_16;
    QFrame *m_lineVideoConfig;
    QFrame *m_lineLongVideoConfig;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_14;
    QSpacerItem *verticalSpacer_19;
    QPushButton *m_bExtremelyHigh;
    QPushButton *m_bSuperHigh;
    QPushButton *m_bHigh;
    QPushButton *m_bStandard;
    QPushButton *m_bLow;
    QPushButton *m_bSuperLow;
    QPushButton *m_bCustom;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_15;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_6;
    QLabel *m_lbResolution;
    QLabel *m_lbValueResolution;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *m_bResolutionDown;
    QSlider *m_sliderResolution;
    QPushButton *m_bResolutionUp;
    QSpacerItem *verticalSpacer_14;
    QHBoxLayout *horizontalLayout_9;
    QLabel *m_lbFPS;
    QLabel *m_lbValueFPS;
    QSpacerItem *verticalSpacer_15;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *m_bFPSDown;
    QSlider *m_sliderFPS;
    QPushButton *m_bFPSUp;
    QSpacerItem *verticalSpacer_16;
    QHBoxLayout *horizontalLayout_11;
    QLabel *m_lbBitrate;
    QLabel *m_lbValueBitrate;
    QSpacerItem *verticalSpacer_17;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *m_bBitrateDown;
    QSlider *m_sliderBitrate;
    QPushButton *m_bBitrateUp;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *horizontalSpacer_7;
    QWidget *m_tabExtraSettings;
    QVBoxLayout *verticalLayout_22;
    QFrame *m_lineExtraSettings;
    QFrame *m_lineLongExtraSettings;
    QHBoxLayout *horizontalLayout_27;
    QSpacerItem *horizontalSpacer_15;
    QVBoxLayout *verticalLayout_17;
    QSpacerItem *verticalSpacer_21;
    QLabel *m_lbEnvironment;
    QSpacerItem *verticalSpacer_22;
    QHBoxLayout *horizontalLayout_14;
    QLabel *m_lbTestEnv;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *m_switchTestEnv;
    QSpacerItem *horizontalSpacer_28;
    QLabel *m_lbSurfaceMerge;
    QSpacerItem *horizontalSpacer_29;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *m_switchSurfaceMerge;
    QSpacerItem *verticalSpacer_23;
    QFormLayout *formLayout_5;
    QLabel *m_lbAPPID;
    QLineEdit *m_strEdAPPID;
    QSpacerItem *verticalSpacer_24;
    QFormLayout *formLayout_6;
    QLabel *m_lbAPPSign;
    QLineEdit *m_strEdAPPSign;
    QSpacerItem *verticalSpacer_33;
    QSpacerItem *horizontalSpacer_17;
    QVBoxLayout *verticalLayout_21;
    QSpacerItem *verticalSpacer_25;
    QLabel *m_lbAdvanced;
    QSpacerItem *verticalSpacer_26;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_15;
    QLabel *m_lbCapture;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *m_switchCapture;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_16;
    QLabel *m_lbFilter;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *m_switchFilter;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_17;
    QLabel *m_lbHardDecode;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *m_switchHardDecode;
    QSpacerItem *verticalSpacer_27;
    QHBoxLayout *horizontalLayout_25;
    QHBoxLayout *horizontalLayout_18;
    QLabel *m_lbRender;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *m_switchRender;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_19;
    QLabel *m_lbHardCode;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *m_switchHardCode;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_20;
    QLabel *m_lbAutoBitrate;
    QSpacerItem *horizontalSpacer_22;
    QPushButton *m_switchAutoBitrate;
    QSpacerItem *verticalSpacer_28;
    QHBoxLayout *horizontalLayout_26;
    QVBoxLayout *verticalLayout_18;
    QLabel *m_lbAudioLeft;
    QSpacerItem *verticalSpacer_29;
    QHBoxLayout *horizontalLayout_21;
    QLabel *m_lbMicAudio;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *m_switchMicAudio;
    QSpacerItem *horizontalSpacer_24;
    QVBoxLayout *verticalLayout_19;
    QLabel *m_lbTime;
    QSpacerItem *verticalSpacer_30;
    QHBoxLayout *horizontalLayout_22;
    QLabel *m_lbTimeCount;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *m_switchTimeCount;
    QSpacerItem *horizontalSpacer_27;
    QVBoxLayout *verticalLayout_20;
    QLabel *m_lbAudioRight;
    QSpacerItem *verticalSpacer_31;
    QHBoxLayout *horizontalLayout_23;
    QLabel *m_lbNational;
    QSpacerItem *horizontalSpacer_26;
    QPushButton *m_switchNational;
    QSpacerItem *verticalSpacer_34;
    QSpacerItem *horizontalSpacer_16;
    QWidget *m_tabUserSettings;
    QVBoxLayout *verticalLayout_13;
    QFrame *m_lineUserSettings;
    QVBoxLayout *verticalLayout_12;
    QFrame *m_lineLongUserSettings;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_7;
    QLabel *m_lbAccount;
    QSpacerItem *verticalSpacer_10;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout;
    QLabel *m_lbUserId;
    QLineEdit *m_strEdUserId;
    QFormLayout *formLayout_2;
    QLabel *m_lbUserName;
    QLineEdit *m_strEdUserName;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_8;
    QLabel *m_lbEquipment;
    QSpacerItem *verticalSpacer_11;
    QVBoxLayout *verticalLayout_9;
    QFormLayout *formLayout_3;
    QLabel *m_lbMircoPhone;
    QComboBox *m_cbMircoPhone;
    QFormLayout *formLayout_4;
    QLabel *m_lbCamera;
    QComboBox *m_cbCamera;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *m_lbVersion;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_bUploadLog;
    QSpacerItem *horizontalSpacer_2;
    QLabel *m_lbTips;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_32;

    void setupUi(QDialog *ZegoMainDialog)
    {
        if (ZegoMainDialog->objectName().isEmpty())
            ZegoMainDialog->setObjectName(QStringLiteral("ZegoMainDialog"));
        ZegoMainDialog->resize(934, 623);
        ZegoMainDialog->setStyleSheet(QStringLiteral("background-color: #ffffff;"));
        verticalLayout_6 = new QVBoxLayout(ZegoMainDialog);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        m_zoneTitle = new QWidget(ZegoMainDialog);
        m_zoneTitle->setObjectName(QStringLiteral("m_zoneTitle"));
        m_zoneTitle->setStyleSheet(QLatin1String("QWidget#m_zoneTitle{\n"
"	background-color: #0e88eb;\n"
" }"));
        horizontalLayout_3 = new QHBoxLayout(m_zoneTitle);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_lbTitle = new QLabel(m_zoneTitle);
        m_lbTitle->setObjectName(QStringLiteral("m_lbTitle"));
        m_lbTitle->setMinimumSize(QSize(117, 0));
        m_lbTitle->setMaximumSize(QSize(117, 16777215));
        m_lbTitle->setStyleSheet(QString::fromUtf8("QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	 font-size: 16px;\n"
"     color: #ffffff;\n"
"     background-color: #0e88eb;\n"
" }"));

        horizontalLayout_2->addWidget(m_lbTitle);

        m_lineVer = new QFrame(m_zoneTitle);
        m_lineVer->setObjectName(QStringLiteral("m_lineVer"));
        m_lineVer->setMinimumSize(QSize(1, 20));
        m_lineVer->setMaximumSize(QSize(1, 20));
        m_lineVer->setFrameShape(QFrame::VLine);
        m_lineVer->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(m_lineVer);

        m_lbTitleVersion = new QLabel(m_zoneTitle);
        m_lbTitleVersion->setObjectName(QStringLiteral("m_lbTitleVersion"));
        m_lbTitleVersion->setMinimumSize(QSize(0, 40));
        m_lbTitleVersion->setMaximumSize(QSize(16777215, 40));
        m_lbTitleVersion->setStyleSheet(QString::fromUtf8("QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	 font-size: 16px;\n"
"     color: #ffffff;\n"
"     background-color: #0e88eb;\n"
" }"));

        horizontalLayout_2->addWidget(m_lbTitleVersion);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        m_bJumpToNet = new QPushButton(m_zoneTitle);
        m_bJumpToNet->setObjectName(QStringLiteral("m_bJumpToNet"));
        m_bJumpToNet->setMinimumSize(QSize(40, 40));
        m_bJumpToNet->setMaximumSize(QSize(40, 40));
        m_bJumpToNet->setCursor(QCursor(Qt::WhatsThisCursor));
        m_bJumpToNet->setFocusPolicy(Qt::ClickFocus);
        m_bJumpToNet->setStyleSheet(QLatin1String("QPushButton{\n"
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
        icon.addFile(QStringLiteral("Resources/images/official.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_bJumpToNet->setIcon(icon);
        m_bJumpToNet->setFlat(true);

        horizontalLayout_3->addWidget(m_bJumpToNet);

        m_bMin = new QPushButton(m_zoneTitle);
        m_bMin->setObjectName(QStringLiteral("m_bMin"));
        m_bMin->setMinimumSize(QSize(40, 40));
        m_bMin->setMaximumSize(QSize(40, 40));
        m_bMin->setFocusPolicy(Qt::ClickFocus);
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
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/images/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_bMin->setIcon(icon1);
        m_bMin->setFlat(true);

        horizontalLayout_3->addWidget(m_bMin);

        m_bClose = new QPushButton(m_zoneTitle);
        m_bClose->setObjectName(QStringLiteral("m_bClose"));
        m_bClose->setMinimumSize(QSize(50, 40));
        m_bClose->setMaximumSize(QSize(50, 40));
        m_bClose->setFocusPolicy(Qt::ClickFocus);
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
        icon2.addFile(QStringLiteral("Resources/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_bClose->setIcon(icon2);
        m_bClose->setFlat(false);

        horizontalLayout_3->addWidget(m_bClose);


        verticalLayout_6->addWidget(m_zoneTitle);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        m_zoneCreateRoom = new QWidget(ZegoMainDialog);
        m_zoneCreateRoom->setObjectName(QStringLiteral("m_zoneCreateRoom"));
        m_zoneCreateRoom->setMinimumSize(QSize(280, 0));
        m_zoneCreateRoom->setMaximumSize(QSize(280, 16777215));
        m_zoneCreateRoom->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: rgb(52, 56, 65);\n"
" }"));
        verticalLayout_5 = new QVBoxLayout(m_zoneCreateRoom);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(20, -1, 20, 0);
        m_lbCreateRoom = new QLabel(m_zoneCreateRoom);
        m_lbCreateRoom->setObjectName(QStringLiteral("m_lbCreateRoom"));
        m_lbCreateRoom->setMinimumSize(QSize(0, 64));
        m_lbCreateRoom->setMaximumSize(QSize(16777215, 64));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_lbCreateRoom->setFont(font);
        m_lbCreateRoom->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 24px;\n"
"    border: none;\n"
"    text-align: left;\n"
"    color: #e6e6e6;\n"
" }"));

        verticalLayout_4->addWidget(m_lbCreateRoom);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        m_lbName = new QLabel(m_zoneCreateRoom);
        m_lbName->setObjectName(QStringLiteral("m_lbName"));
        m_lbName->setMinimumSize(QSize(0, 20));
        m_lbName->setMaximumSize(QSize(16777215, 20));
        m_lbName->setFont(font);
        m_lbName->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"    text-align: left;\n"
"    border: none;\n"
"    color: #e6e6e6;\n"
"    \n"
" }"));

        verticalLayout_4->addWidget(m_lbName);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        m_edRoomName = new QLineEdit(m_zoneCreateRoom);
        m_edRoomName->setObjectName(QStringLiteral("m_edRoomName"));
        m_edRoomName->setMinimumSize(QSize(0, 40));
        m_edRoomName->setMaximumSize(QSize(16777215, 40));
        m_edRoomName->setFocusPolicy(Qt::ClickFocus);
        m_edRoomName->setStyleSheet(QString::fromUtf8("QLineEdit#m_edRoomName{\n"
"     padding-left: 20px;\n"
" }\n"
"\n"
" QLineEdit:!hover#m_edRoomName{\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #999999;\n"
" }\n"
"\n"
" QLineEdit:hover#m_edRoomName{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #999999;\n"
" }\n"
"\n"
" QLineEdit:focus#m_edRoomName{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #ffffff;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_4->addWidget(m_edRoomName);

        verticalSpacer_3 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);

        m_lbMode = new QLabel(m_zoneCreateRoom);
        m_lbMode->setObjectName(QStringLiteral("m_lbMode"));
        m_lbMode->setMinimumSize(QSize(0, 20));
        m_lbMode->setMaximumSize(QSize(16777215, 20));
        m_lbMode->setFont(font);
        m_lbMode->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"    text-align: left;\n"
"    border: none;\n"
"    color: #e6e6e6;\n"
" }"));

        verticalLayout_4->addWidget(m_lbMode);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_4);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(16);
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        m_bMixMode = new QPushButton(m_zoneCreateRoom);
        m_bMixMode->setObjectName(QStringLiteral("m_bMixMode"));
        m_bMixMode->setMinimumSize(QSize(0, 50));
        m_bMixMode->setMaximumSize(QSize(16777215, 50));
        m_bMixMode->setFocusPolicy(Qt::ClickFocus);
        m_bMixMode->setStyleSheet(QString::fromUtf8(" QPushButton:!hover#m_bSingleMode, \n"
" QPushButton:!hover#m_bMixMode, \n"
" QPushButton:!hover#m_bMultiMode{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"     border: 1px solid #b2b2b2;\n"
"     border-radius: 2px;\n"
"     background-color: #343841;\n"
"     color: #e6e6e6;\n"
" }\n"
"\n"
" QPushButton:hover#m_bSingleMode, \n"
" QPushButton:hover#m_bMixMode, \n"
" QPushButton:hover#m_bMultiMode{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #343841;\n"
"     color: #0e88eb;   \n"
" }\n"
"\n"
" QPushButton:checked#m_bSingleMode, \n"
" QPushButton:checked#m_bMixMode, \n"
" QPushButton:checked#m_bMultiMode{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;  \n"
" }"));
        m_bMixMode->setCheckable(true);

        gridLayout->addWidget(m_bMixMode, 0, 1, 1, 1);

        m_bSingleMode = new QPushButton(m_zoneCreateRoom);
        m_bSingleMode->setObjectName(QStringLiteral("m_bSingleMode"));
        m_bSingleMode->setMinimumSize(QSize(0, 50));
        m_bSingleMode->setMaximumSize(QSize(16777215, 50));
        m_bSingleMode->setFocusPolicy(Qt::ClickFocus);
        m_bSingleMode->setContextMenuPolicy(Qt::DefaultContextMenu);
        m_bSingleMode->setStyleSheet(QString::fromUtf8(" QPushButton:!hover#m_bSingleMode, \n"
" QPushButton:!hover#m_bMixMode, \n"
" QPushButton:!hover#m_bMultiMode{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"     border: 1px solid #b2b2b2;\n"
"     border-radius: 2px;\n"
"     background-color: #343841;\n"
"     color: #e6e6e6;\n"
" }\n"
"\n"
" QPushButton:hover#m_bSingleMode, \n"
" QPushButton:hover#m_bMixMode, \n"
" QPushButton:hover#m_bMultiMode{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #343841;\n"
"     color: #0e88eb;   \n"
" }\n"
"\n"
" QPushButton:checked#m_bSingleMode, \n"
" QPushButton:checked#m_bMixMode, \n"
" QPushButton:checked#m_bMultiMode{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;  \n"
" }"));
        m_bSingleMode->setCheckable(true);
        m_bSingleMode->setAutoDefault(true);

        gridLayout->addWidget(m_bSingleMode, 0, 0, 1, 1);

        m_bMultiMode = new QPushButton(m_zoneCreateRoom);
        m_bMultiMode->setObjectName(QStringLiteral("m_bMultiMode"));
        m_bMultiMode->setMinimumSize(QSize(0, 50));
        m_bMultiMode->setMaximumSize(QSize(16777215, 50));
        m_bMultiMode->setFocusPolicy(Qt::ClickFocus);
        m_bMultiMode->setStyleSheet(QString::fromUtf8(" QPushButton:!hover#m_bSingleMode, \n"
" QPushButton:!hover#m_bMixMode, \n"
" QPushButton:!hover#m_bMultiMode{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"     border: 1px solid #b2b2b2;\n"
"     border-radius: 2px;\n"
"     background-color: #343841;\n"
"     color: #e6e6e6;\n"
" }\n"
"\n"
" QPushButton:hover#m_bSingleMode, \n"
" QPushButton:hover#m_bMixMode, \n"
" QPushButton:hover#m_bMultiMode{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #343841;\n"
"     color: #0e88eb;   \n"
" }\n"
"\n"
" QPushButton:checked#m_bSingleMode, \n"
" QPushButton:checked#m_bMixMode, \n"
" QPushButton:checked#m_bMultiMode{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;  \n"
" }"));
        m_bMultiMode->setCheckable(true);

        gridLayout->addWidget(m_bMultiMode, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);


        verticalLayout_5->addLayout(verticalLayout_4);

        m_lineBeforeCreate = new QFrame(m_zoneCreateRoom);
        m_lineBeforeCreate->setObjectName(QStringLiteral("m_lineBeforeCreate"));
        m_lineBeforeCreate->setMinimumSize(QSize(0, 1));
        m_lineBeforeCreate->setMaximumSize(QSize(16777215, 1));
        m_lineBeforeCreate->setStyleSheet(QLatin1String("QFrame#m_lineBeforeCreate{\n"
"     background-color: #b2b2b2;\n"
" }"));
        m_lineBeforeCreate->setFrameShape(QFrame::HLine);
        m_lineBeforeCreate->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(m_lineBeforeCreate);

        m_bCreateRoom = new QPushButton(m_zoneCreateRoom);
        m_bCreateRoom->setObjectName(QStringLiteral("m_bCreateRoom"));
        m_bCreateRoom->setMinimumSize(QSize(0, 60));
        m_bCreateRoom->setMaximumSize(QSize(16777215, 60));
        m_bCreateRoom->setFocusPolicy(Qt::StrongFocus);
        m_bCreateRoom->setStyleSheet(QString::fromUtf8("QPushButton:!hover#m_bCreateRoom{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 18px;\n"
"     border: 1px solid #343841;\n"
"     background-color: #343841;\n"
"     color: #e6e6e6;\n"
" }\n"
"\n"
" QPushButton:hover:!pressed#m_bCreateRoom{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 18px;\n"
"     border: 1px solid #343841;\n"
"     background-color: #343841;\n"
"     color: #0e88eb;\n"
" }\n"
"\n"
" QPushButton:hover:pressed#m_bCreateRoom{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 18px;\n"
"     border: 1px solid #343841;\n"
"     background-color: #343841;\n"
"     color: #0d80de;\n"
" }"));

        verticalLayout_5->addWidget(m_bCreateRoom);

        verticalLayout_5->setStretch(0, 526);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 60);

        horizontalLayout_4->addWidget(m_zoneCreateRoom);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        m_zoneRoomList = new QWidget(ZegoMainDialog);
        m_zoneRoomList->setObjectName(QStringLiteral("m_zoneRoomList"));
        m_zoneRoomList->setMinimumSize(QSize(650, 338));
        m_zoneRoomList->setMaximumSize(QSize(16777215, 16777215));
        m_zoneRoomList->setStyleSheet(QLatin1String("QWidget{\n"
"    background-color: #ffffff;\n"
" }"));
        verticalLayout_3 = new QVBoxLayout(m_zoneRoomList);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, -1, 20, -1);
        m_TitleList = new QLabel(m_zoneRoomList);
        m_TitleList->setObjectName(QStringLiteral("m_TitleList"));
        m_TitleList->setMinimumSize(QSize(0, 64));
        m_TitleList->setMaximumSize(QSize(16777215, 64));
        m_TitleList->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 24px;\n"
"    border: none;\n"
"    text-align: left;\n"
"    color: #333333;\n"
" }"));

        horizontalLayout->addWidget(m_TitleList);

        m_progIndicator = new ZegoProgressIndicator(m_zoneRoomList);
        m_progIndicator->setObjectName(QStringLiteral("m_progIndicator"));
        m_progIndicator->setMinimumSize(QSize(20, 20));
        m_progIndicator->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(m_progIndicator);

        m_bRefreshRoomList = new QPushButton(m_zoneRoomList);
        m_bRefreshRoomList->setObjectName(QStringLiteral("m_bRefreshRoomList"));
        m_bRefreshRoomList->setMinimumSize(QSize(55, 20));
        m_bRefreshRoomList->setMaximumSize(QSize(55, 20));
        m_bRefreshRoomList->setCursor(QCursor(Qt::PointingHandCursor));
        m_bRefreshRoomList->setFocusPolicy(Qt::ClickFocus);
        m_bRefreshRoomList->setLayoutDirection(Qt::RightToLeft);
        m_bRefreshRoomList->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"     color: #0e88eb;\n"
"     text-align: top;\n"
"     border: none;\n"
" }\n"
""));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_bRefreshRoomList->setIcon(icon3);
        m_bRefreshRoomList->setFlat(true);

        horizontalLayout->addWidget(m_bRefreshRoomList);


        verticalLayout_2->addLayout(horizontalLayout);

        m_roomList = new QTableView(m_zoneRoomList);
        m_roomList->setObjectName(QStringLiteral("m_roomList"));
        m_roomList->setMinimumSize(QSize(0, 271));
        m_roomList->setMaximumSize(QSize(16777215, 16777215));
        m_roomList->setStyleSheet(QString::fromUtf8("QTableView{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"     color: #333333; \n"
"     margin-left: 10px;\n"
"     \n"
"     background-color: #ffffff;\n"
"     \n"
" }\n"
"\n"
"QTableView::item{\n"
"     border: none;\n"
"     border-bottom: 1px solid #e6e6e6;\n"
"     padding: 10px;\n"
"\n"
" }\n"
"\n"
"QTableView:item:selected{\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;\n"
"}\n"
"QHeaderView{\n"
"     font-size: 14px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     color: #333333;\n"
"     border: none;\n"
"     padding-left: 10px;\n"
"     border-bottom: 1px solid #e6e6e6;\n"
"}\n"
"\n"
" "));
        m_roomList->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        m_roomList->setShowGrid(false);

        verticalLayout_2->addWidget(m_roomList);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addWidget(m_zoneRoomList);

        m_lineSpread = new QFrame(ZegoMainDialog);
        m_lineSpread->setObjectName(QStringLiteral("m_lineSpread"));
        m_lineSpread->setMinimumSize(QSize(630, 1));
        m_lineSpread->setMaximumSize(QSize(16777215, 1));
        m_lineSpread->setStyleSheet(QLatin1String("background-color: #0e88eb;\n"
"margin-left: 10px;\n"
"margin-right: 10px;"));
        m_lineSpread->setFrameShape(QFrame::HLine);
        m_lineSpread->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(m_lineSpread);

        m_zoneSettings = new QWidget(ZegoMainDialog);
        m_zoneSettings->setObjectName(QStringLiteral("m_zoneSettings"));
        m_zoneSettings->setMinimumSize(QSize(650, 228));
        m_zoneSettings->setMaximumSize(QSize(16777215, 228));
        m_zoneSettings->setStyleSheet(QLatin1String("QWidget{\n"
"    background-color: #ffffff;\n"
" }"));
        verticalLayout_7 = new QVBoxLayout(m_zoneSettings);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        m_tabSettings = new QTabWidget(m_zoneSettings);
        m_tabSettings->setObjectName(QStringLiteral("m_tabSettings"));
        m_tabSettings->setFocusPolicy(Qt::NoFocus);
        m_tabSettings->setAutoFillBackground(false);
        m_tabSettings->setStyleSheet(QString::fromUtf8("QTabWidget::pane{\n"
"    border: none;\n"
" }\n"
"\n"
" QTabBar::tab:!selected{\n"
"     width: 210px;\n"
"	 height: 40px;\n"
"	 font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #333333;\n"
"	 background-color: #ffffff;\n"
" }\n"
"\n"
" QTabBar::tab:selected{\n"
"     width: 210px;\n"
"	 height: 39px;\n"
"	 font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #0e88eb;\n"
"	 background-color: #ffffff;\n"
" }"));
        m_tabVideoConfig = new QWidget();
        m_tabVideoConfig->setObjectName(QStringLiteral("m_tabVideoConfig"));
        m_tabVideoConfig->setStyleSheet(QStringLiteral("background-color: #ffffff;"));
        verticalLayout_16 = new QVBoxLayout(m_tabVideoConfig);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        m_lineVideoConfig = new QFrame(m_tabVideoConfig);
        m_lineVideoConfig->setObjectName(QStringLiteral("m_lineVideoConfig"));
        m_lineVideoConfig->setMinimumSize(QSize(0, 2));
        m_lineVideoConfig->setMaximumSize(QSize(16777215, 2));
        m_lineVideoConfig->setStyleSheet(QLatin1String("margin-left: 65px;\n"
"margin-right:505px;\n"
"border: none;\n"
"background-color: #0e88eb;"));
        m_lineVideoConfig->setFrameShape(QFrame::HLine);
        m_lineVideoConfig->setFrameShadow(QFrame::Sunken);

        verticalLayout_16->addWidget(m_lineVideoConfig);

        m_lineLongVideoConfig = new QFrame(m_tabVideoConfig);
        m_lineLongVideoConfig->setObjectName(QStringLiteral("m_lineLongVideoConfig"));
        m_lineLongVideoConfig->setMinimumSize(QSize(0, 1));
        m_lineLongVideoConfig->setMaximumSize(QSize(16777215, 1));
        m_lineLongVideoConfig->setStyleSheet(QLatin1String("margin-left: 10px;\n"
"margin-right: 10px;\n"
"background-color: #f5f5f5;\n"
"border: none;"));
        m_lineLongVideoConfig->setFrameShape(QFrame::HLine);
        m_lineLongVideoConfig->setFrameShadow(QFrame::Sunken);

        verticalLayout_16->addWidget(m_lineLongVideoConfig);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer_5 = new QSpacerItem(32, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalSpacer_19 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_14->addItem(verticalSpacer_19);

        m_bExtremelyHigh = new QPushButton(m_tabVideoConfig);
        m_bExtremelyHigh->setObjectName(QStringLiteral("m_bExtremelyHigh"));
        m_bExtremelyHigh->setMinimumSize(QSize(140, 28));
        m_bExtremelyHigh->setMaximumSize(QSize(140, 28));
        m_bExtremelyHigh->setStyleSheet(QString::fromUtf8("QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 border: none;\n"
" }\n"
"\n"
" QPushButton:hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #0e88eb;\n"
"	 border: none;\n"
"	 background-color: #ffffff;\n"
" }\n"
" \n"
" QPushButton:checked{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 border: none;\n"
"	 background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }"));
        m_bExtremelyHigh->setCheckable(true);

        verticalLayout_14->addWidget(m_bExtremelyHigh);

        m_bSuperHigh = new QPushButton(m_tabVideoConfig);
        m_bSuperHigh->setObjectName(QStringLiteral("m_bSuperHigh"));
        m_bSuperHigh->setMinimumSize(QSize(140, 28));
        m_bSuperHigh->setMaximumSize(QSize(140, 28));
        m_bSuperHigh->setStyleSheet(QString::fromUtf8("QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 border: none;\n"
" }\n"
"\n"
" QPushButton:hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #0e88eb;\n"
"	 border: none;\n"
"	 background-color: #ffffff;\n"
" }\n"
" \n"
" QPushButton:checked{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 border: none;\n"
"	 background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }"));
        m_bSuperHigh->setCheckable(true);

        verticalLayout_14->addWidget(m_bSuperHigh);

        m_bHigh = new QPushButton(m_tabVideoConfig);
        m_bHigh->setObjectName(QStringLiteral("m_bHigh"));
        m_bHigh->setMinimumSize(QSize(140, 28));
        m_bHigh->setMaximumSize(QSize(140, 28));
        m_bHigh->setStyleSheet(QString::fromUtf8("QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 border: none;\n"
" }\n"
"\n"
" QPushButton:hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #0e88eb;\n"
"	 border: none;\n"
"	 background-color: #ffffff;\n"
" }\n"
" \n"
" QPushButton:checked{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 border: none;\n"
"	 background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }"));
        m_bHigh->setCheckable(true);

        verticalLayout_14->addWidget(m_bHigh);

        m_bStandard = new QPushButton(m_tabVideoConfig);
        m_bStandard->setObjectName(QStringLiteral("m_bStandard"));
        m_bStandard->setMinimumSize(QSize(140, 28));
        m_bStandard->setMaximumSize(QSize(140, 28));
        m_bStandard->setStyleSheet(QString::fromUtf8("QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 border: none;\n"
" }\n"
"\n"
" QPushButton:hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #0e88eb;\n"
"	 border: none;\n"
"	 background-color: #ffffff;\n"
" }\n"
" \n"
" QPushButton:checked{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 border: none;\n"
"	 background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }"));
        m_bStandard->setCheckable(true);

        verticalLayout_14->addWidget(m_bStandard);

        m_bLow = new QPushButton(m_tabVideoConfig);
        m_bLow->setObjectName(QStringLiteral("m_bLow"));
        m_bLow->setMinimumSize(QSize(140, 28));
        m_bLow->setMaximumSize(QSize(140, 28));
        m_bLow->setStyleSheet(QString::fromUtf8("QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 border: none;\n"
" }\n"
"\n"
" QPushButton:hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #0e88eb;\n"
"	 border: none;\n"
"	 background-color: #ffffff;\n"
" }\n"
" \n"
" QPushButton:checked{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 border: none;\n"
"	 background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }"));
        m_bLow->setCheckable(true);

        verticalLayout_14->addWidget(m_bLow);

        m_bSuperLow = new QPushButton(m_tabVideoConfig);
        m_bSuperLow->setObjectName(QStringLiteral("m_bSuperLow"));
        m_bSuperLow->setMinimumSize(QSize(140, 28));
        m_bSuperLow->setMaximumSize(QSize(140, 28));
        m_bSuperLow->setStyleSheet(QString::fromUtf8("QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 border: none;\n"
" }\n"
"\n"
" QPushButton:hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #0e88eb;\n"
"	 border: none;\n"
"	 background-color: #ffffff;\n"
" }\n"
" \n"
" QPushButton:checked{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 border: none;\n"
"	 background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }"));
        m_bSuperLow->setCheckable(true);

        verticalLayout_14->addWidget(m_bSuperLow);

        m_bCustom = new QPushButton(m_tabVideoConfig);
        m_bCustom->setObjectName(QStringLiteral("m_bCustom"));
        m_bCustom->setMinimumSize(QSize(140, 28));
        m_bCustom->setMaximumSize(QSize(140, 28));
        m_bCustom->setStyleSheet(QString::fromUtf8("QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
"	 background-color: #ffffff;\n"
"	 border: none;\n"
" }\n"
"\n"
" QPushButton:hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #0e88eb;\n"
"	 border: none;\n"
"	 background-color: #ffffff;\n"
" }\n"
" \n"
" QPushButton:checked{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 border: none;\n"
"	 background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }"));
        m_bCustom->setCheckable(true);

        verticalLayout_14->addWidget(m_bCustom);


        horizontalLayout_13->addLayout(verticalLayout_14);

        horizontalSpacer_6 = new QSpacerItem(84, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, -1, -1);
        verticalSpacer_12 = new QSpacerItem(22, 22, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        m_lbResolution = new QLabel(m_tabVideoConfig);
        m_lbResolution->setObjectName(QStringLiteral("m_lbResolution"));
        m_lbResolution->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_6->addWidget(m_lbResolution);

        m_lbValueResolution = new QLabel(m_tabVideoConfig);
        m_lbValueResolution->setObjectName(QStringLiteral("m_lbValueResolution"));
        m_lbValueResolution->setLayoutDirection(Qt::LeftToRight);
        m_lbValueResolution->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));
        m_lbValueResolution->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(m_lbValueResolution);


        verticalLayout_15->addLayout(horizontalLayout_6);

        verticalSpacer_13 = new QSpacerItem(12, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_13);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        m_bResolutionDown = new QPushButton(m_tabVideoConfig);
        m_bResolutionDown->setObjectName(QStringLiteral("m_bResolutionDown"));
        m_bResolutionDown->setMinimumSize(QSize(15, 15));
        m_bResolutionDown->setMaximumSize(QSize(15, 15));
        m_bResolutionDown->setFocusPolicy(Qt::TabFocus);
        m_bResolutionDown->setLayoutDirection(Qt::LeftToRight);
        m_bResolutionDown->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
"     border-image: url(:/Resources/images/sub_default.png);\n"
" }\n"
"\n"
"QPushButton:hover:!pressed{\n"
"     border-image: url(:/Resources/images/sub_hover.png);\n"
" }\n"
"\n"
"QPushButton:hover:pressed{\n"
"     border-image: url(:/Resources/images/sub_pressed.png);\n"
" }\n"
"\n"
""));
        m_bResolutionDown->setIconSize(QSize(15, 15));
        m_bResolutionDown->setFlat(true);

        horizontalLayout_8->addWidget(m_bResolutionDown);

        m_sliderResolution = new QSlider(m_tabVideoConfig);
        m_sliderResolution->setObjectName(QStringLiteral("m_sliderResolution"));
        m_sliderResolution->setMinimumSize(QSize(240, 0));
        m_sliderResolution->setStyleSheet(QLatin1String("QSlider::groove:horizontal{\n"
"     border: none;\n"
"	 height: 1px;\n"
" }\n"
"\n"
" QSlider::handle:horizontal:!hover{\n"
"     border: none;\n"
"	 width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_default.png);\n"
" }\n"
"\n"
" QSlider::handle:horizontal:hover:!pressed{\n"
"     border: none;\n"
"	 width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_hover.png);\n"
" }\n"
"\n"
" QSlider::handle:horizontal:hover:pressed{\n"
"     border: none;\n"
"     width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_pressed.png);\n"
" }\n"
"\n"
" QSlider::add-page:horizontal{\n"
"     background-color: #e6e6e6;\n"
"	 \n"
" }\n"
"\n"
" QSlider::sub-page:horizontal{\n"
"     background-color: #0e88eb;\n"
"	 \n"
" }"));
        m_sliderResolution->setMaximum(9);
        m_sliderResolution->setPageStep(1);
        m_sliderResolution->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(m_sliderResolution);

        m_bResolutionUp = new QPushButton(m_tabVideoConfig);
        m_bResolutionUp->setObjectName(QStringLiteral("m_bResolutionUp"));
        m_bResolutionUp->setMinimumSize(QSize(15, 15));
        m_bResolutionUp->setMaximumSize(QSize(15, 15));
        m_bResolutionUp->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
"     border-image: url(:/Resources/images/add_default.png);\n"
" }\n"
"\n"
"QPushButton:hover:!pressed{\n"
"     border-image: url(:/Resources/images/add_hover.png);\n"
" }\n"
"\n"
"QPushButton:hover:pressed{\n"
"     border-image: url(:/Resources/images/add_pressed.png);\n"
" }"));
        m_bResolutionUp->setFlat(true);

        horizontalLayout_8->addWidget(m_bResolutionUp);


        verticalLayout_15->addLayout(horizontalLayout_8);

        verticalSpacer_14 = new QSpacerItem(16, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_14);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        m_lbFPS = new QLabel(m_tabVideoConfig);
        m_lbFPS->setObjectName(QStringLiteral("m_lbFPS"));
        m_lbFPS->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_9->addWidget(m_lbFPS);

        m_lbValueFPS = new QLabel(m_tabVideoConfig);
        m_lbValueFPS->setObjectName(QStringLiteral("m_lbValueFPS"));
        m_lbValueFPS->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));
        m_lbValueFPS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(m_lbValueFPS);


        verticalLayout_15->addLayout(horizontalLayout_9);

        verticalSpacer_15 = new QSpacerItem(12, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_15);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        m_bFPSDown = new QPushButton(m_tabVideoConfig);
        m_bFPSDown->setObjectName(QStringLiteral("m_bFPSDown"));
        m_bFPSDown->setMinimumSize(QSize(15, 15));
        m_bFPSDown->setMaximumSize(QSize(15, 15));
        m_bFPSDown->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
"     border-image: url(:/Resources/images/sub_default.png);\n"
" }\n"
"\n"
"QPushButton:hover:!pressed{\n"
"     border-image: url(:/Resources/images/sub_hover.png);\n"
" }\n"
"\n"
"QPushButton:hover:pressed{\n"
"     border-image: url(:/Resources/images/sub_pressed.png);\n"
" }\n"
"\n"
""));
        m_bFPSDown->setFlat(true);

        horizontalLayout_10->addWidget(m_bFPSDown);

        m_sliderFPS = new QSlider(m_tabVideoConfig);
        m_sliderFPS->setObjectName(QStringLiteral("m_sliderFPS"));
        m_sliderFPS->setMinimumSize(QSize(240, 0));
        m_sliderFPS->setStyleSheet(QLatin1String("QSlider::groove:horizontal{\n"
"     border: none;\n"
"	 height: 1px;\n"
" }\n"
"\n"
" QSlider::handle:horizontal:!hover{\n"
"     border: none;\n"
"	 width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_default.png);\n"
" }\n"
"\n"
" QSlider::handle:horizontal:hover:!pressed{\n"
"     border: none;\n"
"	 width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_hover.png);\n"
" }\n"
"\n"
" QSlider::handle:horizontal:hover:pressed{\n"
"     border: none;\n"
"     width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_pressed.png);\n"
" }\n"
"\n"
" QSlider::add-page:horizontal{\n"
"     background-color: #e6e6e6;\n"
"	 \n"
" }\n"
"\n"
" QSlider::sub-page:horizontal{\n"
"     background-color: #0e88eb;\n"
"	 \n"
" }"));
        m_sliderFPS->setMaximum(5);
        m_sliderFPS->setPageStep(1);
        m_sliderFPS->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(m_sliderFPS);

        m_bFPSUp = new QPushButton(m_tabVideoConfig);
        m_bFPSUp->setObjectName(QStringLiteral("m_bFPSUp"));
        m_bFPSUp->setMinimumSize(QSize(15, 15));
        m_bFPSUp->setMaximumSize(QSize(15, 15));
        m_bFPSUp->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
"     border-image: url(:/Resources/images/add_default.png);\n"
" }\n"
"\n"
"QPushButton:hover:!pressed{\n"
"     border-image: url(:/Resources/images/add_hover.png);\n"
" }\n"
"\n"
"QPushButton:hover:pressed{\n"
"     border-image: url(:/Resources/images/add_pressed.png);\n"
" }"));
        m_bFPSUp->setFlat(true);

        horizontalLayout_10->addWidget(m_bFPSUp);


        verticalLayout_15->addLayout(horizontalLayout_10);

        verticalSpacer_16 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_16);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        m_lbBitrate = new QLabel(m_tabVideoConfig);
        m_lbBitrate->setObjectName(QStringLiteral("m_lbBitrate"));
        m_lbBitrate->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_11->addWidget(m_lbBitrate);

        m_lbValueBitrate = new QLabel(m_tabVideoConfig);
        m_lbValueBitrate->setObjectName(QStringLiteral("m_lbValueBitrate"));
        m_lbValueBitrate->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));
        m_lbValueBitrate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(m_lbValueBitrate);


        verticalLayout_15->addLayout(horizontalLayout_11);

        verticalSpacer_17 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_17);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        m_bBitrateDown = new QPushButton(m_tabVideoConfig);
        m_bBitrateDown->setObjectName(QStringLiteral("m_bBitrateDown"));
        m_bBitrateDown->setMinimumSize(QSize(15, 15));
        m_bBitrateDown->setMaximumSize(QSize(15, 15));
        m_bBitrateDown->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
"     border-image: url(:/Resources/images/sub_default.png);\n"
" }\n"
"\n"
"QPushButton:hover:!pressed{\n"
"     border-image: url(:/Resources/images/sub_hover.png);\n"
" }\n"
"\n"
"QPushButton:hover:pressed{\n"
"     border-image: url(:/Resources/images/sub_pressed.png);\n"
" }\n"
"\n"
""));
        m_bBitrateDown->setFlat(true);

        horizontalLayout_12->addWidget(m_bBitrateDown);

        m_sliderBitrate = new QSlider(m_tabVideoConfig);
        m_sliderBitrate->setObjectName(QStringLiteral("m_sliderBitrate"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_sliderBitrate->sizePolicy().hasHeightForWidth());
        m_sliderBitrate->setSizePolicy(sizePolicy);
        m_sliderBitrate->setMinimumSize(QSize(240, 0));
        m_sliderBitrate->setStyleSheet(QLatin1String("QSlider::groove:horizontal{\n"
"     border: none;\n"
"	 height: 1px;\n"
" }\n"
"\n"
" QSlider::handle:horizontal:!hover{\n"
"     border: none;\n"
"	 width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_default.png);\n"
" }\n"
"\n"
" QSlider::handle:horizontal:hover:!pressed{\n"
"     border: none;\n"
"	 width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_hover.png);\n"
" }\n"
"\n"
" QSlider::handle:horizontal:hover:pressed{\n"
"     border: none;\n"
"     width: 11px;\n"
"	 height: 11px;\n"
"	 margin: -5px 0;\n"
"     border-image: url(:/Resources/images/handle_pressed.png);\n"
" }\n"
"\n"
" QSlider::add-page:horizontal{\n"
"     background-color: #e6e6e6;\n"
"	 \n"
" }\n"
"\n"
" QSlider::sub-page:horizontal{\n"
"     background-color: #0e88eb;\n"
"	 \n"
" }"));
        m_sliderBitrate->setMaximum(22);
        m_sliderBitrate->setPageStep(1);
        m_sliderBitrate->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(m_sliderBitrate);

        m_bBitrateUp = new QPushButton(m_tabVideoConfig);
        m_bBitrateUp->setObjectName(QStringLiteral("m_bBitrateUp"));
        m_bBitrateUp->setMinimumSize(QSize(15, 15));
        m_bBitrateUp->setMaximumSize(QSize(15, 15));
        m_bBitrateUp->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
"     border-image: url(:/Resources/images/add_default.png);\n"
" }\n"
"\n"
"QPushButton:hover:!pressed{\n"
"     border-image: url(:/Resources/images/add_hover.png);\n"
" }\n"
"\n"
"QPushButton:hover:pressed{\n"
"     border-image: url(:/Resources/images/add_pressed.png);\n"
" }"));
        m_bBitrateUp->setFlat(true);

        horizontalLayout_12->addWidget(m_bBitrateUp);


        verticalLayout_15->addLayout(horizontalLayout_12);

        verticalSpacer_18 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_18);


        horizontalLayout_13->addLayout(verticalLayout_15);

        horizontalSpacer_7 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_7);


        verticalLayout_16->addLayout(horizontalLayout_13);

        m_tabSettings->addTab(m_tabVideoConfig, QString());
        m_tabExtraSettings = new QWidget();
        m_tabExtraSettings->setObjectName(QStringLiteral("m_tabExtraSettings"));
        verticalLayout_22 = new QVBoxLayout(m_tabExtraSettings);
        verticalLayout_22->setSpacing(0);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        verticalLayout_22->setContentsMargins(0, 0, 0, 0);
        m_lineExtraSettings = new QFrame(m_tabExtraSettings);
        m_lineExtraSettings->setObjectName(QStringLiteral("m_lineExtraSettings"));
        m_lineExtraSettings->setMinimumSize(QSize(0, 2));
        m_lineExtraSettings->setMaximumSize(QSize(16777215, 2));
        m_lineExtraSettings->setStyleSheet(QLatin1String("margin-left: 275px;\n"
"margin-right: 295px;\n"
"background-color: #0e88eb;\n"
"border: none;"));
        m_lineExtraSettings->setFrameShape(QFrame::HLine);
        m_lineExtraSettings->setFrameShadow(QFrame::Sunken);

        verticalLayout_22->addWidget(m_lineExtraSettings);

        m_lineLongExtraSettings = new QFrame(m_tabExtraSettings);
        m_lineLongExtraSettings->setObjectName(QStringLiteral("m_lineLongExtraSettings"));
        m_lineLongExtraSettings->setMinimumSize(QSize(0, 1));
        m_lineLongExtraSettings->setMaximumSize(QSize(16777215, 1));
        m_lineLongExtraSettings->setStyleSheet(QLatin1String("margin-left: 10px;\n"
"margin-right: 10px;\n"
"background-color: #f5f5f5;\n"
"border: none;"));
        m_lineLongExtraSettings->setFrameShape(QFrame::HLine);
        m_lineLongExtraSettings->setFrameShadow(QFrame::Sunken);

        verticalLayout_22->addWidget(m_lineLongExtraSettings);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(0);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_15 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_15);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(-1, -1, -1, 0);
        verticalSpacer_21 = new QSpacerItem(18, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_17->addItem(verticalSpacer_21);

        m_lbEnvironment = new QLabel(m_tabExtraSettings);
        m_lbEnvironment->setObjectName(QStringLiteral("m_lbEnvironment"));
        m_lbEnvironment->setMaximumSize(QSize(16777215, 16777215));
        m_lbEnvironment->setFont(font);
        m_lbEnvironment->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_17->addWidget(m_lbEnvironment);

        verticalSpacer_22 = new QSpacerItem(18, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_17->addItem(verticalSpacer_22);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        m_lbTestEnv = new QLabel(m_tabExtraSettings);
        m_lbTestEnv->setObjectName(QStringLiteral("m_lbTestEnv"));
        m_lbTestEnv->setMaximumSize(QSize(16777215, 16));
        m_lbTestEnv->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_14->addWidget(m_lbTestEnv);

        horizontalSpacer_8 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);

        m_switchTestEnv = new QPushButton(m_tabExtraSettings);
        m_switchTestEnv->setObjectName(QStringLiteral("m_switchTestEnv"));
        m_switchTestEnv->setMinimumSize(QSize(32, 16));
        m_switchTestEnv->setMaximumSize(QSize(32, 16));
        m_switchTestEnv->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchTestEnv->setCheckable(true);

        horizontalLayout_14->addWidget(m_switchTestEnv);

        horizontalSpacer_28 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_28);

        m_lbSurfaceMerge = new QLabel(m_tabExtraSettings);
        m_lbSurfaceMerge->setObjectName(QStringLiteral("m_lbSurfaceMerge"));
        m_lbSurfaceMerge->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_14->addWidget(m_lbSurfaceMerge);

        horizontalSpacer_29 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_29);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_9);

        m_switchSurfaceMerge = new QPushButton(m_tabExtraSettings);
        m_switchSurfaceMerge->setObjectName(QStringLiteral("m_switchSurfaceMerge"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_switchSurfaceMerge->sizePolicy().hasHeightForWidth());
        m_switchSurfaceMerge->setSizePolicy(sizePolicy1);
        m_switchSurfaceMerge->setMinimumSize(QSize(32, 16));
        m_switchSurfaceMerge->setMaximumSize(QSize(32, 16));
        m_switchSurfaceMerge->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchSurfaceMerge->setCheckable(true);

        horizontalLayout_14->addWidget(m_switchSurfaceMerge);


        verticalLayout_17->addLayout(horizontalLayout_14);

        verticalSpacer_23 = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_17->addItem(verticalSpacer_23);

        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setHorizontalSpacing(23);
        formLayout_5->setVerticalSpacing(0);
        m_lbAPPID = new QLabel(m_tabExtraSettings);
        m_lbAPPID->setObjectName(QStringLiteral("m_lbAPPID"));
        m_lbAPPID->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, m_lbAPPID);

        m_strEdAPPID = new QLineEdit(m_tabExtraSettings);
        m_strEdAPPID->setObjectName(QStringLiteral("m_strEdAPPID"));
        m_strEdAPPID->setMinimumSize(QSize(120, 32));
        m_strEdAPPID->setMaximumSize(QSize(120, 32));
        m_strEdAPPID->setFocusPolicy(Qt::ClickFocus);
        m_strEdAPPID->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QLineEdit:!hover{\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:hover:!focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #ffffff;\n"
" }"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, m_strEdAPPID);


        verticalLayout_17->addLayout(formLayout_5);

        verticalSpacer_24 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_17->addItem(verticalSpacer_24);

        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setHorizontalSpacing(9);
        formLayout_6->setVerticalSpacing(0);
        m_lbAPPSign = new QLabel(m_tabExtraSettings);
        m_lbAPPSign->setObjectName(QStringLiteral("m_lbAPPSign"));
        m_lbAPPSign->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, m_lbAPPSign);

        m_strEdAPPSign = new QLineEdit(m_tabExtraSettings);
        m_strEdAPPSign->setObjectName(QStringLiteral("m_strEdAPPSign"));
        m_strEdAPPSign->setMinimumSize(QSize(120, 32));
        m_strEdAPPSign->setMaximumSize(QSize(120, 32));
        m_strEdAPPSign->setFocusPolicy(Qt::ClickFocus);
        m_strEdAPPSign->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QLineEdit:!hover{\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:hover:!focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #ffffff;\n"
" }"));

        formLayout_6->setWidget(2, QFormLayout::FieldRole, m_strEdAPPSign);


        verticalLayout_17->addLayout(formLayout_6);

        verticalSpacer_33 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_33);


        horizontalLayout_27->addLayout(verticalLayout_17);

        horizontalSpacer_17 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_17);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalSpacer_25 = new QSpacerItem(18, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_21->addItem(verticalSpacer_25);

        m_lbAdvanced = new QLabel(m_tabExtraSettings);
        m_lbAdvanced->setObjectName(QStringLiteral("m_lbAdvanced"));
        m_lbAdvanced->setFont(font);
        m_lbAdvanced->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_21->addWidget(m_lbAdvanced);

        verticalSpacer_26 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_21->addItem(verticalSpacer_26);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(0);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        m_lbCapture = new QLabel(m_tabExtraSettings);
        m_lbCapture->setObjectName(QStringLiteral("m_lbCapture"));
        m_lbCapture->setMinimumSize(QSize(58, 16));
        m_lbCapture->setMaximumSize(QSize(58, 16));
        m_lbCapture->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_15->addWidget(m_lbCapture);

        horizontalSpacer_10 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_10);

        m_switchCapture = new QPushButton(m_tabExtraSettings);
        m_switchCapture->setObjectName(QStringLiteral("m_switchCapture"));
        m_switchCapture->setMinimumSize(QSize(32, 16));
        m_switchCapture->setMaximumSize(QSize(32, 16));
        m_switchCapture->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchCapture->setCheckable(true);

        horizontalLayout_15->addWidget(m_switchCapture);


        horizontalLayout_24->addLayout(horizontalLayout_15);

        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_11);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        m_lbFilter = new QLabel(m_tabExtraSettings);
        m_lbFilter->setObjectName(QStringLiteral("m_lbFilter"));
        m_lbFilter->setMinimumSize(QSize(58, 16));
        m_lbFilter->setMaximumSize(QSize(58, 16));
        m_lbFilter->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_16->addWidget(m_lbFilter);

        horizontalSpacer_12 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_12);

        m_switchFilter = new QPushButton(m_tabExtraSettings);
        m_switchFilter->setObjectName(QStringLiteral("m_switchFilter"));
        sizePolicy1.setHeightForWidth(m_switchFilter->sizePolicy().hasHeightForWidth());
        m_switchFilter->setSizePolicy(sizePolicy1);
        m_switchFilter->setMinimumSize(QSize(32, 16));
        m_switchFilter->setMaximumSize(QSize(32, 16));
        m_switchFilter->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchFilter->setCheckable(true);

        horizontalLayout_16->addWidget(m_switchFilter);


        horizontalLayout_24->addLayout(horizontalLayout_16);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_13);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        m_lbHardDecode = new QLabel(m_tabExtraSettings);
        m_lbHardDecode->setObjectName(QStringLiteral("m_lbHardDecode"));
        m_lbHardDecode->setMinimumSize(QSize(58, 16));
        m_lbHardDecode->setMaximumSize(QSize(58, 16));
        m_lbHardDecode->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_17->addWidget(m_lbHardDecode);

        horizontalSpacer_14 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_14);

        m_switchHardDecode = new QPushButton(m_tabExtraSettings);
        m_switchHardDecode->setObjectName(QStringLiteral("m_switchHardDecode"));
        m_switchHardDecode->setMinimumSize(QSize(32, 16));
        m_switchHardDecode->setMaximumSize(QSize(32, 16));
        m_switchHardDecode->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchHardDecode->setCheckable(true);

        horizontalLayout_17->addWidget(m_switchHardDecode);


        horizontalLayout_24->addLayout(horizontalLayout_17);


        verticalLayout_21->addLayout(horizontalLayout_24);

        verticalSpacer_27 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_21->addItem(verticalSpacer_27);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(0);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        m_lbRender = new QLabel(m_tabExtraSettings);
        m_lbRender->setObjectName(QStringLiteral("m_lbRender"));
        m_lbRender->setMinimumSize(QSize(58, 16));
        m_lbRender->setMaximumSize(QSize(58, 16));
        m_lbRender->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_18->addWidget(m_lbRender);

        horizontalSpacer_18 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_18);

        m_switchRender = new QPushButton(m_tabExtraSettings);
        m_switchRender->setObjectName(QStringLiteral("m_switchRender"));
        m_switchRender->setMinimumSize(QSize(32, 16));
        m_switchRender->setMaximumSize(QSize(32, 16));
        m_switchRender->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchRender->setCheckable(true);

        horizontalLayout_18->addWidget(m_switchRender);


        horizontalLayout_25->addLayout(horizontalLayout_18);

        horizontalSpacer_19 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_19);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        m_lbHardCode = new QLabel(m_tabExtraSettings);
        m_lbHardCode->setObjectName(QStringLiteral("m_lbHardCode"));
        m_lbHardCode->setMinimumSize(QSize(58, 16));
        m_lbHardCode->setMaximumSize(QSize(58, 16));
        m_lbHardCode->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_19->addWidget(m_lbHardCode);

        horizontalSpacer_20 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_20);

        m_switchHardCode = new QPushButton(m_tabExtraSettings);
        m_switchHardCode->setObjectName(QStringLiteral("m_switchHardCode"));
        m_switchHardCode->setMinimumSize(QSize(32, 16));
        m_switchHardCode->setMaximumSize(QSize(32, 16));
        m_switchHardCode->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchHardCode->setCheckable(true);

        horizontalLayout_19->addWidget(m_switchHardCode);


        horizontalLayout_25->addLayout(horizontalLayout_19);

        horizontalSpacer_21 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_21);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(0);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        m_lbAutoBitrate = new QLabel(m_tabExtraSettings);
        m_lbAutoBitrate->setObjectName(QStringLiteral("m_lbAutoBitrate"));
        m_lbAutoBitrate->setMinimumSize(QSize(68, 0));
        m_lbAutoBitrate->setMaximumSize(QSize(58, 16));
        m_lbAutoBitrate->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_20->addWidget(m_lbAutoBitrate);

        horizontalSpacer_22 = new QSpacerItem(4, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_22);

        m_switchAutoBitrate = new QPushButton(m_tabExtraSettings);
        m_switchAutoBitrate->setObjectName(QStringLiteral("m_switchAutoBitrate"));
        m_switchAutoBitrate->setMinimumSize(QSize(32, 16));
        m_switchAutoBitrate->setMaximumSize(QSize(32, 16));
        m_switchAutoBitrate->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchAutoBitrate->setCheckable(true);

        horizontalLayout_20->addWidget(m_switchAutoBitrate);


        horizontalLayout_25->addLayout(horizontalLayout_20);


        verticalLayout_21->addLayout(horizontalLayout_25);

        verticalSpacer_28 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_21->addItem(verticalSpacer_28);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        m_lbAudioLeft = new QLabel(m_tabExtraSettings);
        m_lbAudioLeft->setObjectName(QStringLiteral("m_lbAudioLeft"));
        m_lbAudioLeft->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_18->addWidget(m_lbAudioLeft);

        verticalSpacer_29 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_18->addItem(verticalSpacer_29);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        m_lbMicAudio = new QLabel(m_tabExtraSettings);
        m_lbMicAudio->setObjectName(QStringLiteral("m_lbMicAudio"));
        m_lbMicAudio->setMinimumSize(QSize(0, 16));
        m_lbMicAudio->setMaximumSize(QSize(16777215, 16));
        m_lbMicAudio->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_21->addWidget(m_lbMicAudio);

        horizontalSpacer_23 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_23);

        m_switchMicAudio = new QPushButton(m_tabExtraSettings);
        m_switchMicAudio->setObjectName(QStringLiteral("m_switchMicAudio"));
        m_switchMicAudio->setMinimumSize(QSize(32, 16));
        m_switchMicAudio->setMaximumSize(QSize(32, 16));
        m_switchMicAudio->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchMicAudio->setCheckable(true);

        horizontalLayout_21->addWidget(m_switchMicAudio);


        verticalLayout_18->addLayout(horizontalLayout_21);


        horizontalLayout_26->addLayout(verticalLayout_18);

        horizontalSpacer_24 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_24);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(0);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        m_lbTime = new QLabel(m_tabExtraSettings);
        m_lbTime->setObjectName(QStringLiteral("m_lbTime"));
        m_lbTime->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_19->addWidget(m_lbTime);

        verticalSpacer_30 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_19->addItem(verticalSpacer_30);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        m_lbTimeCount = new QLabel(m_tabExtraSettings);
        m_lbTimeCount->setObjectName(QStringLiteral("m_lbTimeCount"));
        m_lbTimeCount->setMinimumSize(QSize(0, 16));
        m_lbTimeCount->setMaximumSize(QSize(16777215, 16));
        m_lbTimeCount->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_22->addWidget(m_lbTimeCount);

        horizontalSpacer_25 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_25);

        m_switchTimeCount = new QPushButton(m_tabExtraSettings);
        m_switchTimeCount->setObjectName(QStringLiteral("m_switchTimeCount"));
        m_switchTimeCount->setMinimumSize(QSize(32, 16));
        m_switchTimeCount->setMaximumSize(QSize(32, 16));
        m_switchTimeCount->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchTimeCount->setCheckable(true);

        horizontalLayout_22->addWidget(m_switchTimeCount);


        verticalLayout_19->addLayout(horizontalLayout_22);


        horizontalLayout_26->addLayout(verticalLayout_19);

        horizontalSpacer_27 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_27);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        m_lbAudioRight = new QLabel(m_tabExtraSettings);
        m_lbAudioRight->setObjectName(QStringLiteral("m_lbAudioRight"));
        m_lbAudioRight->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_20->addWidget(m_lbAudioRight);

        verticalSpacer_31 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_20->addItem(verticalSpacer_31);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(0);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        m_lbNational = new QLabel(m_tabExtraSettings);
        m_lbNational->setObjectName(QStringLiteral("m_lbNational"));
        m_lbNational->setMinimumSize(QSize(0, 16));
        m_lbNational->setMaximumSize(QSize(16777215, 16));
        m_lbNational->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_23->addWidget(m_lbNational);

        horizontalSpacer_26 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_26);

        m_switchNational = new QPushButton(m_tabExtraSettings);
        m_switchNational->setObjectName(QStringLiteral("m_switchNational"));
        m_switchNational->setMinimumSize(QSize(32, 16));
        m_switchNational->setMaximumSize(QSize(32, 16));
        m_switchNational->setStyleSheet(QLatin1String("QPushButton:!checked{\n"
"     border-image: url(:/Resources/images/switch_off.png);\n"
" }\n"
"\n"
" QPushButton:checked{\n"
"     border-image: url(:/Resources/images/switch_on.png);\n"
" }"));
        m_switchNational->setCheckable(true);

        horizontalLayout_23->addWidget(m_switchNational);


        verticalLayout_20->addLayout(horizontalLayout_23);


        horizontalLayout_26->addLayout(verticalLayout_20);


        verticalLayout_21->addLayout(horizontalLayout_26);

        verticalSpacer_34 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_34);


        horizontalLayout_27->addLayout(verticalLayout_21);

        horizontalSpacer_16 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_16);


        verticalLayout_22->addLayout(horizontalLayout_27);

        m_tabSettings->addTab(m_tabExtraSettings, QString());
        m_tabUserSettings = new QWidget();
        m_tabUserSettings->setObjectName(QStringLiteral("m_tabUserSettings"));
        verticalLayout_13 = new QVBoxLayout(m_tabUserSettings);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(30, 0, 30, 0);
        m_lineUserSettings = new QFrame(m_tabUserSettings);
        m_lineUserSettings->setObjectName(QStringLiteral("m_lineUserSettings"));
        m_lineUserSettings->setMinimumSize(QSize(0, 2));
        m_lineUserSettings->setMaximumSize(QSize(16777215, 2));
        m_lineUserSettings->setStyleSheet(QLatin1String("margin-left: 455px;\n"
"margin-right: 55px;\n"
"background-color: #0e88eb;\n"
"border: none;"));
        m_lineUserSettings->setFrameShape(QFrame::HLine);
        m_lineUserSettings->setFrameShadow(QFrame::Sunken);

        verticalLayout_13->addWidget(m_lineUserSettings);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(-1, 0, -1, -1);
        m_lineLongUserSettings = new QFrame(m_tabUserSettings);
        m_lineLongUserSettings->setObjectName(QStringLiteral("m_lineLongUserSettings"));
        m_lineLongUserSettings->setMinimumSize(QSize(0, 1));
        m_lineLongUserSettings->setMaximumSize(QSize(16777215, 1));
        m_lineLongUserSettings->setStyleSheet(QLatin1String("margin-left: 10px;\n"
"margin-right: 10px;\n"
"background-color: #f5f5f5;\n"
"border: none;"));
        m_lineLongUserSettings->setFrameShape(QFrame::HLine);
        m_lineLongUserSettings->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(m_lineLongUserSettings);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalSpacer_7 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_7);

        m_lbAccount = new QLabel(m_tabUserSettings);
        m_lbAccount->setObjectName(QStringLiteral("m_lbAccount"));
        m_lbAccount->setFont(font);
        m_lbAccount->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_10->addWidget(m_lbAccount);

        verticalSpacer_10 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(10);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        m_lbUserId = new QLabel(m_tabUserSettings);
        m_lbUserId->setObjectName(QStringLiteral("m_lbUserId"));
        m_lbUserId->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        formLayout->setWidget(0, QFormLayout::LabelRole, m_lbUserId);

        m_strEdUserId = new QLineEdit(m_tabUserSettings);
        m_strEdUserId->setObjectName(QStringLiteral("m_strEdUserId"));
        m_strEdUserId->setMinimumSize(QSize(180, 32));
        m_strEdUserId->setMaximumSize(QSize(180, 32));
        m_strEdUserId->setFocusPolicy(Qt::ClickFocus);
        m_strEdUserId->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QLineEdit:!hover{\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:hover:!focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #ffffff;\n"
" }"));

        formLayout->setWidget(0, QFormLayout::FieldRole, m_strEdUserId);


        verticalLayout_8->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        m_lbUserName = new QLabel(m_tabUserSettings);
        m_lbUserName->setObjectName(QStringLiteral("m_lbUserName"));
        m_lbUserName->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, m_lbUserName);

        m_strEdUserName = new QLineEdit(m_tabUserSettings);
        m_strEdUserName->setObjectName(QStringLiteral("m_strEdUserName"));
        m_strEdUserName->setMinimumSize(QSize(180, 32));
        m_strEdUserName->setMaximumSize(QSize(180, 32));
        m_strEdUserName->setFocusPolicy(Qt::ClickFocus);
        m_strEdUserName->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QLineEdit:!hover{\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:hover:!focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fafafa;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #ffffff;\n"
" }"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, m_strEdUserName);


        verticalLayout_8->addLayout(formLayout_2);


        verticalLayout_10->addLayout(verticalLayout_8);


        horizontalLayout_5->addLayout(verticalLayout_10);

        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalSpacer_8 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_8);

        m_lbEquipment = new QLabel(m_tabUserSettings);
        m_lbEquipment->setObjectName(QStringLiteral("m_lbEquipment"));
        m_lbEquipment->setFont(font);
        m_lbEquipment->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_11->addWidget(m_lbEquipment);

        verticalSpacer_11 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_11);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(10);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        m_lbMircoPhone = new QLabel(m_tabUserSettings);
        m_lbMircoPhone->setObjectName(QStringLiteral("m_lbMircoPhone"));
        m_lbMircoPhone->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, m_lbMircoPhone);

        m_cbMircoPhone = new QComboBox(m_tabUserSettings);
        m_cbMircoPhone->setObjectName(QStringLiteral("m_cbMircoPhone"));
        m_cbMircoPhone->setMinimumSize(QSize(260, 32));
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

        formLayout_3->setWidget(0, QFormLayout::FieldRole, m_cbMircoPhone);


        verticalLayout_9->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        m_lbCamera = new QLabel(m_tabUserSettings);
        m_lbCamera->setObjectName(QStringLiteral("m_lbCamera"));
        m_lbCamera->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, m_lbCamera);

        m_cbCamera = new QComboBox(m_tabUserSettings);
        m_cbCamera->setObjectName(QStringLiteral("m_cbCamera"));
        m_cbCamera->setMinimumSize(QSize(260, 32));
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

        formLayout_4->setWidget(0, QFormLayout::FieldRole, m_cbCamera);


        verticalLayout_9->addLayout(formLayout_4);


        verticalLayout_11->addLayout(verticalLayout_9);


        horizontalLayout_5->addLayout(verticalLayout_11);


        verticalLayout_12->addLayout(horizontalLayout_5);

        verticalSpacer_9 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        m_lbVersion = new QLabel(m_tabUserSettings);
        m_lbVersion->setObjectName(QStringLiteral("m_lbVersion"));
        m_lbVersion->setMinimumSize(QSize(0, 0));
        m_lbVersion->setMaximumSize(QSize(16777215, 16777215));
        m_lbVersion->setFont(font);
        m_lbVersion->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_7->addWidget(m_lbVersion);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        m_bUploadLog = new QPushButton(m_tabUserSettings);
        m_bUploadLog->setObjectName(QStringLiteral("m_bUploadLog"));
        m_bUploadLog->setMinimumSize(QSize(100, 34));
        m_bUploadLog->setMaximumSize(QSize(100, 34));
        m_bUploadLog->setStyleSheet(QString::fromUtf8("QPushButton:!hover#m_bUploadLog{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0e88eb;\n"
"     background-color: #ffffff;\n"
"     color: #0e88eb;\n"
" }\n"
"\n"
" QPushButton:hover:!pressed#m_bUploadLog{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0e88eb;\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }\n"
"\n"
" QPushButton:hover:pressed#m_bUploadLog{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0d80de;\n"
"     background-color: #0d80de;\n"
"     color: #ffffff;\n"
" }"));

        horizontalLayout_7->addWidget(m_bUploadLog);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        m_lbTips = new QLabel(m_tabUserSettings);
        m_lbTips->setObjectName(QStringLiteral("m_lbTips"));
        m_lbTips->setStyleSheet(QString::fromUtf8("QLabel#m_lbTips{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #b2b2b2;\n"
" }"));

        horizontalLayout_7->addWidget(m_lbTips);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_12->addLayout(horizontalLayout_7);

        verticalSpacer_6 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_6);


        verticalLayout_13->addLayout(verticalLayout_12);

        m_tabSettings->addTab(m_tabUserSettings, QString());

        verticalLayout_7->addWidget(m_tabSettings);


        verticalLayout->addWidget(m_zoneSettings);

        verticalSpacer_32 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_32);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalLayout_4->setStretch(0, 280);
        horizontalLayout_4->setStretch(1, 650);

        verticalLayout_6->addLayout(horizontalLayout_4);


        retranslateUi(ZegoMainDialog);

        m_bSingleMode->setDefault(false);
        m_tabSettings->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ZegoMainDialog);
    } // setupUi

    void retranslateUi(QDialog *ZegoMainDialog)
    {
        ZegoMainDialog->setWindowTitle(QApplication::translate("ZegoMainDialog", "ZegoLiveDemo", Q_NULLPTR));
        m_lbTitle->setText(QApplication::translate("ZegoMainDialog", "ZegoLiveDemo", Q_NULLPTR));
        m_lbTitleVersion->setText(QApplication::translate("ZegoMainDialog", "\347\211\210\346\234\254:1.0.0.2", Q_NULLPTR));
        m_bJumpToNet->setText(QString());
        m_bMin->setText(QString());
        m_bClose->setText(QString());
        m_lbCreateRoom->setText(QApplication::translate("ZegoMainDialog", "\345\210\233\345\273\272\346\210\277\351\227\264", Q_NULLPTR));
        m_lbName->setText(QApplication::translate("ZegoMainDialog", "\345\220\215\347\247\260", Q_NULLPTR));
        m_edRoomName->setPlaceholderText(QApplication::translate("ZegoMainDialog", "\350\257\267\350\276\223\345\205\245\346\210\277\351\227\264\345\220\215\347\247\260", Q_NULLPTR));
        m_lbMode->setText(QApplication::translate("ZegoMainDialog", "\346\250\241\345\274\217", Q_NULLPTR));
        m_bMixMode->setText(QApplication::translate("ZegoMainDialog", "\346\267\267\346\265\201\346\250\241\345\274\217", Q_NULLPTR));
        m_bSingleMode->setText(QApplication::translate("ZegoMainDialog", "\345\215\225\344\270\273\346\222\255\346\250\241\345\274\217", Q_NULLPTR));
        m_bMultiMode->setText(QApplication::translate("ZegoMainDialog", "\350\277\236\351\272\246\346\250\241\345\274\217", Q_NULLPTR));
        m_bCreateRoom->setText(QApplication::translate("ZegoMainDialog", "+ \345\210\233\345\273\272\346\210\277\351\227\264", Q_NULLPTR));
        m_TitleList->setText(QApplication::translate("ZegoMainDialog", "\347\233\264\346\222\255\351\227\264\345\210\227\350\241\250", Q_NULLPTR));
        m_bRefreshRoomList->setText(QApplication::translate("ZegoMainDialog", "\345\210\267\346\226\260", Q_NULLPTR));
        m_bExtremelyHigh->setText(QApplication::translate("ZegoMainDialog", "\346\236\201\351\253\230\350\264\250\351\207\217", Q_NULLPTR));
        m_bSuperHigh->setText(QApplication::translate("ZegoMainDialog", "\350\266\205\351\253\230\350\264\250\351\207\217", Q_NULLPTR));
        m_bHigh->setText(QApplication::translate("ZegoMainDialog", "\351\253\230\350\264\250\351\207\217", Q_NULLPTR));
        m_bStandard->setText(QApplication::translate("ZegoMainDialog", "\346\240\207\345\207\206\350\264\250\351\207\217", Q_NULLPTR));
        m_bLow->setText(QApplication::translate("ZegoMainDialog", "\344\275\216\350\264\250\351\207\217", Q_NULLPTR));
        m_bSuperLow->setText(QApplication::translate("ZegoMainDialog", "\350\266\205\344\275\216\350\264\250\351\207\217", Q_NULLPTR));
        m_bCustom->setText(QApplication::translate("ZegoMainDialog", "\350\207\252\345\256\232\344\271\211", Q_NULLPTR));
        m_lbResolution->setText(QApplication::translate("ZegoMainDialog", "\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        m_lbValueResolution->setText(QApplication::translate("ZegoMainDialog", "unknown", Q_NULLPTR));
        m_bResolutionDown->setText(QString());
        m_bResolutionUp->setText(QString());
        m_lbFPS->setText(QApplication::translate("ZegoMainDialog", "\345\270\247\347\216\207", Q_NULLPTR));
        m_lbValueFPS->setText(QApplication::translate("ZegoMainDialog", "unknown", Q_NULLPTR));
        m_bFPSDown->setText(QString());
        m_bFPSUp->setText(QString());
        m_lbBitrate->setText(QApplication::translate("ZegoMainDialog", "\347\240\201\347\216\207", Q_NULLPTR));
        m_lbValueBitrate->setText(QApplication::translate("ZegoMainDialog", "unknown", Q_NULLPTR));
        m_bBitrateDown->setText(QString());
        m_bBitrateUp->setText(QString());
        m_tabSettings->setTabText(m_tabSettings->indexOf(m_tabVideoConfig), QApplication::translate("ZegoMainDialog", "\350\247\206\351\242\221\345\217\202\346\225\260", Q_NULLPTR));
        m_lbEnvironment->setText(QApplication::translate("ZegoMainDialog", "Environment", Q_NULLPTR));
        m_lbTestEnv->setText(QApplication::translate("ZegoMainDialog", "\346\265\213\350\257\225\347\216\257\345\242\203", Q_NULLPTR));
        m_switchTestEnv->setText(QString());
        m_lbSurfaceMerge->setText(QApplication::translate("ZegoMainDialog", "\345\261\217\345\271\225\347\233\264\346\222\255", Q_NULLPTR));
        m_switchSurfaceMerge->setText(QString());
        m_lbAPPID->setText(QApplication::translate("ZegoMainDialog", "APP ID", Q_NULLPTR));
        m_lbAPPSign->setText(QApplication::translate("ZegoMainDialog", "APP Sign", Q_NULLPTR));
        m_lbAdvanced->setText(QApplication::translate("ZegoMainDialog", "Advanced", Q_NULLPTR));
        m_lbCapture->setText(QApplication::translate("ZegoMainDialog", "\345\244\226\351\203\250\351\207\207\351\233\206", Q_NULLPTR));
        m_switchCapture->setText(QString());
        m_lbFilter->setText(QApplication::translate("ZegoMainDialog", "\345\244\226\351\203\250\346\273\244\351\225\234", Q_NULLPTR));
        m_switchFilter->setText(QString());
        m_lbHardDecode->setText(QApplication::translate("ZegoMainDialog", "\347\241\254\344\273\266\350\247\243\347\240\201", Q_NULLPTR));
        m_switchHardDecode->setText(QString());
        m_lbRender->setText(QApplication::translate("ZegoMainDialog", "\345\244\226\351\203\250\346\270\262\346\237\223", Q_NULLPTR));
        m_switchRender->setText(QString());
        m_lbHardCode->setText(QApplication::translate("ZegoMainDialog", "\347\241\254\344\273\266\347\274\226\347\240\201", Q_NULLPTR));
        m_switchHardCode->setText(QString());
        m_lbAutoBitrate->setText(QApplication::translate("ZegoMainDialog", "\350\207\252\351\200\202\345\272\224\347\240\201\347\216\207", Q_NULLPTR));
        m_switchAutoBitrate->setText(QString());
        m_lbAudioLeft->setText(QApplication::translate("ZegoMainDialog", "Audio", Q_NULLPTR));
        m_lbMicAudio->setText(QApplication::translate("ZegoMainDialog", "\346\267\267\345\223\215", Q_NULLPTR));
        m_switchMicAudio->setText(QString());
        m_lbTime->setText(QApplication::translate("ZegoMainDialog", "Time", Q_NULLPTR));
        m_lbTimeCount->setText(QApplication::translate("ZegoMainDialog", "\350\256\241\346\227\266", Q_NULLPTR));
        m_switchTimeCount->setText(QString());
        m_lbAudioRight->setText(QApplication::translate("ZegoMainDialog", "Audio", Q_NULLPTR));
        m_lbNational->setText(QApplication::translate("ZegoMainDialog", "\345\233\275\351\231\205\347\211\210", Q_NULLPTR));
        m_switchNational->setText(QString());
        m_tabSettings->setTabText(m_tabSettings->indexOf(m_tabExtraSettings), QApplication::translate("ZegoMainDialog", "\351\253\230\347\272\247\350\256\276\347\275\256", Q_NULLPTR));
        m_lbAccount->setText(QApplication::translate("ZegoMainDialog", "Account", Q_NULLPTR));
        m_lbUserId->setText(QApplication::translate("ZegoMainDialog", "\347\224\250\346\210\267ID", Q_NULLPTR));
        m_lbUserName->setText(QApplication::translate("ZegoMainDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        m_lbEquipment->setText(QApplication::translate("ZegoMainDialog", "Equipment", Q_NULLPTR));
        m_lbMircoPhone->setText(QApplication::translate("ZegoMainDialog", "\351\272\246\345\205\213\351\243\216", Q_NULLPTR));
        m_lbCamera->setText(QApplication::translate("ZegoMainDialog", "\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        m_lbVersion->setText(QApplication::translate("ZegoMainDialog", "Version", Q_NULLPTR));
        m_bUploadLog->setText(QApplication::translate("ZegoMainDialog", "\344\270\212\344\274\240\346\227\245\345\277\227", Q_NULLPTR));
        m_lbTips->setText(QApplication::translate("ZegoMainDialog", "(\345\246\202\351\201\207\347\250\213\345\272\217\345\264\251\346\272\203\347\255\211\351\227\256\351\242\230,\350\257\267\347\202\271\345\207\273\344\270\212\344\274\240\346\227\245\345\277\227,\347\255\211\345\276\205\350\247\243\345\206\263)", Q_NULLPTR));
        m_tabSettings->setTabText(m_tabSettings->indexOf(m_tabUserSettings), QApplication::translate("ZegoMainDialog", "\344\270\252\344\272\272\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZegoMainDialog: public Ui_ZegoMainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEGOMAINDIALOG_H
