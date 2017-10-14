#include "mainwindow.h"
#include "QAction"
#include "QMenuBar"
#include "QInputDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //参数初始化

    setWindowIcon(QPixmap(":/picture/res/picture/bird_yellow.png").copy(0,0,34,24));
    setFixedSize(288,512);

    FPS = 30;
    mainScene = new SceneMain();
//    sceneEnd = new SceneEnd();
//    startScene = new SceneStart();

    scene = mainScene->sceneStart();

    timer = new QTimer(this);
    timer->setInterval(1000/FPS);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimeout()));

    //菜单设置
    QAction *actSetFPS = new QAction("设置帧率",this);
    menuBar()->addAction(actSetFPS);
    connect(actSetFPS,SIGNAL(triggered(bool)),this,SLOT(slotSetFPS()));

    timer->start();
}

MainWindow::~MainWindow()
{

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    scene->keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    scene->keyReleaseEvent(event);
}

void MainWindow::paintEvent(QPaintEvent * )
{
    QPainter painter(this);
    scene->draw(&painter);
}

void MainWindow::slotTimeout()
{
    scene->refresh();
    sceneManager();
    update();
}

void MainWindow::slotSetFPS()
{
    scene->pause = true;
    bool ok = false;
    int newfps = QInputDialog::getInt(this,"设置帧率","请输入帧率",60,1,100,1,&ok);
    if(ok)
        FPS = newfps;
    this->timer->start(1000/FPS);
    scene->pause = false;
    this->activateWindow();
}

void MainWindow::sceneManager()
{
//    int result = scene->sceneFinish();
//    if(result)
//    {
//        if(scene == sceneMain)
//        {
//            scene = sceneEnd->sceneStart();
//        }
//        else if(scene == sceneStart)
//        {
//            scene = sceneMain->sceneStart();
//        }
//        else if(scene == sceneEnd)
//        {
//            scene = sceneMain->sceneStart();
//        }
//    }
}
