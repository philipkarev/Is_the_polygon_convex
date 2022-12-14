#ifndef CPOINT_POINT_H
#define CPOINT_POINT_H


#include <iostream>
using namespace std;


class Point {
    double x, y;
public:
    Point();
    Point(double, double);
    //Point(const Point&);
    int isEqual(Point);

    // следующие функции возвращают коэф. A, B, C
    // в ур-ии прямой A*x + B*y + C = 0
    double createLineA(Point);
    double createLineB(Point);
    double createLineC(Point);

    // подставить точку в уравнение и узнать знак
    int sign(double, double, double);

    Point operator+(const Point&) const;
    Point operator-(const Point&) const;

    friend class Polygon;
    friend ostream& operator<<(ostream& os, const Point& p);
};

#endif //CPOINT_POINT_H
