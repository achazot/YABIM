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

#ifndef FILTER_H
#define FILTER_H

class Image;

/**
 * @brief The Filter class is an abstrat class that defines filters
 *
 * You need to subclass this class and implement the Filter::execute
 * method. Here you are supposed to proceed the given *image*.
 *
 */
class Filter
{
public:
    Filter();

    /**
     * @brief execute proceeds the given *image*
     * @param image is the image onto which the filter has to be applied
     */
    virtual void execute(Image* image) = 0;
};

#endif // FILTER_H
