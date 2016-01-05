#ifndef ROOT_H
#define ROOT_H

#include <QSharedPointer>
#include "vectors_maths/maths_vect.h"
#include "win_size.h"
#include <opencv2/opencv.hpp>

#define PIXEL_COLOR_BLUE(X, Y) imageData[coord_gbr(Vect<int>(X, Y, 0))]
#define PIXEL_COLOR_GREEN(X, Y) imageData[coord_gbr(Vect<int>(X, Y, 0)) + 1]
#define PIXEL_COLOR_RED(X, Y) imageData[coord_gbr(Vect<int>(X, Y, 0)) + 2]

#define PIXEL_COLOR_BLUE_VECT(V) imageData[coord_gbr(V)]
#define PIXEL_COLOR_GREEN_VECT(V) imageData[coord_gbr(V) + 1]
#define PIXEL_COLOR_RED_VECT(V) imageData[coord_gbr(V) + 2]

namespace root {
    class Root {
    public:
        explicit Root();
        ~Root();
        virtual void search(QSharedPointer<IplImage> const &, float const &, int const &, Vect<float> const &);
        void frame(IplImage *);

        Vect<float> p;

    protected:
        // the frame with draw of roots
        // l'image avec les dessins des noeuds
        QSharedPointer<IplImage> SP_frame_draw;
        // frame to stude
        // référence à l'image qu'on étudie
        QSharedPointer<IplImage> SP_frame;
    };
}
#endif // ROOT_H
