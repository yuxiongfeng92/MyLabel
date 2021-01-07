#include "QEditLabel.h"
#include <QKeyEvent>
QEditLabel::QEditLabel(QWidget *parent):QWidget(parent)
{
   initCtrls();
}

bool QEditLabel::eventFilter(QObject * obj, QEvent * e) {
    if (obj == m_label) {
        if (e->type() == QEvent::MouseButtonDblClick){
            m_lineEdit->setText(m_txtLabel);
            m_stackWidget->setCurrentWidget(m_lineEdit);
        }
    }
    else if(obj == m_lineEdit) {
        if (e->type() == QEvent::KeyPress){
            QKeyEvent* keyevt = static_cast<QKeyEvent*>(e);
                        if ((keyevt->key() == Qt::Key_Return) ||
                            (keyevt->key() == Qt::Key_Escape) ||
                            (keyevt->key() == Qt::Key_Enter))   // Qt::Key_Return是大键盘的回车键 Qt::Key_Enter是小键盘的回车键
                        {
                            m_txtLabel=m_lineEdit->text();
                            m_label->setText(QString("%1%2%3").arg("<u>").arg(m_txtLabel).arg("</u>"));
                            m_stackWidget->setCurrentWidget(m_label);
         }
        }else if (e->type() == QEvent::FocusOut)
                {
                    m_txtLabel=m_lineEdit->text();
                    m_label->setText("<u>"+m_txtLabel+"</u>");
                    m_stackWidget->setCurrentWidget(m_label);
                }

    }
    return QWidget::eventFilter(obj, e);
}

void QEditLabel::initCtrls(void) {
    m_stackWidget = new QStackedWidget(this);
    m_txtLabel=QString::fromLocal8Bit("test");
    m_label = new QLabel();
    m_label->setText(QString("%1%2%3").arg("<u>").arg(m_txtLabel).arg("</u>"));
    //m_label->setStyleSheet("background-color:white");
    m_lineEdit = new QLineEdit();
    m_label->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    //m_stackWidget->setGeometry(0, 0, 50, 50);
    m_label->installEventFilter(this);
    m_lineEdit->installEventFilter(this);
    m_stackWidget->addWidget(m_label);
    m_stackWidget->addWidget(m_lineEdit);
    m_stackWidget->setCurrentWidget(m_label);
}

 void QEditLabel::translateIntoLabel(){
     m_label->setText(m_lineEdit->text());
     m_stackWidget->setCurrentWidget(m_label);
 }


