void MainWindow::testpos(QPointF testpoint)
{


   if((ui->VBox_2->isOn) && !BoxVectV.empty())
   {
       for ( int ibox = 0; ibox != BoxVectV.size(); ibox++)
       {
           if(BoxVectV[ibox].contains(testpoint.x(), testpoint.y()))
           {
               QRectF tmpRectV(BoxVectV[ibox].toRect());
               QGraphicsPixmapItem* itemV = new QGraphicsPixmapItem();
               itemV->setPixmap(QPixmap::fromImage(MainWindow::bxV_scal));
               itemV->setPos((tmpRectV.topLeft().x() + int(SxRealOuterRectSizeXV/4)), (tmpRectV.topLeft().y() + int(UpRealOuterRectSizeXV/4)));
               scene_Pallet->addItem(itemV);

               qDebug() << "this point image V:...." << tmpRectV.topLeft();

               break;

           }
       }
   }

   if((ui->HBox_2->isOn) && !BoxVectH.empty())
   {
       for ( int ibox = 0; ibox != BoxVectH.size(); ibox++)
       {
           if(BoxVectH[ibox].contains(testpoint.x(), testpoint.y()))
           {
               QRectF tmpRectH(BoxVectH[ibox].toRect());
               QGraphicsPixmapItem* itemH = new QGraphicsPixmapItem();
               itemH->setPixmap(QPixmap::fromImage(MainWindow::bxH_scal));
               itemH->setPos((tmpRectH.topLeft().x() + int(SxRealOuterRectSizeXH/4)), (tmpRectH.topLeft().y() + int(UpRealOuterRectSizeXH/4)));
               scene_Pallet->addItem(itemH);

               qDebug() << "this point image H:...." << tmpRectH.topLeft();

               break;
           }
       }
   }
}
