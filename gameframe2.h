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

/**
 * @brief The GameFrame2 class
 * @param of construction:
 *        <const bool&> twoplayer - 0 single or 1 double player mode
 *        <const int&> b_volume - bgm volume
 *        <const int&> e_volume - effect sound volume
 *        <QWidget*> parent - inheritance from QWidget
 *
 * The main gameframe class that inherits from QWidget. Keeps track of both players and bombs they own as well as special icons.
 */
class GameFrame2 : public QWidget
{
    Q_OBJECT

public:
    /*******constructors and destructors********/
    explicit GameFrame2(const bool& twoplayer, const int& b_volume, const int& e_volume, QWidget *parent = nullptr);
    ~GameFrame2() override;

    /********GameFrame2 public nested functors********/
    class GameEvent{
    public:
        GameEvent(GameFrame2& parent): parent(parent){}
        virtual ~GameEvent(){}
        virtual void operator()()=0;
        GameFrame2& parent;
    };

    /**
     * @brief The explodeBomb class
     * @param <GameFrame2&> parent, <Bomb*> b
     */
    class explodeBomb:public GameEvent{
        Bomb* b;
    public:
        explodeBomb(GameFrame2& parent, Bomb* bomb): GameEvent(parent), b(bomb){}
        virtual void operator()(){emit parent.explode_timer_out(b);}
    };

    /**
     * @brief The endFrozen class
     * @param <GameFrame2&> parent
     */
    class endFrozen:public GameEvent{
    public:
        endFrozen(GameFrame2& parent): GameEvent(parent){}
        virtual void operator()();
    };

    /**
     * @brief The deactivateMine class
     * @param <GameFrame2&> parent, <Player*> p
     */
    class deactivateMine:public GameEvent{
        Player* p;
    public:
        deactivateMine(GameFrame2& parent, Player* p) : GameEvent(parent), p(p){}
        virtual void operator()();
    };


    /**
     * @brief The clearBomb class
     * @param <GameFrame2&> parent, <Bomb*> b
     */
    class clearBomb:public GameEvent{
        Bomb* b;
    public:
        clearBomb(GameFrame2& parent,Bomb* bomb): GameEvent(parent), b(bomb){}
        virtual void operator()(){emit parent.clear_timer_out(b);}
    };


    /**
     * @brief The push_graphics class
     * @param <GameFrame2&> parent, <Bomb*> b, <const int> d
     */
    class push_graphics:public GameEvent{
        Bomb* b;
        const int d;
    public:
        push_graphics(GameFrame2& parent, Bomb* bomb, const int& dir):GameEvent(parent), b(bomb), d(dir){}
        virtual void operator()();
    };

    /*******helper functions********/
    QPair<int,int> future_position(Player* p, const int& dir);

    //for obstacle checking
    bool hasObstacle(Player* p, const int& dir);
    Bomb* hasBomb(Player* p, const int& dir);

    //for AI calculation
    bool isNear(const Bomb& b) const;

    //for bomb explosion, uses obstacle checkers
    int explodeDist(Bomb* b, const int& dir);

    //for icon placement
    int rand_pos(){return 70*(rand()%10);}

    //for handling events
    void keyPressEvent(QKeyEvent* event) override;
    void player_moves(Player* p, const int& dir);
    void push_bombAt(Player* p, const int& dir);
    void hide_status_icon(QLabel* icon, const int& time);
    void start_ss_timer(QTimer* t, const int& time);

    /********mutator********/
    void set_double_player(const bool&);

    /********public member********/
    Ui::GameFrame2 *ui;

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

    /**
     * volume scroll box emits this signal
     * connected to set the volume of bgm
     * @param <const int&> value
     */
    void bgm_vol_changed(const int& value);

    /**
     * volume scroll box emits this signal
     * connected to set the volume of effect sound
     * @param <const int&> value
     */
    void effects_vol_changed(const int& value);

    /**
     * emitted when player touches powerup
     * connected to release_effect(p,i)
     * @param <Player*> p - player who touches
     * @param <sepcialIcon*> i - the powerup being touched
     */
    void effect_triggered(Player* p, specialIcon* i);

    /**
     * emitted when the bomb release key is pressed
     * connected to place_bomb(p)
     * @param <Player*> p - player who pressed the key
     */
    void enter_pressed(Player* p);

