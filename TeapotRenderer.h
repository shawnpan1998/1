#ifndef TEAPOT_RENDERER_H
#define TEAPOT_RENDERER_H

#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QString>

class TeapotRenderer {
public:
    TeapotRenderer();
    ~TeapotRenderer();

    void init(const QString &filePath);
    void render();

private:
    QOpenGLShaderProgram shaderProgram;
    QOpenGLBuffer vbo;
    QOpenGLVertexArrayObject vao;
    int vertexCount;
};

#endif // TEAPOT_RENDERER_H
