#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class FishItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    explicit FishItem(const QPixmap& pm, QGraphicsItem *parent = nullptr);

    void setBounds(const QRectF& b);   // границы «аквариума»

private slots:
    void swim();                       // шаг анимации

private:
    QTimer  timer_;
    QPointF v_{2.2, 1.4};              // скорость (px / тик)
    QRectF  bounds_;
};
