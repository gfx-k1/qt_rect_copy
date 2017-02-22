#include "highlightrectitem.h"

#include <QPainter>
#include <QPointF>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include "rettangolo.h"

HighlightRectItem::HighlightRectItem(const QRectF & rect, QGraphicsItem * parent )
    :QGraphicsRectItem(rect, parent), m_dragged(false)
//QGraphicsRectItem(parent), QObject(parent), m_dragged(false)
{
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
    selectRectItem = false;
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
    /*dimXImage = int(400/4);
    dimYImage = int(600/4);
    scaleBoximg = Boximg.scaled(dimXImage, dimYImage ,Qt::IgnoreAspectRatio);
    ImgPosition.setX(int(50/4));
    ImgPosition.setY(int(50/4));*/




}
/*HighlightRectItem::~HighlightRectItem()
{
}*/


QImage HighlightRectItem::Boximg("/home/yourniceimage1.png");
QImage HighlightRectItem::scaleBoximg("/home/yourniceimage2.png");
QPoint HighlightRectItem::ImgPosition(0,0);


void HighlightRectItem::setImageDim(QImage realImage, int dXImage, int dYImage)
{
    HighlightRectItem::scaleBoximg = realImage.scaled(dXImage, dYImage , Qt::IgnoreAspectRatio);
}

void HighlightRectItem::getPoint(QPointF myPointBox)
{
    //SignalRectfPass P;

    m_lastBox = myPointBox;
    if((myPointBox.y() != 0) && (myPointBox.x() != 0))
    {
        qDebug() << "V point:  " << myPointBox;
        //MainWindow::testpos(myPointBox);
        //P.xpoint = myPointBox;
       // P.getPoint(myPointBox);
    //QPainter *painter2;
   // painter2->setPen(m_pen);
   // painter2->drawImage(myPointBox, HighlightRectItem::scaleBoximg);
    //painter->begin(&boximg);
    //painter->drawRect(rect());
    }


}

QPointF HighlightRectItem::lastBox()
{
    return m_lastBox;

}

void HighlightRectItem::setImagePos(int Xspace, int Yspace)
{
    HighlightRectItem::ImgPosition.setX(Xspace);
    HighlightRectItem::ImgPosition.setY(Yspace);
}

void HighlightRectItem::setAnchorPoint(const QPointF &anchorPoint)
{
    this->anchorPoint = anchorPoint;
}


void HighlightRectItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    m_pen.setColor(Qt::red);
    update();
}

void HighlightRectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    m_pen.setColor(Qt::green);
    update();
}

void HighlightRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /*QImage rectImage(HighlightRectItem::scaleBoximg);
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    mime->setImageData(QPixmap::fromImage(rectImage));
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(HighlightRectItem::scaleBoximg));
    drag->setHotSpot(QPoint(int(event->pos().rx()), (event->pos().ry())));
    drag->exec();*/
    if(selectRectItem)
    {
        selectRectItem = false;
    }
    else
    {
        selectRectItem = true;
    }
    setCursor(Qt::ClosedHandCursor);



}


void HighlightRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    m_dragged = true;
       QGraphicsRectItem::mouseMoveEvent(event);

}

QVariant HighlightRectItem::itemChange ( GraphicsItemChange change, const QVariant & value )
{
    if (change == ItemPositionChange && scene()) {
        // value is the new position.
        QPointF newPos = value.toPointF();
        QRectF rect = scene()->sceneRect();
        if (!rect.contains(newPos)) {
            // Keep the item inside the scene rect.
            newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
            newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
            return newPos;
        }
    }
    return QGraphicsItem::itemChange(change, value);
}

void HighlightRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /*if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance()) {
        return;
    }
*/



    QPointF thisBox(0,0);
    if(m_dragged){
            QList<QGraphicsItem*> colItems = collidingItems();
            if(colItems.isEmpty()){
                this->setPos(anchorPoint);
            }
            else {
                QGraphicsItem* closestItem = colItems.at(0);
                qreal shortestDist = 100000;
                foreach(QGraphicsItem* item, colItems){
                    QLineF line(item->sceneBoundingRect().center(),
                                this->sceneBoundingRect().center());
                    if(line.length() < shortestDist){
                        shortestDist = line.length();
                        closestItem = item;
                    }
                }
                this->setPos(closestItem->scenePos());
                thisBox.setX(closestItem->scenePos().x());
                thisBox.setY(closestItem->scenePos().y());
                //thisBox.x() = closestItem->scenePos().x();
                //thisBox.y() = closestItem->scenePos().y();
                getPoint(thisBox);
                /*QImage rectImage(HighlightRectItem::scaleBoximg);
                    QDrag *drag = new QDrag(event->widget());
                    QMimeData *mime = new QMimeData;
                    mime->setImageData(QPixmap::fromImage(rectImage));
                    drag->setMimeData(mime);
                    drag->setPixmap(QPixmap::fromImage(HighlightRectItem::scaleBoximg));
                    drag->setHotSpot(QPoint(int(thisBox.x()), (thisBox.y())));
                    drag->exec();*/


            }
            m_dragged = false;
        }
        QGraphicsRectItem::mouseReleaseEvent(event);
        setCursor(Qt::OpenHandCursor);
        //QTimer::singleShot(50, [=]{ setPos(5,5); });
        //QTimer::singleShot(150, [=]{ this->setPos(thisBox); });
       // QTimer::singleShot(200, [=]{ setCursor(Qt::OpenHandCursor); });

}

void HighlightRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->;
   painter->setPen(m_pen);
   painter->drawImage(HighlightRectItem::ImgPosition, HighlightRectItem::scaleBoximg);
   //painter->begin(&boximg);
   painter->drawRect(rect());
   //painter->end();

}


