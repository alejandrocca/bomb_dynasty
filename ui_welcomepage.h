/********************************************************************************
** Form generated from reading UI file 'welcomepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEPAGE_H
#define UI_WELCOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomePage
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *welcome;
    QLabel *title_pic;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *help;
    QPushButton *enter_game;
    QPushButton *settings_button;
    QWidget *settings;
    QPushButton *back_to_main;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QSlider *bgm_vol;
    QSlider *effects_vol;
    QLabel *bgm_label;
    QLabel *effects_label;
    QLabel *settings_label;
    QWidget *selection;
    QLabel *practicelabel;
    QLabel *label;
    QRadioButton *practicebutton;
    QLabel *doublelabel;
    QRadioButton *doublebutton;
    QPushButton *start_game;
    QPushButton *backbutton;
    QWidget *instructions1;
    QPushButton *next_page;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_26;
    QLabel *label_27;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QWidget *instructions2;
    QPushButton *back_to_main2;
    QPushButton *previous_page;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_19;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_9;
    QLabel *label_21;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_13;
    QLabel *label_18;
    QLabel *label_24;
    QLabel *label_20;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_11;
    QLabel *label_25;

    void setupUi(QMainWindow *WelcomePage)
    {
        if (WelcomePage->objectName().isEmpty())
            WelcomePage->setObjectName(QString::fromUtf8("WelcomePage"));
        WelcomePage->setEnabled(true);
        WelcomePage->resize(400, 300);
        WelcomePage->setMinimumSize(QSize(400, 300));
        WelcomePage->setMaximumSize(QSize(400, 300));
        WelcomePage->setAutoFillBackground(false);
        centralWidget = new QWidget(WelcomePage);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 400, 300));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        welcome = new QWidget();
        welcome->setObjectName(QString::fromUtf8("welcome"));
        title_pic = new QLabel(welcome);
        title_pic->setObjectName(QString::fromUtf8("title_pic"));
        title_pic->setGeometry(QRect(50, 10, 300, 225));
        title_pic->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/IMG_0447.PNG")));
        title_pic->setScaledContents(true);
        title_pic->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(welcome);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 240, 334, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        help = new QPushButton(horizontalLayoutWidget);
        help->setObjectName(QString::fromUtf8("help"));
        help->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";"));

        horizontalLayout->addWidget(help);

        enter_game = new QPushButton(horizontalLayoutWidget);
        enter_game->setObjectName(QString::fromUtf8("enter_game"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(enter_game->sizePolicy().hasHeightForWidth());
        enter_game->setSizePolicy(sizePolicy1);
        enter_game->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
""));

        horizontalLayout->addWidget(enter_game);

        settings_button = new QPushButton(horizontalLayoutWidget);
        settings_button->setObjectName(QString::fromUtf8("settings_button"));
        settings_button->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";"));

        horizontalLayout->addWidget(settings_button);

        stackedWidget->addWidget(welcome);
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/background.png);"));
        back_to_main = new QPushButton(settings);
        back_to_main->setObjectName(QString::fromUtf8("back_to_main"));
        back_to_main->setGeometry(QRect(270, 250, 114, 32));
        back_to_main->setAutoFillBackground(false);
        back_to_main->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image: url(:/gamefield_graphics/t.png);"));
        gridLayoutWidget = new QWidget(settings);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 50, 341, 131));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        bgm_vol = new QSlider(gridLayoutWidget);
        bgm_vol->setObjectName(QString::fromUtf8("bgm_vol"));
        bgm_vol->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        bgm_vol->setMaximum(100);
        bgm_vol->setValue(100);
        bgm_vol->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(bgm_vol, 1, 1, 1, 1);

        effects_vol = new QSlider(gridLayoutWidget);
        effects_vol->setObjectName(QString::fromUtf8("effects_vol"));
        effects_vol->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        effects_vol->setMaximum(100);
        effects_vol->setValue(100);
        effects_vol->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(effects_vol, 2, 1, 1, 1);

        bgm_label = new QLabel(gridLayoutWidget);
        bgm_label->setObjectName(QString::fromUtf8("bgm_label"));
        bgm_label->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_2->addWidget(bgm_label, 1, 0, 1, 1);

        effects_label = new QLabel(gridLayoutWidget);
        effects_label->setObjectName(QString::fromUtf8("effects_label"));
        effects_label->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        effects_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(effects_label, 2, 0, 1, 1);

        settings_label = new QLabel(gridLayoutWidget);
        settings_label->setObjectName(QString::fromUtf8("settings_label"));
        settings_label->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        settings_label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(settings_label, 0, 0, 1, 1);

        stackedWidget->addWidget(settings);
        selection = new QWidget();
        selection->setObjectName(QString::fromUtf8("selection"));
        selection->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/background.png);"));
        practicelabel = new QLabel(selection);
        practicelabel->setObjectName(QString::fromUtf8("practicelabel"));
        practicelabel->setGeometry(QRect(20, 80, 160, 120));
        practicelabel->setMouseTracking(false);
        practicelabel->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/practicepic.jpg")));
        practicelabel->setScaledContents(true);
        label = new QLabel(selection);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 151, 16));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image: url(:/t.png);"));
        practicebutton = new QRadioButton(selection);
        practicebutton->setObjectName(QString::fromUtf8("practicebutton"));
        practicebutton->setGeometry(QRect(20, 210, 181, 20));
        practicebutton->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image: url(:/t.png);"));
        practicebutton->setChecked(true);
        doublelabel = new QLabel(selection);
        doublelabel->setObjectName(QString::fromUtf8("doublelabel"));
        doublelabel->setGeometry(QRect(220, 80, 160, 120));
        doublelabel->setMouseTracking(false);
        doublelabel->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/doubleplayerpic.jpg")));
        doublelabel->setScaledContents(true);
        doublebutton = new QRadioButton(selection);
        doublebutton->setObjectName(QString::fromUtf8("doublebutton"));
        doublebutton->setGeometry(QRect(220, 210, 171, 20));
        doublebutton->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image: url(:/t.png);"));
        start_game = new QPushButton(selection);
        start_game->setObjectName(QString::fromUtf8("start_game"));
        start_game->setGeometry(QRect(140, 240, 114, 51));
        start_game->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image:url(:/gamefield_graphics/transparent.png);"));
        backbutton = new QPushButton(selection);
        backbutton->setObjectName(QString::fromUtf8("backbutton"));
        backbutton->setGeometry(QRect(10, 10, 51, 41));
        backbutton->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image:url(:/gamefield_graphics/transparent.png);"));
        stackedWidget->addWidget(selection);
        instructions1 = new QWidget();
        instructions1->setObjectName(QString::fromUtf8("instructions1"));
        instructions1->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/background.png);"));
        next_page = new QPushButton(instructions1);
        next_page->setObjectName(QString::fromUtf8("next_page"));
        next_page->setGeometry(QRect(270, 250, 114, 32));
        next_page->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image: url(:/gamefield_graphics/t.png);"));
        gridLayoutWidget_2 = new QWidget(instructions1);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 50, 341, 121));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
""));

        gridLayout_3->addWidget(label_4, 0, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);"));

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);"));

        gridLayout_3->addWidget(label_5, 1, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);"));

        gridLayout_3->addWidget(label_3, 1, 1, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setMinimumSize(QSize(40, 40));
        label_26->setMaximumSize(QSize(40, 40));
        label_26->setBaseSize(QSize(40, 40));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p1.PNG")));
        label_26->setScaledContents(true);

        gridLayout_3->addWidget(label_26, 0, 0, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setMinimumSize(QSize(40, 40));
        label_27->setMaximumSize(QSize(40, 40));
        label_27->setBaseSize(QSize(40, 40));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p2.PNG")));
        label_27->setScaledContents(true);

        gridLayout_3->addWidget(label_27, 1, 0, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(instructions1);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 170, 341, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);"));

        horizontalLayout_3->addWidget(label_6);

        stackedWidget->addWidget(instructions1);
        instructions2 = new QWidget();
        instructions2->setObjectName(QString::fromUtf8("instructions2"));
        instructions2->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/background.png);"));
        back_to_main2 = new QPushButton(instructions2);
        back_to_main2->setObjectName(QString::fromUtf8("back_to_main2"));
        back_to_main2->setGeometry(QRect(270, 250, 114, 32));
        back_to_main2->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image:url(:/gamefield_graphics/transparent.png);"));
        previous_page = new QPushButton(instructions2);
        previous_page->setObjectName(QString::fromUtf8("previous_page"));
        previous_page->setGeometry(QRect(10, 250, 114, 32));
        previous_page->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";\n"
"background-image:url(:/gamefield_graphics/transparent.png);"));
        gridLayoutWidget_3 = new QWidget(instructions2);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 20, 361, 224));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(gridLayoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/ghost.jpg")));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_19, 3, 2, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_16, 1, 3, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_14, 4, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/mine.jpg")));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_21, 3, 3, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_10, 2, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_12, 3, 1, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_22, 4, 3, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_23->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        gridLayout_4->addWidget(label_23, 0, 0, 1, 2);

        label_13 = new QLabel(gridLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/shield.jpg")));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_13, 4, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_18, 2, 3, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_24->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(label_24, 0, 2, 1, 2);

        label_20 = new QLabel(gridLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/reverse.jpg")));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_20, 4, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_8, 1, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/push.jpg")));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/powerup.jpg")));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_15, 1, 2, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/bomb+1.jpg")));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_17, 2, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/freeze.jpg")));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_11, 3, 0, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 75 10pt \"MS Sans Serif\";"));

        gridLayout_4->addWidget(label_25, 5, 0, 1, 4);

        stackedWidget->addWidget(instructions2);
        WelcomePage->setCentralWidget(centralWidget);

        retranslateUi(WelcomePage);

        QMetaObject::connectSlotsByName(WelcomePage);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomePage)
    {
        WelcomePage->setWindowTitle(QApplication::translate("WelcomePage", "Bomb Dynasty", nullptr));
        title_pic->setText(QString());
        help->setText(QApplication::translate("WelcomePage", "How To Play", nullptr));
        enter_game->setText(QApplication::translate("WelcomePage", "Enter Game", nullptr));
        settings_button->setText(QApplication::translate("WelcomePage", "Settings", nullptr));
        back_to_main->setText(QApplication::translate("WelcomePage", "Back", nullptr));
        bgm_label->setText(QApplication::translate("WelcomePage", "Background music Vol:", nullptr));
        effects_label->setText(QApplication::translate("WelcomePage", "Sound Effects Vol:", nullptr));
        settings_label->setText(QApplication::translate("WelcomePage", "<html><head/><body><p><span style=\" font-size:18pt; color:#000000;\">Settings</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        practicelabel->setToolTip(QApplication::translate("WelcomePage", "Play with the computer.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        practicelabel->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        practicelabel->setText(QString());
        label->setText(QApplication::translate("WelcomePage", "Select Play Mode:", nullptr));
#ifndef QT_NO_TOOLTIP
        practicebutton->setToolTip(QApplication::translate("WelcomePage", "Play with the computer.", nullptr));
#endif // QT_NO_TOOLTIP
        practicebutton->setText(QApplication::translate("WelcomePage", "Single Player Mode", nullptr));
#ifndef QT_NO_TOOLTIP
        doublelabel->setToolTip(QApplication::translate("WelcomePage", "Play with a friend!", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        doublelabel->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        doublelabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        doublebutton->setToolTip(QApplication::translate("WelcomePage", "Play with a friend!", nullptr));
#endif // QT_NO_TOOLTIP
        doublebutton->setText(QApplication::translate("WelcomePage", "Double Player Mode", nullptr));
        start_game->setText(QApplication::translate("WelcomePage", "Start Game", nullptr));
        backbutton->setText(QApplication::translate("WelcomePage", "<-", nullptr));
        next_page->setText(QApplication::translate("WelcomePage", "Next", nullptr));
        label_4->setText(QApplication::translate("WelcomePage", "<html><head/><body><p>Arrow keys to move around<br/>Enter key to place bomb</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("WelcomePage", "Player 1", nullptr));
        label_5->setText(QApplication::translate("WelcomePage", "<html><head/><body><p>W, A, S, D to move around<br/>Space key to place bomb</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("WelcomePage", "<html><head/><body><p>Player 2<br/>(PvP mode)</p></body></html>", nullptr));
        label_26->setText(QString());
        label_27->setText(QString());
        label_6->setText(QApplication::translate("WelcomePage", "<html><head/><body><p>Press Esc in game to toggle menu.<br/>Last one standing wins!</p></body></html>", nullptr));
        back_to_main2->setText(QApplication::translate("WelcomePage", "Done", nullptr));
        previous_page->setText(QApplication::translate("WelcomePage", "Back", nullptr));
#ifndef QT_NO_TOOLTIP
        label_19->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Gain abilities to walk through and place bombs in walls for 10 seconds. Bombs placed in walls are invisible</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_19->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_16->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Bomb range permanently increases by 1 grid. Maximum 5 grids</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("WelcomePage", "<html><head/><body><p>Bomb Power Up</p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_14->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Protects player from bomb attacks for 10 seconds. Does not include mine attacks.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("WelcomePage", "Shield", nullptr));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Bomb drop override: places mine at current location. Mine explodes when stepped on or after 20 seconds, whichever comes first</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_9->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_21->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Gain abilities to walk through and place bombs in walls for 10 seconds. Bombs placed in walls are invisible</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_21->setText(QApplication::translate("WelcomePage", "Ghosting", nullptr));
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Bomb drop override: places mine at current location. Mine explodes when stepped on or after 20 seconds, whichever comes first</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("WelcomePage", "Mine", nullptr));
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Bomb drop override: freeze enemies around you for 2 seconds, single use and limited range</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("WelcomePage", "Freeze", nullptr));
#ifndef QT_NO_TOOLTIP
        label_22->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>When eaten, reverses direction keys for 10 seconds</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_22->setText(QApplication::translate("WelcomePage", "Reverse", nullptr));
        label_23->setText(QApplication::translate("WelcomePage", "<html><head/><body><p><span style=\" font-size:18pt; color:#000000;\">Power Ups</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Protects player from bomb attacks for 10 seconds. Does not include mine attacks.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_13->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_18->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Maximum bombs placed on screen permanently increases by one. Maximum 3 bombs per player</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_18->setText(QApplication::translate("WelcomePage", "<html><head/><body><p>Bomb +1</p></body></html>", nullptr));
        label_24->setText(QApplication::translate("WelcomePage", "<html><head/><body><p><span style=\" font-size:18pt; color:#000000;\">and Effects</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_20->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>When eaten, reverses direction keys for 10 seconds</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_20->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Gain ability to push away bombs for 10 seconds</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_8->setWhatsThis(QApplication::translate("WelcomePage", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_8->setText(QApplication::translate("WelcomePage", "<html><head/><body><p>Push Bomb</p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Gain ability to push away bombs for 10 seconds</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_7->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_15->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Bomb range permanently increases by 1 grid. Maximum 5 grids</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_15->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_17->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Maximum bombs placed on screen permanently increases by one. Maximum 3 bombs per player</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_17->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("WelcomePage", "<html><head/><body><p>Bomb drop override: freeze enemies around you for 2 seconds, single use and limited range</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_11->setText(QString());
        label_25->setText(QApplication::translate("WelcomePage", "<html><head/><body><p><span style=\" font-size:10pt;\">Hover to see description. Timed effects cannot be extended!<br/>Timed effects come with a short cooldown period.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomePage: public Ui_WelcomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEPAGE_H
