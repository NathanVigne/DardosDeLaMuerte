#include "pointsecteur.h"

PointSecteur::PointSecteur(Secteur *parent, shapeType whatShape, numberType number)
                : Secteur(parent),
                  isHover(false),
                  isPressed(false),
                  color(Qt::black),
                  whatShape(whatShape),
                  number(number)

{
    // Pour gerer les evènement de la souris
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::MouseButton::LeftButton);

    // Pour charger la bonne shape
    loadRadius();
    loadShape();
    pointShape = selectShape(whatShape);

    // Charge la bonne texture
    texture = selectColor(number);

    // Connect le click
    connect(this,&PointSecteur::clickPoint,parent->L,&QLabel::setText);

    update();


}


QRectF PointSecteur::boundingRect() const
{
    // Zone de dessin   
    QRectF section = QRectF(Center.x()-this->width()/2,Center.y()-this->height(),this->width(),this->height());
    QRectF bull = QRectF(Center.x()-rOutBull,Center.y()-rOutBull,rOutBull*2,rOutBull*2);
    QRectF board = QRectF(Center.x()-rOutExt,Center.y()-rOutExt,rOutExt*2,rOutExt*2);

    switch (whatShape) {

        case shapeType::OUT :               return board;
        case shapeType::SINGLE :            return section;
        case shapeType::DOUBLE :            return section;
        case shapeType::TRIPLE :            return section;
        case shapeType::SINGLEBULL :        return bull;
        case shapeType::DOUBLEBULL :        return bull;
        default:                            return QRectF();

    }

}

void PointSecteur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QBrush brush;
    QPen pen;
    pen.setColor(QColor(192,192,192));
    pen.setWidth(1);

    painter->setRenderHint(QPainter::Antialiasing);

    //painter->drawRect(this->boundingRect());

    if (isHover) {
        if(isPressed){
            brush.setStyle(Qt::SolidPattern);
            brush.setColor(Qt::yellow);
        }else{
            brush.setStyle(Qt::SolidPattern);
            brush.setColor(Qt::blue);
        }

    } else {
        if(isPressed){
            brush.setStyle(Qt::SolidPattern);
            brush.setColor(Qt::yellow);
        }else{
            brush.setTextureImage(texture);
        }
    }

    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawPath(pointShape);

    if (whatShape == shapeType::OUT){
        addText(painter);
    }


}

QPainterPath PointSecteur::selectShape(shapeType select)
{
    switch (select) {

        case shapeType::OUT :               return OutZero;
        case shapeType::SINGLE :            return Single;
        case shapeType::DOUBLE :            return Double;
        case shapeType::TRIPLE :            return Triple;
        case shapeType::SINGLEBULL :        return sBull;
        case shapeType::DOUBLEBULL :        return dBull;
        default:                            return QPainterPath();
    }

}

QImage PointSecteur::selectColor(numberType number)
{


    if(number == ZERO){
            switch (whatShape) {

                case shapeType::OUT :                 return QImage(":/Texture/texture/cardBoardNoir.png");
                default :                              return QImage();
            }
        }else if (number == VINGTCINQ){
            switch (whatShape) {

                case shapeType::SINGLEBULL :               return QImage(":/Texture/texture/cardBoardVert.png");
                case shapeType::DOUBLEBULL :               return QImage(":/Texture/texture/cardBoardRed.png");
                default :                              return QImage();
            }
        }else if ((number == UN) || (number == QUATRE) || (number == CINQ) || (number == SIX)
                  || (number == NEUF) || (number == ONZE) || (number == QUINZE) || (number == SEIZE)
                  || (number == DIXSEPT) || (number == DIXNEUF)){
            switch (whatShape) {

                case shapeType::SINGLE :               return QImage(":/Texture/texture/cardBoardBlanc.png");
                case shapeType::DOUBLE :               return QImage(":/Texture/texture/cardBoardVert.png");
                case shapeType::TRIPLE :               return QImage(":/Texture/texture/cardBoardVert.png");
                default :                              return QImage();
            }
        }else{
            switch (whatShape) {

                case shapeType::SINGLE :               return QImage(":/Texture/texture/cardBoardNoir.png");
                case shapeType::DOUBLE :               return QImage(":/Texture/texture/cardBoardRed.png");
                case shapeType::TRIPLE :               return QImage(":/Texture/texture/cardBoardRed.png");
                default :                              return QImage();
            }
        }
}

