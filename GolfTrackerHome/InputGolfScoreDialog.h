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
    explicit InputGolfScoreDialog(QWidget *parent = 0);
    ~InputGolfScoreDialog();

protected:
    void PopulateCouseComboBox();

private:
    Ui::InputGolfScoreDialog *ui;
};

#endif // INPUTGOLFSCOREDIALOG_H
