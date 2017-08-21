#include "FlashSign.h"
#include "ui_FlashSign.h"
#include <QPointF>
#include <QPainter>

FlashSign::FlashSign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlashSign)
{
    ui->setupUi(this);
//    setWindowFlags(Qt::FramelessWindowHint);
    m_iMargin = 2;
    m_pen.setColor(Qt::transparent);

    this->resize(10, 100);
}

FlashSign::~FlashSign()
{
    delete ui;
}

void FlashSign::SetPowerLeft(double fVal)
{
    m_fPowerLeft = fVal;
    if(fVal>0.60)
    {
        m_color = QColor(Qt::green);
    }
    else if(fVal>0.2)
    {
        m_color = QColor(Qt::yellow);
    }
    else
    {
        m_color = QColor(Qt::red);
    }
}

void FlashSign::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    int iWidth = this->width();
    int iHeight = this->height();
    int iBatteryW = iWidth-m_iMargin*2;
    int iBatteryH = iHeight-m_iMargin*2;

    QPointF pt_1(m_iMargin + iBatteryW*0.762, m_iMargin);
    QPointF pt_2(m_iMargin, m_iMargin+0.615*iBatteryH);
    QPointF pt_3(m_iMargin + iBatteryW*0.442, m_iMargin + iBatteryH*0.581);
    QPointF pt_4(m_iMargin + iBatteryW*0.149, m_iMargin + iBatteryH);
    QPointF pt_5(m_iMargin + iBatteryW, m_iMargin + iBatteryH*0.382);
    QPointF pt_6(m_iMargin + iBatteryW*0.479, m_iMargin + iBatteryH*0.432);

    QPointF pts[6] = {pt_1, pt_2, pt_3, pt_4, pt_5, pt_6};
    QPainter painter(this);
    painter.setBrush(QBrush(m_color));
    painter.setPen(m_pen);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPolygon(pts, 6);
}

void FlashSign::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    int iWidth = this->width();
    int iHeight = (iWidth + 2*m_iMargin) * 1.8354;

    this->resize(iWidth, iHeight);
}

