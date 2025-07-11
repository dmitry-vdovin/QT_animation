#include "mainwindow.h"
#include "fish.h"
#include <QGraphicsView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Полотно
    auto *view = new QGraphicsView(&scene_, this);
    setCentralWidget(view);
    view->setRenderHint(QPainter::Antialiasing);
    view->setFrameStyle(QFrame::NoFrame);

    // Загружаем картинку из той же папки, где .exe
    QPixmap raw("fish.png");

QPixmap pix = raw.scaled(128, 256, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        qWarning() << "Не найден fish.png рядом с исполняемым файлом";

    // Создаём рыбку
    fish_ = new FishItem(pix);
    scene_.addItem(fish_);
    fish_->setPos(50, 50);
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    QMainWindow::resizeEvent(e);

    // Обновляем размер сцены
    scene_.setSceneRect(rect());

    // Ограничиваем зону плавания рыбки
    QRectF bounds = scene_.sceneRect().adjusted(
        0, 0,
        -fish_->boundingRect().width(),
        -fish_->boundingRect().height());
    fish_->setBounds(bounds);
}
