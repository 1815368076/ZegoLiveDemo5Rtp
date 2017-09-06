#include "ZegoAVView.h"
#include <QDebug>

QZegoAVView::QZegoAVView(QWidget * parent) : QGraphicsView(parent)
{
    setScene(new QZegoAVScene(this));
	m_nAVQuality = -1;
}

QZegoAVView::~QZegoAVView()
{

}

void QZegoAVView::setCurrentQuality(int quality)
{
	m_nAVQuality = quality;
}

int QZegoAVView::getCurrentQuality()
{
	return m_nAVQuality;
}

void QZegoAVView::setSurfaceMergeView(bool state)
{
	isSurfaceMergeView = state;
}

bool QZegoAVView::getSurfaceMergeView()
{
	return isSurfaceMergeView;
}

void QZegoAVView::paintEvent(QPaintEvent *event)
{
	QGraphicsView::paintEvent(event);

	/*QPainter painter(this->viewport());
	painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
	
	QColor color;
	switch (m_nAVQuality)
	{
	case 0:  //优
		color.setRed(0);
		color.setGreen(255);
		color.setBlue(0);
		painter.setPen(QPen(color, 0, Qt::SolidLine));
		painter.setBrush(QBrush(color, Qt::SolidPattern));

		painter.drawEllipse(10, 10, 8, 8);
		break;
	case 1:  //良
		color.setRed(255);
		color.setGreen(255);
		color.setBlue(0);
		painter.setPen(QPen(color, 0, Qt::SolidLine));
		painter.setBrush(QBrush(color, Qt::SolidPattern));

		painter.drawEllipse(10, 10, 8, 8);
		break;
	case 2:  //中
		color.setRed(255);
		color.setGreen(0);
		color.setBlue(0);
		painter.setPen(QPen(color, 0, Qt::SolidLine));
		painter.setBrush(QBrush(color, Qt::SolidPattern));

		painter.drawEllipse(10, 10, 8, 8);
		break;
	case 3:  //差
		color.setRed(211);
		color.setGreen(211);
		color.setBlue(211);
		painter.setPen(QPen(color, 0, Qt::SolidLine));
		painter.setBrush(QBrush(color, Qt::SolidPattern));

		painter.drawEllipse(10, 10, 8, 8);
		break;
	default:
		break;
	}*/
}

QZegoAVScene::QZegoAVScene(QWidget * parent)
	: QGraphicsScene(parent)
{
	
}

QZegoAVScene::~QZegoAVScene()
{

}

void QZegoAVScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsScene::mouseDoubleClickEvent(event);
	qDebug() << "view clicked!";
    
	//QList <QGraphicsView *> list = this->views();
}

void QZegoAVScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "view pressed!";
	QZegoAVView *view = (QZegoAVView *)this->views()[0];
	if (!view->getSurfaceMergeView())
		return;

	QPointF mousePosition = event->scenePos();
	qDebug() << "mouse pos = (" << mousePosition.x()<< ", "<<mousePosition.y()<<" )";

}

void QZegoAVScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "view Released!";
}