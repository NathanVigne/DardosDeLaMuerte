#ifndef ZONECENTRAL_H
#define ZONECENTRAL_H

#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsWidget>

#include "pointsecteur.h"
#include "secteur.h"

class Board : public QGraphicsScene
{
public:
    Board(QGraphicsScene *parent = nullptr, QLabel *label = nullptr);

//    qreal getWidth();
//    qreal getHeight();
//    qreal getMaxRadius();


};

#endif // ZONECENTRAL_H
