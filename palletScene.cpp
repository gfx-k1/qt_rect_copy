#include "palletscene.h"

PalletScene::PalletScene(QGraphicsScene *parent) : QGraphicsScene(parent)
{


}



PalletScene::~PalletScene(){}



void PalletScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /*bool chekpos = false;
    int atpos = 0;
    QPainter* boxnewpaint;

    if(!LayerBoxId.isEmpty())
    {
        while((atpos < 50) || chekpos == true)
        {

            if(!LayerBoxId.at(atpos).contains(event->pos())){atpos++;}
            else
            {
                emit newBoxFocus(atpos);
                boxnewpaint->drawImage(LayerBoxId.at(atpos).topLeft(), PalletScene::scaleBoximg);
                //paint(boxnewpaint,0,0);
                chekpos = true;
            }

        }
    }*/
    emit newBoxFocus(event->lastScenePos());
    QGraphicsScene::mouseReleaseEvent(event);

}



