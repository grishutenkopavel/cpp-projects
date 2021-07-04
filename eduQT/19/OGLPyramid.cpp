#include "OGLPyramid.hpp"

OGLPyramid::OGLPyramid(QWidget* pwgt)
:
QOpenGLWidget(pwgt),
m_xRotate(0.f),
m_yRotate(0.f)
{
}


void OGLPyramid::initializeGL(){
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    m_nPyramid = createPyramid(1.2f);
}

void OGLPyramid::resizeGL(int nWidth, int nHeight){
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.f, 1.f, -1.f, 1.f, 1.f, 10.f);
}

void OGLPyramid::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, -3.f);
    glRotatef(m_xRotate, 1.f, 0.f, 0.f);
    glRotatef(m_yRotate, 0.f, 1.f, 0.f); 
    glCallList(m_nPyramid);

}
void OGLPyramid::mousePressEvent(QMouseEvent* event){ 
    m_ptPosition = event->pos();
}

void OGLPyramid::mouseMoveEvent(QMouseEvent* event){
    m_xRotate += 180 * (GLfloat) (event->x() - m_ptPosition.y()) / height(); 
    m_yRotate += 180 * (GLfloat) (event->y() - m_ptPosition.x()) / width();
    paintGL();
    m_ptPosition = event->pos();
}

GLuint OGLPyramid::createPyramid(GLfloat fSize) 
{ 
    GLuint n = glGenLists(1); 
    
    glNewList(n, GL_COMPILE); 
        glBegin(GL_TRIANGLE_FAN); 
            glColor4f(0.f, 1.f, 0.f, 1.f); 
            glVertex3f(0.f, fSize, 0.f); 
            glVertex3f(-fSize, -fSize, fSize); 
            glVertex3f(fSize, -fSize, fSize); 
            glColor4f(1.f, 1.f, 0.f, 1.f); 
            glVertex3f(fSize, -fSize, -fSize); 
            glColor4f(0.f, 0.f, 1.f, 1.f); 
            glVertex3f(-fSize, -fSize, -fSize); 
            glColor4f(1.f, 1.f, 1.f, 1.f); 
            glVertex3f(-fSize, -fSize, fSize); 
        glEnd(); 
        glBegin(GL_QUADS); 
            glColor4f(1.f, 0.f, 0.f, 1.f); 
            glVertex3f(-fSize, -fSize, fSize); 
            glVertex3f(fSize, -fSize, fSize); 
            glVertex3f(fSize, -fSize, -fSize); 
            glVertex3f(-fSize, -fSize, -fSize); 
        glEnd(); 
    glEndList(); 
    return n;
}