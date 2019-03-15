#include "gameframe2.h"
#include "ui_gameframe2.h"
#include <QString>

/****************global helper function****************/
/**
 * @brief isOutOfBounds
 * @param <int> xpos, ypos - positions being considered
 * @return <bool> - true if position is out of bounds, false otherwise
 */
bool isOutOfBounds(int xpos, int ypos){
    return (xpos>630||xpos<0||ypos>630||ypos<0);
}

/****************constructor and destructor****************/
/**
 * @brief GameFrame2::GameFrame2
 * @param twoplayer - two player mode, true if on
 * @param b_volume - background volume set by WelcomePage sliders, synced with GameFrame2 sliders
 * @param e_volume - effects volume set by WelcomePage sliders, synced with GF2 sliders
 * @param parent , default = null
 * inherits from QWidget object and GameFrame2 Ui
 * called when WelcomePage start game button is clicked
 * initializes game components and connects basic game maintenance signals and slots
 */

GameFrame2::GameFrame2(const bool& twoplayer, const int& b_volume, const int& e_volume, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFrame2),
    double_player_mode(twoplayer)
{
    //set up UI
    ui->setupUi(this);

    /****************SOUND EFFECTS****************/
    icon_sound=new QMediaPlayer();
    icon_sound->setMedia(QUrl("qrc:/sound_effects/icon.mp3"));
    icon_sound->setVolume(e_volume);

    explosion_sound=new QMediaPlayer();
    explosion_sound->setMedia(QUrl("qrc:/sound_effects/explosion.mp3"));
    explosion_sound->setVolume(e_volume);

    mine_sound=new QMediaPlayer();
    mine_sound->setMedia(QUrl("qrc:/sound_effects/mine.mp3"));
    mine_sound->setVolume(e_volume);

    ui->bgm_slider->setValue(b_volume);
    ui->effects_slider->setValue(e_volume);

    /****************WALL & GRAPH INITIALIZATION****************/
    // Initializing wall vector
    {
        walls.push_back(ui->wall1);
        walls.push_back(ui->wall2);
        walls.push_back(ui->wall3);
        walls.push_back(ui->wall4);
        walls.push_back(ui->wall5);
        walls.push_back(ui->wall6);
        walls.push_back(ui->wall7);
        walls.push_back(ui->wall8);
        walls.push_back(ui->wall9);
        walls.push_back(ui->wall10);
        walls.push_back(ui->wall11);
        walls.push_back(ui->wall12);
        walls.push_back(ui->wall13);
        walls.push_back(ui->wall14);
        walls.push_back(ui->wall15);
        walls.push_back(ui->wall16);
        walls.push_back(ui->wall17);
        walls.push_back(ui->wall18);
        walls.push_back(ui->wall19);
        walls.push_back(ui->wall20);
        walls.push_back(ui->wall21);
        walls.push_back(ui->wall22);
        walls.push_back(ui->wall23);
        walls.push_back(ui->wall24);
        walls.push_back(ui->wall25);
        walls.push_back(ui->wall26);
        walls.push_back(ui->wall27);
        walls.push_back(ui->wall28);
        walls.push_back(ui->wall29);
        walls.push_back(ui->wall30);
    }

    // array of vectors is used to store the graph in the form of an adjacency list
     adj = new vector<int>[100];

    /** Creating graph given in the above diagram.
     * add_edge function takes adjacency list, source
     * and destination vertex as argument and forms
     * an edge between them.
    */
    for(int y = 0; y < 10; ++y){
        for(int x = 0; x < 10; ++x){
           if (std::find(walls.begin(),walls.end(), ui->frame->childAt(x*70, y*70)) == walls.end()){
              if(x!=9) add_edge(adj, y*10+x, y*10+x+1);
              if(y!=9) add_edge(adj, y*10+x, (y+1)*10+x);
            }
        }
    }

    /****************POWER UP AND PLAYER STAT ICON INITIALIZATION****************/
    // Initializing player stat icon graphics
    {
        ui->icon_3 ->hide();
        ui->icon_4 ->hide();
        ui->icon_5 ->hide();
        ui->icon_6 ->hide();
        ui->icon_7 ->hide();
        ui->icon_8 ->hide();
        ui->icon_9 ->hide();
        ui->icon_10 ->hide();
        ui->icon_11 ->hide();
        ui->icon_13 ->hide();
        ui->icon_14 ->hide();
        ui->icon_16 ->hide();

    }

    //initialize game field powerup icons
    i1 = new specialIcon;
    i2 = new specialIcon;
    ui->specialEffect1->hide();
    ui->specialEffect2 -> hide();

    //initialize drop power up timers
    drop_icon_timer1 = new QTimer(this); //Timer for icon 1
    connect(drop_icon_timer1, SIGNAL(timeout()), this, SLOT(drop_i1()));
    drop_icon_timer1->start(15000);

    drop_icon_timer2 = new QTimer(this); //Timer for icon 2
    connect(drop_icon_timer2, SIGNAL(timeout()), this, SLOT(drop_i2()));
    drop_icon_timer2->start(20000);

    //initialize pause-correction timers
    resume_icon_timer1.first = new QTimer(this);
    resume_icon_timer1.first->setSingleShot(true);
    resume_icon_timer1.second = 15000;
    resume_icon_timer2.first = new QTimer(this);
    resume_icon_timer2.first->setSingleShot(true);
    resume_icon_timer2.second = 20000;

    /****************PLAYER INITIALIZATION****************/
    p1 = new Player(1,this);
    p2 = new Player(2,this);
    if (double_player_mode)
        ui->groupBox_2->setTitle("Player 2");
    else{
        ui->groupBox_2->setTitle("Player 2 (Computer)");
        npcTimer = new QTimer(this); // Timer for NPC movement
        connect(npcTimer, SIGNAL(timeout()), this, SLOT(npc_moves()));
        npcTimer->start(300);
    }

    /****************TIMER-INDEPENDENT SLOT CONNECTIONS****************/

    //user-input signals and game maintenance signals
    connect(this, SIGNAL(pause_pressed()), this, SLOT(toggle_menu()));
    connect(this, SIGNAL(effect_triggered(Player*, specialIcon*)), this, SLOT(release_effect(Player*, specialIcon*)));
    connect(this, SIGNAL(player_attacked(Player*)), this, SLOT(end_game(Player*)));

    //player action signals
    connect(this, SIGNAL(freeze_pressed(Player*)), this, SLOT(freeze_around(Player*)));
    connect(this, SIGNAL(mine_pressed(Player*)), this, SLOT(place_mine(Player*)));

    //bomb-specific signals
    connect(this, SIGNAL(enter_pressed(Player*)), this, SLOT(place_bomb(Player*)));     // Player presses key -> player places bomb
    connect(this, SIGNAL(bomb_placed(Bomb*)),this, SLOT(start_timer(Bomb*)));           // Bomb is placed     -> start explosion timer
    connect(this, SIGNAL(explode_timer_out(Bomb*)), this, SLOT(start_timer2(Bomb*)));   // Explosion time out -> start clear timer
    connect(this, SIGNAL(explode_timer_out(Bomb*)), this, SLOT(bomb_explodes(Bomb*)));  //                    -> explodes bomb
    connect(this, SIGNAL(clear_timer_out(Bomb*)),this, SLOT(clear_bomb(Bomb*)));        // Clear time out     -> clears bomb

    /****************UPDATE GAME****************/
    //set current page as main game field
    ui->gamefield->setCurrentIndex(1);
    update();
}

