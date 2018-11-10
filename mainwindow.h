#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QWidget"
#include <QMenu>
#include <QToolBar>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QTabBar>
#include <QSplitter>
#include <QTreeView>
#include <QStatusBar>
#include <QGroupBox>
#include <QSizePolicy>
#include <QFileDialog>
#include <QMessageBox>


class MainWindow : public QMainWindow
{
  Q_OBJECT
private:
    QGroupBox *mainBox;
    QTabWidget *mainTabs;
    void createCentralBox();
    void createActions();
    void readSettings();
    void createStatusBar();
public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();
public slots:
void newFile();
void openFile();
void tabsCloseReqest(int);
};

#endif // MAINWINDOW_H
