#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include "TeapotRenderer.h"

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    TeapotRenderer renderer;
};

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    renderer.init("/home/shuo/untitled/teapot.obj");
    //glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderer.render();
}
