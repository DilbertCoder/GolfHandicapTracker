#include "InputGolfScoreDialog.h"
#include "ui_InputGolfScoreDialog.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
InputGolfScoreDialog::InputGolfScoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputGolfScoreDialog)
{
    ui->setupUi(this);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
InputGolfScoreDialog::~InputGolfScoreDialog()
{
    delete ui;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void InputGolfScoreDialog::PopulateCouseComboBox()
{

}
