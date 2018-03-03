#ifndef GOLFTRACKERMAINWINDOW_H
#define GOLFTRACKERMAINWINDOW_H

#include <QMainWindow>

#include "CourseWebRequest.h"

namespace Ui {
class GolfTrackerMainWindow;
}

class GolfTrackerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GolfTrackerMainWindow(QWidget *parent = 0);
    ~GolfTrackerMainWindow();

private:
    Ui::GolfTrackerMainWindow *ui;

    CourseWebRequest m_UsgaRequest;
};

#endif // GOLFTRACKERMAINWINDOW_H
