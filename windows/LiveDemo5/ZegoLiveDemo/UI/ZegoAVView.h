#pragma once

#include <QPainter>
#include <QColor>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#define USE_SURFACE_MERGE
#if (defined Q_OS_WIN32) && (defined USE_SURFACE_MERGE)
#include "ZegoSurfaceMerge.h"
#include "ZegoSurfaceMergeDefine.h"
using namespace ZEGO;
#endif


class QZegoAVScene;
class QZegoAVView : public QGraphicsView
{
	Q_OBJECT
public:
	QZegoAVView(QWidget * parent = 0);
	~QZegoAVView();

	void setCurrentQuality(int quality);
	int getCurrentQuality();

	void setSurfaceMergeView(bool state);
	bool getSurfaceMergeView();

#if (defined Q_OS_WIN32) && (defined USE_SURFACE_MERGE)
	void setSurfaceMergeItemRect(SurfaceMerge::ZegoCaptureItem _screen,
	                         SurfaceMerge::ZegoCaptureItem _camera);
#endif

	void setViewIndex(int index);
	int getViewIndex();

protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void resizeEvent(QResizeEvent *event);

private:
	QZegoAVScene *scene;
	int m_nAVQuality;
	bool isSurfaceMergeView = false;
	int viewIndex;
};

class QZegoAVScene : public QGraphicsScene
{
	Q_OBJECT

public:
	QZegoAVScene(QWidget * parent = 0);
	~QZegoAVScene();

#if (defined Q_OS_WIN32) && (defined USE_SURFACE_MERGE)
	void setSurfaceMergeItemRect(SurfaceMerge::ZegoCaptureItem _screen,
		SurfaceMerge::ZegoCaptureItem _camera);

protected:
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
#endif

#if (defined Q_OS_WIN32) && (defined USE_SURFACE_MERGE)
private:
	bool isMousePressed = false;
	SurfaceMerge::ZegoCaptureItem screen;
	SurfaceMerge::ZegoCaptureItem camera;
	float scaleFactor_X;
	float scaleFactor_Y;
	QPointF curMousePosition;
#endif
};