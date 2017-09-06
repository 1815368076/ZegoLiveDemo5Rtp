#ifndef CHATLISTDELEGATE_H
#define CHATLISTDELEGATE_H

#include <QStyledItemDelegate>

class ChatListDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	explicit ChatListDelegate(QWidget *parent = 0);

	//basic function for a read-only delegate, you can draw anything with the painter
	void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
	//QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const;
};

#endif //CHATLISTDELEGATE_H