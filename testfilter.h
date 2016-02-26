#ifndef TESTFILTER_H
#define TESTFILTER_H

#include "filter.h"
#include "image.h"

#include <QColor>

class TestFilter : public Filter
{
public:
    TestFilter();
    ~TestFilter();

    virtual void execute(Image* image) override;

private:

};

#endif // TESTFILTER_H
