#include "window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{

    // Définition du titre
    setWindowTitle(tr("Dardos de la muerte !!"));
    setWindowIcon(QIcon(":/ICO/Icone/Icone.png"));

    // Menu
    loadMenu();

    // Zone Central
    QWidget *zC = new QWidget;

    // Score
    QLabel *score = new QLabel;
    score->setFixedWidth(100);
    score->setFixedHeight(100);
    score->setAlignment(Qt::AlignCenter);
    score->setText("text");

    // Board
    Board *board = new Board(nullptr,score);

    viewDartBoard->setScene(board);
    viewDartBoard->setRenderHint(QPainter::Antialiasing);
    viewDartBoard->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
    viewDartBoard->setFrameShape(QGraphicsView::NoFrame);


    viewDartBoard->setStyleSheet("background : transparent");

    //Layout
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(viewDartBoard);
    layout->addWidget(score);

    setCentralWidget(zC);
    zC->setLayout(layout);

    // Background color
    centerBackground(viewDartBoard);

    // Set Opening Size & position
    CenterOnScreen();
    resize(800,600);

}


Window::~Window()
{
    delete viewDartBoard;
}

void Window::CenterOnScreen()
{
  QDesktopWidget screen;

  QRect screenGeom = screen.screenGeometry(this);

  int screenCenterX = screenGeom.center().x();
  int screenCenterY = screenGeom.center().y();

  move(screenCenterX - width () / 2,
       screenCenterY - height() / 2);
}

void Window::loadMenu()
{
    QMenu *menuFichier = menuBar()->addMenu("Fichier");
    menuFichier->addAction("Quitter", qApp, SLOT(quit()));

    QMenu *menuEdition = menuBar()->addMenu("Edition");
    menuEdition->addAction("Quitter", qApp, SLOT(quit()));

    QMenu *menuAffichage = menuBar()->addMenu("Affichage");
    menuAffichage->addAction("Quitter", qApp, SLOT(quit()));

}

void Window::centerBackground(QGraphicsView *view)
{
    qreal cx,cy,radius,fx,fy;
    cx = (view->pos().x()+view->width()/2)/(this->width());
    cy = (view->pos().y()+view->height()/2)/(this->height());
    fx = cx;
    fy = cy;
    radius = view->width()/(this->width());

//    QString style = QString("QMainWindow {background: qradialgradient(spread:pad, cx:%1, cy:%2, radius:%3, fx:%4, fy:%5,"
//                            "stop:0 rgba(100, 149, 237,255), stop:1 rgba(25, 25, 112,255))}").arg(cx).arg(cy).arg(radius).arg(fx).arg(fy);
//    this->setStyleSheet(style);

    QPalette palette;
    QRadialGradient grad = QRadialGradient(cx,cy,radius);
    grad.setColorAt(0,QColor(100,149,237));
    grad.setColorAt(1,QColor(25,25,112));
    palette.setBrush(QPalette::Background, grad);
    this->setPalette(palette);
}

void Window::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    //centerBackground(viewDartBoard);
    QRectF rectScene = viewDartBoard->sceneRect();
    viewDartBoard->fitInView(rectScene,Qt::KeepAspectRatio);
}
