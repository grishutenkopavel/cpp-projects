#pragma once

#include <QOpenGLWidget>
#include <QtWidgets>


class OGLPyramid : public QOpenGLWidget
{

private:
    GLuint m_nPyramid;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint m_ptPosition;
protected:
    void initializeGL()                       override;
    void resizeGL(int nWidth, int nHeight)    override;
    void paintGL()                            override;
    void mousePressEvent(QMouseEvent *event)  override;
    void mouseMoveEvent(QMouseEvent *event)   override;
    
    GLuint createPyramid(GLfloat fSize = 1.f);
public:
    OGLPyramid(QWidget* pwgt = 0);
};


