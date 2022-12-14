#include "Point.h"


Point::Point() {

    this->x = 0;
    this->y = 0;
}


Point::Point(double x, double y) {

    this->x = x;
    this->y = y;
}


int Point::isEqual(Point a) {

    if ((this->x - a.x < 0.00000001 or - this->x + a.x < 0.00000001) \
        and (this->y - a.y < 0.00000001 or - this->y + a.y < 0.00000001))
        return 1;
    else
        return 0;
}


double Point::createLineA(Point a) {

    double A = a.y - this->y;
    return A;
}


double Point::createLineB(Point a) {

    double B = this->x - a.x;
    return B;
}


double Point::createLineC(Point a) {

    double C = -a.x * (a.y - this->y) + a.y * (a.x - this->x);
    return C;
}


int Point::sign(double A, double B, double C) {

    double value = A * this->x + B * this->y + C;
    if (value > 0)
        return 1;
    else if (value < 0)
        return -1;
    else
        return 0;
}


Point Point::operator-(const Point &b) const {

    Point p(this->x - b.x, this->y - b.y);
    return p;
}


Point Point::operator+(const Point &d) const {

    Point p(this->x + d.x, this->y + d.y);
    return p;
}

ostream &operator<<(ostream &os, const Point &p) {

    os << "(" << p.x << ", " << p.y << ")";
    return os;
}