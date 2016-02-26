#include "testfilter.h"

TestFilter::TestFilter()
{

}

TestFilter::~TestFilter()
{}

void TestFilter::execute(Image *image)
{
    for(int x(0); x < image->height(); x++)
        for(int y(0); y < image->width(); y++)
        {
            QColor color = QColor::fromRgba(image->pixel(x, y));
            color.setGreen(200);
            image->setPixel(x, y, color.rgb());
        }
}
