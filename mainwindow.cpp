#include "mainwindow.hpp"
#include "resume.hpp"

#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>

#include "resume.hpp"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initActions();

    setMenuBar(&m_menu);
    setCentralWidget(&m_edit);
}

void MainWindow::initActions()
{
    connect(&m_openFile, &QAction::triggered, this, [&] {
        m_file.setFileName(QFileDialog::getOpenFileName());
        m_file.open(QFile::ReadWrite);

        auto content = m_file.readAll();

        m_edit.setText(content);
        setWindowTitle(m_file.fileName());
    });

    connect(&m_saveFile, &QAction::triggered, this, [&] {
        if (!m_file.isOpen()) {
            m_file.setFileName(QFileDialog::getSaveFileName());
            m_file.open(QFile::ReadWrite);
        }

        auto data = m_edit.document()->toHtml();
        m_file.resize(0);
        m_file.write(data.toLatin1());
        setWindowTitle(m_file.fileName());
    });

    connect(&m_aboutMe, &QAction::triggered, this, [&] { m_resume.show(); });

    m_openFile.setText("Open");
    m_saveFile.setText("Save");
    m_aboutMe.setText("AboutMe");

    m_menu.addAction(&m_openFile);
    m_menu.addAction(&m_saveFile);
    m_menu.addAction(&m_aboutMe);

    m_resume.setModal(true);
}

MainWindow::~MainWindow() {}
