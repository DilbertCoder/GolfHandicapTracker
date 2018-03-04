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
#ifndef GOLFTRACKERMAINWINDOW_H
#define GOLFTRACKERMAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>

#include "CourseWebRequest.h"
#include "UpdateCourseDataThread.h"



namespace Ui {
class GolfTrackerMainWindow;
}

class GolfTrackerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GolfTrackerMainWindow(QWidget *parent = 0);
    ~GolfTrackerMainWindow();

signals:

protected slots:
    void OnActionUpdateCoursesTriggered();

private:
    Ui::GolfTrackerMainWindow *ui;

    CourseWebRequest m_UsgaRequest;

    QSharedPointer<UpdateCourseDataThread> m_CourseUpdateThread;
};

#endif // GOLFTRACKERMAINWINDOW_H
