#pragma once
#include <QMainWindow>
#include <QGraphicsScene>

class FishItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *e) override;   // пересчитываем «аквариум»

private:
    QGraphicsScene scene_;
    FishItem      *fish_;
};
