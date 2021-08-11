#include <QDesktopServices>
#include <QUrl>

#include "resume.hpp"
#include "./ui_resume.h"


Resume::Resume() : QDialog(), ui(new Ui::Resume)
{
    ui->setupUi(this);
}

void Resume::openGithub()
{
    QDesktopServices::openUrl(QUrl("https://github.com/LastLightSith"));
}


void Resume::openlinkLinkedIn()
{
    QDesktopServices::openUrl(QUrl("https://www.linkedin.com/in/smit-patil"));
}


void Resume::openBlog()
{
    QDesktopServices::openUrl(QUrl("https://smit17.netlify.app"));
}
