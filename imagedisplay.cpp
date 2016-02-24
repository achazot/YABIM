#include "imagedisplay.h"

ImageDisplay::ImageDisplay(QWidget*& widget)
    : QGraphicsView(widget)
{
}

void ImageDisplay::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    fitInView(this->sceneRect(), Qt::KeepAspectRatio);
}
