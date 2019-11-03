#ifndef PointSecteur_H
#define PointSecteur_H


#include <QGraphicsSceneEvent>
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QObject>
#include <QFrame>

#include "secteur.h"


class PointSecteur : public QObject, public Secteur
{

    Q_OBJECT
    //Q_INTERFACES(QGraphicsItem)

public:
    PointSecteur(Secteur *parent = nullptr, shapeType shape = SINGLE, numberType number = ZERO);



    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual QPainterPath shape() const override;

    QPainterPath selectShape(shapeType select);
    void addText(QPainter *painter);

signals:
    void clickPoint(const QString &);


protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    const QImage& selectColor(numberType number) const;
    void loadRadius();
    void loadShape();
    qreal width() const;
    qreal height() const;

    bool isHover = false;
    bool isPressed = false;
    QPainterPath pointShape;

    QPointF Center;
    qreal rOutExt, rOutIn, rOutBull, rInBull, rInTriple, rOutTriple, rInDouble;
    QPainterPath OutZero, Triple, Double, Single, sBull, dBull;
    qreal angle;

    QColor color;
    shapeType whatShape;
    numberType number;

    const QImage& texture;
};

#endif // PointSecteur_H
