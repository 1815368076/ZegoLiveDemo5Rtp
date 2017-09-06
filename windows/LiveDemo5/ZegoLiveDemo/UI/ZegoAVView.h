#pragma once

#include <QPainter>
#include <QColor>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

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

protected:
	virtual void paintEvent(QPaintEvent *event);
	//virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
	int m_nAVQuality;
	bool isSurfaceMergeView = false;
};

class QZegoAVScene : public QGraphicsScene
{
	Q_OBJECT

public:
	QZegoAVScene(QWidget * parent = 0);
	~QZegoAVScene();

protected:
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};