    /**
     * emitted when the bomb release key is pressed to place mine
     * connected to place_mine(p)
     * @param p - player who pressed the key
     */
    void mine_pressed(Player* p);

    /**
     * emitted when the bomb release key is pressed to freeze
     * connected to freeze_around(p)
     * @param p - player who pressed the key
     */
    void freeze_pressed(Player* p);

    /**
     * emitted when bomb is placed
     * connected to start_timer(b) which explodes the bomb after timeout
     * @param b - bomb being placed
     */
    void bomb_placed(Bomb* b);

    /**
     * emitted when explodeBomb is called (when start_timer is timeout)
     * connected to bomb_explodes(b) and start_timer2(b) (explodes bomb and start clearing timer)
     * @param b
     */
    void explode_timer_out(Bomb* b);

    /**
     * emitted when clearBomb is called (when start_timer2 is timeout)
     * connected to clear_bomb(b)
     * @param b
     */
    void clear_timer_out(Bomb* b);

    /**
     * emitted whenever Player p is attacked (by bomb or mine)
     * connected to  end_game(p)
     * @param p - player who got attacked
     */
    void player_attacked(Player* p);

public slots:
    //general game input maintenance slots
    void toggle_menu();
    void on_quit_game_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_bgm_slider_valueChanged(const int& value);
    void on_effects_slider_valueChanged(const int& value);

    //game routine maintenance slots
    void drop_i1();
    void drop_i2();
    void npc_moves();
    void remove_dead_timers();

    //bomb slots
    void bomb_explodes(Bomb* b);
    void start_timer(Bomb* b);
    void start_timer2(Bomb* b);
    void clear_bomb(Bomb* b);

    //player slots
    void release_effect(Player* p, specialIcon* i);
    void place_mine(Player* p);
    void place_bomb(Player* p);
    void freeze_around(Player* p);
    void end_game(Player* p);

private:
    //media players
    QMediaPlayer* icon_sound;
    QMediaPlayer* explosion_sound;
    QMediaPlayer* mine_sound;

    //game states
    bool double_player_mode=false;
    bool paused = false;

    //game dynamic objects
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    specialIcon* i1 = nullptr;
    specialIcon* i2 = nullptr;

    //timer and timer functions
    QTimer* drop_icon_timer1=nullptr;
    QTimer* drop_icon_timer2=nullptr;
    QPair<QTimer*, int> resume_icon_timer1; //first = timer to correct drop_icon_timer timeouts after pause
    QPair<QTimer*, int> resume_icon_timer2; //second = time remaining for drop_icon_timer when paused
    vector< QPair<QTimer*,int> > ss_timers; //stores all the rest of pausable single shot timers
    QTimer* npcTimer = nullptr;
    void pause_icon_timers();
    void resume_icon_timers();
    void pause_ss_timers();
    void resume_ss_timers();

    /********Pixmap graphics for dynamic objects in game field********/
    const std::vector<QPixmap> icons = {
        QPixmap(":/gamefield_graphics/icons/bomb+1.jpg"),
        QPixmap(":/gamefield_graphics/icons/freeze.jpg"),
        QPixmap(":/gamefield_graphics/icons/ghost.jpg"),
        QPixmap(":/gamefield_graphics/icons/powerup.jpg"),
        QPixmap(":/gamefield_graphics/icons/push.jpg"),
        QPixmap(":/gamefield_graphics/icons/reverse.jpg"),
        QPixmap(":/gamefield_graphics/icons/shield.jpg"),
        QPixmap(":/gamefield_graphics/icons/mine.jpg")
    };

    const std::vector<QPixmap> bombmaps = {
        QPixmap(":/gamefield_graphics/bomb.png"),
        QPixmap(":/gamefield_graphics/bombed.png"),
        QPixmap(":/gamefield_graphics/hbeffect.png"),
        QPixmap(":/gamefield_graphics/vbeffect.png"),
    };

    const std::vector<QPixmap> playermaps = {
        QPixmap(":/gamefield_graphics/p1.PNG"),
        QPixmap(":/gamefield_graphics/p2.PNG"),
    };

    //collection of wall QLabels to keep track of wall positions
    std::vector<QLabel*> walls;

    //adjacency matrix
    vector<int>* adj;



    friend class Bomb;
};



#endif // GAMEFRAME2_H
