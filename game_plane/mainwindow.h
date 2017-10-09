#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"
#include "QKeyEvent"
#include "QPixmap"
#include "scenemain.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void paintEvent(QPaintEvent*);
private slots:
    void slotTimeout();
    void slotSetFPS();
private:
    Scene *scene;
//    SceneEnd *sceneEnd;
    SceneMain *mainScene;
//    SceneStart *sceneStart;
    QTimer *timer;
    int FPS;
    void sceneManager();
};

#endif // MAINWINDOW_H
