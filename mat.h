#ifndef MAT_H
#define MAT_H
#include <QGridLayout>
#include <QPushButton>
#include <QToolButton>
#include <QButtonGroup>
#include <QSizePolicy>
#include <QPalette>
#include <QTime>
#include <vector>
#include <algorithm>
#include <random>
#include <string.h>

using std::vector;

class mat
{
public:
    mat();
    mat(int x,int y);
    int getX();
    int getY();
    void draw(QGridLayout* layout);

private:
    int x;
    int y;
};

#endif // MAT_H
