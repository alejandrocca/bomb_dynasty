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
    // Constructor and destructor
    explicit GameFrame2(const bool& twoplayer, const int& b_volume, const int& e_volume, QWidget *parent = nullptr);
    ~GameFrame2() override;

    void keyPressEvent(QKeyEvent* event) override;
    Ui::GameFrame2 *ui;


    // Helper functions
    QPair<int,int> future_position(Player* p, const int& dir);
    bool hasObstacle(Player* p, const int& dir); //for player movement or bomb placement
    bool isNear(const Bomb& b) const;
    Bomb* hasBomb(Player* p, const int& dir);
    int explodeDist(Bomb* b, const int& dir);
    void push_bombAt(Player* p, const int& dir);
    void player_moves(Player* p, const int& dir);
    void set_double_player(const bool&);

    /**
     * @brief rand_pos
     * @return <int> - generates a random position in gamefield
     */
    int rand_pos(){
        return 70*(rand()%10);
    }


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
    void on_quit_game_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_bgm_slider_valueChanged(const int& value);
    void on_effects_slider_valueChanged(const int& value);
    void npc_moves();
    void remove_dead_timers();

private:
    bool double_player_mode=false;
    bool paused = false;
    QMediaPlayer* icon_sound;
    QMediaPlayer* explosion_sound;
    QMediaPlayer* mine_sound;
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    specialIcon* i1 = nullptr;
    specialIcon* i2 = nullptr;

    // Timer and timer functions
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

    // Graphics vectors
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

    // Graph array
    vector<int>* adj;

public:
    // Functors
    /**
     * @brief The explodeBomb class
     * @param <GameFrame2&> parent, <Bomb*> b
     */
    class explodeBomb{
        GameFrame2& parent;
        Bomb* b;
    public:
        explodeBomb(GameFrame2& parent, Bomb* bomb): parent(parent), b(bomb){}
        void operator()(){emit parent.explode_timer_out(b);}
    };

    /**
     * @brief The endFrozen class
     * @param <GameFrame2&> parent
     */
    class endFrozen{
        GameFrame2& parent;
    public:
        endFrozen(GameFrame2& parent): parent(parent){}
        void operator()();
    };

    /**
     * @brief The deactivateMine class
     * @param <GameFrame2&> parent, <Player*> p
     */
    class deactivateMine{
        GameFrame2& parent;
        Player* p;
    public:
        deactivateMine(GameFrame2& parent, Player* p) : parent(parent), p(p){}
        void operator()();
    };

    /**
     * @brief The clearBomb class
     * @param <GameFrame2&> parent, <Bomb*> b
     */
    class clearBomb{
        GameFrame2& parent;
        Bomb* b;
    public:
        clearBomb(GameFrame2& parent,Bomb* bomb): parent(parent), b(bomb){}
        void operator()(){
            emit parent.clear_timer_out(b);

        }
    };

    /**
     * @brief The push_graphics class
     * @param <GameFrame2&> parent, <Bomb*> b, <const int> d
     */
    class push_graphics{
        GameFrame2& parent;
        Bomb* b;
        const int d;
    public:
        push_graphics(GameFrame2& parent, Bomb* bomb, const int& dir):parent(parent), b(bomb), d(dir){}
        void operator()();
    };

    // Friend class for access
    friend class Bomb;
};



#endif // GAMEFRAME2_H