/**
 * @brief GameFrame2::~GameFrame2
 * deletes ui object, players, specialIcons, media players, and graph
 * called at the start of next game or at the destruction of WelcomePage
 */

GameFrame2::~GameFrame2()
{
    delete ui;
    delete p1;
    delete p2;
    delete i1;
    delete i2;
    delete icon_sound;
    delete explosion_sound;
    delete mine_sound;
    delete[] adj;
}

/****************member helper functionsr****************/
/**
 * @brief GameFrame2::future_position
 * @param <Player*> p
 *        <int> dir - direction Player is facing
 * @return <QPair<int, int>> - a pair of int that contains the player's predicted position for the next movement
 */
QPair<int,int> GameFrame2::future_position(Player* p, const int& dir){
    int future_xpos;
    int future_ypos;
    switch(dir){
    case LEFT:
        future_xpos = p->get_xpos()-p->get_speed();
        future_ypos=p->get_ypos();
        break;
    case RIGHT:
        future_xpos = p->get_xpos()+p->get_speed();
        future_ypos=p->get_ypos();
        break;
    case UP:
        future_ypos = p->get_ypos()-p->get_speed();
        future_xpos=p->get_xpos();
        break;
    case DOWN:
        future_ypos = p->get_ypos()+p->get_speed();
        future_xpos=p->get_xpos();
        break;
    case LU:
        future_xpos = p->get_xpos()-p->get_speed();
        future_ypos=p->get_ypos()-p->get_speed();
        break;
    case LD:
        future_xpos = p->get_xpos()-p->get_speed();
        future_ypos=p->get_ypos()+p->get_speed();
        break;
    case RU:
        future_ypos = p->get_ypos()+p->get_speed();
        future_xpos=p->get_xpos()-p->get_speed();
        break;
    case RD:
        future_ypos = p->get_ypos()+p->get_speed();
        future_xpos=p->get_xpos()+p->get_speed();
        break;
    default:
        future_xpos=700;
        future_ypos=700;
        break;
    }
    QPair<int, int> pair;
    pair.first=future_xpos;
    pair.second=future_ypos;
    return pair;
}

/**
 * @brief GameFrame2::hasObstacle determines whether there is an obstacle (not including bombs) in the player's way
 * @param <Player*> p - the player that is moving
 * @param <Player*> dir - direction the player is going to
 * @return <bool> true if player is running out of bounds or running into a wall
 */
bool GameFrame2::hasObstacle(Player* p, const int& dir){
    QPair<int, int> future_pos = future_position(p,dir);
    int future_xpos=future_pos.first;
    int future_ypos=future_pos.second;

    bool hasPlayerObstacle;
    if (p->get_id()==0){//test player
        if (p2==nullptr) //single player mode
            hasPlayerObstacle=(p1->get_xpos()==future_xpos&&p1->get_ypos()==future_ypos);
        else { //double player mode, check both player's positions
            hasPlayerObstacle=((p1->get_xpos()==future_xpos&&p1->get_ypos()==future_ypos) ||
                               (p1->get_xpos()==future_xpos&&p2->get_ypos()==future_ypos));
        }
    }
    else if (p->get_id()==2) //if p is player 2, check player1 position
        hasPlayerObstacle=(p1->get_xpos()==future_xpos&&p1->get_ypos()==future_ypos);
    else if (p2==nullptr) //if in single player mode, never running into another player
        hasPlayerObstacle=false;
    else {
        //if in double player mode and p is player 1, check player2 position
        hasPlayerObstacle=(p2->get_xpos()==future_xpos&&p2->get_ypos()==future_ypos);
    }
    bool hasIconObstacle=(ui->frame->childAt(future_xpos,future_ypos)==ui->specialEffect1
                          ||ui->frame->childAt(future_xpos,future_ypos)==ui->specialEffect2);

    bool hasWallObstacle = std::find(walls.begin(),walls.end(), ui->frame->childAt(future_xpos, future_ypos)) != walls.end();

    /*evaluates to true (i.e. there is an obstacle) if:
     * is running out of bounds OR
     * is running into an object that is NOT a player or icon
    */
    return (isOutOfBounds(future_xpos,future_ypos)||(hasWallObstacle&&(!hasPlayerObstacle)&&(!hasIconObstacle)));

}

