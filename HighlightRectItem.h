#ifndef HIGHLIGHTRECTITEM_H
#define HIGHLIGHTRECTITEM_H

#include <QGraphicsRectItem>
#include <QPen>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QDesktopWidget>
#include <QDialog>
#include <QWidget>
#include <QWidgetAction>
#include <QWidgetData>
#include <QWidgetItem>
#include <QPixmap>
#include <QtWidgets/qstyle.h>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QObject>
#include <QGraphicsItem>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMimeType>
#include <QMetaType>
#include "rettangolo.h"
#include "signalrectfpass.h"
#include "mainwindow.h"


QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
//class QParallelAnimationGroup;
QT_END_NAMESPACE


class HighlightRectItem : public QGraphicsRectItem //public QObject, public QGraphicsRectItem
{
    //Q_OBJECT

public:
    //HighlightRectItem();
    HighlightRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
    //~HighlightRectItem();
    static QImage Boximg;
    static QImage scaleBoximg;
    static QImage realBoximg;
    static QPoint ImgPosition;
    bool selectRectItem;
    void setAnchorPoint(const QPointF& anchorPoint);
    void setImageDim(QImage realImage, int dXImage, int dYImage);
    void setImagePos(int Xspace, int Yspace);
    void getPoint(QPointF myPointBox);
    QPointF lastBox();


public slots:


protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    virtual QVariant itemChange ( GraphicsItemChange change, const QVariant & value );

protected slots:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPen m_pen;
    QPointF anchorPoint;
    bool m_dragged;
    int dimXImage;
    int dimYImage;
    QPointF m_lastBox;
    //SignalRectfPass m_P;



signals:
    //void getterPoint(QPointF);
   // void clicked(bool);

   // Q_DECLARE_METATYPE(HighlightRectItem);

};

#endif // HIGHLIGHTRECTITEM_H
