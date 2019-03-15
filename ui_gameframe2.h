/********************************************************************************
** Form generated from reading UI file 'gameframe2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFRAME2_H
#define UI_GAMEFRAME2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameFrame2
{
public:
    QStackedWidget *stackedWidget;
    QWidget *main_game;
    QGroupBox *groupBox;
    QLabel *p1_label;
    QLabel *icon;
    QLabel *icon_2;
    QLabel *icon_3;
    QLabel *icon_4;
    QLabel *icon_5;
    QLabel *icon_6;
    QLabel *icon_7;
    QLabel *icon_8;
    QGroupBox *groupBox_2;
    QLabel *p2_label;
    QLabel *icon_16;
    QLabel *icon_9;
    QLabel *icon_12;
    QLabel *icon_15;
    QLabel *icon_10;
    QLabel *icon_13;
    QLabel *icon_14;
    QLabel *icon_11;
    QLabel *label;
    QStackedWidget *gamefield;
    QWidget *winningPage;
    QFrame *winningFrame;
    QLabel *youWin;
    QLabel *winningPlayer;
    QLabel *queen;
    QPushButton *pushButton;
    QWidget *gamePage;
    QFrame *frame;
    QLabel *wall1;
    QLabel *wall2;
    QLabel *wall3;
    QLabel *wall4;
    QLabel *wall5;
    QLabel *wall6;
    QLabel *wall7;
    QLabel *wall8;
    QLabel *wall9;
    QLabel *wall10;
    QLabel *wall11;
    QLabel *wall12;
    QLabel *wall13;
    QLabel *wall14;
    QLabel *wall15;
    QLabel *wall16;
    QLabel *wall17;
    QLabel *wall18;
    QLabel *wall19;
    QLabel *wall20;
    QLabel *wall21;
    QLabel *wall22;
    QLabel *wall23;
    QLabel *wall24;
    QLabel *wall25;
    QLabel *wall26;
    QLabel *wall27;
    QLabel *wall28;
    QLabel *wall29;
    QLabel *wall30;
    QLabel *Player_2;
    QLabel *specialEffect1;
    QLabel *specialEffect2;
    QLabel *Player_1;
    QWidget *page;
    QFrame *end_practice_mode;
    QLabel *youWin_2;
    QLabel *winningPlayer_2;
    QLabel *queen_2;
    QPushButton *pushButton_2;
    QWidget *menu;
    QPushButton *quit_game;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QLabel *label_22;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_21;
    QLabel *label_8;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_7;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_20;
    QLabel *label_24;
    QLabel *label_23;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_26;
    QSlider *bgm_slider;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_25;
    QSlider *effects_slider;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *about;

    void setupUi(QWidget *GameFrame2)
    {
        if (GameFrame2->objectName().isEmpty())
            GameFrame2->setObjectName(QString::fromUtf8("GameFrame2"));
        GameFrame2->resize(1000, 750);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameFrame2->sizePolicy().hasHeightForWidth());
        GameFrame2->setSizePolicy(sizePolicy);
        GameFrame2->setMinimumSize(QSize(1000, 750));
        GameFrame2->setMaximumSize(QSize(1000, 750));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/gamefield_graphics/bombed.png"), QSize(), QIcon::Normal, QIcon::Off);
        GameFrame2->setWindowIcon(icon1);
        GameFrame2->setAutoFillBackground(true);
        stackedWidget = new QStackedWidget(GameFrame2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1000, 750));
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/background.png);"));
        main_game = new QWidget();
        main_game->setObjectName(QString::fromUtf8("main_game"));
        main_game->setAutoFillBackground(false);
        main_game->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/background.png);"));
        groupBox = new QGroupBox(main_game);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 241, 331));
        groupBox->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Fixedsys\";"));
        p1_label = new QLabel(groupBox);
        p1_label->setObjectName(QString::fromUtf8("p1_label"));
        p1_label->setGeometry(QRect(60, 70, 111, 121));
        p1_label->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p1.PNG")));
        p1_label->setScaledContents(true);
        icon = new QLabel(groupBox);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setGeometry(QRect(40, 230, 31, 31));
        icon->setStyleSheet(QString::fromUtf8("border-image: url(:/gamefield_graphics/icons/bomb+1.jpg) 0 0 0 0 stretch stretch;\n"
"color: rgb(255, 230, 230);"));
        icon->setAlignment(Qt::AlignCenter);
        icon_2 = new QLabel(groupBox);
        icon_2->setObjectName(QString::fromUtf8("icon_2"));
        icon_2->setGeometry(QRect(80, 230, 31, 31));
        icon_2->setStyleSheet(QString::fromUtf8("border-image:url(:/gamefield_graphics/icons/powerup.jpg) 0 0 0 0 stretch stretch;\n"
"color: rgb(255, 230, 230);"));
        icon_2->setAlignment(Qt::AlignCenter);
        icon_3 = new QLabel(groupBox);
        icon_3->setObjectName(QString::fromUtf8("icon_3"));
        icon_3->setGeometry(QRect(120, 230, 31, 31));
        icon_3->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/freeze.jpg")));
        icon_3->setScaledContents(true);
        icon_4 = new QLabel(groupBox);
        icon_4->setObjectName(QString::fromUtf8("icon_4"));
        icon_4->setGeometry(QRect(160, 230, 31, 31));
        icon_4->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/ghost.jpg")));
        icon_4->setScaledContents(true);
        icon_5 = new QLabel(groupBox);
        icon_5->setObjectName(QString::fromUtf8("icon_5"));
        icon_5->setGeometry(QRect(40, 270, 31, 31));
        icon_5->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/push.jpg")));
        icon_5->setScaledContents(true);
        icon_6 = new QLabel(groupBox);
        icon_6->setObjectName(QString::fromUtf8("icon_6"));
        icon_6->setGeometry(QRect(80, 270, 31, 31));
        icon_6->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/reverse.jpg")));
        icon_6->setScaledContents(true);
        icon_7 = new QLabel(groupBox);
        icon_7->setObjectName(QString::fromUtf8("icon_7"));
        icon_7->setGeometry(QRect(120, 270, 31, 31));
        icon_7->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/shield.jpg")));
        icon_7->setScaledContents(true);
        icon_8 = new QLabel(groupBox);
        icon_8->setObjectName(QString::fromUtf8("icon_8"));
        icon_8->setGeometry(QRect(160, 270, 31, 31));
        icon_8->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/mine.jpg")));
        icon_8->setScaledContents(true);
        groupBox_2 = new QGroupBox(main_game);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 390, 241, 331));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Fixedsys\";\n"
""));
        p2_label = new QLabel(groupBox_2);
        p2_label->setObjectName(QString::fromUtf8("p2_label"));
        p2_label->setEnabled(true);
        p2_label->setGeometry(QRect(60, 70, 111, 121));
        p2_label->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p2.PNG")));
        p2_label->setScaledContents(true);
        icon_16 = new QLabel(groupBox_2);
        icon_16->setObjectName(QString::fromUtf8("icon_16"));
        icon_16->setGeometry(QRect(160, 270, 31, 31));
        icon_16->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/mine.jpg")));
        icon_16->setScaledContents(true);
        icon_9 = new QLabel(groupBox_2);
        icon_9->setObjectName(QString::fromUtf8("icon_9"));
        icon_9->setGeometry(QRect(120, 230, 31, 31));
        icon_9->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/freeze.jpg")));
        icon_9->setScaledContents(true);
        icon_12 = new QLabel(groupBox_2);
        icon_12->setObjectName(QString::fromUtf8("icon_12"));
        icon_12->setEnabled(true);
        icon_12->setGeometry(QRect(80, 230, 31, 31));
        icon_12->setStyleSheet(QString::fromUtf8("border-image:url(:/gamefield_graphics/icons/powerup.jpg) 0 0 0 0 stretch stretch;\n"
"color: rgb(255, 230, 230);"));
        icon_12->setAlignment(Qt::AlignCenter);
        icon_15 = new QLabel(groupBox_2);
        icon_15->setObjectName(QString::fromUtf8("icon_15"));
        icon_15->setEnabled(true);
        icon_15->setGeometry(QRect(40, 230, 31, 31));
        icon_15->setStyleSheet(QString::fromUtf8("border-image: url(:/gamefield_graphics/icons/bomb+1.jpg) 0 0 0 0 stretch stretch;\n"
"color: rgb(255, 230, 230);"));
        icon_15->setAlignment(Qt::AlignCenter);
        icon_10 = new QLabel(groupBox_2);
        icon_10->setObjectName(QString::fromUtf8("icon_10"));
        icon_10->setGeometry(QRect(160, 230, 31, 31));
        icon_10->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/ghost.jpg")));
        icon_10->setScaledContents(true);
        icon_13 = new QLabel(groupBox_2);
        icon_13->setObjectName(QString::fromUtf8("icon_13"));
        icon_13->setGeometry(QRect(80, 270, 31, 31));
        icon_13->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/reverse.jpg")));
        icon_13->setScaledContents(true);
        icon_14 = new QLabel(groupBox_2);
        icon_14->setObjectName(QString::fromUtf8("icon_14"));
        icon_14->setGeometry(QRect(120, 270, 31, 31));
        icon_14->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/shield.jpg")));
        icon_14->setScaledContents(true);
        icon_11 = new QLabel(groupBox_2);
        icon_11->setObjectName(QString::fromUtf8("icon_11"));
        icon_11->setGeometry(QRect(40, 270, 31, 31));
        icon_11->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/push.jpg")));
        icon_11->setScaledContents(true);
        label = new QLabel(main_game);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 231, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Fixedsys"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";"));
        gamefield = new QStackedWidget(main_game);
        gamefield->setObjectName(QString::fromUtf8("gamefield"));
        gamefield->setGeometry(QRect(280, 30, 700, 700));
        winningPage = new QWidget();
        winningPage->setObjectName(QString::fromUtf8("winningPage"));
        winningFrame = new QFrame(winningPage);
        winningFrame->setObjectName(QString::fromUtf8("winningFrame"));
        winningFrame->setGeometry(QRect(0, 0, 700, 700));
        winningFrame->setAutoFillBackground(false);
        winningFrame->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/gamefield.png);"));
        winningFrame->setFrameShape(QFrame::StyledPanel);
        winningFrame->setFrameShadow(QFrame::Raised);
        youWin = new QLabel(winningFrame);
        youWin->setObjectName(QString::fromUtf8("youWin"));
        youWin->setGeometry(QRect(160, 10, 401, 131));
        youWin->setStyleSheet(QString::fromUtf8("font: 75 35pt \"Fixedsys\";\n"
"color: rgb(255, 255, 255);\n"
"background-image: url(:/gamefield_graphics/t.png);"));
        youWin->setScaledContents(false);
        youWin->setAlignment(Qt::AlignCenter);
        winningPlayer = new QLabel(winningFrame);
        winningPlayer->setObjectName(QString::fromUtf8("winningPlayer"));
        winningPlayer->setEnabled(true);
        winningPlayer->setGeometry(QRect(220, 190, 261, 281));
        winningPlayer->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/ribbons.png);"));
        winningPlayer->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p2.PNG")));
        winningPlayer->setScaledContents(true);
        queen = new QLabel(winningFrame);
        queen->setObjectName(QString::fromUtf8("queen"));
        queen->setEnabled(true);
        queen->setGeometry(QRect(110, 420, 501, 281));
        queen->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        queen->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/Queen.png")));
        queen->setScaledContents(true);
        pushButton = new QPushButton(winningFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 110, 251, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Fixedsys"));
        font1.setPointSize(11);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        gamefield->addWidget(winningPage);
        gamePage = new QWidget();
        gamePage->setObjectName(QString::fromUtf8("gamePage"));
        frame = new QFrame(gamePage);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/gamefield.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        wall1 = new QLabel(frame);
        wall1->setObjectName(QString::fromUtf8("wall1"));
        wall1->setGeometry(QRect(0, 0, 70, 70));
        wall1->setStyleSheet(QString::fromUtf8("border-image: url(:/gamefield_graphics/t.png);"));
        wall1->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall1->setScaledContents(true);
        wall2 = new QLabel(frame);
        wall2->setObjectName(QString::fromUtf8("wall2"));
        wall2->setGeometry(QRect(350, 350, 70, 70));
        wall2->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall2->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall2->setScaledContents(true);
        wall3 = new QLabel(frame);
        wall3->setObjectName(QString::fromUtf8("wall3"));
        wall3->setGeometry(QRect(70, 280, 70, 70));
        wall3->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall3->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall3->setScaledContents(true);
        wall4 = new QLabel(frame);
        wall4->setObjectName(QString::fromUtf8("wall4"));
        wall4->setGeometry(QRect(70, 210, 70, 70));
        wall4->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall4->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall4->setScaledContents(true);
        wall5 = new QLabel(frame);
        wall5->setObjectName(QString::fromUtf8("wall5"));
        wall5->setGeometry(QRect(0, 210, 70, 70));
        wall5->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall5->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall5->setScaledContents(true);
        wall6 = new QLabel(frame);
        wall6->setObjectName(QString::fromUtf8("wall6"));
        wall6->setGeometry(QRect(0, 140, 70, 70));
        wall6->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall6->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall6->setScaledContents(true);
        wall7 = new QLabel(frame);
        wall7->setObjectName(QString::fromUtf8("wall7"));
        wall7->setGeometry(QRect(210, 0, 70, 70));
        wall7->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall7->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall7->setScaledContents(true);
        wall8 = new QLabel(frame);
        wall8->setObjectName(QString::fromUtf8("wall8"));
        wall8->setGeometry(QRect(70, 0, 70, 70));
        wall8->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall8->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall8->setScaledContents(true);
        wall9 = new QLabel(frame);
        wall9->setObjectName(QString::fromUtf8("wall9"));
        wall9->setGeometry(QRect(140, 0, 70, 70));
        wall9->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall9->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall9->setScaledContents(true);
        wall10 = new QLabel(frame);
        wall10->setObjectName(QString::fromUtf8("wall10"));
        wall10->setGeometry(QRect(210, 210, 70, 70));
        wall10->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall10->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall10->setScaledContents(true);
        wall11 = new QLabel(frame);
        wall11->setObjectName(QString::fromUtf8("wall11"));
        wall11->setGeometry(QRect(630, 560, 70, 70));
        wall11->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall11->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall12 = new QLabel(frame);
        wall12->setObjectName(QString::fromUtf8("wall12"));
        wall12->setGeometry(QRect(560, 630, 70, 70));
        wall12->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall12->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall12->setScaledContents(true);
        wall13 = new QLabel(frame);
        wall13->setObjectName(QString::fromUtf8("wall13"));
        wall13->setGeometry(QRect(630, 630, 70, 70));
        wall13->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall13->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall13->setScaledContents(true);
        wall14 = new QLabel(frame);
        wall14->setObjectName(QString::fromUtf8("wall14"));
        wall14->setGeometry(QRect(420, 210, 70, 70));
        wall14->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall14->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall14->setScaledContents(true);
        wall15 = new QLabel(frame);
        wall15->setObjectName(QString::fromUtf8("wall15"));
        wall15->setGeometry(QRect(350, 280, 70, 70));
        wall15->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall15->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall15->setScaledContents(true);
        wall16 = new QLabel(frame);
        wall16->setObjectName(QString::fromUtf8("wall16"));
        wall16->setGeometry(QRect(280, 420, 70, 70));
        wall16->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall16->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall16->setScaledContents(true);
        wall17 = new QLabel(frame);
        wall17->setObjectName(QString::fromUtf8("wall17"));
        wall17->setGeometry(QRect(350, 420, 70, 70));
        wall17->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall17->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall17->setScaledContents(true);
        wall18 = new QLabel(frame);
        wall18->setObjectName(QString::fromUtf8("wall18"));
        wall18->setGeometry(QRect(350, 210, 70, 70));
        wall18->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall18->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall18->setScaledContents(true);
        wall19 = new QLabel(frame);
        wall19->setObjectName(QString::fromUtf8("wall19"));
        wall19->setGeometry(QRect(210, 280, 70, 70));
        wall19->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall19->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall19->setScaledContents(true);
        wall20 = new QLabel(frame);
        wall20->setObjectName(QString::fromUtf8("wall20"));
        wall20->setGeometry(QRect(560, 210, 70, 70));
        wall20->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall20->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall20->setScaledContents(true);
        wall21 = new QLabel(frame);
        wall21->setObjectName(QString::fromUtf8("wall21"));
        wall21->setGeometry(QRect(560, 140, 70, 70));
        wall21->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall21->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall21->setScaledContents(true);
        wall22 = new QLabel(frame);
        wall22->setObjectName(QString::fromUtf8("wall22"));
        wall22->setGeometry(QRect(560, 70, 70, 70));
        wall22->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall22->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall22->setScaledContents(true);
        wall23 = new QLabel(frame);
        wall23->setObjectName(QString::fromUtf8("wall23"));
        wall23->setGeometry(QRect(210, 630, 70, 70));
        wall23->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall23->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall23->setScaledContents(true);
        wall24 = new QLabel(frame);
        wall24->setObjectName(QString::fromUtf8("wall24"));
        wall24->setGeometry(QRect(140, 560, 70, 70));
        wall24->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall24->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall24->setScaledContents(true);
        wall25 = new QLabel(frame);
        wall25->setObjectName(QString::fromUtf8("wall25"));
        wall25->setGeometry(QRect(140, 630, 70, 70));
        wall25->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall25->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall25->setScaledContents(true);
        wall26 = new QLabel(frame);
        wall26->setObjectName(QString::fromUtf8("wall26"));
        wall26->setGeometry(QRect(70, 560, 70, 70));
        wall26->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall26->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall26->setScaledContents(true);
        wall27 = new QLabel(frame);
        wall27->setObjectName(QString::fromUtf8("wall27"));
        wall27->setGeometry(QRect(560, 280, 70, 70));
        wall27->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall27->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall27->setScaledContents(true);
        wall28 = new QLabel(frame);
        wall28->setObjectName(QString::fromUtf8("wall28"));
        wall28->setGeometry(QRect(490, 420, 70, 70));
        wall28->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall28->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall28->setScaledContents(true);
        wall29 = new QLabel(frame);
        wall29->setObjectName(QString::fromUtf8("wall29"));
        wall29->setGeometry(QRect(490, 490, 70, 70));
        wall29->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall29->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall29->setScaledContents(true);
        wall30 = new QLabel(frame);
        wall30->setObjectName(QString::fromUtf8("wall30"));
        wall30->setGeometry(QRect(420, 630, 70, 70));
        wall30->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        wall30->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/wall.jpg")));
        wall30->setScaledContents(true);
        Player_2 = new QLabel(frame);
        Player_2->setObjectName(QString::fromUtf8("Player_2"));
        Player_2->setEnabled(true);
        Player_2->setGeometry(QRect(0, 630, 70, 70));
        Player_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        Player_2->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        Player_2->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p2.PNG")));
        Player_2->setScaledContents(true);
        Player_2->setWordWrap(false);
        Player_2->setIndent(-1);
        specialEffect1 = new QLabel(frame);
        specialEffect1->setObjectName(QString::fromUtf8("specialEffect1"));
        specialEffect1->setGeometry(QRect(0, 560, 70, 70));
        specialEffect1->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/t.png);"));
        specialEffect1->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/powerup.jpg")));
        specialEffect1->setAlignment(Qt::AlignCenter);
        specialEffect2 = new QLabel(frame);
        specialEffect2->setObjectName(QString::fromUtf8("specialEffect2"));
        specialEffect2->setGeometry(QRect(0, 70, 70, 70));
        specialEffect2->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/t.png);"));
        specialEffect2->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/powerup.jpg")));
        specialEffect2->setAlignment(Qt::AlignCenter);
        Player_1 = new QLabel(frame);
        Player_1->setObjectName(QString::fromUtf8("Player_1"));
        Player_1->setGeometry(QRect(630, 0, 70, 70));
        Player_1->setAutoFillBackground(false);
        Player_1->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/t.png);"));
        Player_1->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p1.PNG")));
        Player_1->setScaledContents(true);
        gamefield->addWidget(gamePage);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        end_practice_mode = new QFrame(page);
        end_practice_mode->setObjectName(QString::fromUtf8("end_practice_mode"));
        end_practice_mode->setGeometry(QRect(0, 0, 700, 700));
        end_practice_mode->setAutoFillBackground(false);
        end_practice_mode->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/gamefield.png);"));
        end_practice_mode->setFrameShape(QFrame::StyledPanel);
        end_practice_mode->setFrameShadow(QFrame::Raised);
        youWin_2 = new QLabel(end_practice_mode);
        youWin_2->setObjectName(QString::fromUtf8("youWin_2"));
        youWin_2->setGeometry(QRect(160, 10, 401, 131));
        youWin_2->setStyleSheet(QString::fromUtf8("font: 75 35pt \"Fixedsys\";\n"
"color: rgb(255, 255, 255);\n"
"background-image: url(:/t.png);"));
        youWin_2->setScaledContents(false);
        youWin_2->setAlignment(Qt::AlignCenter);
        winningPlayer_2 = new QLabel(end_practice_mode);
        winningPlayer_2->setObjectName(QString::fromUtf8("winningPlayer_2"));
        winningPlayer_2->setEnabled(true);
        winningPlayer_2->setGeometry(QRect(220, 190, 261, 281));
        winningPlayer_2->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/ribbons.png);"));
        winningPlayer_2->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p2.PNG")));
        winningPlayer_2->setScaledContents(true);
        queen_2 = new QLabel(end_practice_mode);
        queen_2->setObjectName(QString::fromUtf8("queen_2"));
        queen_2->setEnabled(true);
        queen_2->setGeometry(QRect(110, 420, 501, 281));
        queen_2->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);"));
        queen_2->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/Queen.png")));
        queen_2->setScaledContents(true);
        pushButton_2 = new QPushButton(end_practice_mode);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 110, 251, 51));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        gamefield->addWidget(page);
        stackedWidget->addWidget(main_game);
        menu = new QWidget();
        menu->setObjectName(QString::fromUtf8("menu"));
        quit_game = new QPushButton(menu);
        quit_game->setObjectName(QString::fromUtf8("quit_game"));
        quit_game->setGeometry(QRect(10, 50, 161, 61));
        quit_game->setStyleSheet(QString::fromUtf8("background-image:url(:/gamefield_graphics/transparent.png);\n"
"font: 13pt \"Fixedsys\";"));
        gridLayoutWidget_3 = new QWidget(menu);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(540, 60, 441, 321));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(gridLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_10, 2, 1, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_22, 4, 3, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/freeze.jpg")));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_11, 3, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/powerup.jpg")));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_15, 1, 2, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_21, 3, 3, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_8, 1, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_16, 1, 3, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/ghost.jpg")));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_19, 3, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/mine.jpg")));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/shield.jpg")));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_13, 4, 0, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/bomb+1.jpg")));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_17, 2, 2, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_18, 2, 3, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/push.jpg")));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_14, 4, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_4->addWidget(label_12, 3, 1, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/icons/reverse.jpg")));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_20, 4, 2, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_24->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(label_24, 0, 2, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_23->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        gridLayout_4->addWidget(label_23, 0, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(menu);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 120, 611, 268));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 3);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_3->addWidget(label_5, 2, 2, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setMinimumSize(QSize(80, 80));
        label_26->setMaximumSize(QSize(80, 80));
        label_26->setBaseSize(QSize(80, 80));
        label_26->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p2.PNG")));
        label_26->setScaledContents(true);

        gridLayout_3->addWidget(label_26, 2, 0, 1, 1);

        bgm_slider = new QSlider(gridLayoutWidget_2);
        bgm_slider->setObjectName(QString::fromUtf8("bgm_slider"));
        bgm_slider->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        bgm_slider->setMaximum(100);
        bgm_slider->setValue(100);
        bgm_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(bgm_slider, 3, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_3->addWidget(label_3, 2, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_3->addWidget(label_4, 1, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        label_25->setMinimumSize(QSize(80, 80));
        label_25->setMaximumSize(QSize(80, 80));
        label_25->setBaseSize(QSize(80, 80));
        label_25->setStyleSheet(QString::fromUtf8("background-image: url(:/gamefield_graphics/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_25->setPixmap(QPixmap(QString::fromUtf8(":/gamefield_graphics/p1.PNG")));
        label_25->setScaledContents(true);

        gridLayout_3->addWidget(label_25, 1, 0, 1, 1);

        effects_slider = new QSlider(gridLayoutWidget_2);
        effects_slider->setObjectName(QString::fromUtf8("effects_slider"));
        effects_slider->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        effects_slider->setMaximum(100);
        effects_slider->setValue(99);
        effects_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(effects_slider, 4, 2, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_3->addWidget(label_27, 3, 1, 1, 1);

        label_28 = new QLabel(gridLayoutWidget_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));

        gridLayout_3->addWidget(label_28, 4, 1, 1, 1);

        label_29 = new QLabel(menu);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 0, 191, 21));
        label_29->setStyleSheet(QString::fromUtf8("background-image: url(:/t.png);\n"
"font: 11pt \"Fixedsys\";"));
        label_29->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        about = new QLabel(menu);
        about->setObjectName(QString::fromUtf8("about"));
        about->setGeometry(QRect(590, 620, 401, 111));
        about->setStyleSheet(QString::fromUtf8("font: 11pt \"Fixedsys\";"));
        about->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        stackedWidget->addWidget(menu);
        quit_game->raise();
        gridLayoutWidget_3->raise();
        gridLayoutWidget_2->raise();
        about->raise();
        label_29->raise();

        retranslateUi(GameFrame2);

        QMetaObject::connectSlotsByName(GameFrame2);
    } // setupUi

    void retranslateUi(QWidget *GameFrame2)
    {
        GameFrame2->setWindowTitle(QApplication::translate("GameFrame2", "Bomb Dynasty", nullptr));
        groupBox->setTitle(QApplication::translate("GameFrame2", "Player 1", nullptr));
        p1_label->setText(QString());
        icon->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-weight:600; color:#ffe6e6;\">1</span></p></body></html>", nullptr));
        icon_2->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-weight:600; color:#ffe6e6;\">1</span></p></body></html>", nullptr));
        icon_3->setText(QString());
        icon_4->setText(QString());
        icon_5->setText(QString());
        icon_6->setText(QString());
        icon_7->setText(QString());
        icon_8->setText(QString());
        groupBox_2->setTitle(QApplication::translate("GameFrame2", "Player 2", nullptr));
        p2_label->setText(QString());
        icon_16->setText(QString());
        icon_9->setText(QString());
        icon_12->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-weight:600; color:#ffe6e6;\">1</span></p></body></html>", nullptr));
        icon_15->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-weight:600; color:#ffe6e6;\">1</span></p></body></html>", nullptr));
        icon_10->setText(QString());
        icon_13->setText(QString());
        icon_14->setText(QString());
        icon_11->setText(QString());
        label->setText(QApplication::translate("GameFrame2", "Press Esc to toggle menu...", nullptr));
        youWin->setText(QApplication::translate("GameFrame2", "YOU WIN!", nullptr));
        winningPlayer->setText(QString());
        queen->setText(QString());
        pushButton->setText(QApplication::translate("GameFrame2", "R E T U R N   T O   M E N U", nullptr));
        wall1->setText(QString());
        wall2->setText(QString());
        wall3->setText(QString());
        wall4->setText(QString());
        wall5->setText(QString());
        wall6->setText(QString());
        wall7->setText(QString());
        wall8->setText(QString());
        wall9->setText(QString());
        wall10->setText(QString());
        wall11->setText(QString());
        wall12->setText(QString());
        wall13->setText(QString());
        wall14->setText(QString());
        wall15->setText(QString());
        wall16->setText(QString());
        wall17->setText(QString());
        wall18->setText(QString());
        wall19->setText(QString());
        wall20->setText(QString());
        wall21->setText(QString());
        wall22->setText(QString());
        wall23->setText(QString());
        wall24->setText(QString());
        wall25->setText(QString());
        wall26->setText(QString());
        wall27->setText(QString());
        wall28->setText(QString());
        wall29->setText(QString());
        wall30->setText(QString());
        Player_2->setText(QString());
        specialEffect1->setText(QString());
        specialEffect2->setText(QString());
        Player_1->setText(QString());
        youWin_2->setText(QApplication::translate("GameFrame2", "YOU LOST!", nullptr));
        winningPlayer_2->setText(QString());
        queen_2->setText(QString());
        pushButton_2->setText(QApplication::translate("GameFrame2", "R E T U R N   T O   M E N U", nullptr));
#ifndef QT_NO_TOOLTIP
        quit_game->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Return to game selection menu</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        quit_game->setText(QApplication::translate("GameFrame2", "Quit Game", nullptr));
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Bomb drop override: places mine at current location. Explodes when stepped on or after 30 seconds, whichever comes first</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Mine</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_22->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>When eaten, reverses direction keys for 10 seconds</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_22->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Reverse</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Bomb drop override: freeze enemies around you for 2 seconds, single use and limited range</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_11->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_15->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Bomb range permanently increases by 1 grid. Maximum 5 grids</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_15->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_21->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Gain abilities to walk through and place bombs in walls for 10 seconds. Bombs placed in walls are invisible</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_21->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Ghosting</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Gain ability to push away bombs for 10 seconds</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_8->setWhatsThis(QApplication::translate("GameFrame2", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_8->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Push Bomb</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_16->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Bomb range permanently increases by 1 grid. Maximum 5 grids</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Bomb Power Up</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_19->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Gain abilities to walk through and place bombs in walls for 10 seconds. Bombs placed in walls are invisible</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_19->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Bomb drop override: places mine at current location. Explodes when stepped on or after 30 seconds, whichever comes first</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_9->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Protects you from one bomb attack</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_13->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_17->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Maximum bombs placed on screen permanently increases by one. Maximum 3 bombs per player</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_17->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_18->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Maximum bombs placed on screen permanently increases by one. Maximum 3 bombs per player</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_18->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Bomb +1</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Gain ability to push away bombs for 10 seconds</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_7->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_14->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Protects you from one bomb attack</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Shield</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>Bomb drop override: freeze enemies around you for 2 seconds, single use and limited range</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Freeze</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_20->setToolTip(QApplication::translate("GameFrame2", "<html><head/><body><p>When eaten, reverses direction keys for 10 seconds</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_20->setText(QString());
        label_24->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:18pt; color:#000000;\">and Effects</span></p></body></html>", nullptr));
        label_23->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:18pt; color:#000000;\">Power Ups</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:18pt; color:#000000;\">How To Play</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">W, A, S, D to move around<br/>Space key to place bomb</span></p></body></html>", nullptr));
        label_26->setText(QString());
        label_3->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Player 2 (two-player mode)</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Arrow keys to move around<br/>Enter key to place bomb</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">Player 1</span></p></body></html>", nullptr));
        label_25->setText(QString());
        label_27->setText(QApplication::translate("GameFrame2", "Background music volume:", nullptr));
        label_28->setText(QApplication::translate("GameFrame2", "Sound Effects volume:", nullptr));
        label_29->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" color:#000000;\">Press Esc to return to game...</span></p></body></html>", nullptr));
        about->setText(QApplication::translate("GameFrame2", "<html><head/><body><p><span style=\" font-size:14pt;\">About this game:</span><br/>The mechanic of this game is derived from &quot;Bomberman&quot;,<br/>originally released in 1987 by Hudson Soft.<br/>The background music used is Five Armies by The Descent.<br/>We do not own the original game idea nor the background music.<br/>All credits belong to original creators.<br/>This game is not for commercial usage.<br/>We reserve the right of interpretation.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameFrame2: public Ui_GameFrame2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFRAME2_H
