#include "player.h"

//to be implemented

/**
 * @brief Player::Player
 * @param id of player, 1 if player 1, 2 if player 2
 * sets starting position to bottom left corner if player id=1
 * sets starting position to top right corner if player id=2
 */
Player::Player(int i, GameFrame2* g) : game(g), id(i), xpos(0), ypos(630)
{
    //if second player, start on top right corner
    if (id == 1){
        xpos = 630;
        ypos = 0;
    }

    Bomb b1(g,xpos, ypos);
    b1.activate(true);
    Bomb b2(g,xpos, ypos); // activated when bomb+1 is triggered
    Bomb b3(g,xpos, ypos); // same as above
    bombs.push_back(b1);
    bombs.push_back(b2);
    bombs.push_back(b3);

    mine = new Mine(g, this);

}

/**
 * @brief Player::~Player
 * Destructor of Player object
 */
Player::~Player()
{
    //delete mine;
    mine=nullptr;
}



/**
 * @brief Player::get_id
 * @return id of player
 */

int Player::get_id() const{return id;}

/**
 * @brief Player::get_xpos
 * @return xpos of player
 */
int Player::get_xpos() const{return xpos;}

/**
 * @brief Player::get_ypos
 * @return ypos of player
 */

int Player::get_ypos() const{return ypos;}

/**
 * @brief Player::get_speed
 * @return speed of player
 */
int Player::get_speed() const{

    if(!reverse) return speed;
    else return -speed;
}

/**
 * @brief Player::move
 * @param <const int&> dir
 * Move player to assigned direction if future position not out of bound
 */
void Player::move(const int& dir){
    if(dir == LEFT)
        if(xpos-get_speed()>=0 && xpos-get_speed()<=630) xpos-=get_speed();
    if(dir == RIGHT)
        if(xpos+get_speed()>=0 && xpos+get_speed()<=630) xpos+=get_speed();
    if(dir == UP)
        if(ypos-get_speed()>=0 && ypos-get_speed()<=630) ypos-=get_speed();
    if(dir == DOWN)
       if(ypos+get_speed()>=0 && ypos+get_speed()<=630) ypos+=get_speed();
}

/**
 * @brief Player::it
 * @return <vector<Bomb>::iterator> iterator to the first bomb that is active and not placed
 */
vector<Bomb>::iterator Player::it(){
    vector<Bomb>::iterator iter = std::find_if(bombs.begin(), bombs.end(), is_active);
    while(iter != bombs.end()){
        if ((*iter).if_placed() == false){
            return iter;
        }
        else {
            iter = std::find_if(iter +1, bombs.end(), is_active);
        }
    }
    return iter;
}
