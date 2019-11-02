#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <QMenuBar>
#include <QEvent>
#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QLabel>

#include "board.h"


class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

    void centerBackground(QGraphicsView *view);

private:
    void CenterOnScreen();
    void loadMenu();

    QGraphicsView *viewDartBoard = new QGraphicsView;

protected:
    virtual void	resizeEvent(QResizeEvent *event);




};
#endif
