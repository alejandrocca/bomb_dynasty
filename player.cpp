#include "player.h"

//to be implemented

/**
 * @brief Player::Player
 * @param id of player, 1 if player 1, 2 if player 2
 * sets starting position to bottom left corner if player id=1
 * sets starting position to top right corner if player id=2
 */
Player::Player(int i, GameFrame2* g):id(i), xpos(0), ypos(630), game(g)
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

Player::~Player()
{
    delete mine;
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
 * The following 4 functions adjusts player position
 * position is checked for validity by gameframe before passed to player
 */

void Player::move_left(){if(xpos-get_speed()>=0 && xpos-get_speed()<=630) xpos-=get_speed();}
void Player::move_right(){if(xpos+get_speed()>=0 && xpos+get_speed()<=630) xpos+=get_speed();}
void Player::move_up(){if(ypos-get_speed()>=0 && ypos-get_speed()<=630) ypos-=get_speed();}
void Player::move_down(){if(ypos+get_speed()>=0 && ypos+get_speed()<=630) ypos+=get_speed();}

void Player::move(const int& dir){
    if(dir == LEFT)
        move_left();
    if(dir == RIGHT)
        move_right();
    if(dir == UP)
        move_up();
    if(dir == DOWN)
        move_down();
}



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

//NPC::NPC(GameFrame2* g) : Player(2,g) {
//};


