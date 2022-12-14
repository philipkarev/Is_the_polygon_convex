//
// Created by phlilp on 14.12.22.
//

#ifndef TASK_10_2_POLYGON_H
#define TASK_10_2_POLYGON_H

#include <iostream>

#include "Point.h"

using namespace std;


class Polygon {
    Point* a = nullptr; // array of Points
    int l = 0; // length of a
public:
    Polygon(Point*, int);
    ~Polygon();

    int isConvex();

    friend ostream &operator<<(ostream &stream, const Polygon &s);
};

#endif //TASK_10_2_POLYGON_H
