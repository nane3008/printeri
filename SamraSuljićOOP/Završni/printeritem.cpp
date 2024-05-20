
// PrinterItem.cpp
#include "PrinterItem.h"
#include <QGraphicsSceneMouseEvent>

PrinterItem::PrinterItem(const QPixmap &pixmap, qreal x, qreal y, QGraphicsItem *parent)
   : QGraphicsPixmapItem(pixmap, parent)
{
   setPos(x, y);
}

void PrinterItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   originalPos = pos();
   QGraphicsPixmapItem::mousePressEvent(event);
}

void PrinterItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   // Allow the printer to be moved
   QPointF newPos = mapToScene(event->pos());
   setPos(newPos);
   QGraphicsPixmapItem::mouseMoveEvent(event);
}

void PrinterItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   // Update printer's position in the database
   // Implement the database update logic here
   QGraphicsPixmapItem::mouseReleaseEvent(event);
}
