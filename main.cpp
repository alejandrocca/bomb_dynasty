#include "welcomepage.h"
#include <QApplication>

/**
 * @brief main
 * @param argc
 * @param argv
 * @return a.exec()
 * Names: Cindy Wang, Xingjia Wang
 */

int main(int argc, char *argv[])
{
    srand (time(NULL));
    QApplication a(argc, argv);
    WelcomePage w;
    w.show();

    return a.exec();
}
