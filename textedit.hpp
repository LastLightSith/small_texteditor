#pragma once

#include <QTextEdit>
#include <QObject>
#include <QAction>

class TextEdit : public QTextEdit
{
    Q_OBJECT


    QAction m_makeBold;
    QAction m_makeSup;
    QAction m_makeSub;

    void initActions();

public:
    TextEdit();

    // QTextEdit interface
protected:
    void contextMenuEvent(QContextMenuEvent *e) override;
};

