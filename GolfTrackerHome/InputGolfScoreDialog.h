//-----------------------------------------------------------------------------
//Golf Tracker Home
//Copyright (C) 2018 DilbertCoder
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------------
#ifndef INPUTGOLFSCOREDIALOG_H
#define INPUTGOLFSCOREDIALOG_H

#include <QDialog>

namespace Ui {
class InputGolfScoreDialog;
}

class InputGolfScoreDialog : public QDialog
{
    Q_OBJECT

public:
    //-------------------------------------------------------------------------
    //! Constructor
    //! \param parent Pointer to the parent widget (default nullptr)
    //-------------------------------------------------------------------------
    explicit InputGolfScoreDialog(QWidget *parent = 0);

    //-------------------------------------------------------------------------
    //! Deconstructor
    //-------------------------------------------------------------------------
    ~InputGolfScoreDialog();

protected slots:
    void OnPushButtonFindCourseClicked();

private:
    Ui::InputGolfScoreDialog *ui;

    const QString m_CourseDataDir;
};

#endif // INPUTGOLFSCOREDIALOG_H
