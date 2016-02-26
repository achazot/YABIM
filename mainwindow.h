/*
 * YABIM
 * Version: 0.1
 *
 * Yet Another Basic Image Manipulator
 *
 * Authors :
 *  A.Chazot <alban.chazot@insa-cvl.fr>
 *  A.Gourd <auxidevelopper@auxisuite.fr>
 *
 * 2016
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileDialog>

#include "image.h"
#include "filter.h"
#include "testfilter.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lin_prompt_returnPressed();

    void on_com_displayParameter_currentTextChanged(const QString &arg1);

    void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;
    Image m_currentImage;
    QGraphicsPixmapItem* m_pixelMap;
    QGraphicsScene* m_graphicsScene;

    void parseCommand(QString command);
    void loadImage(const QString& filename);

};

#endif // MAINWINDOW_H
