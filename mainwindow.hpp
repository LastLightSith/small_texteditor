#pragma once

#include <QAction>
#include <QMainWindow>
#include <QMenuBar>
#include <QTextEdit>
#include <QFile>
#include <QMenu>
#include "textedit.hpp"
#include "resume.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    TextEdit m_edit;
    Resume m_resume;
    QMenuBar m_menu;

    QFile m_file;

    QAction m_openFile;
    QAction m_saveFile;
    QAction m_aboutMe;

    void initActions();


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
