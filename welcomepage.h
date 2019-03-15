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

/**
 * @brief The WelcomePage class
 * Front end class that inherits from QMainWindow
 * Includes:
 * - Setting page
 * - Help page(2 pgs)
 * - Playmode page
 * Connects to:
 * - GameFrame2* game
 */
class WelcomePage : public QMainWindow
{
    Q_OBJECT

// Detailed comments of member functions in cpp file

public:
    // Constructor, Destructor and keyPressEvent
    explicit WelcomePage(QWidget *parent = nullptr);
    ~WelcomePage();

    void keyPressEvent(QKeyEvent* event);

public slots:
   void on_bgm_vol_valueChanged(const int& value);
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
   void on_effects_vol_valueChanged(const int& value);
   void on_backbutton_clicked();
   void change_bgm_volume(const int& value);
   void change_effects_volume(const int& value);

private:
    // design mode access
    Ui::WelcomePage *ui;

    QMediaPlayer* backgroundmusic = nullptr;
    GameFrame2* game = nullptr;
    bool double_player = false;
    int sound_effect_vol=100;

    // friend class to access memberfields
    friend class GameFrame2;

};

#endif // WELCOMEPAGE_H
