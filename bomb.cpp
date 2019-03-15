#include "bomb.h"

#include "gameframe2.cpp"

/**
 * @brief Bomb::Bomb
 * Constructor of the Bomb class: initializes the graphics and positions of the bomb
 * @param <GameFrame2*> g - gameframe that owns the bomb object
 * @param <int> x - x position of the bomb
 * @param <int> y - y position of the bomb  `   `           `   `
 */
Bomb::Bomb(GameFrame2* g, int x, int y) : game(g), xpos(x), ypos(y) {
    bombgraphics = new QLabel;
    bombgraphics->setPixmap(g->bombmaps[0]);
    bombgraphics->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    bombgraphics->setParent(g->ui->frame);
    bombgraphics->hide();

    bombedgraphics = new QLabel;
    bombedgraphics->setPixmap(g->bombmaps[1]);
    bombedgraphics->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    bombedgraphics->setParent(g->ui->frame);
    bombedgraphics->hide();

    bombEffectL = new QLabel;
    bombEffectL->setPixmap(g->bombmaps[2]);
    bombEffectL->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    bombEffectL->setParent(g->ui->frame);
    bombEffectL->hide();

    bombEffectR = new QLabel;
    bombEffectR->setPixmap(g->bombmaps[2]);
    bombEffectR->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    bombEffectR->setParent(g->ui->frame);
    bombEffectR->hide();

    bombEffectU = new QLabel;
    bombEffectU->setPixmap(g->bombmaps[3]);
    bombEffectU->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    bombEffectU->setParent(g->ui->frame);
    bombEffectU->hide();

    bombEffectD = new QLabel;
    bombEffectD->setPixmap(g->bombmaps[3]);
    bombEffectD->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    bombEffectD->setParent(g->ui->frame);
    bombEffectD->hide();

}


/**
 * @brief is_active predicate
 * @param <Bomb> bomb
 * @return <bool> true if current bomb is activated, false otherwise
 */
bool is_active(const Bomb& bomb){
    return (bomb.if_activated());
}

/**
 * @brief is_nonactive
 * @param <Bomb> bomb
 * @return <bool> if current bomb is not activated
 */
bool is_nonactive(const Bomb& bomb){
    return (bomb.if_activated() == false);
}


/**
 * @brief Mine::Mine
 * Constructor of the Mine class: initializes the graphics of the mine
 * @param <GameFrame2*> g - gameframe that owns the mine object
 * @param <Player*> p - player that owns the mine object
 */
Mine::Mine(GameFrame2* g, Player* p): g(g),p(p){
    graphics = new QLabel;
    QPixmap* temp = new QPixmap(":/gamefield_graphics/minegraphics.png");
    graphics->setPixmap(*temp);
    graphics->setStyleSheet("QLabel{background-image:url(:/gamefield_graphics/t.png)}");
    graphics->setParent(g->ui->frame);
    graphics->hide();
}
