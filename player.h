#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "bomb.h"

using std::vector;


// Forward Declaration of classes
class GameFrame2;
class Mine;

/**
 * @brief The Player class
 *
 */
class Player
{
public:

    // Constructor and Destructor
    Player(int i, GameFrame2* g);
    ~Player();

    /**
     * accessors
     * @return int/bool data member
    */
    int get_id() const;
    int get_xpos() const;
    int get_ypos() const;
    int get_speed() const;
    int get_power() const {return bombpower;}
    int get_bombcount() const {return bombcount;}
    int get_shield() const {return shield;}
    bool get_reverse() const {return reverse;}
    bool get_ghost() const {return ghost;}
    bool get_push() const {return push;}
    bool get_freeze() const {return freeze;}
    bool if_frozen() const {return frozen;}

    /**
     * mutator
     * @param x/y/a/p
     * sets xpos/ypos/activated/placed to @param
     */
    void powerup(){bombpower++;}
    void bombplus(){bombcount++;}
    void increase_speed(){speed *= 2;}
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void move(const int& dir);
    void set_xpos(const int& x){xpos = x;}
    void set_ypos(const int& y){ypos = y;}
    void set_reverse(const bool& r){reverse = r;}
    void set_ghost(const bool& g){ghost = g;}
    void set_speed(const int& s){speed = s;}
    void set_shield(const int& s){shield =s ;}
    void set_push(const bool& p){push = p;}
    void set_freeze(const bool& f){freeze = f;}
    void become_frozen(const bool& f){frozen = f;}


    GameFrame2* game;


    vector<Bomb> bombs;
    vector<Bomb>::iterator it();
    Mine* mine;
    //check written file for screenshots of welcome page, diagram of inheritance,
    //and detailed descriptions of each class

private:
    const int id;
    int xpos;
    int ypos;
    int speed = 70;
    int bombpower = 1;
    int bombcount = 1;
    bool reverse = 0;
    bool ghost = 0;
    bool push = 0;
    bool freeze = 0;
    bool frozen = 0;
    bool shield = 0;


};

#endif // PLAYER_H
