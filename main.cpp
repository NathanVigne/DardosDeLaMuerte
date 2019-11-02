#include "window.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication Dardos(argc, argv);
    Window win;
    win.show();



//    // Board
//    QGraphicsScene dartBoard;
//    Board *board = new Board;
//    board->setPos(100,100);

//    dartBoard.addItem(board);

//    QGraphicsView viewDartBoard(&dartBoard);
//    viewDartBoard.setMinimumSize(400,400);
//    viewDartBoard.setRenderHint(QPainter::Antialiasing);
//    viewDartBoard.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//    viewDartBoard.setBackgroundBrush(QColor(230, 200, 167));
//    viewDartBoard.setWindowTitle("Drag and Drop Robot");
//    viewDartBoard.show();

    return Dardos.exec();
}
