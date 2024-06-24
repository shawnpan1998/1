#include "TeapotRenderer.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

TeapotRenderer::TeapotRenderer() {}

TeapotRenderer::~TeapotRenderer() {
    vao.destroy();
    vbo.destroy();
}

void TeapotRenderer::init(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << filePath;
        return;
    }

    // 读OBJ文件
    QVector<QVector3D> vertices;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(' ', QString::SkipEmptyParts);
        if (parts.isEmpty())
            continue;
        if (parts[0] == "v") {
            if (parts.size() < 4)
                continue;
            float x = parts[1].toFloat();
            float y = parts[2].toFloat();
            float z = parts[3].toFloat();
            vertices.append(QVector3D(x, y, z));
        }
    }
    file.close();

    vertexCount = vertices.size();

    shaderProgram.create();
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "/home/shuo/untitled/vertexShader.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "/home/shuo/untitled/fragmentShader.frag");
    shaderProgram.link();


    vao.create();
    vao.bind();
    vbo.create();
    vbo.bind();
    vbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector3D));
    shaderProgram.enableAttributeArray(0);
    shaderProgram.setAttributeBuffer(0, GL_FLOAT, 0, 3);
    vao.release();
    vbo.release();
}

void TeapotRenderer::render() {
    shaderProgram.bind();
    vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    vao.release();
    shaderProgram.release();
}
