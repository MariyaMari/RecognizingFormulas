#ifndef ASPECTRATIOLABEL_H
#define ASPECTRATIOLABEL_H

#pragma once

#include <QLabel>

class AspectRatioLabel : public QLabel
{
public:
    explicit AspectRatioLabel(QWidget* parent = NULL, Qt::WindowFlags f = Qt::WindowFlags());
    ~AspectRatioLabel();

public slots:
    void setPixmap(const QPixmap& pm);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void updateMargins();

    int pixmapWidth = 0;
    int pixmapHeight = 0;
};

#endif
