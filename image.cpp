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

#include "image.h"

Image::Image() : QImage()
{}

Image::Image(const QString &filename) : QImage(filename)
{}

Image::~Image()
{}

void Image::applyFilter(Filter* filter)
{
    filter->execute(this);

    // TODO: Manage history
}

bool Image::undo()
{
    return false;
}

void Image::toFT()
{

}

void Image::fromFT()
{

}
