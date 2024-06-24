#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OpenGLWidget *openGLWidget = new OpenGLWidget(this);
    setCentralWidget(openGLWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

