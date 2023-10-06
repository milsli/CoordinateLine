#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "geocoordin.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    GeoCoordin* geoLongitude;
    GeoCoordin* geoLatitude;
};
#endif // WIDGET_H