/**
 * @brief GameFrame2::hasBomb if there is a bomb ahead of player
 * @param <Player*> p
 * @param <int> dir - direction Player p is travelling
 * @return <Bomb*> pointer to bomb if there is a bomb ahead of player, NULL otherwise
 */

Bomb* GameFrame2::hasBomb(Player* p, const int& dir){
    QPair<int, int> future_pos = future_position(p,dir);
    int xpos=future_pos.first;
    int ypos=future_pos.second;

    for (size_t k=0; k<p1->bombs.size();k++){
        // for each bomb in p1's bomb list
        if (p1->bombs[k].xpos==xpos && p1->bombs[k].ypos==ypos && p1->bombs[k].placed==true)
            // if p1 is at the bomb's position and the bomb is placed
            return &(p1->bombs[k]); // return that bomb (first bomb found)
    }
    if (p2!=nullptr){
        // if p2 is active
        for (size_t k=0; k<p2->bombs.size();k++){
            // for each bomb in p2's bomb list
            if (p2->bombs[k].xpos==xpos && p2->bombs[k].ypos==ypos && p2->bombs[k].placed==true)
                // if p1 is at the bomb's position and the bomb is placed
                return &(p2->bombs[k]); // return that bomb (first bomb found)
        }
    }
    return nullptr; // if not found return nullptr
}

/**
 * @brief GameFrame2::isNear
 * A predicate function to test if the NPC is near a bomb under the single player mode
 * @param <const Bomb&> b - bomb we are testing for
 * @return <const bool> returns true if that bomb is placed and near NPC
 */
bool GameFrame2::isNear(const Bomb &b) const{
    int npc_loc = p2->get_ypos()/7+p2->get_xpos()/70;
    int b_loc = b.getypos()/7+b.getxpos()/70;
    vector<int> path = ShortestPath(adj, b_loc, npc_loc);
    if (b.if_placed() == true &&path.size()<=3) return true;
    else return false;
}

/**
 * @brief GameFrame2::player_moves
 * @param p
 * @param dir
 */
void GameFrame2::player_moves(Player* p, const int& dir){
    //push bomb if able to
    if (hasBomb(p,dir)!=nullptr && p->get_push()==true)
        push_bombAt(p,dir);
    //if ghost mode off
    if (p->get_ghost() == false){
        if (!hasObstacle(p,dir)&&hasBomb(p,dir)==nullptr){
            p->move(dir);
            if(p->mine->if_placed()){
                p->mine->graphics->show();

                QTimer* timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), p->mine->graphics, SLOT(hide()));
                timer->callOnTimeout(deactivateMine(*this, p));
                start_ss_timer(timer, 20000);
            }
        }
    }
    //if ghost mode on
    else{
        if (!isOutOfBounds(p->get_xpos()-p->get_speed(),p->get_ypos()) && hasBomb(p,dir)==nullptr){
            p->move(dir);
            if(p->mine->if_placed()){
                p->mine->graphics->show();

                QTimer* timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), p->mine->graphics, SLOT(hide()));
                timer->callOnTimeout(deactivateMine(*this, p));
                start_ss_timer(timer, 20000);
            }
         }
    }
}

// Returns distance (in units of 70) of furthest grid within bomb power range that is not a wall at direction dir
int GameFrame2::explodeDist(Bomb* b, const int& dir){
    Player* temp = new Player(0,this);
    temp->set_xpos(b->getxpos());
    temp->set_ypos(b->getypos());
    int pos = 0;
    for(int i = 1; i <= b->getpower(); ++i){
        //temp->set_speed(i * 70);
        bool result = hasObstacle(temp, dir);
        if (result == true)//if there is an obstacle
            break;
        else{
            ++pos;
            QPair<int, int> future_pos=future_position(temp, dir);
            temp->set_xpos(future_pos.first);
            temp->set_ypos(future_pos.second);
        }
    }
    delete temp;
    return pos;
}

void GameFrame2::pause_icon_timers(){
    if (!resume_icon_timer1.first->isActive()){
        resume_icon_timer1.second=drop_icon_timer1->remainingTime();
        drop_icon_timer1->stop();
    }
    else {
        resume_icon_timer1.second=resume_icon_timer1.first->remainingTime();
        resume_icon_timer1.first->stop();
    }
    if (resume_icon_timer1.second < 0)
        resume_icon_timer1.second =0;

    if (!resume_icon_timer2.first->isActive()){
        resume_icon_timer2.second=drop_icon_timer2->remainingTime();
        drop_icon_timer2->stop();
    }
    else {
        resume_icon_timer2.second=resume_icon_timer2.first->remainingTime();
        resume_icon_timer2.first->stop();
    }
    if (resume_icon_timer2.second < 0)
        resume_icon_timer2.second =0;
}

