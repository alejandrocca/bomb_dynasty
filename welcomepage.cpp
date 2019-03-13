#include "welcomepage.h"
#include "ui_welcomepage.h"
#include <QMediaPlaylist>

/**
 * @brief WelcomePage::WelcomePage
 * @param parent , default = null,
 * inherits from QMainWindow object and WelcomePage Ui
 * set up QMediaPlayer with sounds
 */

WelcomePage::WelcomePage(QWidget *parent) :QMainWindow(parent), ui(new Ui::WelcomePage)   {

    ui->setupUi(this);

    QMediaPlaylist* playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sound_effects/Five_Armies.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    backgroundmusic=new QMediaPlayer();
    backgroundmusic->setPlaylist(playlist);
    backgroundmusic->play();

}

/**
 * @brief WelcomePage::~WelcomePage
 * deletes game which is not a direct child of welcomepage
 * deletes ui object
 */

WelcomePage::~WelcomePage(){
    delete game;
    delete ui;
    delete backgroundmusic;
}

void WelcomePage::keyPressEvent(QKeyEvent* event){

    if(event->key() == Qt::Key_Escape) {

        ui->stackedWidget->setCurrentIndex(0);
        update();
        QCoreApplication::processEvents();
    }

}

/**
 * @brief WelcomePage::on_welcomemenu_buttons_clicked
 * slot: next seven functions switch between pages on welcomepage ui stackedWidget
 */

void WelcomePage::on_settings_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void WelcomePage::on_enter_game_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void WelcomePage::on_help_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void WelcomePage::on_next_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void WelcomePage::on_back_to_main2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void WelcomePage::on_previous_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void WelcomePage::on_back_to_main_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/**
 * @brief WelcomePage::on_start_game_clicked
 * creates game with appropriate settings
 * hides welcomepage and shows game
 * connects quit button press signal of game to showing of welcomepage
 */

void WelcomePage::on_start_game_clicked()
{
    game = new GameFrame2(double_player, backgroundmusic->volume(), sound_effect_vol);

    connect(game, SIGNAL(quit_pressed()), this, SLOT(show()));
    connect(game, SIGNAL(bgm_vol_changed(int)), this, SLOT(change_bgm_volume(int)));
    connect(game, SIGNAL(effects_vol_changed(int)), this, SLOT(change_effects_volume(int)));


    this->hide();
    game->show();
}

/**
 * @brief WelcomePage::on_mode_selection_buttons_clicked
 * slot: next two functions changes double_player member field to true or false
 */

void WelcomePage::on_practicebutton_clicked()
{
    double_player = false;
}

void WelcomePage::on_doublebutton_clicked()
{
    double_player = true;
}

/**
 * @brief WelcomePage::on_vol_valueChanged
 * @param value on slider
 * slot: changes volume of media
 */

void WelcomePage::on_bgm_vol_valueChanged(int value)
{
    backgroundmusic->setVolume(value);
}

void WelcomePage::on_effects_vol_valueChanged(int value)
{
    sound_effect_vol=value;
}

void WelcomePage::on_backbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void WelcomePage::change_bgm_volume(int value)
{
    ui->bgm_vol->setValue(value);
}

void WelcomePage::change_effects_volume(int value)
{
    ui->effects_vol->setValue(value);
}

