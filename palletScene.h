#ifndef PALLETSCENE_H
#define PALLETSCENE_H

#include <QGraphicsItem>
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
#include <QPainter>
#include <QGraphicsObject>
#include <QObject>
#include <QGraphicsItem>ì
#include <QDrag>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMimeType>
#include <QImage>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
QT_END_NAMESPACE


class PalletScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PalletScene(QGraphicsScene *parent = 0);

    virtual ~PalletScene();
    //static QImage Boximg;
    //static QImage scaleBoximg;
    //static QImage realBoximg;
    //static QPoint ImgPosition;

   // void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    //void setImageDim(QImage realImage, int dXImage, int dYImage);
    //void setImagePos(int Xspace, int Yspace);

public slots:
    //void addLayerBox (int id, QRectF rect);

protected:
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    //QList<QRectF> LayerBoxId;

signals:
    void newBoxId(int);
    void newBoxFocus(QPointF);
    void selectedBox(QRectF);



};

#endif // PALLETSCENE_H
