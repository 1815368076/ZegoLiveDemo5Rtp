#include "ZegoShareDialog.h"
#include <QDebug>

ZegoShareDialog::ZegoShareDialog(const QString& link, QWidget *parent)
	: m_link(link), QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.m_copy, &QPushButton::clicked, this, &ZegoShareDialog::OnButtonCopy);
	connect(ui.m_quit, &QPushButton::clicked, this, &ZegoShareDialog::OnButtonQuit);

	ui.m_link->setText(m_link);
	qDebug() << m_link;
}

ZegoShareDialog::~ZegoShareDialog()
{

}

void ZegoShareDialog::OnButtonCopy()
{
	QClipboard *board = QApplication::clipboard();
	board->setText(m_link);

	QMessageBox::information(NULL, QStringLiteral("成功"), QStringLiteral("链接已复制到粘贴板"));
	this->close();
}

void ZegoShareDialog::OnButtonQuit()
{
	this->close();
}