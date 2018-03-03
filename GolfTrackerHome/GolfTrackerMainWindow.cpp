#include "GolfTrackerMainWindow.h"
#include "ui_GolfTrackerMainWindow.h"

GolfTrackerMainWindow::GolfTrackerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GolfTrackerMainWindow)
{
    ui->setupUi(this);
}

GolfTrackerMainWindow::~GolfTrackerMainWindow()
{
    delete ui;
}
