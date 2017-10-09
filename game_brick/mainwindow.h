#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "QList"
#include "scenemain.h"
#include "sceneend.h"
#include "scenestart.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
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
    SceneEnd *sceneEnd;
    SceneMain *sceneMain;
    SceneStart *sceneStart;
    QList<Scene*> *allScene;
    QTimer *timer;
    int FPS;
    void sceneManager();
};

#endif // MAINWINDOW_H
