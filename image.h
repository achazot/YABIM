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

#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QString>
#include <QStack>

#include "filter.h"

/**
 * @brief The Image class subclasses QImage
 * to implement image filtering manipulations
 *
 * Use the Image::applyFilter function to apply a Filter to the image.
 * The current version of the image will be stored in the history
 * before applying the filter. You can reset the image to its
 * previous state using the Image::undo method.
 *
 * Please refert to [Qt QImage's documentation](http://doc.qt.io/qt-5/qimage.html)
 * for details about QImage
 */
class Image : public QImage
{
public:
    /**
     * @brief Image constructs an empty Image
     */
    Image();

    /**
     * @brief Image construct an Image by loading a file
     * @param filename
     */
    Image(const QString& filename);
    ~Image();

    /**
     * @brief applyFilter applies the given *filter* to itself
     *
     * The current version of the image will be stored in the history
     * before applying the filter. You can reset the image to its
     * previous state using the Image::undo method.
     *
     * @param filter the filter to apply
     *
     * @see Image::undo
     */
    void applyFilter(Filter* filter);

    /**
     * @brief undo reset the image to its previous state
     * @return false if no more undo data are available after
     * this call, true otherwise
     */
    bool undo();

    /**
     * @brief toFT swap the picture data for its frenquencies
     * representation
     */
    void toFT();

    /**
     * @brief fromFT swap the picture frenquencies data for
     * its spacial representation
     */
    void fromFT();

private:
    QString m_name;
    QStack<Image> m_history;
};

#endif // IMAGE_H
