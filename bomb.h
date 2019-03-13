#ifndef BOMB_H
#define BOMB_H

#include <QLabel>
#include <QPixmap>

//globals
const int LEFT = 1;
const int RIGHT = 2;
const int UP = 3;
const int DOWN = 4;

const int LU = 5;
const int LD = 6;
const int RU = 7;
const int RD = 8;

// Forward Declaration of classes
class GameFrame2;

class Player;

/**
 * @brief The Bomb class
 * C++ API class that includes the status and position of a bomb (backend)
 * while knowing the existence of the front end interface and stores graphics for the bomb （frontend).
 */
class Bomb
{
public:

    // Constructors and Destrctors
    Bomb(int x=0, int y=0, int p=0):xpos(x),ypos(y),power(p){}
    Bomb(GameFrame2* g, int x = 0, int y = 0);
    ~Bomb(){}

    /**
     * accessors
     * @return int/bool data member
    */
    int getAge() const{return age;}
    int getxpos() const{return xpos;}
    int getypos() const{return ypos;}
    int getpower() const {return power;}
    int if_activated() const{return activated;}
    int if_placed() const{return placed;}

    /**
     * mutator
     * @param x/y/a/p
     * sets xpos/ypos/activated/placed to @param
     */
    void setxpos(const int& x){xpos=x;}
    void setypos(const int& y){ypos=y;}
    void activate(const bool& a){activated = a;}
    void place(const bool& p){placed = p;}

private: 
    // Frontend Acknowledgement
    GameFrame2* game;
    friend class GameFrame2;

    // Backend Info
    int xpos;
    int ypos;
    int age;
    int power=1;
    bool activated = false;
    bool placed = false;

    // API: Graphics
    QLabel* bombgraphics;
    QLabel* bombedgraphics;
    QLabel* bombEffectL;
    QLabel* bombEffectR;
    QLabel* bombEffectU;
    QLabel* bombEffectD;
};


// Non-member functions of Bomb Class - forward declaration
/**
 * @brief is_active
 * @param <Bomb> bomb
 * @return <bool> if current bomb is activated
 */
bool is_active(const Bomb& bomb);

/**
 * @brief is_nonactive
 * @param <Bomb> bomb
 * @return <bool> if current bomb is not activated
 */
bool is_nonactive(const Bomb& bomb);

/**
 * @brief The Mine class
 * Similar to the Bomb class, a c++ API class that stores backend information(position and status)
 * as well as acknowledgement of frontend graphics and interface.
 */
class Mine{
public:
    // Constructor
    Mine(GameFrame2* g, Player* p);

    /**
     * accessors
     * @return int/bool data member
    */
    bool if_activated() const {return activated;}
    bool if_placed() const {return placed;}
    int get_xpos() const {return x;}
    int get_ypos() const {return y;}

    /**
     * mutator
     * @param x/y/a/p
     * sets xpos/ypos/activated/placed to @param
     */
    void set_xpos(const int& xpos){x = xpos;}
    void set_ypos(const int& ypos){y = ypos;}
    void set_activated(const bool& a) {activated = a;}
    void set_placed(const bool& p){placed = p;}

private:
    // API: Graphics
    GameFrame2* g;
    friend class GameFrame2;
    Player* p; // parent Player who owns the Mine
    QLabel* graphics;

    // Backend info
    int x;
    int y;
    bool activated = false;
    bool placed = false;


};

#endif // BOMB_H