void GameFrame2::resume_icon_timers(){
    resume_icon_timer1.first->start(resume_icon_timer1.second);
    connect(resume_icon_timer1.first,SIGNAL(timeout()), drop_icon_timer1, SIGNAL(timeout()));
    connect(resume_icon_timer1.first,SIGNAL(timeout()),drop_icon_timer1,SLOT(start()));

    resume_icon_timer2.first->start(resume_icon_timer2.second);
    connect(resume_icon_timer2.first,SIGNAL(timeout()), drop_icon_timer2, SIGNAL(timeout()));
    connect(resume_icon_timer2.first,SIGNAL(timeout()),drop_icon_timer2,SLOT(start()));
}

void GameFrame2::pause_ss_timers()
{
    for (size_t k=0;k<ss_timers.size();k++){
        if (ss_timers[k].first->isActive()){
            ss_timers[k].second = ss_timers[k].first->remainingTime();
            ss_timers[k].first->stop();
        }
        else {
            ss_timers[k].second = 0;
        }
    }
}

void GameFrame2::resume_ss_timers(){
    for (size_t k=0; k<ss_timers.size();k++){
        if (ss_timers[k].second > 0)
            ss_timers[k].first->start(ss_timers[k].second);
    }
}

/**
 * @brief GameFrame2::remove_dead_timers
 * slot: will be called at every timeout event of singleshot timers, will remove all the timers that are not running (timed out)
 */
void GameFrame2::remove_dead_timers(){
    for (vector< QPair<QTimer*,int> >::iterator it = ss_timers.begin(); it != ss_timers.end();){
        if (it->first->isActive() == false)
            it = ss_timers.erase(it);
        else
            ++it;
    }
}

void GameFrame2::hide_status_icon(QLabel *icon, int time){
    QTimer* t = new QTimer(this);
    connect(t,SIGNAL(timeout()),icon,SLOT(hide()));
    connect(t,SIGNAL(timeout()),this,SLOT(remove_dead_timers()));
    t->setSingleShot(true);
    t->start(time);
    QPair<QTimer*,int> pair(t,0);
    ss_timers.push_back(pair);

}

void GameFrame2::start_ss_timer(QTimer* t, int time){
    connect(t,SIGNAL(timeout()),this,SLOT(remove_dead_timers()));
    t->setSingleShot(true);
    t->start(time);
    QPair<QTimer*,int> pair(t,0);
    ss_timers.push_back(pair);
}



/**
 * @brief GameFrame2::keyPressEvent
 * @param event
 * registers keypressevents
 * esc = toggle menu
 * arrow keys = Player 1 movement
 * enter key = Player 1 place bomb
 * wasd = Player 2 movement
 * space key = Player 2 place bomb
 * checks for position validity before movement/placement
 * movement and bomb placement to be implemented
 */

void GameFrame2::keyPressEvent(QKeyEvent* event){
    //handle esc press event
    switch(event->key()){
    case Qt::Key_Escape:
        if (paused==false){
            paused=true;
            pause_icon_timers();
            pause_ss_timers();
        }
        else{
            paused=false;
            resume_icon_timers();
            resume_ss_timers();
        }
        ui->stackedWidget->setCurrentIndex(paused);
        update();
        QCoreApplication::processEvents();
        emit pause_pressed();
        break;
    default:
        break;
    }

    if (paused == false){

        //handle player1 keypress events
        if (p1!=nullptr && p1->if_frozen()==false){
            switch(event->key()){
            case Qt::Key_Left:
                player_moves(p1, LEFT);

                break;
            case Qt::Key_Right:
                player_moves(p1, RIGHT);
                break;
            case Qt::Key_Up:
                player_moves(p1, UP);
                break;
            case Qt::Key_Down:
                player_moves(p1, DOWN);
                break;

            case Qt::Key_Return:
                if(p1->get_freeze()){
                    emit freeze_pressed(p1);
                }
                else if (p1->mine->if_activated() && p1->mine->if_placed() == false){
                    emit mine_pressed(p1);
                }
                else{
                    if((p1->it() != p1->bombs.end()) )
                        emit enter_pressed(p1);
                }

                break;

            default:
                break;
            }
            if (ui->frame->childAt(p1->get_xpos(),p1->get_ypos())==ui->specialEffect1)
                emit effect_triggered(p1,i1);
            if (ui->frame->childAt(p1->get_xpos(),p1->get_ypos())==ui->specialEffect2)
                emit effect_triggered(p1,i2);

            if (p2!=nullptr){
                if (ui->frame->childAt(p1->get_xpos(),p1->get_ypos())==p1->mine->graphics || ui->frame->childAt(p1->get_xpos(),p1->get_ypos())==p2->mine->graphics){
                    emit player_attacked(p1);
                    mine_sound->play();
                }
            }

        }

        //handle player2 keypress events
        if (p2!=nullptr && p2->if_frozen()==false){
            switch(event->key()){
            case Qt::Key_A:
                player_moves(p2, LEFT);
                break;
            case Qt::Key_D:
                player_moves(p2, RIGHT);
                break;
            case Qt::Key_W:
                player_moves(p2, UP);
                break;
            case Qt::Key_S:
                player_moves(p2, DOWN);
                break;
            case Qt::Key_Space:
                if(p2->get_freeze()){
                    emit freeze_pressed(p2);
                }
                else if (p2->mine->if_activated() && p2->mine->if_placed()==false){
                    emit mine_pressed(p2);
                }
                else{
                    if((p2->it() != p2->bombs.end()) )
                        emit enter_pressed(p2);
                }
                break;
            default:
                break;
            }
            if (ui->frame->childAt(p2->get_xpos(),p2->get_ypos())==ui->specialEffect1)
                emit effect_triggered(p2,i1);
            if (ui->frame->childAt(p2->get_xpos(),p2->get_ypos())==ui->specialEffect2)
                emit effect_triggered(p2,i2);

            if (ui->frame->childAt(p2->get_xpos(),p2->get_ypos())==p1->mine->graphics || ui->frame->childAt(p2->get_xpos(),p2->get_ypos())==p2->mine->graphics){
                emit player_attacked(p2);
                mine_sound->play();
            }

        }


        //adjust the player icon positions accordingly
        ui->Player_1->move(p1->get_xpos(),p1->get_ypos());
        if (p2!=nullptr)
            ui->Player_2->move(p2->get_xpos(),p2->get_ypos());
    }
    //bomb ui

    ui->frame->repaint();
}
/*
void GameFrame2::npc_key_gen(){
    int i = rand()%5 + 1;
    if (i == LEFT){
        QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier);
        QCoreApplication::postEvent (this, event);
    }
    if (i == RIGHT){
        QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_D, Qt::NoModifier);
        QCoreApplication::postEvent (this, event);
    }
    if (i == UP){
        QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier);
        QCoreApplication::postEvent (this, event);
    }
    if (i == DOWN){
        QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier);
        QCoreApplication::postEvent (this, event);

    }
    if (i == 5){
        QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
        QCoreApplication::postEvent (this, event);
    }

}*/

