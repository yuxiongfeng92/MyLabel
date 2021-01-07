#ifndef QEDITLABEL_H
#define QEDITLABEL_H
#include <QStackedWidget>
#include <QLabel>
#include <QLineEdit>
#include <QEvent>
#include <QObject>
#include <QWidget>
#include <QString>


class QEditLabel :public QWidget
{
    Q_OBJECT
public:
    QEditLabel(QWidget *parent=0);

public:
    bool eventFilter(QObject * obj, QEvent * e);

public:
    QStackedWidget * m_stackWidget=nullptr;
    QLabel * m_label=nullptr;
    QLineEdit * m_lineEdit=nullptr;
    void translateIntoLabel();
    QString m_txtLabel;

public:
    void initCtrls(void);
};

#endif // QEDITLABEL_H
