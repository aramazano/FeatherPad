/*
 * Copyright (C) Pedram Pourang (aka Tsu Jan) 2014 <tsujan2000@gmail.com>
 *
 * FeatherPad is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FeatherPad is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @license GPL-3.0+ <https://spdx.org/licenses/GPL-3.0+.html>
 */

#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QShortcut>
#include <QLineEdit>
#include <QIcon>
#include <QKeyEvent>

namespace FeatherPad {

class LineEdit : public QLineEdit {
    Q_OBJECT
public:
    LineEdit (QWidget *parent = 0);
    ~LineEdit();

signals:
    void receivedFocus();

protected:
    virtual void keyPressEvent (QKeyEvent *event)
    {
        /* because of a bug in Qt5, the non-breaking space (ZWNJ) isn't inserted with SHIFT+SPACE */
        if (event->key() == 0x200c)
        {
            insert (QChar (0x200C));
            event->accept();
            return;
        }
        QLineEdit::keyPressEvent (event);
    }
    void focusInEvent (QFocusEvent *ev);

private slots:
    void Klear();
    void unfocused();
    void focused();

private:
    QShortcut *klear;
};

}

#endif // LINEEDIT_H
