#ifndef FLASH_SIGN_H
#define FLASH_SIGN_H

#include <QWidget>
#include <QPen>

namespace Ui {
class FlashSign;
}

class FlashSign : public QWidget
{
    Q_OBJECT

public:
    explicit FlashSign(QWidget *parent = 0);
    ~FlashSign();
    void SetPowerLeft(double fVal);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent* event);

private:
    Ui::FlashSign *ui;
    int m_iMargin;
    double m_fPowerLeft;

    QColor m_color;
    QPen m_pen;
};

#endif // FLASH_SIGN_H
