#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Resume;
}
QT_END_NAMESPACE

class Resume : public QDialog
{
    Q_OBJECT
private:
    Ui::Resume *ui;

public:
    Resume();

private slots:
    void openGithub();
    void openlinkLinkedIn();
    void openBlog();
};
