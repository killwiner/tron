#ifndef RENDER_H
#define RENDER_H

#include "../defines.h"
#include <QtOpenGL>
#include <QGLWidget>
#include <opencv2/core.hpp>

#include <QSharedPointer>

namespace rendering {

class Render : public QGLWidget
{
    Q_OBJECT
public:

    // interval_time : interval time between each image
    Render(const quint16 &framesPerSecond, const quint16 &interval_time);
    virtual ~Render();

    // accesseurs
    bool toClose();

    void setImages(const QSPVImage &VImage);
    void setImage(const cv::Mat *Image);

public slots:
    void timeOutSlot();

signals:
    void close();

protected:
    QTimer *t_Timer;

    GLuint texture;
    QSPVImage PVImage_;

    void closeEvent(QCloseEvent *event);
    virtual void initializeGL();
    virtual void resizeGL(int width, int height);
    virtual void paintGL();

private:
    bool closing;

};
}

#endif // RENDER_H