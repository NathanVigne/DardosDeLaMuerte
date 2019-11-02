#include "secteur.h"
#include "pointsecteur.h"


Secteur::Secteur(QGraphicsItem *parent, QLabel *label)
    : QGraphicsItem(parent), L(label)
{

}

QRectF Secteur::boundingRect() const
{
    return QRectF();
}

void Secteur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Secteur::loadBull()
{
    PointSecteur *dBull = new PointSecteur(this,shapeType::DOUBLEBULL,numberType::VINGTCINQ);
    PointSecteur *sBull = new PointSecteur(this,shapeType::SINGLEBULL,numberType::VINGTCINQ);
    dBull->setPos(0,0);
    sBull->setPos(0,0);
}

void Secteur::loadOut()
{
    PointSecteur *zeroOut = new PointSecteur(this,shapeType::OUT,numberType::ZERO);
    zeroOut->setPos(0,0);
}

void Secteur::loadSection(int selectNum)
{
    PointSecteur *single = new PointSecteur(this,shapeType::SINGLE,numberType(selectNum));
    PointSecteur *_double = new PointSecteur(this,shapeType::DOUBLE,numberType(selectNum));
    PointSecteur *triple = new PointSecteur(this,shapeType::TRIPLE,numberType(selectNum));
    single->setPos(0,0);
    _double->setPos(0,0);
    triple->setPos(0,0);

}
