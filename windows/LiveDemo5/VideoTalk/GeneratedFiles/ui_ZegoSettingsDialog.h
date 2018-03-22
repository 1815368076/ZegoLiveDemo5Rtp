/********************************************************************************
** Form generated from reading UI file 'ZegoSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEGOSETTINGSDIALOG_H
#define UI_ZEGOSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZegoSettingsDialog
{
public:
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_9;
    QWidget *m_zoneTitle;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_4;
    QLabel *m_lbTitle;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *m_bMin;
    QPushButton *m_bClose;
    QSpacerItem *verticalSpacer_11;
    QVBoxLayout *verticalLayout_7;
    QWidget *m_zoneSdkVersion;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *m_lbSdkTitle;
    QLabel *m_lbSdkVersion;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_bUploadLog;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *m_bSaveSettings;
    QSpacerItem *horizontalSpacer_11;
    QFrame *m_hLine;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_7;
    QWidget *m_zoneUserConfig;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_7;
    QLabel *m_lbAccount;
    QSpacerItem *verticalSpacer_10;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_16;
    QLabel *m_lbUserId;
    QSpacerItem *horizontalSpacer_17;
    QLineEdit *m_strEdUserId;
    QHBoxLayout *horizontalLayout_17;
    QLabel *m_lbUserName;
    QSpacerItem *horizontalSpacer_18;
    QLineEdit *m_strEdUserName;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_22;
    QComboBox *m_cbAppVersion;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *m_switchTestEnv;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_18;
    QLabel *m_lbAPPID_2;
    QSpacerItem *horizontalSpacer_19;
    QLineEdit *m_strEdAPPID;
    QHBoxLayout *horizontalLayout_19;
    QLabel *m_lbAPPSign_2;
    QSpacerItem *horizontalSpacer_20;
    QLineEdit *m_strEdAPPSign;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QFrame *m_vLine;
    QSpacerItem *horizontalSpacer_10;
    QWidget *m_zoneVideoQuality;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *m_lbVideo;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_21;
    QComboBox *m_cbVideoQuality;
    QSpacerItem *horizontalSpacer_16;
    QLabel *m_lbSurfaceMerge;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *m_switchSurfaceMerge;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_6;
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
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_19;

    void setupUi(QDialog *ZegoSettingsDialog)
    {
        if (ZegoSettingsDialog->objectName().isEmpty())
            ZegoSettingsDialog->setObjectName(QStringLiteral("ZegoSettingsDialog"));
        ZegoSettingsDialog->resize(895, 455);
        ZegoSettingsDialog->setStyleSheet(QStringLiteral("background-color: #fafafa;"));
        verticalLayout_11 = new QVBoxLayout(ZegoSettingsDialog);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, -1, -1, 0);
        m_zoneTitle = new QWidget(ZegoSettingsDialog);
        m_zoneTitle->setObjectName(QStringLiteral("m_zoneTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_zoneTitle->sizePolicy().hasHeightForWidth());
        m_zoneTitle->setSizePolicy(sizePolicy);
        m_zoneTitle->setMinimumSize(QSize(0, 40));
        m_zoneTitle->setMaximumSize(QSize(16777215, 40));
        m_zoneTitle->setStyleSheet(QStringLiteral("background-color: #0e88eb;"));
        horizontalLayout_15 = new QHBoxLayout(m_zoneTitle);
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_4);

        m_lbTitle = new QLabel(m_zoneTitle);
        m_lbTitle->setObjectName(QStringLiteral("m_lbTitle"));
        m_lbTitle->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	 font-size: 16px;\n"
"     color: #ffffff;"));

        horizontalLayout_14->addWidget(m_lbTitle);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);

        m_bMin = new QPushButton(m_zoneTitle);
        m_bMin->setObjectName(QStringLiteral("m_bMin"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_bMin->sizePolicy().hasHeightForWidth());
        m_bMin->setSizePolicy(sizePolicy1);
        m_bMin->setMinimumSize(QSize(40, 40));
        m_bMin->setMaximumSize(QSize(40, 40));
        m_bMin->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
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

        horizontalLayout_14->addWidget(m_bMin);

        m_bClose = new QPushButton(m_zoneTitle);
        m_bClose->setObjectName(QStringLiteral("m_bClose"));
        sizePolicy1.setHeightForWidth(m_bClose->sizePolicy().hasHeightForWidth());
        m_bClose->setSizePolicy(sizePolicy1);
        m_bClose->setMinimumSize(QSize(50, 40));
        m_bClose->setMaximumSize(QSize(50, 40));
        m_bClose->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
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
        icon1.addFile(QStringLiteral(":/Resources/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_bClose->setIcon(icon1);

        horizontalLayout_14->addWidget(m_bClose);


        horizontalLayout_15->addLayout(horizontalLayout_14);


        verticalLayout_9->addWidget(m_zoneTitle);

        verticalSpacer_11 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_9->addItem(verticalSpacer_11);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        m_zoneSdkVersion = new QWidget(ZegoSettingsDialog);
        m_zoneSdkVersion->setObjectName(QStringLiteral("m_zoneSdkVersion"));
        horizontalLayout_7 = new QHBoxLayout(m_zoneSdkVersion);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, 0, -1);
        m_lbSdkTitle = new QLabel(m_zoneSdkVersion);
        m_lbSdkTitle->setObjectName(QStringLiteral("m_lbSdkTitle"));
        m_lbSdkTitle->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;\n"
"color: #666666;"));

        horizontalLayout_5->addWidget(m_lbSdkTitle);

        m_lbSdkVersion = new QLabel(m_zoneSdkVersion);
        m_lbSdkVersion->setObjectName(QStringLiteral("m_lbSdkVersion"));
        m_lbSdkVersion->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;\n"
"color: #666666;"));

        horizontalLayout_5->addWidget(m_lbSdkVersion);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        m_bUploadLog = new QPushButton(m_zoneSdkVersion);
        m_bUploadLog->setObjectName(QStringLiteral("m_bUploadLog"));
        m_bUploadLog->setMinimumSize(QSize(100, 32));
        m_bUploadLog->setMaximumSize(QSize(16777215, 32));
        m_bUploadLog->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0e88eb;\n"
"     background-color: #ffffff;\n"
"     color: #0e88eb;\n"
" }\n"
"\n"
" QPushButton:hover:!pressed{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0e88eb;\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }\n"
"\n"
" QPushButton:hover:pressed{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0d80de;\n"
"     background-color: #0d80de;\n"
"     color: #ffffff;\n"
" }"));

        horizontalLayout_5->addWidget(m_bUploadLog);

        horizontalSpacer_14 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_14);

        m_bSaveSettings = new QPushButton(m_zoneSdkVersion);
        m_bSaveSettings->setObjectName(QStringLiteral("m_bSaveSettings"));
        sizePolicy1.setHeightForWidth(m_bSaveSettings->sizePolicy().hasHeightForWidth());
        m_bSaveSettings->setSizePolicy(sizePolicy1);
        m_bSaveSettings->setMinimumSize(QSize(100, 30));
        m_bSaveSettings->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:!hover{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0e88eb;\n"
"     background-color: #ffffff;\n"
"     color: #0e88eb;\n"
" }\n"
"\n"
" QPushButton:hover:!pressed{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0e88eb;\n"
"     background-color: #0e88eb;\n"
"     color: #ffffff;\n"
" }\n"
"\n"
" QPushButton:hover:pressed{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 border-radius: 2px;\n"
"     border: 1px solid #0d80de;\n"
"     background-color: #0d80de;\n"
"     color: #ffffff;\n"
" }"));

        horizontalLayout_5->addWidget(m_bSaveSettings);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalSpacer_11 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_7->addWidget(m_zoneSdkVersion);

        m_hLine = new QFrame(ZegoSettingsDialog);
        m_hLine->setObjectName(QStringLiteral("m_hLine"));
        m_hLine->setMinimumSize(QSize(0, 1));
        m_hLine->setMaximumSize(QSize(16777215, 1));
        m_hLine->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0e88eb;"));
        m_hLine->setFrameShape(QFrame::HLine);
        m_hLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(m_hLine);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_7);

        m_zoneUserConfig = new QWidget(ZegoSettingsDialog);
        m_zoneUserConfig->setObjectName(QStringLiteral("m_zoneUserConfig"));
        verticalLayout_4 = new QVBoxLayout(m_zoneUserConfig);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_7);

        m_lbAccount = new QLabel(m_zoneUserConfig);
        m_lbAccount->setObjectName(QStringLiteral("m_lbAccount"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        m_lbAccount->setFont(font);
        m_lbAccount->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        verticalLayout_10->addWidget(m_lbAccount);

        verticalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(15);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        m_lbUserId = new QLabel(m_zoneUserConfig);
        m_lbUserId->setObjectName(QStringLiteral("m_lbUserId"));
        m_lbUserId->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_16->addWidget(m_lbUserId);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_17);

        m_strEdUserId = new QLineEdit(m_zoneUserConfig);
        m_strEdUserId->setObjectName(QStringLiteral("m_strEdUserId"));
        m_strEdUserId->setMinimumSize(QSize(230, 32));
        m_strEdUserId->setMaximumSize(QSize(230, 32));
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
"	 background-color: #fdfdfd;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:hover:!focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fdfdfd;\n"
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

        horizontalLayout_16->addWidget(m_strEdUserId);


        verticalLayout_8->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        m_lbUserName = new QLabel(m_zoneUserConfig);
        m_lbUserName->setObjectName(QStringLiteral("m_lbUserName"));
        m_lbUserName->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_17->addWidget(m_lbUserName);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_18);

        m_strEdUserName = new QLineEdit(m_zoneUserConfig);
        m_strEdUserName->setObjectName(QStringLiteral("m_strEdUserName"));
        m_strEdUserName->setMinimumSize(QSize(230, 32));
        m_strEdUserName->setMaximumSize(QSize(230, 32));
        m_strEdUserName->setFocusPolicy(Qt::StrongFocus);
        m_strEdUserName->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QLineEdit:!hover{\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fdfdfd;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:hover:!focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fdfdfd;\n"
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

        horizontalLayout_17->addWidget(m_strEdUserName);


        verticalLayout_8->addLayout(horizontalLayout_17);


        verticalLayout_10->addLayout(verticalLayout_8);


        verticalLayout_3->addLayout(verticalLayout_10);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        label_4 = new QLabel(m_zoneUserConfig);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;"));

        verticalLayout_2->addWidget(label_4);

        verticalSpacer_9 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(m_zoneUserConfig);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;"));

        horizontalLayout->addWidget(label_7);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_22);

        m_cbAppVersion = new QComboBox(m_zoneUserConfig);
        m_cbAppVersion->setObjectName(QStringLiteral("m_cbAppVersion"));
        m_cbAppVersion->setMinimumSize(QSize(120, 30));
        m_cbAppVersion->setMaximumSize(QSize(120, 30));
        m_cbAppVersion->setStyleSheet(QString::fromUtf8(" QComboBox{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QComboBox:!enabled{\n"
"    border: 1px solid #e6e6e6;\n"
"    border-radius: 2px;\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"	background-color: #fdfdfd;\n"
"	color: #cccccc;\n"
" }\n"
"\n"
" QComboBox:enabled:!hover{\n"
"    border: 1px solid #e6e6e6;\n"
"    border-radius: 2px;\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"	background-color: #fdfdfd;\n"
"	color: #666666;\n"
"}\n"
"QComboBox:enabled:hover{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fdfdfd;\n"
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
"    border-top-right-radius: 2px; /* same radi"
                        "us as the QComboBox */\n"
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
" }"));

        horizontalLayout->addWidget(m_cbAppVersion);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(m_zoneUserConfig);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;"));

        horizontalLayout_2->addWidget(label_8);

        horizontalSpacer_12 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        m_switchTestEnv = new QPushButton(m_zoneUserConfig);
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

        horizontalLayout_2->addWidget(m_switchTestEnv);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        m_lbAPPID_2 = new QLabel(m_zoneUserConfig);
        m_lbAPPID_2->setObjectName(QStringLiteral("m_lbAPPID_2"));
        m_lbAPPID_2->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_18->addWidget(m_lbAPPID_2);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_19);

        m_strEdAPPID = new QLineEdit(m_zoneUserConfig);
        m_strEdAPPID->setObjectName(QStringLiteral("m_strEdAPPID"));
        m_strEdAPPID->setMinimumSize(QSize(230, 32));
        m_strEdAPPID->setMaximumSize(QSize(230, 32));
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
"	 background-color: #fdfdfd;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:hover:!focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fdfdfd;\n"
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

        horizontalLayout_18->addWidget(m_strEdAPPID);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        m_lbAPPSign_2 = new QLabel(m_zoneUserConfig);
        m_lbAPPSign_2->setObjectName(QStringLiteral("m_lbAPPSign_2"));
        m_lbAPPSign_2->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_19->addWidget(m_lbAPPSign_2);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_20);

        m_strEdAPPSign = new QLineEdit(m_zoneUserConfig);
        m_strEdAPPSign->setObjectName(QStringLiteral("m_strEdAPPSign"));
        m_strEdAPPSign->setMinimumSize(QSize(230, 32));
        m_strEdAPPSign->setMaximumSize(QSize(230, 32));
        m_strEdAPPSign->setFocusPolicy(Qt::StrongFocus);
        m_strEdAPPSign->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QLineEdit:!hover{\n"
"     border: 1px solid #e6e6e6;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fdfdfd;\n"
"	 color: #666666;\n"
" }\n"
"\n"
" QLineEdit:hover:!focus{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fdfdfd;\n"
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

        horizontalLayout_19->addWidget(m_strEdAPPSign);


        verticalLayout->addLayout(horizontalLayout_19);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_13->addWidget(m_zoneUserConfig);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_9);

        m_vLine = new QFrame(ZegoSettingsDialog);
        m_vLine->setObjectName(QStringLiteral("m_vLine"));
        m_vLine->setMinimumSize(QSize(1, 0));
        m_vLine->setMaximumSize(QSize(1, 16777215));
        m_vLine->setStyleSheet(QLatin1String("border: none;\n"
"background-color: #0e88eb;"));
        m_vLine->setFrameShape(QFrame::VLine);
        m_vLine->setFrameShadow(QFrame::Sunken);

        horizontalLayout_13->addWidget(m_vLine);

        horizontalSpacer_10 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_10);

        m_zoneVideoQuality = new QWidget(ZegoSettingsDialog);
        m_zoneVideoQuality->setObjectName(QStringLiteral("m_zoneVideoQuality"));
        verticalLayout_6 = new QVBoxLayout(m_zoneVideoQuality);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, -1, 0);
        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);

        m_lbVideo = new QLabel(m_zoneVideoQuality);
        m_lbVideo->setObjectName(QStringLiteral("m_lbVideo"));
        m_lbVideo->setFont(font);
        m_lbVideo->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;"));

        verticalLayout_5->addWidget(m_lbVideo);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(m_zoneVideoQuality);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;"));

        horizontalLayout_4->addWidget(label_10);

        horizontalSpacer_21 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_21);

        m_cbVideoQuality = new QComboBox(m_zoneVideoQuality);
        m_cbVideoQuality->setObjectName(QStringLiteral("m_cbVideoQuality"));
        m_cbVideoQuality->setMinimumSize(QSize(120, 30));
        m_cbVideoQuality->setStyleSheet(QString::fromUtf8(" QComboBox{\n"
"     padding-left: 10px;\n"
" }\n"
"\n"
" QComboBox:!enabled{\n"
"    border: 1px solid #e6e6e6;\n"
"    border-radius: 2px;\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"	background-color: #fdfdfd;\n"
"	color: #cccccc;\n"
" }\n"
"\n"
" QComboBox:enabled:!hover{\n"
"    border: 1px solid #e6e6e6;\n"
"    border-radius: 2px;\n"
"    font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    font-size: 16px;\n"
"	background-color: #fdfdfd;\n"
"	color: #666666;\n"
"}\n"
"QComboBox:enabled:hover{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 16px;\n"
"	 background-color: #fdfdfd;\n"
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
"    border-top-right-radius: 2px; /* same radi"
                        "us as the QComboBox */\n"
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
" }"));

        horizontalLayout_4->addWidget(m_cbVideoQuality);

        horizontalSpacer_16 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_16);

        m_lbSurfaceMerge = new QLabel(m_zoneVideoQuality);
        m_lbSurfaceMerge->setObjectName(QStringLiteral("m_lbSurfaceMerge"));
        m_lbSurfaceMerge->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_4->addWidget(m_lbSurfaceMerge);

        horizontalSpacer_15 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);

        m_switchSurfaceMerge = new QPushButton(m_zoneVideoQuality);
        m_switchSurfaceMerge->setObjectName(QStringLiteral("m_switchSurfaceMerge"));
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

        horizontalLayout_4->addWidget(m_switchSurfaceMerge);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_6);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, -1, -1);
        verticalSpacer_12 = new QSpacerItem(22, 22, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_15->addItem(verticalSpacer_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        m_lbResolution = new QLabel(m_zoneVideoQuality);
        m_lbResolution->setObjectName(QStringLiteral("m_lbResolution"));
        m_lbResolution->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_6->addWidget(m_lbResolution);

        m_lbValueResolution = new QLabel(m_zoneVideoQuality);
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
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        m_bResolutionDown = new QPushButton(m_zoneVideoQuality);
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

        m_sliderResolution = new QSlider(m_zoneVideoQuality);
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

        m_bResolutionUp = new QPushButton(m_zoneVideoQuality);
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
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        m_lbFPS = new QLabel(m_zoneVideoQuality);
        m_lbFPS->setObjectName(QStringLiteral("m_lbFPS"));
        m_lbFPS->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_9->addWidget(m_lbFPS);

        m_lbValueFPS = new QLabel(m_zoneVideoQuality);
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
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        m_bFPSDown = new QPushButton(m_zoneVideoQuality);
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

        m_sliderFPS = new QSlider(m_zoneVideoQuality);
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

        m_bFPSUp = new QPushButton(m_zoneVideoQuality);
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
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        m_lbBitrate = new QLabel(m_zoneVideoQuality);
        m_lbBitrate->setObjectName(QStringLiteral("m_lbBitrate"));
        m_lbBitrate->setStyleSheet(QString::fromUtf8(" QLabel{\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 color: #666666;\n"
" }"));

        horizontalLayout_11->addWidget(m_lbBitrate);

        m_lbValueBitrate = new QLabel(m_zoneVideoQuality);
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
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        m_bBitrateDown = new QPushButton(m_zoneVideoQuality);
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

        m_sliderBitrate = new QSlider(m_zoneVideoQuality);
        m_sliderBitrate->setObjectName(QStringLiteral("m_sliderBitrate"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_sliderBitrate->sizePolicy().hasHeightForWidth());
        m_sliderBitrate->setSizePolicy(sizePolicy2);
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

        m_bBitrateUp = new QPushButton(m_zoneVideoQuality);
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


        verticalLayout_5->addLayout(verticalLayout_15);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_8);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_13->addWidget(m_zoneVideoQuality);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_8);

        horizontalLayout_13->setStretch(1, 3);
        horizontalLayout_13->setStretch(5, 5);

        verticalLayout_7->addLayout(horizontalLayout_13);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(2, 6);

        verticalLayout_9->addLayout(verticalLayout_7);

        verticalSpacer_19 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer_19);


        verticalLayout_11->addLayout(verticalLayout_9);


        retranslateUi(ZegoSettingsDialog);

        QMetaObject::connectSlotsByName(ZegoSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ZegoSettingsDialog)
    {
        ZegoSettingsDialog->setWindowTitle(QApplication::translate("ZegoSettingsDialog", "Settings", Q_NULLPTR));
        m_lbTitle->setText(QApplication::translate("ZegoSettingsDialog", "\350\256\276\347\275\256", Q_NULLPTR));
        m_bMin->setText(QString());
        m_bClose->setText(QString());
        m_lbSdkTitle->setText(QApplication::translate("ZegoSettingsDialog", "SDK\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
        m_lbSdkVersion->setText(QApplication::translate("ZegoSettingsDialog", "Version", Q_NULLPTR));
        m_bUploadLog->setText(QApplication::translate("ZegoSettingsDialog", "\344\270\212\344\274\240\346\227\245\345\277\227", Q_NULLPTR));
        m_bSaveSettings->setText(QApplication::translate("ZegoSettingsDialog", "\344\277\235\345\255\230\350\256\276\347\275\256", Q_NULLPTR));
        m_lbAccount->setText(QApplication::translate("ZegoSettingsDialog", "Account", Q_NULLPTR));
        m_lbUserId->setText(QApplication::translate("ZegoSettingsDialog", "\347\224\250\346\210\267ID", Q_NULLPTR));
        m_lbUserName->setText(QApplication::translate("ZegoSettingsDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("ZegoSettingsDialog", "Environment", Q_NULLPTR));
        label_7->setText(QApplication::translate("ZegoSettingsDialog", "App \347\211\210\346\234\254", Q_NULLPTR));
        label_8->setText(QApplication::translate("ZegoSettingsDialog", "\346\265\213\350\257\225\347\216\257\345\242\203", Q_NULLPTR));
        m_switchTestEnv->setText(QString());
        m_lbAPPID_2->setText(QApplication::translate("ZegoSettingsDialog", "APP ID", Q_NULLPTR));
        m_lbAPPSign_2->setText(QApplication::translate("ZegoSettingsDialog", "APP Sign", Q_NULLPTR));
        m_lbVideo->setText(QApplication::translate("ZegoSettingsDialog", "Video", Q_NULLPTR));
        label_10->setText(QApplication::translate("ZegoSettingsDialog", "\350\247\206\351\242\221\345\217\202\346\225\260", Q_NULLPTR));
        m_lbSurfaceMerge->setText(QApplication::translate("ZegoSettingsDialog", "\345\261\217\345\271\225\347\233\264\346\222\255", Q_NULLPTR));
        m_switchSurfaceMerge->setText(QString());
        m_lbResolution->setText(QApplication::translate("ZegoSettingsDialog", "\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        m_lbValueResolution->setText(QApplication::translate("ZegoSettingsDialog", "unknown", Q_NULLPTR));
        m_bResolutionDown->setText(QString());
        m_bResolutionUp->setText(QString());
        m_lbFPS->setText(QApplication::translate("ZegoSettingsDialog", "\345\270\247\347\216\207", Q_NULLPTR));
        m_lbValueFPS->setText(QApplication::translate("ZegoSettingsDialog", "unknown", Q_NULLPTR));
        m_bFPSDown->setText(QString());
        m_bFPSUp->setText(QString());
        m_lbBitrate->setText(QApplication::translate("ZegoSettingsDialog", "\347\240\201\347\216\207", Q_NULLPTR));
        m_lbValueBitrate->setText(QApplication::translate("ZegoSettingsDialog", "unknown", Q_NULLPTR));
        m_bBitrateDown->setText(QString());
        m_bBitrateUp->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ZegoSettingsDialog: public Ui_ZegoSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEGOSETTINGSDIALOG_H
