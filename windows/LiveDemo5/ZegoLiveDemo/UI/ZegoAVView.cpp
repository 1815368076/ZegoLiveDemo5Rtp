#include "ZegoAVView.h"
#include <QDebug>

QZegoAVView::QZegoAVView(QWidget * parent) : QGraphicsView(parent)
{
	scene = new QZegoAVScene(this);
	scene->setSceneRect(0, 0,
		dynamic_cast<QZegoAVView *>(scene->parent())->size().width()
		, dynamic_cast<QZegoAVView *>(scene->parent())->size().height());
    setScene(scene);

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

void QZegoAVView::setSurfaceMergeItemRect(SurfaceMerge::ZegoCaptureItem _screen,
	SurfaceMerge::ZegoCaptureItem _camera)
{
	scene->setSurfaceMergeItemRect(_screen, _camera);
}

void QZegoAVView::setViewIndex(int index)
{
	viewIndex = index;
}

int QZegoAVView::getViewIndex()
{
	return viewIndex;
}

void QZegoAVView::resizeEvent(QResizeEvent *event)
{
	
	scene->setSceneRect(0, 0,
		dynamic_cast<QZegoAVView *>(scene->parent())->size().width()
		, dynamic_cast<QZegoAVView *>(scene->parent())->size().height());
	
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

void QZegoAVScene::setSurfaceMergeItemRect(ZEGO::SurfaceMerge::ZegoCaptureItem _screen,
	ZEGO::SurfaceMerge::ZegoCaptureItem _camera)
{
	screen = _screen;
	camera = _camera;
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
	qDebug() << "this view's width = " << view->width() << " height = " << view->height();
	if (!view->getSurfaceMergeView())
		return;

	QPointF mousePosition = event->scenePos();
	int vx = view->width();
	int vy = view->height();
	scaleFactor_X = screen.position.width*(1.0) / view->width();
	scaleFactor_Y = screen.position.height*(1.0) / view->height();

	if ((mousePosition.x() >= (camera.position.xPos / scaleFactor_X)) && (mousePosition.x() <= ((camera.position.xPos + camera.position.width) / scaleFactor_X)) && (mousePosition.y() >= (camera.position.yPos / scaleFactor_Y)) && (mousePosition.y() <= ((camera.position.yPos + camera.position.height) / scaleFactor_Y)))
	{
		isMousePressed = true;
		curMousePosition = mousePosition;
	}

}

void QZegoAVScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QZegoAVView *view = (QZegoAVView *)this->views()[0];
	if (!view->getSurfaceMergeView())
		return;

	if (isMousePressed){
		
		//QMutex mutex;
		//mutex.lock();
		QPointF mousePosition = event->scenePos();
		if (mousePosition.x() >= view->width() || mousePosition.x() < 0)
			return;
		if (mousePosition.y() >= view->height() || mousePosition.y() < 0)
			return;

		QPointF move;
		move.setX(mousePosition.x() - curMousePosition.x());
		move.setY(mousePosition.y() - curMousePosition.y());

		bool isUpdate = false;
		if ((move.x() > 0 && (camera.position.xPos + camera.position.width) < (screen.position.xPos + screen.position.width)) || (move.x() < 0 && (camera.position.xPos > 0)))
		{
			camera.position.xPos += (int)(move.x() * scaleFactor_X);
			isUpdate = true;
		}
		if ((move.y() > 0 && (camera.position.yPos + camera.position.height) < (screen.position.yPos + screen.position.height)) || (move.y() < 0 && (camera.position.yPos > 0)))
		{
			camera.position.yPos += (int)(move.y() * scaleFactor_Y);
			isUpdate = true;
		}
		if (isUpdate)
		{
			SurfaceMerge::ZegoCaptureItem *itemList = new SurfaceMerge::ZegoCaptureItem[2];
			itemList[0] = camera;
			itemList[1] = screen;

			SurfaceMerge::UpdateSurface(itemList, 2);
			delete[]itemList;
		}
		curMousePosition = mousePosition;
		//mutex.unlock();
	}
}

void QZegoAVScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	isMousePressed = false;
	qDebug() << "view Released!";
}