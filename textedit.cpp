#include "textedit.hpp"

#include <QMenu>
#include <QContextMenuEvent>
#include <QFont>
#include <QTextFormat>

TextEdit::TextEdit()
{
    initActions();
}

void TextEdit::initActions()
{
    m_makeBold.setText("Bold");
    m_makeSup.setText("SuperScript");
    m_makeSub.setText("SubScript");

    connect(&m_makeBold, &QAction::triggered, this, [&] {
        QTextCharFormat format;
        if (textCursor().charFormat().font().weight() == QFont::Bold ) {
            format.setFontWeight(QFont::Normal);
        }
        else {
            format.setFontWeight(QFont::Bold);
        }
        textCursor().mergeCharFormat(format);

    });

    connect(&m_makeSub, &QAction::triggered, this, [&] {
        QTextCharFormat format;

        if (textCursor().charFormat().verticalAlignment() == QTextCharFormat::AlignSubScript) {
            format.setVerticalAlignment(QTextCharFormat::AlignBaseline);
        }
        else {
            format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
        }
        textCursor().mergeCharFormat(format);
    });
    connect(&m_makeSup, &QAction::triggered, this, [&] {
        QTextCharFormat format;
        if (textCursor().charFormat().verticalAlignment() == QTextCharFormat::AlignSuperScript) {
            format.setVerticalAlignment(QTextCharFormat::AlignBaseline);
        }
        else {
            format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
        }
        textCursor().mergeCharFormat(format);
    });
}

void TextEdit::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu *menu = createStandardContextMenu();

    menu->addAction(&m_makeBold);
    menu->addAction(&m_makeSub);
    menu->addAction(&m_makeSup);

    menu->exec(e->globalPos());
}
