#ifndef PRINTERITEM
#define PRINTERITEM

#endif // PRINTERITEM

// PrinterItem.h
#ifndef PRINTERITEM_H
#define PRINTERITEM_H

#include <QGraphicsPixmapItem>

class PrinterItem : public QGraphicsPixmapItem
{
public:
    PrinterItem(const QPixmap &pixmap, qreal x, qreal y, QGraphicsItem *parent = NULL);
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
   QPointF originalPos;
};

#endif // PRINTERITEM_H
