#ifndef ROOT_ELBOW_H
#define ROOT_ELBOW_H

#include "root.h"

class Elbow : public Root {
public:
    explicit Elbow(IplImage*);
    void first_search(Vect<float> const &vect_shoulder, Vect<float> const &vect_hand);

};

#endif // ROOT_ELBOW_H