void PointSecteur::addText(QPainter *painter)
{
    QPen pen;
    QFont font;
    if (isHover){
        pen.setColor(Qt::black);
    }else{
        pen.setColor(Qt::white);
    }
    //font.setBold(true);
    font.setFamily("Impact");
    font.setPointSize(32);
    painter->setPen(pen);
    painter->setFont(font);

    int textWidth = 100;
    int textHeight = 100;
    QRect textRect(Center.x()-textWidth/2,Center.y()-(rOutExt+rOutIn)/2-textHeight/2,textWidth,textHeight);

    painter->drawText(textRect,Qt::AlignCenter,"20");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"1");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"18");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"4");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"13");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"6");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"10");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"15");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"2");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"17");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"3");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"19");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"7");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"16");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"8");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"11");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"14");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"9");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"12");
    painter->rotate(18);
    painter->drawText(textRect,Qt::AlignCenter,"5");

}

void PointSecteur::loadShape()
{

    QPainterPath OutExt, OutIn, In;
    QPainterPath Triangle;
    QPainterPath interOut, interIn, inter;
    QPainterPath outerIn, InBull;

    // Creation du tiangle par section
    QPolygonF tri;
    tri << Center
        << QPointF(Center.x()+tan(angle/2)*rOutIn,Center.y()-rOutIn)
        << QPointF(Center.x()-tan(angle/2)*rOutIn,Center.y()-rOutIn);
    Triangle.addPolygon(tri);

    // Création du cercle exterieur de la zone OUT
    OutExt.addEllipse(Center.x()-rOutExt,Center.y()-rOutExt,rOutExt*2,rOutExt*2);

    // Création du cercle int de le zone OUT
    OutIn.addEllipse(Center.x()-rOutIn,Center.y()-rOutIn,rOutIn*2,rOutIn*2);

    // Création du cercle du BullEyes Ext
    In.addEllipse(Center.x()-rOutBull,Center.y()-rOutBull,rOutBull*2,rOutBull*2);

    // Création du cercle du BullEyes Ext
    InBull.addEllipse(Center.x()-rInBull,Center.y()-rInBull,rInBull*2,rInBull*2);

    // Création du cercle inférieur du Triple
    interIn.addEllipse(Center.x()-rInTriple,Center.y()-rInTriple,rInTriple*2,rInTriple*2);

    // Création du cercle suppérieur du triple
    interOut.addEllipse(Center.x()-rOutTriple,Center.y()-rOutTriple,rOutTriple*2,rOutTriple*2);

    // Création du cercle inférieur du double
    outerIn.addEllipse(Center.x()-rInDouble,Center.y()-rInDouble,rInDouble*2,rInDouble*2);

    // Définition des zones
    Triple.addPath(interOut.subtracted(interIn).intersected(Triangle));
    Double.addPath(OutIn.subtracted(outerIn).intersected(Triangle));
    Single.addPath(Triangle.subtracted(In).intersected(OutIn));
    //Single.addPath(Triangle.subtracted(In).intersected(OutIn).subtracted(Triple).subtracted(Double));
    OutZero.addPath(OutExt.subtracted(OutIn));
    sBull.addPath(In.subtracted(InBull));
    dBull.addEllipse(Center.x()-rInBull,Center.y()-rInBull,rInBull*2,rInBull*2);

}

qreal PointSecteur::width() const
{
    return rOutExt*tan(18*3.14/180);
}

qreal PointSecteur::height() const
{
    return rOutExt;
}

void PointSecteur::loadRadius()
{
    rOutExt = 225.5;
    rOutIn = 170;
    rOutBull = 17.9;
    rInBull = 8.35;
    rOutTriple = 105.4;
    rInTriple = 92.4;
    rInDouble = 157;
    angle = 18*3.14/180.0;
    Center.setX(this->parentItem()->pos().x());
    Center.setY(this->parentItem()->pos().y());
}

QPainterPath PointSecteur::shape() const
{
    // Defini la zone clicable
    return pointShape;

}

void PointSecteur::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if(shape().contains(event->pos()))
    {
        isHover = true;
        update();
    }else
    {
       event->ignore();
    }
}

void PointSecteur::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    isHover = false;
    update();
}

void PointSecteur::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    if(shape().contains(event->pos()))
    {
        isHover = true;
        update();
    }else
    {
        isHover = false;
        update();
    }
}

void PointSecteur::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(shape().contains(mouseEvent->pos()))
    {
        isPressed = true;
        update();
    }else
    {
        isPressed = false;
        update();
    }
}

void PointSecteur::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
        Q_UNUSED(mouseEvent)
        isPressed = false;

        QString point;

        switch (PointSecteur::whatShape) {

            case shapeType::OUT :               point = "0";break;
            case shapeType::SINGLE :            point = point.number(PointSecteur::number);break;
            case shapeType::DOUBLE :            point = point.number(PointSecteur::number*2);break;
            case shapeType::TRIPLE :            point = point.number(PointSecteur::number*3);break;
            case shapeType::SINGLEBULL :        point = point.number(PointSecteur::number);break;
            case shapeType::DOUBLEBULL :        point = point.number(PointSecteur::number*2);break;
            default:                            point = "default" ;

        }

        emit PointSecteur::clickPoint(point);
        update();

}
