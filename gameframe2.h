#ifndef GAMEFRAME2_H
#define GAMEFRAME2_H

#include <QWidget>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QTimer>
#include <QPainter>
#include <QPair>

#include <stack>
#include <stdlib.h>
#include <time.h>
#include <graph.h>

namespace Ui {
class GameFrame2;
}

class GameFrame2 : public QWidget
{
    Q_OBJECT

public:
    //helper function
    QPair<int,int> future_position(Player* p, int dir);
    bool hasObstacle(Player* p, int dir); //for player movement or bomb placement
    bool isNear(const Bomb& b) const;
    Bomb* hasBomb(Player* p, int dir);
    int explodeDist(Bomb* b, int dir);
    void push_bombAt(Player* p, int dir);

    //constructor and destructor
    explicit GameFrame2(bool twoplayer, int b_volume, int e_volume, QWidget *parent = nullptr);
    ~GameFrame2() override;


    void keyPressEvent(QKeyEvent* event) override;
    void set_double_player(bool);
    Ui::GameFrame2 *ui;
    int rand_pos(){

        return 70*(rand()%10);
    }

    void player_moves(Player* p, int dir);


public:
    signals:
    /**
    * esc button keypress emits this signal
    * connected to slot toggle_menu
    */
    void pause_pressed();

    /**
    * quit button clicked emits this signal
    * connected to reset_game of gameframe and show() of welcome window
    */
    void quit_pressed();
    void bgm_vol_changed(int value);
    void effects_vol_changed(int value);

    void effect_triggered(Player* p, specialIcon* i);

    void enter_pressed(Player* p);
    void freeze_pressed(Player* p);
    void bomb_placed(Bomb* b);
    void explode_timer_out(Bomb* b);
    void clear_timer_out(Bomb* b);
    void bomb_exploded(Bomb* b);
    void bomb_cleared(Bomb* b);
    void player_attacked(Player* p);
    void mine_pressed(Player* p);




public slots:
    void toggle_menu();
    void drop_i1();
    void drop_i2();
    void release_effect(Player* p, specialIcon* i);
    void place_bomb(Player* p);
    void freeze_around(Player* p);
    void bomb_explodes(Bomb* b);
    void start_timer(Bomb* b);
    void start_timer2(Bomb* b);
    void clear_bomb(Bomb* b);
    void end_game(Player* p);
    void place_mine(Player* p);




private slots:
    void on_quit_game_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_bgm_slider_valueChanged(int value);

    void on_effects_slider_valueChanged(int value);

    void npc_key_gen();

    void npc_moves();

    void remove_dead_timers();

private:

    QMediaPlayer* icon_sound;
    QMediaPlayer* explosion_sound;
    QMediaPlayer* mine_sound;
    bool double_player_mode=false;
    bool paused = false;
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    //NPC* npc = nullptr;
    specialIcon* i1 = nullptr;
    specialIcon* i2 = nullptr;

    //timer and timer functions
    QTimer* timer1=nullptr; //drop icon timers
    QTimer* timer2=nullptr;
    QTimer* removeTimer = nullptr;
    QTimer* npcTimer = nullptr;
    int timer1_time_remaining = 0;
    int timer2_time_remaining = 0;
    vector< QPair<QTimer*,int> > ss_timers;

    void pause_icon_timers();
    void resume_icon_timers();
    void pause_ss_timers();
    void resume_ss_timers();

    const std::vector<QPixmap*> icons = {
        new QPixmap(":/gamefield_graphics/icons/bomb+1.jpg"),
        new QPixmap(":/gamefield_graphics/icons/freeze.jpg"),
        new QPixmap(":/gamefield_graphics/icons/ghost.jpg"),
        new QPixmap(":/gamefield_graphics/icons/powerup.jpg"),
        new QPixmap(":/gamefield_graphics/icons/push.jpg"),
        new QPixmap(":/gamefield_graphics/icons/reverse.jpg"),
        new QPixmap(":/gamefield_graphics/icons/shield.jpg"),
        new QPixmap(":/gamefield_graphics/icons/mine.jpg")
    };

    const std::vector<QPixmap*> bombmaps = {
        new QPixmap(":/gamefield_graphics/bomb.png"),
        new QPixmap(":/gamefield_graphics/bombed.png"),
        new QPixmap(":/gamefield_graphics/hbeffect.png"),
        new QPixmap(":/gamefield_graphics/vbeffect.png"),
    };

    const std::vector<QPixmap*> playermaps = {
        new QPixmap(":/gamefield_graphics/p1.PNG"),
        new QPixmap(":/gamefield_graphics/p2.PNG"),
    };

    std::vector<QLabel*> walls;

    vector<int>* adj;
public:
    class explodeBomb{
        GameFrame2& parent;
        Bomb* b;
    public:
        explodeBomb(GameFrame2& parent, Bomb* bomb): parent(parent), b(bomb){}
        void operator()(){emit parent.explode_timer_out(b);}
    };
    class endFrozen{
        GameFrame2& parent;
    public:
        endFrozen(GameFrame2& parent): parent(parent){}
        void operator()();
    };
    class deactivateMine{
        GameFrame2& parent;
        Player* p;
    public:
        deactivateMine(GameFrame2& parent, Player* p) : parent(parent), p(p){}
        void operator()();
    };
    class clearBomb{
        GameFrame2& parent;
        Bomb* b;
    public:
        clearBomb(GameFrame2& parent,Bomb* bomb): parent(parent), b(bomb){}
        void operator()(){
            emit parent.clear_timer_out(b);

        }
    };
    class push_graphics{
        GameFrame2& parent;
        Bomb* b;
        const int d;
    public:
        push_graphics(GameFrame2& parent, Bomb* bomb, const int& dir):parent(parent), b(bomb), d(dir){}
        void operator()();
    };
    friend class Bomb;
};



#endif // GAMEFRAME2_H