void GameFrame2::npc_moves(){
    if(paused == false){
        int npc_loc = p2->get_ypos()/7+p2->get_xpos()/70;

        vector<Bomb> nearbyBombs;

        for (size_t i = 0; i < p1->bombs.size(); ++i){
            if(isNear(p1->bombs[i])) nearbyBombs.push_back(p1->bombs[i]);
        }

        for (size_t i = 0; i < p2->bombs.size(); ++i){
            if(isNear(p2->bombs[i])) nearbyBombs.push_back(p2->bombs[i]);
        }

        if (nearbyBombs.begin()!=nearbyBombs.end()){
            vector<vector<int>> paths;
            paths.push_back(ShortestPath(adj, 10, npc_loc));
            paths.push_back(ShortestPath(adj, 9, npc_loc));
            paths.push_back(ShortestPath(adj, 90, npc_loc));
            paths.push_back(ShortestPath(adj, 79, npc_loc));

            vector<vector<int> >::iterator max_itr= max_element(paths.begin(),paths.end(),
                  [](const vector<int> &A, const vector<int> &B){return A.size()<B.size();});

            vector<int> path = *max_itr;
            if(path.size()>2){
                if (path[1] == path[0]-1){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (path[1] == path[0]+1){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_D, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (path[1] == path[0]-10){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (path[1] == path[0]+10){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
            }
            else{
                int i = rand()%5 + 1;
                if (i == LEFT){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (i == RIGHT){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_D, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (i == UP){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (i == DOWN){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);

                }
                if (i == 5){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }

            }

        }


        else{
            int pc_loc = p1->get_ypos()/7+p1->get_xpos()/70;
            vector<int> path = ShortestPath(adj, pc_loc, npc_loc);
            if(path.size()>4){
                if (path[1] == path[0]-1){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (path[1] == path[0]+1){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_D, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (path[1] == path[0]-10){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (path[1] == path[0]+10){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
            }
            else{
                int i = rand()%5 + 1;
                if (i == LEFT){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (i == RIGHT){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_D, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (i == UP){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }
                if (i == DOWN){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);

                }
                if (i == 5){
                    QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
                    QCoreApplication::postEvent (this, event);
                }

            }
        }
    }

}


/**
 * @brief GameFrame2::set_double_player
 * @param a
 * change mode of game
 * called when game is created by welcomepage
 */

void GameFrame2::set_double_player(const bool& a){
    double_player_mode=a;
}


/**
 * @brief GameFrame2::on_quit_game_clicked
 * slot: hides game window and emits signal to show welcome window
 */

void GameFrame2::on_quit_game_clicked()
{
    hide();
    emit quit_pressed();
}

/**
 * @brief GameFrame2::toggle_menu
 * slot: toggles menu in game at the esc keypress event
 */

void GameFrame2::toggle_menu(){
    ui->stackedWidget->setCurrentIndex(paused);
}

void GameFrame2::place_bomb(Player* p){
    vector<Bomb>::iterator i = p->it();
    if(i != p->bombs.end()){

        (*i).setxpos(p->get_xpos());
        (*i).setypos(p->get_ypos());
        (*i).place(true);

        (*i).bombgraphics->setGeometry(p->get_xpos(),p->get_ypos(),70,70);

        (*i).bombgraphics->lower();
        (*i).bombgraphics->show();

        if(p->get_xpos()/70 != 9) delete_edge(adj, p->get_ypos()/7 + p->get_xpos()/70, p->get_ypos()/7 + p->get_xpos()/70 + 1);
        if(p->get_ypos()/70 != 9) delete_edge(adj, p->get_ypos()/7 + p->get_xpos()/70, (p->get_ypos()/70 + 1)* 10 + p->get_xpos()/70);

        emit bomb_placed(&(*i));
        ui->frame->update();
    }
}

void GameFrame2::place_mine(Player* p){
    p->mine->graphics->setGeometry(p->get_xpos(),p->get_ypos(),70,70);
    p->mine->set_xpos(p->get_xpos());
    p->mine->set_ypos(p->get_ypos());
    p->mine->set_placed(true);
    if(p->get_xpos()/70 != 9) delete_edge(adj, p->get_ypos()/7 + p->get_xpos()/70, p->get_ypos()/7 + p->get_xpos()/70 + 1);
    if(p->get_ypos()/70 != 9) delete_edge(adj, p->get_ypos()/7 + p->get_xpos()/70, (p->get_ypos()/70 + 1)* 10 + p->get_xpos()/70);
}

void GameFrame2::freeze_around(Player* p){
    p->set_freeze(false);
    if(p->get_id() == 1) ui->icon_3->hide();
    else ui->icon_9->hide();
    int x = p->get_xpos();
    int y = p->get_ypos();
    bool fp = false;
    if(!hasObstacle(p, LEFT)){
        if(ui->frame->childAt(x-70, y) == ui->Player_1) {
            p1->become_frozen(true);
            ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
        }

        else if(ui->frame->childAt(x-70,y) == ui->Player_2) {
            p2->become_frozen(true);
            ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
         }
    }
    if(!hasObstacle(p, RIGHT)){
        if(ui->frame->childAt(x+70, y) == ui->Player_1) {
            p1->become_frozen(true);
            ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
        }
        else if(ui->frame->childAt(x+70,y) == ui->Player_2) {
            p2->become_frozen(true);
            ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
         }
    }
    if(!hasObstacle(p, UP)){
        if(ui->frame->childAt(x, y-70) == ui->Player_1) {
            p1->become_frozen(true);
            ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
        }
        else if(ui->frame->childAt(x,y-70) == ui->Player_2) {
            p2->become_frozen(true);
            ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
         }
    }
    if(!hasObstacle(p, DOWN)){
        if(ui->frame->childAt(x, y+70) == ui->Player_1) {
            p1->become_frozen(true);
            ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
        }
        else if(ui->frame->childAt(x,y+70) == ui->Player_2) {
            p2->become_frozen(true);
            ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
         }
    }
    if(!hasObstacle(p, LU)){
        if(ui->frame->childAt(x-70, y-70) == ui->Player_1) {
            p1->become_frozen(true);
            ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
        }
        else if(ui->frame->childAt(x-70,y-70) == ui->Player_2) {
            p2->become_frozen(true);
            ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
         }
    }
    if(!hasObstacle(p, RD)){
        if(ui->frame->childAt(x+70, y+70) == ui->Player_1) {
            p1->become_frozen(true);
            ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
        }
        else if(ui->frame->childAt(x+70,y+70) == ui->Player_2) {
            p2->become_frozen(true);
            ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
         }
    }
    if(!hasObstacle(p, RU)){
        if(ui->frame->childAt(x+70, y-70) == ui->Player_1) {
            p1->become_frozen(true);
            ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
        }
        else if(ui->frame->childAt(x+70,y-70) == ui->Player_2) {
            p2->become_frozen(true);
            ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
         }
    }
    if(!hasObstacle(p, LD)){
        if(ui->frame->childAt(x-70, y+70) == ui->Player_1) {
            p1->become_frozen(true);
            ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
        }
        else if(ui->frame->childAt(x-70,y+70) == ui->Player_2) {
            p2->become_frozen(true);
            ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/freezebg.png)}");
            fp = true;
         }
    }
    if (fp){
        QTimer* timer = new QTimer(this);
        timer->callOnTimeout(endFrozen(*this));
        start_ss_timer(timer, 2000);
        ui->frame->update();
    }

}

void GameFrame2::start_timer(Bomb* b){
    QTimer* timer = new QTimer(this);
    timer->callOnTimeout(explodeBomb(*this, b));
    start_ss_timer(timer, 3000);

}

void GameFrame2::start_timer2(Bomb* b){
    QTimer* timer = new QTimer(this);
    timer->callOnTimeout(clearBomb(*this,b));
    start_ss_timer(timer,1000);
}

void GameFrame2::bomb_explodes(Bomb* b){
    explosion_sound->stop();
    explosion_sound->play();
    int x = b->getxpos();
    int y = b->getypos();
//    int p = b->getPower();

    b->bombgraphics->hide();

    b->bombedgraphics->setGeometry(x,y,70,70);
    b->bombedgraphics->lower();
    b->bombedgraphics->show();

    b->bombEffectL->lower();
    b->bombEffectR->lower();
    b->bombEffectU->lower();
    b->bombEffectD->lower();

    int d=explodeDist(b,DOWN);
    int u=explodeDist(b,UP);
    int l=explodeDist(b,LEFT);
    int r=explodeDist(b,RIGHT);

    if(d!=0){

        b->bombEffectD->setGeometry(x,y+70,70,d*70);
        b->bombEffectD->setScaledContents(true);
        b->bombEffectD->show();
        if(p1->get_shield()== false && p1->get_xpos() == x && (p1->get_ypos() >= y && p1->get_ypos() <= y+ d*70))
            emit player_attacked(p1);
        if (p2!=nullptr){
            if(p2->get_shield()== false && p2->get_xpos() == x && (p2->get_ypos() >= y && p2->get_ypos() <= y +d*70))
                emit player_attacked(p2);
        }
    }
    if(u!=0){
        b->bombEffectU->setGeometry(x,y-u*70,70,u*70);
        b->bombEffectU->setScaledContents(true);
        b->bombEffectU->show();
        if(p1->get_shield()== false && p1->get_xpos() == x && (p1->get_ypos() <= y && p1->get_ypos() >= y - u*70))
            emit player_attacked(p1);
        if (p2!=nullptr){
            if(p2->get_shield()== false && p2->get_xpos() == x && (p2->get_ypos() <= y && p2->get_ypos() >= y - u*70))
                emit player_attacked(p2);
        }
    }
    if(l!=0){
        b->bombEffectL->setGeometry(x-l*70,y,l*70,70);
        b->bombEffectL->setScaledContents(true);
        b->bombEffectL->show();
        if(p1->get_shield()== false && p1->get_ypos() == y && (p1->get_xpos() <= x && p1->get_xpos() >= x - l*70))
            emit player_attacked(p1);
        if (p2!=nullptr){
            if(p2->get_shield()== false && p2->get_ypos() == y && (p2->get_xpos() <= x && p2->get_xpos() >= x - l*70))
                emit player_attacked(p2);
        }
    }
    if(r!=0){
        b->bombEffectR->setGeometry(x+70,y,r*70,70);
        b->bombEffectR->setScaledContents(true);
        b->bombEffectR->show();
        if(p1->get_shield()== false && p1->get_ypos() == y && (p1->get_xpos() >= x && p1->get_xpos() <= x + r*70))
            emit player_attacked(p1);
        if (p2!=nullptr){
            if(p2->get_shield()== false && p2->get_ypos() == y && (p2->get_xpos() >= x && p2->get_xpos() <= x + r*70))
                emit player_attacked(p2);
        }
    }

   if(b->getxpos()/70 != 9)  add_edge(adj, b->getypos()/7 + b->getxpos()/70, b->getypos()/7 + b->getxpos()/70 + 1);
   if(b->getypos()/70 != 9) add_edge(adj, b->getypos()/7 + b->getxpos()/70, (b->getypos()/70 + 1)* 10 + b->getxpos()/70);

}

void GameFrame2::clear_bomb(Bomb* b){

    b->bombedgraphics->hide();
    b->bombEffectD->hide();
    b->bombEffectU->hide();
    b->bombEffectL->hide();
    b->bombEffectR->hide();
    b->place(false);
}

void GameFrame2::drop_i1(){
    int x = 0;
    int y = 0;
    size_t t = 0;

    do {
        x = rand_pos();
        y = rand_pos();
        t = rand() % 8;
    }  while(ui->frame->childAt(x,y)!=nullptr);

    i1->set_xpos(x);
    i1->set_ypos(y);
    i1->set_type(t);
    ui->specialEffect1->setPixmap(icons[t]);
    ui->specialEffect1->setGeometry(x,y,70, 70);
    ui->specialEffect1->show();
}

void GameFrame2::drop_i2(){
    int x = 0;
    int y = 0;
    size_t t = 0;

    do {
        x = rand_pos();
        y = rand_pos();
        t = rand() % 8;
    }  while(ui->frame->childAt(x,y)!=nullptr);

    i2->set_xpos(x);
    i2->set_ypos(y);
    i2->set_type(t);
    ui->specialEffect2->setPixmap(icons[t]);
    ui->specialEffect2->setGeometry(x,y,70, 70);
    ui->specialEffect2->show();
}

void GameFrame2::release_effect(Player* p, specialIcon* i){
    //play sound effect
    icon_sound->stop();
    icon_sound->play();

    //hide triggered icon and move out of game arena so no one steps on it again
    if (i == i1){
        ui->specialEffect1->hide();
        ui->specialEffect1->move(700,700);
    }
    else if (i == i2){
        ui->specialEffect2->hide();
        ui->specialEffect2->move(700,700);
    }
    size_t n = i->get_type();
    if (n == 0){
        // Bomb+1
        std::vector<Bomb>::iterator iter = std::find_if(p->bombs.begin(), p->bombs.end(), is_nonactive);
        if (iter!=p->bombs.end()){
            (*iter).activate(true);
            p->bombplus();
            QString s = QString::number(p->get_bombcount());
            if (p->get_id()==1)
                ui->icon->setText(s);
            else
                ui->icon_15->setText(s);
            repaint();
        }
    }
    else if(n == 1){
        // freeze
        p->set_freeze(true);
        if (p->get_id()==1){
            ui->icon_3->show();
        }
        else{
            ui->icon_9->show();

        }
        repaint();

    }
    else if (n==2) {
        // ghost
        p->set_ghost(true);
        if (p->get_id()==1){
            ui->icon_4->show();
            hide_status_icon(ui->icon_4, 10000);
        }
        else{
            ui->icon_10->show();
            hide_status_icon(ui->icon_10, 10000);
        }

        QTimer* timer = new QTimer(this);
        timer->callOnTimeout(end_ghost(*p));
        start_ss_timer(timer, 10000);
        repaint();
    }
    else if (n == 3){
        // bombpowerup
        if (p->get_power()<5) p->powerup();
        for (size_t k=0; k<p->bombs.size();k++){
            p->bombs[k].power = p->get_power();
        }
        QString s = QString::number(p->get_power());
        if (p->get_id()==1)

            ui->icon_2->setText(s);
        else
            ui->icon_12->setText(s);
        repaint();

    }
    else if(n == 4){
        // push
        p->set_push(true);

        if (p->get_id()==1){
            ui->icon_5->show();
            hide_status_icon(ui->icon_5, 10000);
        }
        else{
            ui->icon_11->show();
            hide_status_icon(ui->icon_11, 10000);
        }
        QTimer* timer = new QTimer(this);
        timer->callOnTimeout(end_push(*p));
        start_ss_timer(timer, 10000);
    }
    else if(n == 5){
        // reverse
        p->set_reverse(true);

        if (p->get_id()==1){
            ui->icon_6->show();
            hide_status_icon(ui->icon_6, 10000);
        }
        else{
            ui->icon_13->show();
            hide_status_icon(ui->icon_13, 10000);
        }
        QTimer* timer = new QTimer(this);
        timer->callOnTimeout(reverse_dir(*p));
        start_ss_timer(timer, 10000);
    }
    else if(n== 6){
        // shield
        p->set_shield(true);

        if (p->get_id()==1){
            ui->icon_7->show();
            hide_status_icon(ui->icon_7, 10000);
        }
        else{
            ui->icon_14->show();
            hide_status_icon(ui->icon_14, 10000);
        }
        QTimer* timer = new QTimer(this);
        timer->callOnTimeout(end_shield(*p));
        start_ss_timer(timer, 10000);
    }
    else if(n==7){
        //mine
        if (p->get_id()==1){
            ui->icon_8->show();
        }
        else{
            ui->icon_16->show();
        }
        if (p->mine->if_activated() == false && p->mine->if_placed() == false){

            p->mine->set_activated(true);
        }
    }
    else return;
}

void GameFrame2::push_bombAt(Player* p, const int& dir){
    QPair<int, int> future_pos = future_position(p,dir);
    int xpos=future_pos.first;
    int ypos=future_pos.second;

    //create temp bomb to see how far it can go
    Bomb* b = new Bomb(xpos, ypos, 5);
    int dist=explodeDist(b, dir);
    delete b;

    //do bomb graphics
    Bomb* temp = hasBomb(p,dir);
    if (temp!=nullptr){
        for (int k=1;k<=dist;k++)
            QTimer::singleShot(k*10,this,push_graphics(*this, temp, dir));
    }
}

void GameFrame2::end_game(Player* p){
    if(p->get_id() == 2){
        ui->winningPlayer->setPixmap(playermaps[0]);
        ui->gamefield->setCurrentIndex(0);
    }
    else{
        if (double_player_mode == false){
            ui->gamefield->setCurrentIndex(2);
        }
        else {
            ui->winningPlayer->setPixmap(playermaps[1]);
            ui->gamefield->setCurrentIndex(0);
        }
    }

    //PAUSE GAME
    paused = true;
    pause_icon_timers();
    pause_ss_timers();
    update();
}


void GameFrame2::on_pushButton_clicked(){
    hide();
    emit quit_pressed();
}

void GameFrame2::on_pushButton_2_clicked(){
    hide();
    emit quit_pressed();
}

void GameFrame2::on_bgm_slider_valueChanged(int value){emit bgm_vol_changed(value);}

void GameFrame2::on_effects_slider_valueChanged(int value){
    icon_sound->setVolume(value);
    explosion_sound->setVolume(value);
    mine_sound->setVolume(value);
    emit effects_vol_changed(value);
}

/****************nested class member functions****************/
/**
 * @brief GameFrame2::deactivateMine::operator ()
 * change status of mine of the passed player, updates ui and graph
 * called when mine expires
 */
void GameFrame2::deactivateMine::operator()(){
    p->mine->set_activated(false);
    p->mine->set_placed(false);

    //hide icon of correct player
    if (p->get_id()==1){
        parent.ui->icon_8->hide();
    }
    else{
        parent.ui->icon_16->hide();
    }
    //if not placed in right or bottom corner, add edge to the graph
    if(p->mine->get_xpos()/70 != 9) add_edge(parent.adj, p->mine->get_ypos()/7 + p->mine->get_xpos()/70, p->mine->get_ypos()/7 + p->mine->get_xpos()/70 + 1);
    if(p->mine->get_ypos()/70 != 9) add_edge(parent.adj, p->mine->get_ypos()/7 + p->mine->get_xpos()/70, (p->mine->get_ypos()/70 + 1)* 10 + p->mine->get_xpos()/70);

}

/**
 * @brief GameFrame2::endFrozen::operator ()
 * changes freeze status of frozen player and update graphics
 */
void GameFrame2::endFrozen::operator()(){
    //checks whether players are frozen
    if(parent.p1->if_frozen()){
        parent.p1->become_frozen(false);
        parent.ui->Player_1->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    }

    if(parent.p2->if_frozen()){
        parent.p2->become_frozen(false);
        parent.ui->Player_2->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    }

}

/**
 * @brief GameFrame2::push_graphics - pushes bomb passed to functor in direction d by one block, then calls repaint.
 * Position validity is checked by caller.
 * uses a temporary player object to use GameFrame2::future_position
 */

void GameFrame2::push_graphics::operator()(){
    //Creates a temp player to use future_position function, then set bomb position
    Player* temp = new Player(0,&parent); //temp player
    temp->set_xpos(b->getxpos());
    temp->set_ypos(b->getypos());
    QPair<int, int> future_pos = parent.future_position(temp,d);
    b->setxpos(future_pos.first);
    b->setypos(future_pos.second);
    delete temp;

    //update bomb graphics
    b->bombgraphics->move(future_pos.first,future_pos.second);
    parent.repaint();
}
