#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    geoLongitude = new GeoCoordin(true);
    geoLatitude = new GeoCoordin(false);
    geoLongitude->setMaximumWidth(200);
    geoLatitude->setMaximumWidth(200);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(30);
    layout->setAlignment(Qt::AlignCenter);
    layout->addWidget(geoLongitude);
    layout->addWidget(geoLatitude);


    setLayout(layout);
}

Widget::~Widget()
{
}

