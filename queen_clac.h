#ifndef QUEEN_CLAC_H
#define QUEEN_CLAC_H
#include <QTextBrowser>
#include <QStatusBar>
#include <set>
#include <QCoreApplication>
#include <QTime>

class queen_clac
{
public:
    queen_clac(int num);
    void startClac(QTextBrowser * browser,QStatusBar * statusBar);
    int num;

};

#endif // QUEEN_CLAC_H
