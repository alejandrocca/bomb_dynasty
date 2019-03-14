#ifndef ICON_H
#define ICON_H

#include "player.h"

/**
 * @brief The specialIcon class
 * Backend c++ class that includes the position and type of a powerup.
 */
class specialIcon{

    int xpos;
    int ypos;
    size_t type = 0;

public:
    /**
     * @brief specialIcon constructor
     * @param <int> x, y - position of powerup
     */
    specialIcon(const int& x = 0, const int& y = 0):xpos(x), ypos(y){}

    /**
     * Mutators
     * @param <const int&> x, y, <const size_t&> t
     */
    void set_xpos(const int& x){xpos = x;}
    void set_ypos(const int& y){ypos = y;}
    void set_type(const size_t& t){type = t;}

    /**
     * Accesors
     * @return <const int> xpos, ypos, <const size_t> type
     */
    int get_xpos() const{return xpos;}
    int get_ypos() const{return ypos;}
    size_t get_type() const{return type;}

};


// Non-member Powerup Functors

/**
 * @brief The reverse_dir function object
 * @param <Player&> person
 * Functor: reverses Player p's key actions
 */

class reverse_dir{
    Player& person;
public:
    reverse_dir(Player& p):person(p){}
    void operator()(){
        person.set_reverse(false);
                     }
};


/**
 * @brief The end_ghost function object
 * @param <Player&> person
 * Functor: ends ghost mode for Player p
 */
class end_ghost{
    Player& person;
public:
    end_ghost(Player& p):person(p){}
    void operator()(){
        person.set_ghost(false);
    }
};

/**
 * @brief The end_push function object
 * @param <Player&> p
 * Functor: ends push mode for Player p
 */
class end_push{
    Player& person;
public:
    end_push(Player& p):person(p){}
    void operator()(){
        person.set_push(false);
    }
};

/**
 * @brief The end_shield function object
 * @param <Player&> person
 * Functor: ends shield mode for Player p
 */
class end_shield{
    Player& person;
public:
    end_shield(Player& p):person(p){}
    void operator()(){
        person.set_shield(false);
    }
};




#endif // ICON_H
