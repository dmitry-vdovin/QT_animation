#include "fish.h"

FishItem::FishItem(const QPixmap& pm, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(pm, parent)
{
    setTransformOriginPoint(pm.width() / 2.0, pm.height() / 2.0);
    timer_.setInterval(16);                       // ≈60 fps
    connect(&timer_, &QTimer::timeout, this, &FishItem::swim);
    timer_.start();
}

void FishItem::setBounds(const QRectF& b) { bounds_ = b; }

void FishItem::swim()
{
    moveBy(v_.x(), v_.y());

    // отражение от стен
    if (x() < bounds_.left() || x()+boundingRect().width() > bounds_.right())
        v_.rx() *= -1;
    if (y() < bounds_.top()  || y()+boundingRect().height() > bounds_.bottom())
        v_.ry() *= -1;

    // «поворачиваемся» в сторону движения
    setScale(v_.x() < 0 ? -1 : 1);
}
