#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QMainWindow>
#include <QRadioButton>
#include <QGridLayout>
#include <QPixmap>
#include <QPalette>
#include <QMediaPlayer>
#include <QStackedWidget>
#include "gameframe2.h"

namespace Ui {
class WelcomePage;
}

class WelcomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget *parent = nullptr);
    ~WelcomePage();

    void keyPressEvent(QKeyEvent* event);

public slots:
   void on_bgm_vol_valueChanged(int value);

private slots:
    void on_settings_button_clicked();

    void on_enter_game_clicked();

    void on_help_clicked();

    void on_next_page_clicked();

    void on_back_to_main2_clicked();

    void on_previous_page_clicked();

    void on_back_to_main_clicked();

    void on_start_game_clicked();


    void on_practicebutton_clicked();

    void on_doublebutton_clicked();

    void on_effects_vol_valueChanged(int value);

    void on_backbutton_clicked();

    void change_bgm_volume(int value);

    void change_effects_volume(int value);

private:

    Ui::WelcomePage *ui;
    QMediaPlayer* backgroundmusic;

    GameFrame2* game = nullptr;
    bool double_player = false;
    int sound_effect_vol=100;
    friend class GameFrame2;

};

#endif // WELCOMEPAGE_H
