#ifndef IMAGEDISPLAY_H
#define IMAGEDISPLAY_H

#include <QGraphicsView>

class ImageDisplay : public QGraphicsView
{
public:
    ImageDisplay(QWidget*&);

private:
    void resizeEvent(QResizeEvent *event);
};

#endif // IMAGEDISPLAY_H
