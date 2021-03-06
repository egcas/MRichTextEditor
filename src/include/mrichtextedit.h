/*
** Copyright (C) 2013 Jiří Procházka (Hobrasoft)
** Contact: http://www.hobrasoft.cz/
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file is under the terms of the GNU Lesser General Public License
** version 2.1 as published by the Free Software Foundation and appearing
** in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the
** GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
*/

#ifndef _MRICHTEXTEDIT_H_
#define _MRICHTEXTEDIT_H_

#include <QPointer>
#include <QScopedPointer>
#include <QtCore>
#include <QtGui>
#include <QFont>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>


namespace Ui {
        class MRichTextEdit;
}

/**
 * @Brief A simple rich-text editor
 */
class MRichTextEdit : public QWidget {
    Q_OBJECT
  public:
    MRichTextEdit(QWidget *parent = 0, bool showInsertImage = true, bool removeFormatting = false);
    virtual ~MRichTextEdit();

    QString toHtml() const;
    QTextDocument *document();
    QString toPlainText() const;
    QTextCursor    textCursor() const;
    void           setTextCursor(const QTextCursor& cursor);
    /**
     * @brief setBasicFont set the basic font (font of normal text)
     * @param font the font to set
     */
    void setBasicFont(const QFont &font);
    /**
     * @brief setHeadingPointSizes set the point sizes for the headings
     * @param fontsize_h1 point size of heading H1
     * @param fontsize_h2 point size of heading H2
     * @param fontsize_h3 point size of heading H3
     * @param m_fontsize_h4 point size of heading H4
     */
    void setHeadingPointSizes(int fontsize_h1, int fontsize_h2, int fontsize_h3, int fontsize_h4);

  public slots:
    void setText(const QString &text);

  protected slots:
    void setPlainText(const QString &text);
    void setHtml(const QString &text);
    void textRemoveFormat();
    void textRemoveAllFormat();
    void textBold();
    void textSuperscript();
    void textSubscript();
    void textUnderline();
    void textStrikeout();
    void textItalic();
    void textSize(const QString &p);
    void setFont(const QFont &font);
    void textLink(bool checked);
    void textStyle(int index);
    void textFgColor();
    void textBgColor();
    void listBullet(bool checked);
    void listOrdered(bool checked);
    void slotCurrentCharFormatChanged(const QTextCharFormat &format);
    void slotCursorPositionChanged();
    void slotClipboardDataChanged();
    void increaseIndentation();
    void decreaseIndentation();
    void insertImage();
    void textSource();

  protected:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void fontChanged(const QFont &f);
    void fgColorChanged(const QColor &c);
    void bgColorChanged(const QColor &c);
    void list(bool checked, QTextListFormat::Style style);
    void indent(int delta);
    void focusInEvent(QFocusEvent *event);

    QStringList m_paragraphItems;
    int m_fontsize_h1;
    int m_fontsize_h2;
    int m_fontsize_h3;
    int m_fontsize_h4;

    enum ParagraphItems { ParagraphStandard = 0,
                          ParagraphHeading1,
                          ParagraphHeading2,
                          ParagraphHeading3,
                          ParagraphHeading4,
                          ParagraphMonospace };

    QPointer<QTextList> m_lastBlockList;
    QScopedPointer<Ui::MRichTextEdit> m_ui;
};

#endif
