#include "ChatListDelegate.h"
#include <QPainter>
#include <QDebug>
#include <QTextOption>
#include <QStyleOptionViewItem>
#include <QLabel>

ChatListDelegate::ChatListDelegate(QWidget *parent) :
QStyledItemDelegate(parent)
{
	QLabel *label = new QLabel;
}

void ChatListDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	//QStyleOptionViewItem itemOption(option);

	QString srcStr = index.data().toString();

	//以冒号分割字符串，分别配上不同的颜色
	int strIndex = srcStr.indexOf(":");
	QString userName = srcStr.left(strIndex);
	QString content = srcStr.mid(strIndex, srcStr.size());
	
	QTextOption op(Qt::AlignLeft | Qt::AlignVCenter);
	op.setWrapMode(QTextOption::WordWrap);

	painter->save();
	//QRect displayRect(0, 0, 100, 100);//set the paint rect
	painter->setPen(QColor(14, 136, 235));
	painter->drawText(option.rect, userName, op);
	painter->restore();

	painter->save();

	painter->setPen(QColor(51, 51, 51));
	painter->drawText(option.rect, content, op);
	painter->restore();
	

	//qDebug() << "username = "<<userName << " content = " << content;
	//QStyledItemDelegate::paint(painter, itemOption, index);
}