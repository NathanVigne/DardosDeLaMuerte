#ifndef SECTEUR_H
#define SECTEUR_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QColor>
#include <QLabel>

//#include "pointsecteur.h"


class PointSecteur;

enum shapeType   {TRIPLE,
                  DOUBLE,
                  SINGLE,
                  OUT,
                  SINGLEBULL,
                  DOUBLEBULL};

enum numberType {ZERO, UN, DEUX, TROIS, QUATRE,
                 CINQ, SIX, SEPT, HUIT, NEUF,
                 DIX, ONZE, DOUZE, TREIZE, QUATORZE,
                 QUINZE, SEIZE, DIXSEPT, DIXHUIT, DIXNEUF,
                 VINGT, VINGTCINQ = 25};


class Secteur : public QGraphicsItem
{
public:
    Secteur(QGraphicsItem *parent = nullptr, QLabel *label = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void loadBull();
    void loadOut();
    void loadSection(int selectNum);

    QLabel *L = new QLabel;

};


#endif // SECTEUR_H
