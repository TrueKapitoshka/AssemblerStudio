#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  readSettings();
  createActions();
  createStatusBar();
  createCentralBox();
}

MainWindow::~MainWindow()
{

}

void MainWindow::newFile(){
  QTextEdit *newText = new QTextEdit();
  mainTabs->addTab(newText,tr("new"));
}

void MainWindow::createActions(){
  QMenu *menyFile = menuBar()->addMenu(tr("File"));
  QAction *actionNewFile = new QAction(tr("New file"));
  actionNewFile->setShortcut(QKeySequence::New);
  actionNewFile->setStatusTip(tr("Create a new file"));
  connect(actionNewFile, &QAction::triggered, this, &MainWindow::newFile);
  menyFile->addAction(actionNewFile);

  QAction *actionOpenFile = new QAction(tr("Open file"));
  actionOpenFile->setShortcut(QKeySequence::New);
  actionOpenFile->setStatusTip(tr("Open exist file"));
  menyFile->addAction(actionOpenFile);
  connect(actionOpenFile,SIGNAL(triggered()),this,SLOT(openFile()));
}

void MainWindow::createStatusBar()
{
  QStatusBar *statusBar = new QStatusBar();
  this->setStatusBar(statusBar);
}

void MainWindow::readSettings(){

}

void MainWindow::createCentralBox(){
  mainBox = new QGroupBox();
  QSplitter *spliter = new QSplitter();
  QTreeView *fileTree = new QTreeView();
  QSizePolicy spFileTree(QSizePolicy::Preferred, QSizePolicy::Preferred);
  spFileTree.setHorizontalStretch(1);
  fileTree->setSizePolicy(spFileTree);

  mainTabs = new QTabWidget();
  mainTabs->setTabsClosable(true);
  QTextEdit *textEdit = new QTextEdit();
  mainTabs->addTab(textEdit,tr("new"));
  QSizePolicy spMainTabs(QSizePolicy::Preferred, QSizePolicy::Preferred);
  spMainTabs.setHorizontalStretch(3);
  mainTabs->setSizePolicy(spMainTabs);

  QHBoxLayout *boxLayaut = new QHBoxLayout();
  boxLayaut->addWidget(fileTree);
  boxLayaut->addWidget(mainTabs);
  boxLayaut->addWidget(spliter);
  mainBox->setLayout(boxLayaut);

  connect(mainTabs,SIGNAL(tabCloseRequested(int)),this,SLOT(tabsCloseReqest(int)));
  spliter->addWidget(fileTree);
  spliter->addWidget(mainTabs);
  setCentralWidget(mainBox);
}

void MainWindow::tabsCloseReqest(int tabIndex){
  mainTabs->removeTab(tabIndex);
}

void MainWindow::openFile(){
  QString fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Save Address Book"), "",
                                                  tr("Assembler files (*.asm);;All Files (*)"));
  if (fileName.isEmpty()){
      return;
    }
  else {
      QFile file(fileName);
      if (!file.open(QIODevice::ReadOnly)) {
          QMessageBox::information(this, tr("Unable to open file"),
                                   file.errorString());
          return;
        }
    }
  QDataStream &inFileStream();
}
