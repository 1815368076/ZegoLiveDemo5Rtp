#include "ZegoAVView.h"
#include <QDebug>

QZegoAVView::QZegoAVView(QWidget * parent) : QGraphicsView(parent)
{
	//quality = new QLabel(this);
	scene = new QZegoAVScene(this);
	scene->setSceneRect(0, 0, dynamic_cast<QZegoAVView *>(scene->parent())->size().width(), dynamic_cast<QZegoAVView *>(scene->parent())->size().height());
    setScene(scene);

	m_nAVQuality = -1;
	//quality->setText(tr("哈哈哈哈哈哈哈哈哈哈哈"));
	//quality->setGeometry(QRect(10, 10, 300, 40));
	//quality->setWindowFlags(quality->windowFlags() | Qt::WindowStaysOnTopHint);
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

#if (defined Q_OS_WIN32) && (defined USE_SURFACE_MERGE)
void QZegoAVView::setSurfaceMergeItemRect(SurfaceMerge::ZegoCaptureItem _screen,
	SurfaceMerge::ZegoCaptureItem _camera)
{
	scene->setSurfaceMergeItemRect(_screen, _camera);
}
#endif

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
	scene->setSceneRect(0 , 0 , dynamic_cast<QZegoAVView *>(scene->parent())->size().width() , dynamic_cast<QZegoAVView *>(scene->parent())->size().height());
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

#if (defined Q_OS_WIN32) && (defined USE_SURFACE_MERGE)
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
	//qDebug() << "view pressed!";
	QZegoAVView *view = (QZegoAVView *)this->views()[0];
	qDebug() << "this view's width = " << view->width() << " height = " << view->height();
	if (!view->getSurfaceMergeView())
		return;

	QPointF mousePosition = event->scenePos();
	int vx = view->width();
	int vy = view->height();
    
	scaleFactor_X = screen.position.width*(1.0) / view->width();
	scaleFactor_Y = screen.position.height*(1.0) / view->height();
   
	float blackBorderWidth = 0;
	float blackBorderHeight = 0;
	//初始化捕捉camera的范围
	float startPointX = camera.position.xPos / scaleFactor_X;
	float endPointX = (camera.position.xPos + camera.position.width) / scaleFactor_X;
	float startPointY = camera.position.yPos / scaleFactor_Y;
	float endPointY = (camera.position.yPos + camera.position.height) / scaleFactor_Y;

	//比例大于16:9或者4:3的话，黑边出现在左右
	if (view->width() * (1.0) / view->height() > screen.position.width * (1.0) / screen.position.height)
	{
		float screenWholeWidth = view->height() * screen.position.width / screen.position.height;
		blackBorderWidth = (view->width() - screenWholeWidth) / 2;

		startPointX = screenWholeWidth * (camera.position.xPos / scaleFactor_X) / view->width();
		endPointX = screenWholeWidth * ((camera.position.xPos + camera.position.width) / scaleFactor_X) / view->width();

	}
	//比例小于16:9或者4:3的话，黑边出现在上下
	else if (view->width() * (1.0) / view->height() < screen.position.width * (1.0) / screen.position.height)
	{
		float screenWholeHeight = view->width() * screen.position.height / screen.position.width;
		blackBorderHeight = (view->height() - screenWholeHeight) / 2;
		
		startPointY = screenWholeHeight * (camera.position.yPos / scaleFactor_Y) / view->height();
		endPointY = screenWholeHeight * ((camera.position.yPos + camera.position.height) / scaleFactor_Y) / view->height();
	}

	if (mousePosition.x() >= (startPointX + blackBorderWidth) && mousePosition.x() <= (endPointX + blackBorderWidth) && mousePosition.y() >= (startPointY + blackBorderHeight) && mousePosition.y() <= (endPointY + blackBorderHeight))
	{
		qDebug() << "pressed camera!!!";
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
		
		QPointF mousePosition = event->scenePos();

		if (mousePosition.x() >= view->width() || mousePosition.x() < 0)
			return;
		if (mousePosition.y() >= view->height() || mousePosition.y() < 0)
			return;

		QPointF move;
		move.setX(mousePosition.x() - curMousePosition.x());
		move.setY(mousePosition.y() - curMousePosition.y());

		bool isUpdate = false;
		//显示屏幕区域实际宽高
		float screenWholeWidth = view->width();
		float screenWholeHeight = view->height();
		//比例大于16:9或者4:3的话，黑边出现在左右
		if (view->width() * (1.0) / view->height() > screen.position.width * (1.0) / screen.position.height)
		{
			screenWholeWidth = view->height() * screen.position.width / screen.position.height;
		}
		//比例小于16:9或者4:3的话，黑边出现在上下
		else if (view->width() * (1.0) / view->height() < screen.position.width * (1.0) / screen.position.height)
		{
			screenWholeHeight = view->width() * screen.position.height / screen.position.width;
		}
		

		//右移情况
		if (move.x() > 0 && (camera.position.xPos + (move.x() * scaleFactor_X * (view->width() / screenWholeWidth)) + camera.position.width) <= (screen.position.xPos + screen.position.width))
		{
			camera.position.xPos += (int)(move.x() * scaleFactor_X * (view->width() / screenWholeWidth));
			isUpdate = true;
		}
		//右移最大值
		else if (move.x() > 0 && (camera.position.xPos + camera.position.width) < (screen.position.xPos + screen.position.width))
		{
			if (!isUpdate)
			{
				camera.position.xPos = (screen.position.width - camera.position.width);
				isUpdate = true;
			}
		}
        //左移情况
		if (move.x() < 0 && (camera.position.xPos + (move.x() * scaleFactor_X * (view->width() / screenWholeWidth)) >= 0))
        {
			camera.position.xPos += (int)(move.x() * scaleFactor_X * (view->width() / screenWholeWidth));
            isUpdate = true;
        }
        //左移最小值
        else if (move.x() < 0 && camera.position.xPos > 0)
        {
            if (!isUpdate)
            {
                camera.position.xPos = 0;
                isUpdate = true;
            }
        }
        //下移情况
		if (move.y() > 0 && (camera.position.yPos + (move.y() * scaleFactor_Y * (view->height() / screenWholeHeight)) + camera.position.height) <= (screen.position.yPos + screen.position.height))
		{
			camera.position.yPos += (int)(move.y() * scaleFactor_Y * (view->height() / screenWholeHeight));
			isUpdate = true;
		}
        //下移最大值
        else if (move.y() > 0 && (camera.position.yPos + camera.position.height) < (screen.position.yPos + screen.position.height))
        {
            if (!isUpdate)
            {
                camera.position.yPos = (screen.position.height - camera.position.height);
                isUpdate = true;
            }
        }
        //上移情况
		if (move.y() < 0 && (camera.position.yPos + (move.y() * scaleFactor_Y * (view->height() / screenWholeHeight)) >= 0))
        {
			camera.position.yPos += (int)(move.y() * scaleFactor_Y * (view->height() / screenWholeHeight));
            isUpdate = true;
        }
        //上移最小值
        else if (move.y() < 0 && camera.position.yPos > 0)
        {
            if (!isUpdate)
            {
                camera.position.yPos = 0;
                isUpdate = true;
            }
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


	}
}

void QZegoAVScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	isMousePressed = false;
}
#endif